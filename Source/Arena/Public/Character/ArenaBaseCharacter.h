#pragma once

#include "CoreMinimal.h"
#include "Actor/ObjectPoolManager.h"
#include "GameFramework/Character.h"
#include "ArenaBaseCharacter.generated.h"

UCLASS(Abstract)
class ARENA_API AArenaBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AArenaBaseCharacter();
	virtual void Tick(float DeltaTime) override;

	UObjectPoolManager* GetObjectPoolManager() const { return ObjectPoolManager; }

	FVector GetBulletSpawnLocation() const { return BulletSpawnLocation->GetComponentLocation(); }

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, Category = "Pool")
	TObjectPtr<class UObjectPoolManager> ObjectPoolManager;
	
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	TObjectPtr<class USceneComponent> BulletSpawnLocation;
};
