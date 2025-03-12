// Fill out your copyright notice in the Description page of Project Settings.


#include "Objects/FloorSwitch.h"

#include "Components/BoxComponent.h"

AFloorSwitch::AFloorSwitch()
{
	PrimaryActorTick.bCanEverTick = true;

	TriggerBox = CreateDefaultSubobject<UBoxComponent>("TriggerBox");
	RootComponent = TriggerBox;

	TriggerBox->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	TriggerBox->SetCollisionObjectType(ECC_WorldStatic);
	TriggerBox->SetCollisionResponseToAllChannels(ECR_Ignore);
	TriggerBox->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);

	TriggerBox->SetBoxExtent(FVector(62, 62, 32));
	
	FloorSwitch = CreateDefaultSubobject<UStaticMeshComponent>("FloorSwitch");
	FloorSwitch->SetupAttachment(RootComponent);
	
	Door = CreateDefaultSubobject<UStaticMeshComponent>("Door");
	Door->SetupAttachment(RootComponent);

	SwitchTimeDelay = .5f;
	bCharacterOnFloorSwitch = false;
}

void AFloorSwitch::BeginPlay()
{
	Super::BeginPlay();

	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBoxBeginOverlap);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnBoxEndOverlap);

	InitDoorLocation = Door->GetComponentLocation();
	InitSwitchLocation = FloorSwitch->GetComponentLocation();
}

void AFloorSwitch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFloorSwitch::OnBoxBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("OnBoxBeginOverlap"));

	if (!bCharacterOnFloorSwitch)
		bCharacterOnFloorSwitch = true;
	
	RaiseDoor();
	LowerSwitch();
}

void AFloorSwitch::OnBoxEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	UE_LOG(LogTemp, Warning, TEXT("OnBoxEndOverlap"));	

	if (bCharacterOnFloorSwitch)
		bCharacterOnFloorSwitch = false;
	
	GetWorldTimerManager().SetTimer(SwitchTimerHandler, this,
		&ThisClass::CloseDoor, SwitchTimeDelay);
}

void AFloorSwitch::UpdateDoorLocation(float Z)
{
	FVector NewLocation = InitDoorLocation;
	NewLocation += FVector(0, 0, Z);
	Door->SetWorldLocation(NewLocation);
}

void AFloorSwitch::UpdateSwitchLocation(float Z)
{
	FVector NewLocation = InitSwitchLocation;
	NewLocation += FVector(0, 0, Z);
	FloorSwitch->SetWorldLocation(NewLocation);
}

void AFloorSwitch::CloseDoor()
{
	if (!bCharacterOnFloorSwitch)
	{
		LowerDoor();
		RaiseSwitch();	
	}
}


