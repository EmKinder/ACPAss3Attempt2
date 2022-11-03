// Fill out your copyright notice in the Description page of Project Settings.

#include "ProcedurallyGeneratedMap.h"
#include "Engine/World.h"
#include "ChunkGenerator.h"

// Sets default values
AChunkGenerator::AChunkGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//SetRootComponent(CreateDefaultSubobject<AProcedurallyGeneratedMap>(TEXT("Map"));
	i = 0;

	
}

// Called when the game starts or when spawned
void AChunkGenerator::BeginPlay()
{
	Super::BeginPlay();
	auto str = TEXT("ProcedurallyGeneratedMap");

	for (int h = 0; h > 3; h++) {
		for (int w = 0; w > 3; h++) {
			FVector SpawnLocation = FVector(h * 100.0f, 0.0f, w * 100.0f);
			FVector SpawnRotation = FVector(0.0f, 0.0f, 0.0f);
			AProcedurallyGeneratedMap* Chunk = GetWorld()->SpawnActor<AProcedurallyGeneratedMap>(AProcedurallyGeneratedMap::StaticClass());
			Chunks.Add(Chunk);
			Chunks[i]->SetMapPosition(SpawnLocation);
			i++;

		}
	}
	
}

// Called every frame
void AChunkGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

