// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameMenu.h"
#include "MainMenu.generated.h"

/**
 * 
 */
class IMenuInterface;
class UButton;
class UWidget;

UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UUserWidget
{

	GENERATED_BODY()
public:
	UMainMenu(const FObjectInitializer & ObjectInitializer);
	
	void SetMenuInterface(IMenuInterface* MenuInterface);

    void SetServerList(TArray<FString> ServerNames);
    
	void Setup();

	void Teardown();

	void SelectIndex(uint32 Index);

protected:
	virtual bool Initialize() override;

private:
	TSubclassOf<class UUserWidget> ServerRowClass;

	class UServerRow* ServerRow;
	
	UPROPERTY(meta = (BindWidget))
	UButton* HostButton;
	
	UPROPERTY(meta = (BindWidget))
	UButton* JoinButton;

	UPROPERTY(meta=(BindWidget))
	UButton* CancelButton;

	UPROPERTY(meta=(BindWidget))
	UButton* JoinTwoButton;

	UPROPERTY(meta=(BindWidget))
	UButton* ExitButton;
	
	
	UPROPERTY(meta = (BindWidget))
    class UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
	UWidget* JoinMenu;

	UPROPERTY(meta=(BindWidget))
	UWidget* Menu;
	
	UPROPERTY(meta =(BindWidget))
	class UPanelWidget* ServerList;

	UFUNCTION()
	void HostServer();

	UFUNCTION()
	void OpenJoinMenu();

	UFUNCTION()
	void CancelMenu();

	UFUNCTION()
	void JoinToGame();

	UFUNCTION()
	void EXitGame();

	IMenuInterface* _MenuInterface;

	TOptional<uint32> SelectedIndex;
};
