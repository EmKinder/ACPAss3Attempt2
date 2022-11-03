// Fill out your copyright notice in the Description page of Project Settings.


//#include "ConstructorHelpers.h"
#include "Chunk.h"
#include "House.h"
#include "Tower.h"
#include "Rocks.h"
#include "Tree1.h"
#include "Tree2.h"
#include "Tree3.h"
#include "EnemyCharacter.h"
#include "Components/MeshComponent.h"
#include "KismetProceduralMeshLibrary.h"


// Sets default values
AChunk::AChunk()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComponent = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Mesh Component"));
	MeshComponent->SetupAttachment(RootComponent);


	PerlinRoughness = 0.4f; 
	PerlinScale = 20.0f;
	Height = 10; 
	Width = 10;
	GridSize = 100;
	ThisAIManager = UGameplayStatics::GetActorOfClass(GetWorld(), AAIManager::StaticClass());

	AIManager = Cast<AAIManager>(ThisAIManager);

	if (AIManager != nullptr)
		UE_LOG(LogTemp, Warning, TEXT("AI Manager found"));
}

// Called when the game starts or when spawned
void AChunk::BeginPlay()
{
	Super::BeginPlay();

	GenerateFloor();


} 

// Called every frame
void AChunk::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


//Creating Chunk Attributes
void AChunk::GenerateFloor() {


	//Procedually Generated Flooring
	float PerlinOffset = FMath::RandRange(-10000.0f, 10000.0f);
	for (int32 Y = 0; Y < Height; Y++)
	{
		for (int32 X = 0; X < Width; X++)
		{
			float Z = FMath::PerlinNoise2D(FVector2D(X * PerlinRoughness + PerlinOffset, Y * PerlinRoughness + PerlinOffset)) * PerlinScale;
			Vertices.Add(FVector(X * GridSize, Y * GridSize, Z));
			UVCoords.Add(FVector2D(X, Y));

			if (X != Width - 1 && Y != Height - 1)
			{
				Triangles.Add(Y * Width + X);
				Triangles.Add((Y + 1) * Width + X);
				Triangles.Add(Y * Width + X + 1);
				Triangles.Add(Y * Width + X + 1);
				Triangles.Add((Y + 1) * Width + X);
				Triangles.Add((Y + 1) * Width + X + 1);

			}

		}
	}

	UKismetProceduralMeshLibrary::CalculateTangentsForMesh(Vertices, Triangles, UVCoords, Normals, Tangents);

	MeshComponent->CreateMeshSection(0, Vertices, Triangles, Normals, UVCoords, Color, Tangents, true);

	//Using AI Manager to generate nodes along each chunk
	//if (AIManager)
	//{
		//AIManager->GenerateNodes(Vertices, Width, Height);

//	}

	//Determining whether a tree or a house will spawn on new chunk (20% rarity for tree (33% chance for each tree) & 5% chance for house)

	int Random = FMath::RandRange(0, 100);
	FVector RandPosition = FVector(FMath::RandRange(0, 100), FMath::RandRange(0, 100), 0.0f);
	if (Random >= 0 && Random <= 20) {
		int RandomTree = FMath::RandRange(0, 3);
		if (RandomTree == 0) {
			NewTree1 = GetWorld()->SpawnActor<ATree1>(ATree1::StaticClass(), this->GetActorLocation(), FRotator(0.0f, 0.0f, 0.0f));
			Tree1Exists = true;
		}
		if (RandomTree == 1) {
			NewTree2 = GetWorld()->SpawnActor<ATree2>(ATree2::StaticClass(), this->GetActorLocation(), FRotator(0.0f, 0.0f, 0.0f));
			Tree2Exists = true;
		}
		if (RandomTree == 2) {
			NewTree3 = GetWorld()->SpawnActor<ATree3>(ATree3::StaticClass(), this->GetActorLocation(), FRotator(0.0f, 0.0f, 0.0f));
			Tree3Exists = true;
		}


	}
	if (Random >= 90 && Random <= 95) {
		NewHouse = GetWorld()->SpawnActor<AHouse>(AHouse::StaticClass(), this->GetActorLocation(), FRotator(0.0f, 0.0f, 0.0f));
		UE_LOG(LogTemp, Warning, TEXT("Building Spawned"));
		NewHouse->SetActorScale3D(FVector(3.0f, 3.0f, 5.0f));
		HouseExists = true;
	}
}
void AChunk::OnDeleteActor() {
	if (HouseExists) {
		NewHouse->Destroy();
	}
	if (Tree1Exists) {
		NewTree1->Destroy();
	}
	if (Tree2Exists) {
		NewTree2->Destroy();
	}
	if (Tree3Exists) {
		NewTree3->Destroy();
	}

}






