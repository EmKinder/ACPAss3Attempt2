// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"

// Sets default values
ATower::ATower()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	UStaticMeshComponent* Tower = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tower"));
	Tower->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh>TowerAsset(TEXT("/Game/Meshes/Tower.Tower"));
	if (TowerAsset.Succeeded()) {
		Tower->SetStaticMesh(TowerAsset.Object);
		Tower->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		Tower->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	}
}

// Called when the game starts or when spawned
void ATower::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

