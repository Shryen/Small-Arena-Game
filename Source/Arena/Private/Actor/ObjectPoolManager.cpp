#include "Actor/ObjectPoolManager.h"

#include "Actor/PooledActor.h"


UObjectPoolManager::UObjectPoolManager()
{

	PrimaryComponentTick.bCanEverTick = false;

}

void UObjectPoolManager::InitializePool()
{
	for (int i=0; i<PoolSize; ++i)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
		APooledActor* PoolActor = GetWorld()->SpawnActor<APooledActor>(PooledActorClass, FVector::ZeroVector,
			FRotator::ZeroRotator, SpawnParams);
		ObjectPool.AddUnique(PoolActor); 
		PoolActor->SetInUse(false);
		UE_LOG(LogTemp, Warning, TEXT("Actor added to pool: %s"), *PoolActor->GetName());
	}
}


void UObjectPoolManager::BeginPlay()
{
	Super::BeginPlay();
	
	InitializePool();
}

APooledActor* UObjectPoolManager::FindFirstAvailableActor()
{
	for (int i=0; i<PoolSize; ++i)
		if (!ObjectPool[i]->GetInUse())
			return ObjectPool[i];
	
	UE_LOG(LogTemp, Error, TEXT("No available actor in pool!"));
	return nullptr;
}

APooledActor* UObjectPoolManager::SpawnFromPool(FTransform SpawnTransform)
{
	if (APooledActor* FoundActor = FindFirstAvailableActor())
	{
		if (IsValid(FoundActor))
		{
			FoundActor->SetInUse(true);
			FoundActor->SetActorTransform(SpawnTransform);
			return FoundActor;
		}
	}
	return nullptr;
}

