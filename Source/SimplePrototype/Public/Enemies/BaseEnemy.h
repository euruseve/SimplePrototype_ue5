// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseEnemy.generated.h"

class UCapsuleComponent;

UCLASS()
class SIMPLEPROTOTYPE_API ABaseEnemy : public APawn
{
	GENERATED_BODY()

public:
	ABaseEnemy();
	
protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;


protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	UCapsuleComponent* CapsuleComp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mesh")
	USkeletalMeshComponent* MeshComp;
};
