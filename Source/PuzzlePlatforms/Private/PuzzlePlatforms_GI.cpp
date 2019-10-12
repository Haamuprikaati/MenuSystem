// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatforms_GI.h"

#include "GameFramework/PlayerController.h"
#include "Engine/Engine.h"

UPuzzlePlatforms_GI::UPuzzlePlatforms_GI(const FObjectInitializer& ObjectInitializer)
{

	UE_LOG(LogTemp, Warning, TEXT("GI Contructor"))
}

void UPuzzlePlatforms_GI::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Warning, TEXT("GI Init"))

}

void UPuzzlePlatforms_GI::Host()
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, TEXT("Hosting"));

	UWorld* World = GetWorld();
	if (!ensure(World != nullptr)) return;

	World->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
}

void UPuzzlePlatforms_GI::Join(const FString& Address)
{
	UEngine* Engine = GetEngine();
	if (!ensure(Engine != nullptr)) return;

	Engine->AddOnScreenDebugMessage(0, 2, FColor::Green, FString::Printf(TEXT("Joining %s"), *Address));

	APlayerController* PlayerController = GetFirstLocalPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
}
