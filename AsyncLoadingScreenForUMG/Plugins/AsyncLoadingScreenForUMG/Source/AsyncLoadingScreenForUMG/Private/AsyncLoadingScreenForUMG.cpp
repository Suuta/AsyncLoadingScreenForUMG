
#include "AsyncLoadingScreenForUMG.h"

#define LOCTEXT_NAMESPACE "FAsyncLoadingScreenForUMGModule"


void FAsyncLoadingScreenForUMGModule::StartupModule()
{
    // ���̃R�[�h�́A���W���[�����������Ƀ��[�h���ꂽ��Ɏ��s����܂�.
    // ���m�ȃ^�C�~���O�́A���W���[�����Ƃ�.uplugin�t�@�C���Ŏw�肳��܂�.
}

void FAsyncLoadingScreenForUMGModule::ShutdownModule()
{
    // ���̊֐��́A���W���[�����N���[���A�b�v���邽�߂ɃV���b�g�_�E�����ɌĂяo�����ꍇ������܂�.
    // ���I�����[�h���T�|�[�g���郂�W���[���̏ꍇ�A���W���[�����A�����[�h����O�ɂ��̊֐����Ăяo���܂�.
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FAsyncLoadingScreenForUMGModule, AsyncLoadingScreenForUMG)