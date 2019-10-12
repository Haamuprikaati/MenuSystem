// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PuzzlePlatforms_GI.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UPuzzlePlatforms_GI : public UGameInstance
{
	GENERATED_BODY()

public:
		UPuzzlePlatforms_GI(const FObjectInitializer& ObjectInitializer);

		virtual void Init();

		UFUNCTION(Exec) //Can be called from console while playing as developer cheat kinda like scry menu
		void Host();

		UFUNCTION(Exec)
		void Join(const FString& Address);
};
