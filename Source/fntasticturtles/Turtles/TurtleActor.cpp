#include "TurtleActor.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SplineComponent.h"

ATurtleActor::ATurtleActor()
{
	PrimaryActorTick.bCanEverTick = true;


	Capsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	Capsule->SetupAttachment(GetRootComponent());
	Body = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("TurtleBody"));
	Body->SetupAttachment(Capsule);

	DestroySeconds = 3.0f;
	Distance = 0.0f;
	Speed = 150.0f;
	bIsAllowedToMove = false;
	bFinished = false;
}

void ATurtleActor::BeginPlay()
{
	Super::BeginPlay();
}

void ATurtleActor::OnFinish_Implementation()
{
	GetWorldTimerManager().SetTimer(DestroyTimer, this, &ATurtleActor::Remove, DestroySeconds, false);

	SetActorHiddenInGame(true);
}

void ATurtleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsAllowedToMove) {
		MoveAlongSpline(DeltaTime);
	}
}

void ATurtleActor::Move_Implementation()
{
	bIsAllowedToMove = true;

	Execute_OnMove(this);
}

void ATurtleActor::Stop_Implementation()
{
	bIsAllowedToMove = false;

	Execute_OnStop(this);
}

void ATurtleActor::SetSpline(USplineComponent* spline) 
{
	Spline = spline;
}

void ATurtleActor::MoveAlongSpline_Implementation(float DeltaTime)
{
	if (!Spline) 
	{
		return;
	}

	float splineLength = Spline->GetSplineLength();

	if (splineLength >= Distance) {
		Distance += Speed * DeltaTime;
		FTransform transform = Spline->GetTransformAtDistanceAlongSpline(Distance, ESplineCoordinateSpace::World);
		SetActorLocationAndRotation(transform.GetLocation(), transform.GetRotation());
	}
	else
	{
		if (!bFinished) {
			bFinished = true;
			OnFinish();
		}
	}
}

void ATurtleActor::Remove()
{
	Destroy();
}