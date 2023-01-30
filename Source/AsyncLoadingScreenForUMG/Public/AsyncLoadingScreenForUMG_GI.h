
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Engine/GameInstance.h"
#include "AsyncLoadingScreenForUMG_GI.generated.h"


UCLASS(Blueprintable, BlueprintType)
class ASYNCLOADINGSCREENFORUMG_API UAsyncLoadingScreenForUMG_GI : public UGameInstance
{
    GENERATED_BODY()

public:

    //-------------------------------------------------
    // ロード画面に使用したいUMGを指定する
    //-------------------------------------------------
    UFUNCTION(BlueprintCallable, Category = Loading)
    void RegisterWidget(TSubclassOf<UUserWidget> Widget, bool bPlayOnPreLoadMapDelegate);

public:

    //-------------------------------------------------
    // static ゲッター
    //-------------------------------------------------
    static UAsyncLoadingScreenForUMG_GI* Get();

    //-------------------------------------------------
    // 明示的にロード画面の開始・停止を行う
    //-------------------------------------------------
    void StartLoadingScreen(bool bPlayUntilStopped);
    void StopLoadingScreen();

private:

    //-------------------------------------------------
    // FCoreUObjectDelegatesからのコールバック関数
    //-------------------------------------------------
    void OnPreLoadMap(const FString& MapName);
    void OnPostLoadMap(UWorld* World);

private:

    UUserWidget*        UserWidget;  // UMG
    TSharedPtr<SWidget> SlateWidget; // Slate
};
