// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "NexusCharacterBase.generated.h"

class UAttributeSetBasic;

UCLASS()
class GASNEXUS_API ANexusCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ANexusCharacterBase();
	
	virtual void Tick(float DeltaTime) override;
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// 1.3 Это для врагов, тут мы будем InitAbilityActorInfo, для обозначения кто владелец, а кто аватар
	virtual void PossessedBy(AController* NewController) override;
	// 1.4 Это для игрока, тут мы будем запускать InitAbilityActorInfo, для обозначения кто владелец, а кто аватар
	virtual void OnRep_PlayerState() override;

	// 4.7 Функция отправляющие ивент, пока только для UI
	UFUNCTION(BlueprintCallable, Category = "NexusCharacterBase")
	void SendGameplayEventToUpdate(FGameplayTag Tag);
protected:
	// 1.1 Создадим компонент ASC
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="NexusCharacterBase")
	UAbilitySystemComponent* AbilitySystemComponent;

	// 2. Создадим компонент AttibuteSet
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="NexusCharacterBase")
	UAttributeSetBasic* AttributeSet;
	
	// 1.2 Сделаем переменную которую мы сможем редактировать для назначения репликации для игрока и для врагов
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="NexusCharacterBase")
	EGameplayEffectReplicationMode ASCReplicationMode = EGameplayEffectReplicationMode::Mixed;

	// 4.8 Создадим стартовые абилки
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="NexusCharacterBase")
	TArray<TSubclassOf<UGameplayAbility>> StartedAbilities;

protected:
	virtual void BeginPlay() override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	//4.1 Создадим функцию которая будет предоставлять абилки персонажу
	UFUNCTION(BlueprintCallable, Category = "NexusCharacterBase")
	TArray<FGameplayAbilitySpecHandle>GrantAbilities(TArray<TSubclassOf<UGameplayAbility>>ClassOfAbilities);

	// 4.5 Создадим функцию, которая будет чистить абилки когда надо
	UFUNCTION(BlueprintCallable, Category = "NexusCharacterBase")
	void ClearAbilities(TArray<FGameplayAbilitySpecHandle>Abilities);

	
};
