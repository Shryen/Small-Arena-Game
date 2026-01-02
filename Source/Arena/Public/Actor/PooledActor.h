
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PooledActor.generated.h"

UCLASS()
class ARENA_API APooledActor : public AActor
{
	GENERATED_BODY()

public:
	APooledActor();
	bool GetInUse() const { return bIsInUse; }
	float GetTimeToLive() const { return TimeToLive;}
	
	UFUNCTION(BlueprintCallable)
	virtual void SetInUse(bool bInUse);
	UFUNCTION(BlueprintCallable)
	void ReturnToPool();

protected:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Object Pool", meta = (ExposeOnSpawn = "true"))
	float TimeToLive = 5.f;
	
	FTimerHandle TimerHandle;
private:
	bool bIsInUse = false;
	
};
