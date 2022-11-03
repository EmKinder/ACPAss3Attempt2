// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChunkCounter.generated.h"

UCLASS()
class ADVGAMESPROGRAMMING_API AChunkCounter : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AChunkCounter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int ChunkNumber;
	int EnemyStatMultiplier;
	void IncreaseChunks();
	int ReturnChunks();
	int ReturnEnemyStatMultiplier();
};
