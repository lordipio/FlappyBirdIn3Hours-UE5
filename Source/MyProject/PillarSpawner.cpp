// Fill out your copyright notice in the Description page of Project Settings.

#include "Pillar.h"
#include "PillarSpawner.h"

// Sets default values
APillarSpawner::APillarSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APillarSpawner::BeginPlay()
{
	Super::BeginPlay();
	GetWorld()->GetTimerManager().SetTimer(TimerHandler, this, &APillarSpawner::Spawn, 0.5f, false);
}

// Called every frame
void APillarSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!Pillars.IsEmpty())
		for (APillar* Pillar : Pillars)
		{
			Pillar->AddActorLocalOffset(FVector::BackwardVector * PillarMoveSpeed * DeltaTime);
		}
}


void APillarSpawner::Spawn()
{
	// APillar* Pillar = GetWorld()->SpawnActor<APillar>(Pillar, Location, FRotator::ZeroRotator);
	// Pillars
	APillar* Pillar = GetWorld()->SpawnActor<APillar>(PillarClass, DownLocation, FRotator::ZeroRotator);
	if (Pillar)
	{
		if (FMath::RandBool())
		{
			FRotator PillarRotation = Pillar->GetActorRotation();
			FRotator PillarNewRotation = FRotator(180.f, 180.f, PillarRotation.Yaw);
			Pillar->Mesh->SetWorldRotation(PillarNewRotation);
			Pillar->SetActorLocation(UpLocation);
		}

		FVector PillarScale = Pillar->Mesh->GetRelativeScale3D();
		float RandomScale = FMath::RandRange(MinScale, MaxScale);
		FVector PillarNewScale = FVector(PillarScale.X, PillarScale.Y, PillarScale.Z * RandomScale);
		Pillar->Mesh->SetRelativeScale3D(PillarNewScale);

		Pillars.Add(Pillar);
	}

	float SpawnRate = FMath::RandRange(MinSpawnTime, MaxSpawnTime);
	GetWorld()->GetTimerManager().SetTimer(TimerHandler, this, &APillarSpawner::Spawn, SpawnRate, false);

}