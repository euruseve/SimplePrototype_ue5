// Fill out your copyright notice in the Description page of Project Settings.

#include "Enemies/BaseEnemy.h"

#include "Components/CapsuleComponent.h"

ABaseEnemy::ABaseEnemy()
{
	PrimaryActorTick.bCanEverTick = false;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	RootComponent = CapsuleComp;
	
	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	MeshComp->SetupAttachment(RootComponent);
}

void ABaseEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


