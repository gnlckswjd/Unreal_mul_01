// Fill out your copyright notice in the Description page of Project Settings.


#include "ServerRow.h"

#include "Components/Button.h"
#include  "MainMenu.h"

void UServerRow::SetUp(UMainMenu* ParentMenu, uint32 Index)
{
	Parent = ParentMenu;
	_Index=Index;
	RowButton->OnClicked.AddDynamic(this,&UServerRow::OnClicked);	
}

void UServerRow::OnClicked()
{
	Parent->SelectIndex(_Index);
}
