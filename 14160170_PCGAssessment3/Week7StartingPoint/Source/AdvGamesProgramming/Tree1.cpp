// Fill out your copyright notice in the Description page of Project Settings.


#include "Tree1.h"

// Sets default values
ATree1::ATree1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	UStaticMeshComponent* Tree = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tree"));
	Tree->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh>TreeAsset(TEXT("/Game/Meshes/Foliage/Assets/SM_Common_Tree_11.SM_Common_Tree_11"));
	if (TreeAsset.Succeeded()) {
		Tree->SetStaticMesh(TreeAsset.Object);
		float RandomRotation = FMath::RandRange(0, 360);
		Tree->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		Tree->SetRelativeRotation(FRotator(0.0f, RandomRotation, 0.0f));
		Tree->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	}

}

// Called when the game starts or when spawned
void ATree1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATree1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

