// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NestActor.generated.h"

UCLASS()
class FNTASTICTURTLES_API ANestActor : public AActor
{
	GENERATED_BODY()
	
public:
	ANestActor();

	UFUNCTION(BlueprintCallable)
	void Spawn();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void OnSpawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Spawn", meta = (AllowPrivateAccess = "true"))
	TSubclassOf<class ATurtleActor> SpawnClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* Box;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USceneComponent* SpawnPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UStaticMeshComponent* Body;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USplineComponent* Spline;
};
