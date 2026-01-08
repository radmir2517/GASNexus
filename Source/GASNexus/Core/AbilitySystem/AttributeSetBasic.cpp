// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSetBasic.h"

#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UAttributeSetBasic::UAttributeSetBasic()
{//2.4 сделаем конструктор и назначим там пока временно первичные значения
	MaxHealth = 100.f;
	Health = 100.0f;
	MaxStamina= 100.f;
	Stamina = 100.0f;
}

void UAttributeSetBasic::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{//2.3 для репликация атрибута
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	//2.3.1 пока репликация во всех случаях даже если не изменился аттрибут
	DOREPLIFETIME_CONDITION_NOTIFY(UAttributeSetBasic,Health,COND_None,REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UAttributeSetBasic,MaxHealth,COND_None,REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UAttributeSetBasic,Stamina,COND_None,REPNOTIFY_Always)
	DOREPLIFETIME_CONDITION_NOTIFY(UAttributeSetBasic,MaxStamina,COND_None,REPNOTIFY_Always)
	
}

void UAttributeSetBasic::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	float HealthValue = 0.f;
	float StaminaValue = 0.f;
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		HealthValue = Data.EvaluatedData.Attribute.GetNumericValue(this);
		SetHealth(FMath::Clamp(HealthValue, 0.f, GetMaxHealth()));
	}
	else if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
	{ 
		StaminaValue = Data.EvaluatedData.Attribute.GetNumericValue(this);
		SetStamina(FMath::Clamp(StaminaValue, 0.f, GetMaxStamina()));
	}
}

//2.3 для репликация атрибута
void UAttributeSetBasic::OnRep_Health(const FGameplayAttributeData& OldValue) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeSetBasic, Health, OldValue);
}

void UAttributeSetBasic::OnRep_MaxHealth(const FGameplayAttributeData& OldValue) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeSetBasic, MaxHealth, OldValue);
}

void UAttributeSetBasic::OnRep_Stamina(const FGameplayAttributeData& OldValue) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeSetBasic, Stamina, OldValue);
}

void UAttributeSetBasic::OnRep_MaxStamina(const FGameplayAttributeData& OldValue) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAttributeSetBasic, MaxStamina, OldValue);
}
















