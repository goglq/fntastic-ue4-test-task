// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "TurtleInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UTurtleInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class FNTASTICTURTLES_API ITurtleInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnMove();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Move();

	virtual void Move_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnStop();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void Stop();

	virtual void Stop_Implementation();
};
