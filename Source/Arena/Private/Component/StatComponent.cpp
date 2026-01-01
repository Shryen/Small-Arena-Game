#include "Component/StatComponent.h"


UStatComponent::UStatComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


void UStatComponent::BeginPlay()
{
	Super::BeginPlay();
	OnHealthChanged.Broadcast(Health, MaxHealth);
}

void UStatComponent::SetHealth(float NewHealth)
{
	Health = FMath::Clamp(NewHealth, 0.f, MaxHealth);
    
	OnHealthChanged.Broadcast(Health, MaxHealth);
}


