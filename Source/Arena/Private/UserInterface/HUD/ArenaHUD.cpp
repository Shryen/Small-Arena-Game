#include "UserInterface/HUD/ArenaHUD.h"
#include "Character/Player/ArenaPlayerCharacter.h"
#include "UserInterface/PlayerHealthWidget.h"
#include "UserInterface/HUD/Widgets/ArenaLayout.h"


void AArenaHUD::BeginPlay()
{
	Super::BeginPlay();
	
	TryInitializeHUD();
}

void AArenaHUD::TryInitializeHUD()
{
	if (APawn* PlayerPawn = Cast<APawn>(GetOwningPawn()))
	{
		PlayerCharacter = Cast<AArenaPlayerCharacter>(PlayerPawn);

		if (PlayerCharacter)
		{
			StatComponent = PlayerCharacter->GetStatComponent();
			if (StatComponent && MainLayoutClass)
			{
				MainLayout = CreateWidget<UArenaLayout>(GetOwningPlayerController(), MainLayoutClass);
				MainLayout->AddToViewport();
				if (MainLayout->PlayerHealthBar)
				{
					StatComponent->OnHealthChanged.AddDynamic(MainLayout->PlayerHealthBar, &UPlayerHealthWidget::UpdateHealthBar);
					MainLayout->PlayerHealthBar->UpdateHealthBar(StatComponent->GetHealth(), StatComponent->GetMaxHealth());
				}
			} else
			{
				if (!StatComponent) UE_LOG(LogTemp, Error, TEXT("HUD: StatComponent is NULL"));
				if (!MainLayoutClass) UE_LOG(LogTemp, Error, TEXT("HUD: MainLayoutClass is NULL - Check BP_ArenaHUD details!"));			
			}
			return; // return if everything fine
		}
	}
	// Set timer to try again at next frame if not
	GetWorld()->GetTimerManager().SetTimerForNextTick(this, &AArenaHUD::TryInitializeHUD);
}
