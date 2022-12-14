// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "MenuSystems/MainMenu.h"
#include "MenuSystems/MenuInterface.h"
#include "PuzzlePlatformsGameInstance.generated.h"


/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatformsGameInstance : public UGameInstance, public IMenuInterface
{
	GENERATED_BODY()
public:
	UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer);
	virtual void Init();

	UFUNCTION(BlueprintCallable)
	void LoadMenuWidget();

	UFUNCTION(Exec)
	void Host(FString ServerName);

	UFUNCTION(Exec)
	void Join(uint32 Index);

	void StartSession();

	UFUNCTION(Exec)
	void RefreshServerList() override;

	UFUNCTION(BlueprintCallable)
	void GameMenu();
	class UMainMenu* Menu;
private:
	TSubclassOf<class UUserWidget> MenuClass;
	TSubclassOf<class UUserWidget> ExitMenuClass;
	
	IOnlineSessionPtr SessionInterface;
	TSharedPtr<FOnlineSessionSearch> SessionSearch;

	FString DesiredServerName;
	class UGameMenu* ExitMenu;

	virtual  void LoadMainMenu() override;

	void OnCreateSessionComplete(FName SessionName, bool Success);
	void OnDestroySessionComplete(FName SessionName, bool Success);
	void OnFindSessionComplete(bool Success);
	void OnJoinSessionComplete(FName SessionName, EOnJoinSessionCompleteResult::Type Result);

	void OnNetworkFailure(UWorld* World, UNetDriver* NetDriver, ENetworkFailure::Type FailureType, const FString& ErrorString);
	
	void CreateSession();
};
