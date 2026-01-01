#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ArenaHUD.generated.h"

/**
 * 
 */
UCLASS()
class ARENA_API AArenaHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	AArenaHUD();
	
protected:
	void TryInitializeHUD();
	
	UPROPERTY(EditDefaultsOnly, Category = "Arena|UI")
	TSubclassOf<class UArenaLayout> MainLayoutClass;
	
private:
	UPROPERTY()
	TObjectPtr<class AArenaPlayerCharacter> PlayerCharacter;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<class UStatComponent> StatComponent;

	UPROPERTY()
	TObjectPtr<class UArenaLayout> MainLayout;
};
