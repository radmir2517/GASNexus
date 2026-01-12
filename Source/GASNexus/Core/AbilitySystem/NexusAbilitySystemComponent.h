// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "UObject/Object.h"
#include "NexusAbilitySystemComponent.generated.h"

class ANexusCharacterBase;
/**
 * 
 */
UCLASS()
class GASNEXUS_API UNexusAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
protected:

protected:
	// 4.9 переопределим функцию, которая будет активироваться каждый раз когда будут обновляться абилки,в том числе после активации
	virtual void OnRep_ActivateAbilities() override;

private:
	// 4.8 Создадим переменную которая будет хранить Абилки которые у нас активны были в прошлый раз
	TArray<FGameplayAbilitySpec> LastActivatedAbilities;

	UPROPERTY()
	TObjectPtr<ANexusCharacterBase> NexusCharacter;
	
};
