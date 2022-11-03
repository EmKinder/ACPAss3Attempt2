// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Rocks.generated.h"

UCLASS()
class ADVGAMESPROGRAMMING_API ARocks : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARocks();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UStaticMeshComponent* Rock1;
	UStaticMeshComponent* Rock2;
	UStaticMeshComponent* Rock3;
	UStaticMeshComponent* Rock4;
	UStaticMeshComponent* Rock5;
	
	TArray<UStaticMeshComponent*> Rocks;

};
