// Fill out your copyright notice in the Description page of Project Settings.


#include "AttributeSetBasic.h"

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
















