// Fill out your copyright notice in the Description page of Project Settings.


#include "NestActor.h"
#include "Components/SplineComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SceneComponent.h"
#include "Components/BoxComponent.h"
#include "../Turtles/TurtleActor.h"

// Sets default values
ANestActor::ANestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Box = CreateDefaultSubobject<UBoxComponent>(TEXT("Origin"));
	SetRootComponent(Box);

	Body = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Body"));
	Body->SetupAttachment(Box);

	SpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnPoint"));
	SpawnPoint->SetupAttachment(Box);

	Spline = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
	Spline->SetupAttachment(Box);
}

// Called when the game starts or when spawned
void ANestActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ANestActor::Spawn()
{
	if (!SpawnClass)
	{
		return;
	}

	OnSpawn();

	FTransform transform = SpawnPoint->GetComponentTransform();

	if (ATurtleActor* turtle = GetWorld()->SpawnActor<ATurtleActor>(SpawnClass, transform))
	{
		turtle->SetSpline(Spline);
		turtle->Execute_Move(turtle);
	}
}

