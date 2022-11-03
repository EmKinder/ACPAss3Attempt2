// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponPickup.h"
#include "Pickup.h"

void AWeaponPickup::OnGenerate() {
	&APickup::OnGenerate;

	float BadBulletDamage = FMath::RandRange(2.0f, 15.0f);
	float BadMuzzleVelocity = FMath::RandRange(5000.0f, 10000.0f);
	float BadMagazineSize = FMath::RandRange(1, 20);
	float BadWeaponAccuracy = FMath::RandRange(0.8f, 0.95f);

	float GoodBulletDamage = FMath::RandRange(15.0f, 30.0f);
	float GoodMuzzleVelocity = FMath::RandRange(10000.0f, 20000.0f);
	float GoodMagazineSize = FMath::RandRange(20, 100);
	float GoodWeaponAccuracy = FMath::RandRange(0.95f, 1.0f);

	FString randomBadWeapon[] = {"BulletDamage", "MuzzleVelocity", "MagazineSize", "WeaponAccuracy" };

	int32 randomWeapon = FMath::RandRange(1, 100);
	if (randomWeapon >= 1 || randomWeapon <= 50) {
		Rarity = EWeaponPickupRarity::COMMON;
		BulletDamage = BadBulletDamage;
		MuzzleVelocity = BadMuzzleVelocity;
		MagazineSize = BadMagazineSize;
		WeaponAccuracy = BadWeaponAccuracy;
	}
	else if (randomWeapon >= 51 || randomWeapon <= 80) {
		Rarity = EWeaponPickupRarity::RARE;
		BulletDamage = GoodBulletDamage;
		MuzzleVelocity = GoodMuzzleVelocity;
		MagazineSize = GoodMagazineSize;
		WeaponAccuracy = GoodWeaponAccuracy;

		int i = FMath::RandRange(0, 3);
		if (randomBadWeapon[i].Equals("BulletDamage"))
			BulletDamage = BadBulletDamage;
		else if (randomBadWeapon[i].Equals("MuzzleVelocity"))
			MuzzleVelocity = BadMuzzleVelocity;
		else if (randomBadWeapon[i].Equals("MagazineSize"))
			MagazineSize = BadMagazineSize;
		else
			WeaponAccuracy = BadWeaponAccuracy;
		randomBadWeapon->RemoveAt(i);

		i = FMath::RandRange(0, 2);
		if (randomBadWeapon[i].Equals("BulletDamage"))
			BulletDamage = BadBulletDamage;
		else if (randomBadWeapon[i].Equals("MuzzleVelocity"))
			MuzzleVelocity = BadMuzzleVelocity;
		else if (randomBadWeapon[i].Equals("MagazineSize"))
			MagazineSize = BadMagazineSize;
		else
			WeaponAccuracy = BadWeaponAccuracy;
	}
	else if (randomWeapon >= 81 || randomWeapon <= 95) {
		Rarity = EWeaponPickupRarity::MASTER;
		BulletDamage = GoodBulletDamage;
		MuzzleVelocity = GoodMuzzleVelocity;
		MagazineSize = GoodMagazineSize;
		WeaponAccuracy = GoodWeaponAccuracy;

		int i = FMath::RandRange(0, 3);
		randomBadWeapon[i] = randomBadWeapon[i];
		if (randomBadWeapon[i].Equals("BulletDamage"))
			BulletDamage = BadBulletDamage;
		else if (randomBadWeapon[i].Equals("MuzzleVelocity"))
			MuzzleVelocity = BadMuzzleVelocity;
		else if (randomBadWeapon[i].Equals("MagazineSize"))
			MagazineSize = BadMagazineSize;
		else
			WeaponAccuracy = BadWeaponAccuracy;
	}
	else {
		Rarity = EWeaponPickupRarity::LEGENDARY;
		BulletDamage = GoodBulletDamage;
		MuzzleVelocity = GoodMuzzleVelocity;
		MagazineSize = GoodMagazineSize;
		WeaponAccuracy = GoodWeaponAccuracy;
	}
}