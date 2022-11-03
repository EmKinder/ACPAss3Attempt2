// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Chunk.h"
#include "GameFramework/Actor.h"
#include "PlayerCharacter.h"
#include "EnemyCharacter.h"
#include "AIManager.h"
#include "ChunkCounter.h"
#include "ChunkGen.generated.h"

UCLASS()
class ADVGAMESPROGRAMMING_API AChunkGen : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChunkGen();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	APlayerCharacter* Player;
	FVector PlayerPosition();
	int ChunkSize;
	FVector LastPlayerPosition;
	void CreateNewChunks();
	float RenderRange;
	AChunk* Chunk;
	TArray<AChunk*> SpawnedChunks;
	TArray<FVector> SpawnedChunkPositions;
	void DestoyChunks();
	bool CheckIfEnemiesCanSpawn(int ChunkType);
	void SpawnEnemies(FVector SpawnPoint);
	void DeleteEnemies(int i);

	AEnemyCharacter* Enemy;

	TArray<AEnemyCharacter*> ActiveEnemies;

	TArray<AEnemyCharacter*> GetEnemyArray();
	bool IsValidChunkSpace(int X, int Y);

	TArray<ATower*> SpawnedEnemies;

	ATower* NewTower;
	int NoOfSpawnedEnemies;
	FVector SpawnPoint;

	void DeleteChunk();

	int NoOfChunks;

	UPROPERTY(EditAnywhere)
	AChunkCounter* ChunkCounter;
	
};
