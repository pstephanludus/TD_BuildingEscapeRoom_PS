// Fill out your copyright notice in the Description page of Project Settings.

#include "TD_BEAR.h"
#include "Grabber.h"

#define OUT 

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();

	if (PhysicsHandle) {

		//Found
	}
	else {

		UE_LOG(LogTemp, Warning, TEXT("%s missing phyics handleComponent"), *GetOwner()->GetName());
	}

	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();

	if (InputComponent) {

		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("%s missing phyics handleComponent"), *GetOwner()->GetName());
	}

	// ...

}


// Called every frame
void UGrabber::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	FVector PlayerVector;
	FRotator PlayerRotator;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(PlayerVector, PlayerRotator);

	UE_LOG(LogTemp, Warning, TEXT("Player Vector: %s Player Rotator: %s"), *PlayerVector.ToString(), *PlayerRotator.ToString());

	FVector LineTraceEnd = PlayerVector + PlayerRotator.Vector() * Reach;

	DrawDebugLine(
		GetWorld(),
		PlayerVector,
		LineTraceEnd,
		FColor(255, 0, 0),
		false,
		-1.f,
		0.f,
		10.f
	);

	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());

	FHitResult Hit;
	GetWorld()->LineTraceSingleByObjectType(
		OUT Hit,
		PlayerVector,
		LineTraceEnd,
		FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody),
		TraceParameters
	);
	AActor* ActorHit = Hit.GetActor();
	if (ActorHit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Line trace hit: %s"), *(ActorHit->GetName()));
	}
}

void UGrabber::Grab() {
	UE_LOG(LogTemp, Warning, TEXT("click droit ok"))
}