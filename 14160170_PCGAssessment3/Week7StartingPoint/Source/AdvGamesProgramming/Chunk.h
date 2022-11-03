// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/Object.h"
#include "Components/StaticMeshComponent.h "
#include "ProceduralMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "AIManager.h"
#include "Tower.h"
#include "Tree1.h"
#include "Tree2.h"
#include "Tree3.h"
#include "House.h"
#include "Chunk.generated.h"

UCLASS()
class ADVGAMESPROGRAMMING_API AChunk : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChunk();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UStaticMeshComponent* House;


	UPROPERTY(VisibleAnywhere)
		UProceduralMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere)
		int32 Width;
	UPROPERTY(EditAnywhere)
		int32 Height;
	UPROPERTY(EditAnywhere)
		float GridSize;

	UPROPERTY(EditAnywhere)
		float PerlinScale;
	UPROPERTY(EditAnywhere)
		float PerlinRoughness;


	TArray<FVector> Vertices;
	TArray<int32> Triangles;
	TArray<FVector2D> UVCoords;
	TArray<FVector> Normals;
	TArray<FProcMeshTangent> Tangents;
	TArray<FColor> Color;



	void GenerateFloor();

	TArray<FVector> GetVertices();
	int32 GetHeight();
	int32 GetWidth();

	UPROPERTY(EditAnywhere)
		AActor* ThisAIManager;

	AAIManager* AIManager;

	TArray<FVector> AllNodePositions;
	

	FVector CurrentNearestNode;

	void OnDeleteActor();

	bool HouseExists;
	bool Tree1Exists;
	bool Tree2Exists;
	bool Tree3Exists;

	ATree1* NewTree1;
	ATree2* NewTree2;
	ATree3* NewTree3; 
	AHouse* NewHouse;

};
