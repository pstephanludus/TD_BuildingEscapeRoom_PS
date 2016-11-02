// Fill out your copyright notice in the Description page of Project Settings.

#include "TD_BEAR.h"
#include "PositionReport.h"


// Sets default values for this component's properties
UPositionReport::UPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	UE_LOG(LogTemp, Warning, TEXT("Position"));
	// ...
}


// Called when the game starts
void UPositionReport::BeginPlay()
{
	Super::BeginPlay();
	// ...
	FString Name = GetOwner()->GetName();
	FString ObjectPosition = GetOwner()->GetTransform().GetLocation().ToString();
	FString ObjectRotation = GetOwner()->GetTransform().GetRotation().ToString();
	FString ObjectScale = GetOwner()->GetTransform().GetScale3D().ToString();
	UE_LOG(LogTemp, Warning, TEXT("%s is at %s, Rotation: %s, Scale: %s"), *Name, *ObjectPosition, *ObjectRotation, *ObjectScale);
	
}


// Called every frame
void UPositionReport::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

