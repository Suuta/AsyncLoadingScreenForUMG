
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintUtility.generated.h"


UCLASS()
class GAME_API UBlueprintUtility : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    //-------------------------------------------------
    // Slate用ロード画面 スタート
    //-------------------------------------------------
    UFUNCTION(BlueprintCallable, Category = Loading)
    static void StartLoadingScreen_Slate(bool bPlayUntilStopped);

    //-------------------------------------------------
    // Slate用ロード画面 ストップ
    //-------------------------------------------------
    UFUNCTION(BlueprintCallable, Category = Loading)
    static void StopLoadingScreen_Slate();

};
