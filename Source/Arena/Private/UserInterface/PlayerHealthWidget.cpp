#include "UserInterface/PlayerHealthWidget.h"

#include "Components/ProgressBar.h"

void UPlayerHealthWidget::UpdateHealthBar(const float CurrentHealth, const float MaxHealth)
{
	if (HealthBar && MaxHealth > 0.f)
	{
		const float HealthPercent = CurrentHealth / MaxHealth;
		HealthBar->SetPercent(HealthPercent);
	}
}
