
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AsyncLoadingScreenForUMG_BPL.generated.h"


UCLASS(Blueprintable, BlueprintType)
class ASYNCLOADINGSCREENFORUMG_API UAsyncLoadingScreenForUMG_BPL : public UBlueprintFunctionLibrary
{
    GENERATED_UCLASS_BODY()

public:

    //-------------------------------------------------
    // ���[�h��ʂɎg�p������UMG���w�肷��
    //-------------------------------------------------
    UFUNCTION(BlueprintCallable, Category = Loading)
    static void RegisterLoadingScreenWidget(TSubclassOf<UUserWidget> Widget, bool bPlayOnPreLoadMapDelegate);

    //-------------------------------------------------
    // ���[�h��ʂ̊J�n
    //-------------------------------------------------
    UFUNCTION(BlueprintCallable, Category = Loading)
    static void StartLoadingScreen_UMG(bool bPlayUntilStopped);

    //-------------------------------------------------
    // ���[�h��ʂ̏I�� �� �����I�ɏI��������
    //-------------------------------------------------
    UFUNCTION(BlueprintCallable, Category = Loading)
    static void StopLoadingScreen_UMG();
};
