// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "AttributeSetBasic.generated.h"

/**
 * 
 */
UCLASS()
class GASNEXUS_API UAttributeSetBasic : public UAttributeSet
{
	GENERATED_BODY()

public:
	//2.4 сделаем конструктор и назначим там пока временно первичные значения
	UAttributeSetBasic();
	
	// 2.1.1 сделаем атрибут здоровья
	UPROPERTY(BlueprintReadOnly,Category="NexusCharacterBase", ReplicatedUsing="OnRep_Health")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS_BASIC(UAttributeSetBasic,Health);
	// 2.1.2 сделаем атрибут макс здоровья
	UPROPERTY(BlueprintReadOnly,Category="NexusCharacterBase", ReplicatedUsing="OnRep_MaxHealth")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS_BASIC(UAttributeSetBasic,MaxHealth);
	// 2.1.3 сделаем атрибут Стамины
	UPROPERTY(BlueprintReadOnly,Category="NexusCharacterBase", ReplicatedUsing="OnRep_Stamina")
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS_BASIC(UAttributeSetBasic,Stamina);
	// 2.1.3 сделаем атрибут Макс стамины
	UPROPERTY(BlueprintReadOnly,Category="NexusCharacterBase", ReplicatedUsing="OnRep_MaxStamina")
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS_BASIC(UAttributeSetBasic,MaxStamina);

public:
	//2.3 для репликация атрибута
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;


	//3.
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;

	
	//2.2 для репликация атрибута
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldValue) const;
	//2.2 для репликация атрибута
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldValue) const;
	//2.2 для репликация атрибута
	UFUNCTION()
	void OnRep_Stamina(const FGameplayAttributeData& OldValue) const;
	//2.2 для репликация атрибута
	UFUNCTION()
	void OnRep_MaxStamina(const FGameplayAttributeData& OldValue) const;
	
};
