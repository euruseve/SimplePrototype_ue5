// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class SIMPLEPROTOTYPE_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpawnVolume();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Spawn")
	TObjectPtr<class UBoxComponent> SpawningBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Spawn")
	TSubclassOf<class ABaseEnemy> PawnToSpawn;

	
protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintPure, Category = "Spawn")
	FVector GetSpawnPoint();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Spawn")
	void SpawnPawn(UClass* ToSpawn, const FVector& SpawnLocation);
public:	
	virtual void Tick(float DeltaTime) override;

};


