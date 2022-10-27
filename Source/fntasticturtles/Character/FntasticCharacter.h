// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FntasticCharacter.generated.h"

UCLASS()
class FNTASTICTURTLES_API AFntasticCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AFntasticCharacter();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	virtual void BeginPlay() override;

private:	
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float InteractionLength;

	UFUNCTION()
	void Forward(float value);

	UFUNCTION()
	void Right(float value);

	UFUNCTION()
	void LookUp(float value);

	UFUNCTION()
	void LookRight(float value);

	UFUNCTION()
	void Interact();
};
