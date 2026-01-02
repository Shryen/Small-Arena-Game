
#pragma once

#include "CoreMinimal.h"
#include "PooledActor.h"
#include "GameFramework/Actor.h"
#include "Bullet.generated.h"


UCLASS()
class ARENA_API ABullet : public APooledActor
{
	GENERATED_BODY()

public:
	ABullet();

protected:
	virtual void BeginPlay() override;
	
	virtual void SetInUse(bool bInUse) override;
	
private:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<class USphereComponent> BulletCollision;
	
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<class UProjectileMovementComponent> ProjectileMovementComponent;
};
