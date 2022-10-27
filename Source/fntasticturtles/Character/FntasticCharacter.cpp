// Fill out your copyright notice in the Description page of Project Settings.


#include "FntasticCharacter.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "../Interfaces/Interactable.h"

AFntasticCharacter::AFntasticCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(GetRootComponent());

	InteractionLength = 100.0f;
}

void AFntasticCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void AFntasticCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFntasticCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("Forward"), this, &AFntasticCharacter::Forward);
	PlayerInputComponent->BindAxis(TEXT("Right"), this, &AFntasticCharacter::Right);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AFntasticCharacter::LookUp);
	PlayerInputComponent->BindAxis(TEXT("LookRight"), this, &AFntasticCharacter::LookRight);

	PlayerInputComponent->BindAction(TEXT("Interact"), EInputEvent::IE_Pressed, this, &AFntasticCharacter::Interact);
}

void AFntasticCharacter::Forward(float value)
{
	FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);

	AddMovementInput(direction, value);
}

void AFntasticCharacter::Right(float value)
{
	FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);

	AddMovementInput(direction, value);
}

void AFntasticCharacter::LookUp(float value)
{
	AddControllerPitchInput(value);
}

void AFntasticCharacter::LookRight(float value)
{
	AddControllerYawInput(value);
}

void AFntasticCharacter::Interact()
{
	FVector location;
	FRotator rotation;
	FHitResult hitResult;

	GetController()->GetPlayerViewPoint(location, rotation);

	FVector start = location;
	FVector	end = start + (rotation.Vector() * InteractionLength);

	FCollisionQueryParams params;
	if (GetWorld()->LineTraceSingleByChannel(hitResult, start, end, ECC_Visibility, params))
	{
		
		if (AActor* target = hitResult.GetActor()) 
		{
			if (target->GetClass()->ImplementsInterface(UInteractable::StaticClass()))
			{
				IInteractable::Execute_OnInteract(target);
			}
		}
	}
}