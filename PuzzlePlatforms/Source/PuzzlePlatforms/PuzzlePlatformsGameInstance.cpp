// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformsGameInstance.h"

#include "OnlineSubsystem.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "PlatformTrigger.h"
#include "Blueprint/UserWidget.h"

#include "OnlineSessionSettings.h"
#include "UnrealWidgetFwd.h"

#include "MenuSystems/GameMenu.h"
#include "MenuSystems/MainMenu.h"



const static FName SESSION_NAME =TEXT("Game");
const static FName SERVER_NAME_SETTINGS_KEY= TEXT("ServerName");
UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> MenuBPClass(TEXT("/Game/MenuSystem/MainMenu"));

	if(MenuBPClass.Class == nullptr)
	{
		return;
	}

	MenuClass = MenuBPClass.Class;

	ConstructorHelpers::FClassFinder<UUserWidget> ExitMenuBPClass(TEXT("/Game/MenuSystem/ExitMenu"));

	if(ExitMenuBPClass.Class == nullptr)
	{
		return;
	}
	ExitMenuClass=ExitMenuBPClass.Class;
}

void UPuzzlePlatformsGameInstance::Init()
{

	IOnlineSubsystem* Subsystem = IOnlineSubsystem::Get();
	if (Subsystem != nullptr)
	{
		UE_LOG(LogTemp, Warning,TEXT("Found Subsystem %s"), *Subsystem->GetSubsystemName().ToString());
		SessionInterface = Subsystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(
				this,
				&UPuzzlePlatformsGameInstance::OnCreateSessionComplete
				);
			SessionInterface->OnDestroySessionCompleteDelegates.AddUObject(
				this,
				&UPuzzlePlatformsGameInstance::OnDestroySessionComplete
				);

			SessionInterface->OnFindSessionsCompleteDelegates.AddUObject(
				this,
				&UPuzzlePlatformsGameInstance::OnFindSessionComplete
				);

			SessionInterface->OnJoinSessionCompleteDelegates.AddUObject(
				this,
				&UPuzzlePlatformsGameInstance::OnJoinSessionComplete
				);
		}
		if (GEngine != nullptr)
		{
			GEngine->OnNetworkFailure().AddUObject(this,&UPuzzlePlatformsGameInstance::OnNetworkFailure);
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found no Subsystem"));
	}
	
	
}

void UPuzzlePlatformsGameInstance::LoadMenuWidget()
{
	if(!ensure(MenuClass != nullptr)) return;
	Menu = CreateWidget<UMainMenu>(this, MenuClass);

	if (!ensure((Menu != nullptr))) return;

	Menu->Setup();

	Menu->SetMenuInterface(this);

}



void UPuzzlePlatformsGameInstance::Host(FString ServerName)
{
	DesiredServerName=ServerName;
	if (SessionInterface.IsValid())
	{
		FNamedOnlineSession* ExistingSession = SessionInterface->GetNamedSession(SESSION_NAME);

		if (ExistingSession != nullptr)
		{
			SessionInterface->DestroySession(SESSION_NAME);
		}
		else
		{
			CreateSession();
		}
		
	}
}


void UPuzzlePlatformsGameInstance::OnCreateSessionComplete(FName SessionName, bool Success)
{

	if (!Success)
	{
		UE_LOG(LogTemp, Warning, TEXT("Could not create session"));
		return;
	}
	if (Menu !=nullptr)
	{
		Menu->Teardown();
	}
	
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 2,FColor::Green,TEXT("Hosting"));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/PuzzlePlatform/Maps/Lobby?listen");
}

void UPuzzlePlatformsGameInstance::OnDestroySessionComplete(FName SessionName, bool Success)
{
	if (Success)
	{
		CreateSession();
	}
}

void UPuzzlePlatformsGameInstance::OnFindSessionComplete(bool Success)
{
	if (Success && SessionSearch.IsValid()&& Menu != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Finished Find Session"));
		TArray<FServerData> ServerNames;
		
		for (const FOnlineSessionSearchResult& SearchResult : SessionSearch->SearchResults)
		{
			UE_LOG(LogTemp, Warning, TEXT("Found session names: %s"), *SearchResult.GetSessionIdStr());
			FServerData ServerData;
			
			ServerData.MaxPlayers = SearchResult.Session.SessionSettings.NumPublicConnections;
			ServerData.CurrentPlayers = ServerData.MaxPlayers- SearchResult.Session.NumOpenPublicConnections;
			ServerData.HostUsername = SearchResult.Session.OwningUserName;
			FString ServerName;
			if(SearchResult.Session.SessionSettings.Get(SERVER_NAME_SETTINGS_KEY,ServerName))
			{
				ServerData.Name= ServerName;
			}
			else
			{
				ServerData.Name="Could not find name.";
			}
;			ServerNames.Add(ServerData);
		}

		Menu->SetServerList(ServerNames);
	}
}

void UPuzzlePlatformsGameInstance::OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
	if (!SessionInterface.IsValid()) return;

	FString Address;
	if(!SessionInterface->GetResolvedConnectString(SessionName,Address))
	{
		UE_LOG(LogTemp,Warning,TEXT("Could not get Connect String."));
	}
	
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;
	
	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));
	
	APlayerController* PlayerController = GetFirstLocalPlayerController();
	
	if (!ensure(PlayerController != nullptr)) return;
	
	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}

void UPuzzlePlatformsGameInstance::OnNetworkFailure(UWorld* World, UNetDriver* NetDriver,
	ENetworkFailure::Type FailureType, const FString& ErrorString)
{
	LoadMainMenu();
}

void UPuzzlePlatformsGameInstance::CreateSession()
{
	if(SessionInterface.IsValid())
	{
		FOnlineSessionSettings SessionSettings;
		if(IOnlineSubsystem::Get()->GetSubsystemName() == "NULL")
		{
			SessionSettings.bIsLANMatch = true;
		}
		else
		{
			SessionSettings.bIsLANMatch = false;	
		}

		SessionSettings.NumPublicConnections = 5;
		SessionSettings.bShouldAdvertise = true;
		SessionSettings.bUsesPresence = true;
		SessionSettings.Set(SERVER_NAME_SETTINGS_KEY,DesiredServerName,EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);
		
		//SessionSettings.bUseLobbiesIfAvailable = true;

		SessionInterface->CreateSession(0, SESSION_NAME,SessionSettings);
	}
	
}

void UPuzzlePlatformsGameInstance::Join(uint32 Index)
{
	if (!SessionInterface.IsValid()) return;
	if(!SessionSearch.IsValid()) return;
	if(Menu != nullptr)
	{
		FServerData Test1, Test2;
		Test1.Name="Test1";
		Test2.Name="Test2";
		Menu->SetServerList({Test1,Test2});
		Menu->Teardown();
	}
	SessionInterface->JoinSession(0,SESSION_NAME, SessionSearch->SearchResults[Index]);
	
	
}

void UPuzzlePlatformsGameInstance::StartSession()
{
	if (SessionInterface.IsValid())
	{
		SessionInterface->StartSession(SESSION_NAME);
	}
}

void UPuzzlePlatformsGameInstance::RefreshServerList()
{
	SessionSearch = MakeShareable(new FOnlineSessionSearch());
	if(SessionSearch.IsValid())
	{
		//SessionSearch->bIsLanQuery = true;
		SessionSearch->MaxSearchResults = 100;
		SessionSearch->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals);
		UE_LOG(LogTemp, Warning,TEXT("Starting Find Session"));
		SessionInterface->FindSessions(0, SessionSearch.ToSharedRef());

	}
}

void UPuzzlePlatformsGameInstance::GameMenu()
{
	if(!ensure(ExitMenuClass != nullptr)) return;
	ExitMenu = CreateWidget<UGameMenu>(this, ExitMenuClass);

	if (ExitMenu==nullptr) return;

	ExitMenu->Setup();

	ExitMenu->SetMenuInterface(this);
	
}

void UPuzzlePlatformsGameInstance::LoadMainMenu()
{
	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if(PlayerController == nullptr) return;

	PlayerController->ClientTravel("/Game/PuzzlePlatform/Maps/Main", ETravelType::TRAVEL_Absolute);
	
}

