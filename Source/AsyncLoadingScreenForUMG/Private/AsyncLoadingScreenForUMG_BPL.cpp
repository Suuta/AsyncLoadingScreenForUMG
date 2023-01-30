
#include "AsyncLoadingScreenForUMG_BPL.h"
#include "AsyncLoadingScreenForUMG_GI.h"


UAsyncLoadingScreenForUMG_BPL::UAsyncLoadingScreenForUMG_BPL(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

void UAsyncLoadingScreenForUMG_BPL::RegisterLoadingScreenWidget(TSubclassOf<UUserWidget> Widget, bool bPlayOnPreLoadMapDelegate)
{
    UAsyncLoadingScreenForUMG_GI* gi = UAsyncLoadingScreenForUMG_GI::Get();
    if (gi)
    {
        gi->RegisterWidget(Widget, bPlayOnPreLoadMapDelegate);
    }
}

void UAsyncLoadingScreenForUMG_BPL::StartLoadingScreen_UMG(bool bPlayUntilStopped)
{
    UAsyncLoadingScreenForUMG_GI* gi = UAsyncLoadingScreenForUMG_GI::Get();
    if (gi)
    {
        gi->StartLoadingScreen(bPlayUntilStopped);
    }
}

void UAsyncLoadingScreenForUMG_BPL::StopLoadingScreen_UMG()
{
    UAsyncLoadingScreenForUMG_GI* gi = UAsyncLoadingScreenForUMG_GI::Get();
    if (gi)
    {
        gi->StopLoadingScreen();
    }
}
