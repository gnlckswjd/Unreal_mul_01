// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformsGameInstance.h"

#include "OnlineSubsystem.h"
#include "Engine/Engine.h"
#include "UObject/ConstructorHelpers.h"
#include "PlatformTrigger.h"
#include "Blueprint/UserWidget.h"

#include "Interfaces/OnlineSessionInterface.h"
#include "OnlineSessionSettings.h"
#include "UnrealWidgetFwd.h"

#include "MenuSystems/GameMenu.h"
#include "MenuSystems/MainMenu.h"



const static FName SESSION_NAME =TEXT("My Session Game");

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



void UPuzzlePlatformsGameInstance::Host()
{
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

	World->ServerTravel("/Game/ThirdPerson/Maps/ThirdPersonMap?listen");
}

void UPuzzlePlatformsGameInstance::OnDestroySessionComplete(FName SessionName, bool Success)
{
	if (Success)
	{
		CreateSession();
	}
}

void UPuzzlePlatformsGameInstance::CreateSession()
{
	if(SessionInterface.IsValid())
	{
		FOnlineSessionSettings SessionSettings;
		SessionInterface->CreateSession(0, SESSION_NAME,SessionSettings);
	}
	
}

void UPuzzlePlatformsGameInstance::Join(const FString& Address)
{

	if(Menu != nullptr)
	{
		Menu->Teardown();
	}
	
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 5, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();

	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
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

