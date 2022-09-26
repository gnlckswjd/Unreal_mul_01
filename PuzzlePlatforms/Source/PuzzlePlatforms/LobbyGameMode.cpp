// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	++NumberOfPlayers;
	if(NumberOfPlayers>=2)
	{
		UE_LOG(LogTemp, Warning, TEXT("it is working"));
		UWorld* World = GetWorld();
		if(World == nullptr)
		{
			return;
		}
		bUseSeamlessTravel = true;
		World->ServerTravel("/Game/PuzzlePlatform/Maps/ThirdPersonMap?listen");
		
	}
}

void ALobbyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
	--NumberOfPlayers;
}