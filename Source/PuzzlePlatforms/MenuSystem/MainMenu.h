// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuInterface.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

public:

	void SetMenuInterface(IMenuInterface* MenuInterface);

	void Setup();

	virtual void OnLevelRemovedFromWorld(ULevel* InLevel, UWorld* InWorld) override;
	
protected:

		virtual bool Initialize();

private:

		IMenuInterface* MenuInterface;

		UPROPERTY(meta = (BindWidget))
		class UWidgetSwitcher* MenuSwitcher;

		//Located in Main Menu
		UPROPERTY(meta = (BindWidget))
		class UButton* HostButton;

		UPROPERTY(meta = (BindWidget))
		class UButton* JoinButton;

		UPROPERTY(meta = (BindWidget))
		class UWidget* JoinMenu;

		UFUNCTION()
		void OpenJoinMenu();

		UFUNCTION()
		void HostServer();

		//Located in Join Menu
		UPROPERTY(meta = (BindWidget))
		class UButton* BackButton;

		UPROPERTY(meta = (BindWidget))
		class UButton* JoinGameButton;

		UPROPERTY(meta = (BindWidget))
		class UEditableTextBox* IPAddressField;

		UFUNCTION()
		void OpenMainMenu();

		UPROPERTY(meta = (BindWidget))
		class UWidget* MainMenu;

		UFUNCTION()
		void JoinServer();

		FText IPAddress;

};
