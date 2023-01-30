
#include "AsyncLoadingScreenForUMG_GI.h"

#include "UObject/UObjectGlobals.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "Widgets/SWidget.h"
#include "MoviePlayer.h"


void UAsyncLoadingScreenForUMG_GI::RegisterWidget(TSubclassOf<class UUserWidget> Widget, bool bPlayOnPreLoadMapDelegate)
{
    // UUSerWidget生成
    UserWidget = CreateWidget(this, Widget);

    if (UserWidget)
    {
        // UUSerWidget を Slateに変換
        SlateWidget = UserWidget->TakeWidget();

        // 自動ロードが指定されていたら、ロード前・後のコールバックに登録
        if (SlateWidget && bPlayOnPreLoadMapDelegate)
        {
            FCoreUObjectDelegates::PreLoadMap.AddUObject(this, &UAsyncLoadingScreenForUMG_GI::OnPreLoadMap);
            FCoreUObjectDelegates::PostLoadMapWithWorld.AddUObject(this, &UAsyncLoadingScreenForUMG_GI::OnPostLoadMap);
        }
    }
}

UAsyncLoadingScreenForUMG_GI* UAsyncLoadingScreenForUMG_GI::Get()
{
    UAsyncLoadingScreenForUMG_GI* instance = nullptr;
    if (GEngine)
    {
        // ビューポートからゲームインスタンスを取得
        FWorldContext* context = GEngine->GetWorldContextFromGameViewport(GEngine->GameViewport);
        instance = Cast<UAsyncLoadingScreenForUMG_GI>(context->OwningGameInstance);
    }

    return instance;
}

void UAsyncLoadingScreenForUMG_GI::OnPreLoadMap(const FString& MapName)
{
    FLoadingScreenAttributes LoadingScreen;

    LoadingScreen.WidgetLoadingScreen               = SlateWidget;
    LoadingScreen.bAutoCompleteWhenLoadingCompletes = true;
    LoadingScreen.bAllowEngineTick                  = true;

    GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
}

void UAsyncLoadingScreenForUMG_GI::OnPostLoadMap(UWorld* World)
{
    GetMoviePlayer()->StopMovie();
}

void UAsyncLoadingScreenForUMG_GI::StartLoadingScreen(bool bPlayUntilStopped)
{
    FLoadingScreenAttributes LoadingScreen;

    LoadingScreen.WidgetLoadingScreen               = SlateWidget;
    LoadingScreen.bAllowEngineTick                  = true;
    LoadingScreen.bAutoCompleteWhenLoadingCompletes = !bPlayUntilStopped;
    LoadingScreen.bWaitForManualStop                = bPlayUntilStopped;

    GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
}

void UAsyncLoadingScreenForUMG_GI::StopLoadingScreen()
{
    GetMoviePlayer()->StopMovie();
}
