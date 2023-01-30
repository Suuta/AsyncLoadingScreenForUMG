
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
    // ロード画面に使用したいUMGを指定する
    //-------------------------------------------------
    UFUNCTION(BlueprintCallable, Category = Loading)
    static void RegisterLoadingScreenWidget(TSubclassOf<UUserWidget> Widget, bool bPlayOnPreLoadMapDelegate);

    //-------------------------------------------------
    // ロード画面の開始
    //-------------------------------------------------
    UFUNCTION(BlueprintCallable, Category = Loading)
    static void StartLoadingScreen_UMG(bool bPlayUntilStopped);

    //-------------------------------------------------
    // ロード画面の終了 ※ 明示的に終了させる
    //-------------------------------------------------
    UFUNCTION(BlueprintCallable, Category = Loading)
    static void StopLoadingScreen_UMG();
};
