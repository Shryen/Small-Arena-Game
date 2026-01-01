
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHealthWidget.generated.h"


UCLASS()
class ARENA_API UPlayerHealthWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(meta=(BindWidget))
	TObjectPtr<class UProgressBar> HealthBar;
	
	UFUNCTION()
	void UpdateHealthBar(float CurrentHealth, float MaxHealth);
};
