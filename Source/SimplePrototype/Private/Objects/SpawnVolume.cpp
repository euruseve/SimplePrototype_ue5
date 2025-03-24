// Fill out your copyright notice in the Description page of Project Settings.

#include "Objects/SpawnVolume.h"

#include "Components/BoxComponent.h"
#include "Enemies/BaseEnemy.h"
#include "Kismet/KismetMathLibrary.h"

ASpawnVolume::ASpawnVolume()
{
	PrimaryActorTick.bCanEverTick = true;

	SpawningBox = CreateDefaultSubobject<UBoxComponent>("SpawningBox");
}

void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpawnVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector ASpawnVolume::GetSpawnPoint()
{
	FVector Extent = SpawningBox->GetScaledBoxExtent();
	FVector Origin = SpawningBox->GetComponentLocation();

	return UKismetMathLibrary::RandomPointInBoundingBox(Origin, Extent);
}

void ASpawnVolume::SpawnPawn_Implementation(UClass* ToSpawn, const FVector& SpawnLocation)
{
	if (!ToSpawn) return;

	UWorld* World = GetWorld();
	if (World)
	{
		FActorSpawnParameters SpawnParameters;
	
		World->SpawnActor<ABaseEnemy>(ToSpawn, SpawnLocation, FRotator(0.f), SpawnParameters);
	}
}

