#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StatComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnAttributeChangedSignature, float, CurrentValue, float, MaxValue);
UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ARENA_API UStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UStatComponent();

	UPROPERTY(BlueprintAssignable, Category = "Stats|Vital")
	FOnAttributeChangedSignature OnHealthChanged;
	
	UFUNCTION(BlueprintCallable, Category = "Stats|Vital")
	void SetHealth(float NewHealth);
	
	float GetHealth() const {return Health;}
	float GetMaxHealth() const {return MaxHealth;}
	
	UFUNCTION(BlueprintCallable)
	void TakeDamage(float DamageAmount);
	
protected:
	virtual void BeginPlay() override;
	
	
private:
	UPROPERTY(EditDefaultsOnly, Category = "Stats|Vital")
	float Health = 0.f;
	
	UPROPERTY(EditDefaultsOnly, Category = "Stats|Vital")
	float MaxHealth = 100.f;
	
	UPROPERTY(EditDefaultsOnly, Category = "Stats|Weapon")
	int Ammo = 62.f;
};
