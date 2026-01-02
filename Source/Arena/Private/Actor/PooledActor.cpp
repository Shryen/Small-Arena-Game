#include "Actor/PooledActor.h"


// Sets default values
APooledActor::APooledActor()
{
	PrimaryActorTick.bCanEverTick = false;
}

void APooledActor::SetInUse(bool bInUse)
{
	bIsInUse = bInUse;
	SetActorEnableCollision(bIsInUse);
	SetActorHiddenInGame(!bIsInUse);
	SetActorTickEnabled(bIsInUse);
	
	GetWorld()->GetTimerManager().ClearTimer(TimerHandle);
	
	if (bIsInUse && TimeToLive > 0)
		GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &APooledActor::ReturnToPool, TimeToLive, false);	
}

void APooledActor::BeginPlay()
{
	Super::BeginPlay();
	SetInUse(false);
}

void APooledActor::ReturnToPool()
{
	SetInUse(false);
}


