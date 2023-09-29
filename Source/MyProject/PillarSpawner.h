// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PillarSpawner.generated.h"

UCLASS()
class MYPROJECT_API APillarSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APillarSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class APillar> PillarClass;

	void Spawn();

	UPROPERTY(EditDefaultsOnly)
		FVector DownLocation;

	UPROPERTY(EditDefaultsOnly)
		FVector UpLocation;

	UPROPERTY(EditDefaultsOnly)
		float PillarMoveSpeed = 2000.f;

	TArray<APillar*> Pillars;

	FTimerHandle TimerHandler;

	UPROPERTY(EditDefaultsOnly)
	float MinSpawnTime = 4.f;

	UPROPERTY(EditDefaultsOnly)
	float MaxSpawnTime = 1.f;

	UPROPERTY(EditDefaultsOnly)
		float MinScale = 1.f;

	UPROPERTY(EditDefaultsOnly)
		float MaxScale = 3.f;
};
