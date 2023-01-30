
#include "AsyncLoadingScreenForUMG.h"

#define LOCTEXT_NAMESPACE "FAsyncLoadingScreenForUMGModule"


void FAsyncLoadingScreenForUMGModule::StartupModule()
{
    // このコードは、モジュールがメモリにロードされた後に実行されます.
    // 正確なタイミングは、モジュールごとの.upluginファイルで指定されます.
}

void FAsyncLoadingScreenForUMGModule::ShutdownModule()
{
    // この関数は、モジュールをクリーンアップするためにシャットダウン中に呼び出される場合があります.
    // 動的リロードをサポートするモジュールの場合、モジュールをアンロードする前にこの関数を呼び出します.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAsyncLoadingScreenForUMGModule, AsyncLoadingScreenForUMG)