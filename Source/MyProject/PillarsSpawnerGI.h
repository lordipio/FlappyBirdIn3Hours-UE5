// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "PillarsSpawnerGI.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API UPillarsSpawnerGI : public UGameInstance
{
	GENERATED_BODY()


public:
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<class APillar> Pillar;

	void Spawn();

	UPROPERTY(EditDefaultsOnly)
	FVector Location;
	
};
