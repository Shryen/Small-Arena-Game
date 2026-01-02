#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ObjectPoolManager.generated.h"


class APooledActor;

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ARENA_API UObjectPoolManager : public UActorComponent
{
	GENERATED_BODY()

public:
	UObjectPoolManager();
	
	void InitializePool();
	
	UFUNCTION(BlueprintCallable, Category = "Pool")
	APooledActor* SpawnFromPool(FTransform SpawnTransform);

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, Category = "Pool")
	TSubclassOf<APooledActor> PooledActorClass;
	
	UPROPERTY(EditDefaultsOnly, Category = "Pool")
	int32 PoolSize = 5;
	
	UPROPERTY(VisibleAnywhere, Category = "Pool")
	TArray<APooledActor*> ObjectPool;
	
	APooledActor* FindFirstAvailableActor();
};
