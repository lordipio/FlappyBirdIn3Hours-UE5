// Fill out your copyright notice in the Description page of Project Settings.

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "PillarsSpawnerGI.h"
#include "Bird.h"

// Sets default values
ABird::ABird()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateAbstractDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	SetRootComponent(Mesh);

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>("CameraBoom");
	CameraBoom->SetupAttachment(GetRootComponent());

	Camera = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	Camera->SetupAttachment(CameraBoom);

}

// Called when the game starts or when spawned
void ABird::BeginPlay()
{
	Super::BeginPlay();

	//UPillarsSpawnerGI* PillarSpawner = Cast<UPillarsSpawnerGI>(GetGameInstance());
	//if (PillarSpawner)
	//	PillarSpawner->Spawn();
	//else
	//	UE_LOG(LogTemp, Error, TEXT("NO Pillar Spawner"))
}

// Called every frame
void ABird::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABird::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(FName("Jump"), EInputEvent::IE_Pressed, this, &ABird::Jump);
}

void ABird::Jump()
{
	UE_LOG(LogTemp, Error, TEXT("WORKED!"))
	Mesh->AddForce(FVector::UpVector * JumpForce);

}