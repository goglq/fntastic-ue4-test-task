// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Interfaces/TurtleInterface.h"
#include "TurtleActor.generated.h"

class USplineComponent;

UCLASS()
class FNTASTICTURTLES_API ATurtleActor : public AActor, public ITurtleInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurtleActor();

	virtual void Tick(float DeltaTime) override;

	virtual void Move_Implementation() override;

	virtual void Stop_Implementation() override;

	void SetSpline(USplineComponent* spline);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool bIsAllowedToMove;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float DestroySeconds;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, meta = (AllowPrivateAccess = "true"))
	void OnFinish();

	virtual void OnFinish_Implementation();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void MoveAlongSpline(float DeltaTime);

	virtual void MoveAlongSpline_Implementation(float DeltaTime);

private:

	void Remove();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float Speed;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float Distance;

	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	bool bFinished;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class USkeletalMeshComponent* Body;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* Capsule;

	UPROPERTY(BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	USplineComponent* Spline;

	FTimerHandle DestroyTimer;
};
