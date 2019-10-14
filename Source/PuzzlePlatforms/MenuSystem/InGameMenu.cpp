// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameMenu.h"

#include "Components/Button.h"
#include "Components/EditableTextBox.h"
#include "Components/WidgetSwitcher.h"
#include "Kismet/GameplayStatics.h"

bool UInGameMenu::Initialize()
{
	bool Success = Super::Initialize();

	if (!Success) return false;

	// Bind dynamic functions for buttons
	if (!ensure(CancelButton != nullptr)) return false;
	CancelButton->OnClicked.AddDynamic(this, &UInGameMenu::Cancel);

	if (!ensure(QuitButton != nullptr)) return false;
	QuitButton->OnClicked.AddDynamic(this, &UInGameMenu::Quit);

	return true;

}

void UInGameMenu::Cancel()
{
	RemoveFromViewport();

	auto* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	auto* PlayerController = World->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeGameOnly InputMode;
	PlayerController->SetInputMode(InputMode);
	PlayerController->bShowMouseCursor = false;

}

void UInGameMenu::Quit()
{
	UGameplayStatics::OpenLevel(GetWorld(), "MainMenu");

}