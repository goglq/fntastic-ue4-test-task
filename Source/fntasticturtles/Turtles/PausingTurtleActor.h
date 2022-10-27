// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "./TurtleActor.h"
#include "PausingTurtleActor.generated.h"

/**
 * 
 */
UCLASS()
class FNTASTICTURTLES_API APausingTurtleActor : public ATurtleActor
{
	GENERATED_BODY()

public:

	APausingTurtleActor();

	virtual void Move_Implementation() override;

	virtual void Stop_Implementation() override;

private:

	FTimerHandle StartMovingTimer;

	FTimerHandle BeginPauseTimer;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Fntastic Turtle", meta = (AllowPrivateAccess = "true"))
	float PauseSeconds;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Fntastic Turtle", meta = (AllowPrivateAccess = "true"))
	float MoveSeconds;

	void StartMoving();

	void BeginPause();
};
