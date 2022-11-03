// Fill out your copyright notice in the Description page of Project Settings.


#include "Tree2.h"

// Sets default values
ATree2::ATree2()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

 //Locating Mesh through FObjectFinder and assigning it has Root Component
	UStaticMeshComponent* Tree = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tree"));
	Tree->SetupAttachment(RootComponent);
	static ConstructorHelpers::FObjectFinder<UStaticMesh>TreeAsset(TEXT("/Game/Meshes/Foliage/Assets/SM_Common_Tree_08.SM_Common_Tree_08"));
	if (TreeAsset.Succeeded()) {
		Tree->SetStaticMesh(TreeAsset.Object);
		float RandomRotation = FMath::RandRange(0, 360);
		Tree->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
		Tree->SetRelativeRotation(FRotator(0.0f, RandomRotation, 0.0f));
		Tree->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	}
}

// Called when the game starts or when spawned
void ATree2::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATree2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

