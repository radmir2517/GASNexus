// Fill out your copyright notice in the Description page of Project Settings.


#include "NexusAbilitySystemComponent.h"

#include "Core/Characters/NexusCharacterBase.h"

void UNexusAbilitySystemComponent::OnRep_ActivateAbilities()
{
	Super::OnRep_ActivateAbilities();

	bool NeedToUpdateUI = false;
	// 4.10 Проверим действителен ли персонаж
	if (!IsValid(NexusCharacter))
	{
		NexusCharacter = Cast<ANexusCharacterBase>(GetAvatarActor());
		if (!IsValid(NexusCharacter))
		{
			return;
		}
	}
	// 4.11 Если не совпадает число то томечаем на обновление
	if (ActivatableAbilities.Items.Num() != LastActivatedAbilities.Num())
	{
		NeedToUpdateUI = true;
	}
	else
	{	// 4.12 Далее перебираем и смотрим что указатели одиннаковые если нет то отмечаем на обнолвение
		for (int i = 0; i < ActivatableAbilities.Items.Num(); i++)
		{
			if (ActivatableAbilities.Items[i].Ability != LastActivatedAbilities[i].Ability)
			{
				NeedToUpdateUI = true;
				break;
			}
		}
	}
	// 4.12.2 обновим список абилок
	LastActivatedAbilities = ActivatableAbilities.Items;
	if (NeedToUpdateUI)
	{
		NexusCharacter->SendGameplayEventToUpdate(FGameplayTag::RequestGameplayTag(FName("UI.UpdateAbilityBar")));
	}
}
