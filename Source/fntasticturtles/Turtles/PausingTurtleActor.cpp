// Fill out your copyright notice in the Description page of Project Settings.


#include "./PausingTurtleActor.h"

APausingTurtleActor::APausingTurtleActor()
{
	PauseSeconds = 0.5f;
	MoveSeconds = 1.0f;
}

void APausingTurtleActor::Move_Implementation()
{
	bIsAllowedToMove = true;

	GetWorldTimerManager().SetTimer(StartMovingTimer, this, &APausingTurtleActor::BeginPause, MoveSeconds, false);
}

void APausingTurtleActor::Stop_Implementation()
{
	bIsAllowedToMove = false;

	GetWorldTimerManager().SetTimer(StartMovingTimer, this, &APausingTurtleActor::StartMoving, PauseSeconds, false);
}

void APausingTurtleActor::StartMoving()
{
	Execute_Move(this);
}

void APausingTurtleActor::BeginPause()
{
	Execute_Stop(this);
}
