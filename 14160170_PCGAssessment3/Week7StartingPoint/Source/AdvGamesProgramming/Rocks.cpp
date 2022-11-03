// Fill out your copyright notice in the Description page of Project Settings.


#include "Rocks.h"

// Sets default values
ARocks::ARocks()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Rock1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Rock 1"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Rock1Asset(TEXT("Game/Stylized_PBR_Nature/Rocks/Assets/SM_R_Rock_01.SM_R_Rock_01"));
	if (Rock1Asset.Succeeded()) {
		Rock1->SetStaticMesh(Rock1Asset.Object);
		Rocks.Add(Rock1);
	}

	Rock2 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Rock 2"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Rock2Asset(TEXT("Game/Stylized_PBR_Nature/Rocks/Assets/SM_R_Rock_02.SM_R_Rock_02"));
	if (Rock2Asset.Succeeded()) {
		Rock2->SetStaticMesh(Rock2Asset.Object);
		Rocks.Add(Rock2);
	}

	Rock3 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Rock 3"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Rock3Asset(TEXT("Game/Stylized_PBR_Nature/Rocks/Assets/SM_R_Rock_03.SM_R_Rock_03"));
	if (Rock3Asset.Succeeded()) {
		Rock3->SetStaticMesh(Rock3Asset.Object);
		Rocks.Add(Rock3);
	}

	Rock4 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Rock 4"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Rock4Asset(TEXT("Game/Stylized_PBR_Nature/Rocks/Assets/SM_R_Rock_04.SM_R_Rock_04"));
	if (Rock4Asset.Succeeded()) {
		Rock4->SetStaticMesh(Rock4Asset.Object);
		Rocks.Add(Rock4);
	}

	Rock5 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Rock 5"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh>Rock5Asset(TEXT("Game/Stylized_PBR_Nature/Rocks/Assets/SM_R_Rock_05.SM_R_Rock_05"));
	if (Rock5Asset.Succeeded()) {
		Rock5->SetStaticMesh(Rock5Asset.Object);
		Rocks.Add(Rock5);
	}


}

// Called when the game starts or when spawned
void ARocks::BeginPlay()
{
	Super::BeginPlay();

	PrimaryActorTick.bCanEverTick = true;

	if(Rocks.Num() != 0){
	for (int i = 0; i < 4; i++) {
		float Rand = FMath::RandRange(0.0f, 10.0f);
		Rocks[i]->SetRelativeLocation(FVector(Rand, Rand, 0.f));
		Rocks[i]->SetWorldScale3D(FVector(0.1f));
		}
	}
	
}

// Called every frame
void ARocks::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

