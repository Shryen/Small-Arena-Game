
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ArenaLayout.generated.h"

/**
 * 
 */
UCLASS()
class ARENA_API UArenaLayout : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (BindWidget), Category = "UI")
	TObjectPtr<class UPlayerHealthWidget> PlayerHealthBar;
};
