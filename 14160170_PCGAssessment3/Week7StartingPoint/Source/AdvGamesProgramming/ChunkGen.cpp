// Fill out your copyright notice in the Description page of Project Settings.

#include "Chunk.h"
#include "Math/Vector.h"
#include "Math/UnrealMathUtility.h"
#include "EnemyCharacter.h"
#include "Tower.h"
#include "ChunkGen.h"

// Sets default values
AChunkGen::AChunkGen()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RenderRange = 10;
	ChunkSize = 800;

}

// Called when the game starts or when spawned
void AChunkGen::BeginPlay()
{
	Super::BeginPlay();
	LastPlayerPosition = FVector(200.0f, 200.0f, 200.0f);

}

// Called every frame
void AChunkGen::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Check whether the player has moved from their last position, if so attempt to create a new Chunk
	if (PlayerPosition().X == LastPlayerPosition.X && PlayerPosition().Y == LastPlayerPosition.Y) { 
	}
	else {
		LastPlayerPosition = PlayerPosition();
		CreateNewChunks();
		

	}

	DeleteChunk();

	//Randomly spawn enemy within RenderRange of Player (without overlapping)
	int RandChance = FMath::RandRange(0, 50);
	if (RandChance == 10) {
		float RandDistanceX = FMath::RandRange(-ChunkSize * (RenderRange / 2), ChunkSize * (RenderRange/2));
		float RandDistanceY = FMath::RandRange(-ChunkSize * (RenderRange / 2), ChunkSize * (RenderRange / 2));
		SpawnPoint = FVector(Player->GetActorLocation().X + RandDistanceX, Player->GetActorLocation().Y + RandDistanceY, 0.0f);
		SpawnedEnemies.Add(GetWorld()->SpawnActor<ATower>(ATower::StaticClass(), SpawnPoint, FRotator(0.0f, 0.0f, 0.0f)));
		UE_LOG(LogTemp, Warning, TEXT("Enemy Spawned"));
		NoOfSpawnedEnemies++;
	}

	//Check whether the enemy is out of RenderRange from the PlayerCharacter. If so then destroy.
	if(NoOfSpawnedEnemies != 0){
	for (int i = 0; i < NoOfSpawnedEnemies; i++) { 
		ATower* ThisEnemy = SpawnedEnemies[i];
		double DistanceBetweenActors = FVector::Dist(ThisEnemy->GetActorLocation(), Player->GetActorLocation());
		if (DistanceBetweenActors >= ChunkSize * (RenderRange)) {
			SpawnedEnemies[i]->Destroy();
			SpawnedEnemies.RemoveAt(i);
			UE_LOG(LogTemp, Warning, TEXT("Enemy Despawned"));
			NoOfSpawnedEnemies--;
			}
		}
	}
}

//Return the PlayerCharacter position in relation to the size of the chunk 
FVector AChunkGen::PlayerPosition() {
	FVector CurrentPlayerPosition = Player->GetPlayerPosition();
	FVector a = CurrentPlayerPosition / ChunkSize; 
	int X = (int)a.X;
	int Y = (int)a.Y;
	return FVector(X, Y, 0);
}

//Create a 
void AChunkGen::CreateNewChunks() {
	for (int x = -RenderRange; x < RenderRange; x++) { //Loops through chunks to be created along X and Y axis' based of RenderRange
		int tempX = x;
		for (int y = -RenderRange; y < RenderRange; y++) {
			int tempY = y;
			FVector NewChunkPosition = FVector((PlayerPosition().X + tempX) * ChunkSize, (PlayerPosition().Y + tempY) * ChunkSize, 0.0f);
			int NewChunkX = (int)NewChunkPosition.X;
			int NewChunkY = (int)NewChunkPosition.Y;

			//Following if statment is performing a series of checks to see whether new chunk generation is possible
			//1. Check that there isn't already a Chunk in the same position
			//2. Take into account the magnitude of the chunks to create in a circle around the player (eg. corners which are further than 10 chunks away will not be created)
			//3. Check that it is a valid chunk space by not overlapping other chunks
			if (!(SpawnedChunkPositions.Contains(NewChunkPosition)) && (ChunkSize * RenderRange) >= FVector((tempX * ChunkSize), (tempY * ChunkSize), 0.0f).Size() && IsValidChunkSpace(NewChunkX, NewChunkY)){
				SpawnedChunkPositions.Add(NewChunkPosition);
				AChunk* NewChunk = GetWorld()->SpawnActor<AChunk>(AChunk::StaticClass(), NewChunkPosition, FRotator(0.0f, 0.0f, 0.0f));
				SpawnedChunks.Add(NewChunk);
				NoOfChunks++;

			}

		}
	}
}

//Check to see whether chunk is in a unique position in the world
bool AChunkGen::IsValidChunkSpace(int X, int Y) {
	return ((X % ChunkSize == 0 && Y % ChunkSize == 0)); 
}

//Check if chunk is Render Range away from player, if so delete
void AChunkGen::DeleteChunk() {
	if(NoOfChunks != 0){
		for (int i = 0; i < NoOfChunks; i++) {
			double DistanceBetweenActors = FVector::Dist(SpawnedChunks[i]->GetActorLocation(), Player->GetActorLocation());
			if (DistanceBetweenActors >= ChunkSize * RenderRange) {
				SpawnedChunks[i]->OnDeleteActor();
				SpawnedChunks[i]->Destroy();
				SpawnedChunks.RemoveAt(i);
				SpawnedChunkPositions.RemoveAt(i);
				UE_LOG(LogTemp, Warning, TEXT("Chunk Destoyed"));
				NoOfChunks--;
			}
		}
	}
}









