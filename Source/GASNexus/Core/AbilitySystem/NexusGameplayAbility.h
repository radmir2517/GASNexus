// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "NexusGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class GASNEXUS_API UNexusGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:
	//4.13 Сделаем переменную которая будет определять надо ли ее выводить в UIBar
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Abilities")
	bool ShowAbilityToUIBar = false;
};
