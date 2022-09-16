// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "MenuInterface.h"
#include "ServerRow.h"
#include "Components/Button.h"
#include "Components/EditableText.h"
#include "Components/EditableTextBox.h"
#include "Components/WidgetSwitcher.h"
#include "Components/TextBlock.h"


UMainMenu::UMainMenu(const FObjectInitializer & ObjectInitializer): UUserWidget(ObjectInitializer)
{
	ConstructorHelpers::FClassFinder<UUserWidget> ServerRowBPClass(TEXT("/Game/MenuSystem/WBP_ServerRow"));
	if (!ensure(ServerRowBPClass.Class != nullptr)) return;

	ServerRowClass = ServerRowBPClass.Class;
}


void UMainMenu::SetMenuInterface(IMenuInterface* MenuInterface)
{
	this->_MenuInterface = MenuInterface;
}

void UMainMenu::SetServerList(TArray<FString> ServerNames)
{
		
	
	UWorld* World = this->GetWorld();
	if (World == nullptr) return;

	ServerList->ClearChildren();

	uint32 i= 0;
	for (const FString& ServerName : ServerNames)
	{
		ServerRow = CreateWidget<UServerRow>(this, ServerRowClass);

		if (!ensure((ServerRow != nullptr))) return;

		ServerRow->ServerName->SetText(FText::FromString(ServerName));
		ServerRow->SetUp(this,i++);
		ServerList->AddChild(ServerRow);
	}
	
	
}

void UMainMenu::Setup()
{
	this->AddToViewport();

	UWorld* World = GetWorld();

	if(World == nullptr) return;
	
	APlayerController* PlayerController = World->GetFirstPlayerController();

	if (PlayerController == nullptr)
	{
		return;
	}
	FInputModeUIOnly InputModeData;
	InputModeData.SetWidgetToFocus(this->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor=true;
}

void UMainMenu::Teardown()
{
	this->RemoveFromViewport();
	
	
	UWorld* World = GetWorld();

	if(World == nullptr) return;
	
	APlayerController* PlayerController = World->GetFirstPlayerController();

	if (PlayerController == nullptr)
	{
		return;
	}

	FInputModeGameOnly InputModeData;
	PlayerController->SetInputMode(InputModeData);

	PlayerController->bShowMouseCursor=false;
	
}

void UMainMenu::SelectIndex(uint32 Index)
{
	SelectedIndex = Index;
}

bool UMainMenu::Initialize()
{
	bool Success = Super::Initialize();
	if(!Success) return false;

	if(HostButton==nullptr) return false;
	
	HostButton->OnClicked.AddDynamic(this, &UMainMenu::HostServer);

	if(JoinButton==nullptr) return false;
	
	JoinButton->OnClicked.AddDynamic(this, &UMainMenu::OpenJoinMenu);

	if(CancelButton==nullptr) return false;
	CancelButton->OnClicked.AddDynamic(this, &UMainMenu::CancelMenu);

	if(JoinTwoButton==nullptr) return false;
	JoinTwoButton->OnClicked.AddDynamic(this, &UMainMenu::JoinToGame);

	if(ExitButton==nullptr) return false;
	ExitButton->OnClicked.AddDynamic(this,&UMainMenu::EXitGame);
	
	return true;
}

void UMainMenu::HostServer()
{
	if(_MenuInterface==nullptr) return;
	_MenuInterface->Host();
}

void UMainMenu::OpenJoinMenu()
{ 
	if(MenuSwitcher == nullptr) return;
	if(JoinMenu == nullptr) return;
	
	MenuSwitcher->SetActiveWidget(JoinMenu);
	if(_MenuInterface != nullptr)
	{
		_MenuInterface->RefreshServerList();
	}
}

void UMainMenu::CancelMenu()
{
	if(MenuSwitcher == nullptr) return;
	if(Menu == nullptr) return;
	MenuSwitcher->SetActiveWidget(Menu);
}

void UMainMenu::JoinToGame()
{
	if(SelectedIndex.IsSet()&&_MenuInterface!=nullptr)
	{
		UE_LOG(LogTemp,Warning,TEXT("Selected Index %d"),SelectedIndex.GetValue());
		_MenuInterface->Join(SelectedIndex.GetValue());
	}
	else
	{
		UE_LOG(LogTemp,Warning,TEXT("Selected Index not sat "));
	}
	
}

void UMainMenu::EXitGame()
{
	UWorld* World = GetWorld();

	if(World == nullptr) return;
	
	APlayerController* PlayerController = World->GetFirstPlayerController();

	if (PlayerController == nullptr)
	{
		return;
	}
	PlayerController->ConsoleCommand("quit");

}
