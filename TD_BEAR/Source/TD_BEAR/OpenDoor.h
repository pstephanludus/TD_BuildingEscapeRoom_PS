// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TD_BEAR_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()
private:
	UPROPERTY(VisibleAnywhere)
	float OpenAngle;

	UPROPERTY(EditAnywhere)
	ATriggerVolume *PressurePlate;

	UPROPERTY(EditAnywhere)
	AActor *ActorThatOpens = nullptr;
	
	UPROPERTY(EditAnywhere)
	float Delay = 1.0f;
	float LastDoorOpenTime;

	AActor* Owner;


public:	
	// Sets default values for this component's properties
	UOpenDoor();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

	// M�thode ouvrir porte
	void OpenDoor();

	// M�thode fermer porte
	void CloseDoor();
};
