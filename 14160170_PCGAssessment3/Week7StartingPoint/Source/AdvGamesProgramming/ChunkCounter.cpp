// Fill out your copyright notice in the Description page of Project Settings.


#include "ChunkCounter.h"

// Sets default values
AChunkCounter::AChunkCounter()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ChunkNumber = 0;
	EnemyStatMultiplier = 1;

}

// Called when the game starts or when spawned
void AChunkCounter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AChunkCounter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AChunkCounter::IncreaseChunks() {
	ChunkNumber++;
	UE_LOG(LogTemp, Warning, TEXT("Number of Total Chunks: %i"), ReturnChunks());
	ReturnEnemyStatMultiplier();

}

int AChunkCounter::ReturnChunks() {
	return ChunkNumber;
}

int AChunkCounter::ReturnEnemyStatMultiplier() {
	if (ChunkNumber % 500 == 0) {
		EnemyStatMultiplier++;
		UE_LOG(LogTemp, Warning, TEXT("Enemy Difficulty Level: %i"), EnemyStatMultiplier);

	}
	return EnemyStatMultiplier;
}

