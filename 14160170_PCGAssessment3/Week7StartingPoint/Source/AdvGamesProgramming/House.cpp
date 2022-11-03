// Fill out your copyright notice in the Description page of Project Settings.


#include "House.h"

// Sets default values
AHouse::AHouse()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Locating Mesh through FObjectFinder and assigning it has Root Component
	House = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("House"));
	House->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh>HouseAsset(TEXT("/Game/Meshes/House.House"));
	if (HouseAsset.Succeeded()) {
		House->SetStaticMesh(HouseAsset.Object);
		House->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		House->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	}
}

// Called when the game starts or when spawned
void AHouse::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHouse::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

