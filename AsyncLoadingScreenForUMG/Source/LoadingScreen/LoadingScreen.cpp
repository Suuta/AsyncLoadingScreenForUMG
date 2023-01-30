
#include "LoadingScreen.h"

#include "SlateBasics.h"
#include "SlateExtras.h"
#include "MoviePlayer.h"
#include "SThrobber.h"
#include "SlateMaterialBrush.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "SlateDelegates.h"
#include "Widgets/Layout/SConstraintCanvas.h"
#include "Math/UnrealMathUtility.h"


LOADINGSCREEN_API
class SLoadingScreen : public SCompoundWidget
{
public:
    SLATE_BEGIN_ARGS(SLoadingScreen) {}
    SLATE_END_ARGS()


    void Construct(const FArguments& InArgs)
    {
        // �w�i�摜
        m_BackgroundBrush = MakeShareable(new FSlateBrush);
        m_BackgroundBrush->TintColor = FLinearColor(0.02f, 0.02f, 0.02f, 1.0f);
        m_BackgroundBrush->SetImageSize(FVector2D(1920.f, 1080.f));

        // ���[�f�B���O�E�B�W�F�b�g�̉摜
        m_IconElementBrush = MakeShareable(new FSlateBrush);
        m_IconElementBrush->TintColor = FLinearColor(0.5f, 0.5f, 0.5f, 1.0f);
        m_IconElementBrush->SetImageSize(FVector2D(32.f, 32.f));


        // 45�x��]�̕ϊ��ŏ�����
        for (uint32 i = 0; i < 8; i++)
        {
            m_Elements[i].Transform = m_Elements[i].Transform.Concatenate(FTransform2D(FMatrix2x2(FQuat2D(FMath::DegreesToRadians(45.0f)))));
        }

        m_Elements[0].Transform = m_Elements[0].Transform.Concatenate(FTransform2D(FMatrix2x2(FScale2D(1.0f, 1.0f))));
        m_Elements[0].Color     = FLinearColor(0.5f, 0.5f, 0.5f, 1.0f);

        m_Elements[1].Transform = m_Elements[1].Transform.Concatenate(FTransform2D(FMatrix2x2(FScale2D(0.5f, 0.5f))));
        m_Elements[1].Color     = FLinearColor(0.5f, 0.5f, 0.5f, 0.5f);

        m_Elements[2].Transform = m_Elements[2].Transform.Concatenate(FTransform2D(FMatrix2x2(FScale2D(0.5f, 0.5f))));
        m_Elements[2].Color     = FLinearColor(0.5f, 0.5f, 0.5f, 0.5f);

        m_Elements[3].Transform = m_Elements[3].Transform.Concatenate(FTransform2D(FMatrix2x2(FScale2D(0.5f, 0.5f))));
        m_Elements[3].Color     = FLinearColor(0.5f, 0.5f, 0.5f, 0.5f);

        m_Elements[4].Transform = m_Elements[4].Transform.Concatenate(FTransform2D(FMatrix2x2(FScale2D(1.0f, 1.0f))));
        m_Elements[4].Color     = FLinearColor(0.5f, 0.5f, 0.5f, 0.75f);

        m_Elements[5].Transform = m_Elements[5].Transform.Concatenate(FTransform2D(FMatrix2x2(FScale2D(1.0f, 1.0f))));
        m_Elements[5].Color     = FLinearColor(0.5f, 0.5f, 0.5f, 0.75f);

        m_Elements[6].Transform = m_Elements[6].Transform.Concatenate(FTransform2D(FMatrix2x2(FScale2D(1.0f, 1.0f))));
        m_Elements[6].Color     = FLinearColor(0.5f, 0.5f, 0.5f, 0.75f);

        m_Elements[7].Transform = m_Elements[7].Transform.Concatenate(FTransform2D(FMatrix2x2(FScale2D(1.0f, 1.0f))));
        m_Elements[7].Color     = FLinearColor(0.5f, 0.5f, 0.5f, 1.0f);


        // ���C�A�E�g�̍\�z
        ChildSlot
        [
            //=============================================
            // �L�����o�X�p�l��
            //=============================================
            SNew(SConstraintCanvas)
            //---------------------------------------------
            + SConstraintCanvas::Slot()
            .Anchors(FAnchors(0.0f, 0.0f, 1.0f, 1.0f))
            .Offset(FMargin(0, 0, 0, 0))
            .Alignment(FVector2D(0, 0))
            .AutoSize(false)
            .ZOrder(0)
            [
                SNew(SImage)
                .Image(m_BackgroundBrush.Get())
            ]
            //---------------------------------------------
            + SConstraintCanvas::Slot()
            .Anchors(FAnchors(0.5f, 0.5f, 0.5f, 0.5f))
            .Offset(FMargin(0, 0, 0, 0))
            .Alignment(FVector2D(0, 0))
            .AutoSize(false)
            .ZOrder(0)
            [
                //=============================================
                // �L�����o�X�p�l��
                //=============================================
                SNew(SConstraintCanvas) 
                //---------------------------------------------
                + SConstraintCanvas::Slot()
                .Anchors(FAnchors(0.5f, 0.5f, 0.5f, 0.5f))
                .Offset(FMargin(0, 0, 20, 20))
                .Alignment(FVector2D(0, 2))
                .AutoSize(false)
                .ZOrder(0)
                [
                    SNew(SImage)
                    .Image(m_IconElementBrush.Get())
                    .RenderTransformPivot(FVector2D(0.5f, 0.5f))
                    .ColorAndOpacity_Lambda([this]() { return m_Elements[0].Color;     })
                    .RenderTransform_Lambda([this]() { return m_Elements[0].Transform; })
                ]
                //---------------------------------------------
                + SConstraintCanvas::Slot()
                .Anchors(FAnchors(0.5f, 0.5f, 0.5f, 0.5f))
                .Offset(FMargin(0, 0, 20, 20))
                .Alignment(FVector2D(-1, 1))
                .AutoSize(false)
                .ZOrder(0)
                [
                    SNew(SImage)
                    .Image(m_IconElementBrush.Get())
                    .RenderTransformPivot(FVector2D(0.5f, 0.5f))
                    .ColorAndOpacity_Lambda([this]() { return m_Elements[1].Color;     })
                    .RenderTransform_Lambda([this]() { return m_Elements[1].Transform; })
                ]
                //---------------------------------------------
                + SConstraintCanvas::Slot()
                .Anchors(FAnchors(0.5f, 0.5f, 0.5f, 0.5f))
                .Offset(FMargin(0, 0, 20, 20))
                .Alignment(FVector2D(-2, 0))
                .AutoSize(false)
                .ZOrder(0)
                [
                    SNew(SImage)
                    .Image(m_IconElementBrush.Get())
                    .RenderTransformPivot(FVector2D(0.5f, 0.5f))
                    .ColorAndOpacity_Lambda([this]() { return m_Elements[2].Color;     })
                    .RenderTransform_Lambda([this]() { return m_Elements[2].Transform; })
                ]
                //---------------------------------------------
                + SConstraintCanvas::Slot()
                .Anchors(FAnchors(0.5f, 0.5f, 0.5f, 0.5f))
                .Offset(FMargin(0, 0, 20, 20))
                .Alignment(FVector2D(-1, -1))
                .AutoSize(false)
                .ZOrder(0)
                [
                    SNew(SImage)
                    .Image(m_IconElementBrush.Get())
                    .RenderTransformPivot(FVector2D(0.5f, 0.5f))
                    .ColorAndOpacity_Lambda([this]() { return m_Elements[3].Color;     })
                    .RenderTransform_Lambda([this]() { return m_Elements[3].Transform; })
                ]
                //---------------------------------------------
                + SConstraintCanvas::Slot()
                .Anchors(FAnchors(0.5f, 0.5f, 0.5f, 0.5f))
                .Offset(FMargin(0, 0, 20, 20))
                .Alignment(FVector2D(0, -2))
                .AutoSize(false)
                .ZOrder(0)
                [
                    SNew(SImage)
                    .Image(m_IconElementBrush.Get())
                    .RenderTransformPivot(FVector2D(0.5f, 0.5f))
                    .ColorAndOpacity_Lambda([this]() { return m_Elements[4].Color;     })
                    .RenderTransform_Lambda([this]() { return m_Elements[4].Transform; })
                ]
                //---------------------------------------------
                + SConstraintCanvas::Slot()
                .Anchors(FAnchors(0.5f, 0.5f, 0.5f, 0.5f))
                .Offset(FMargin(0, 0, 20, 20))
                .Alignment(FVector2D(1, -1))
                .AutoSize(false)
                .ZOrder(0)
                [
                    SNew(SImage)
                    .Image(m_IconElementBrush.Get())
                    .RenderTransformPivot(FVector2D(0.5f, 0.5f))
                    .ColorAndOpacity_Lambda([this]() { return m_Elements[5].Color;     })
                    .RenderTransform_Lambda([this]() { return m_Elements[5].Transform; })
                ]
                //---------------------------------------------
                + SConstraintCanvas::Slot()
                .Anchors(FAnchors(0.5f, 0.5f, 0.5f, 0.5f))
                .Offset(FMargin(0, 0, 20, 20))
                .Alignment(FVector2D(2, 0))
                .AutoSize(false)
                .ZOrder(0)
                [
                    SNew(SImage)
                    .Image(m_IconElementBrush.Get())
                    .RenderTransformPivot(FVector2D(0.5f, 0.5f))
                    .ColorAndOpacity_Lambda([this]() { return m_Elements[6].Color;     })
                    .RenderTransform_Lambda([this]() { return m_Elements[6].Transform; })
                ]
                //---------------------------------------------
                + SConstraintCanvas::Slot()
                .Anchors(FAnchors(0.5f, 0.5f, 0.5f, 0.5f))
                .Offset(FMargin(0, 0, 20, 20))
                .Alignment(FVector2D(1, 1))
                .AutoSize(false)
                .ZOrder(0)
                [
                    SNew(SImage)
                    .Image(m_IconElementBrush.Get())
                    .RenderTransformPivot(FVector2D(0.5f, 0.5f))
                    .ColorAndOpacity_Lambda([this]() { return m_Elements[7].Color;     })
                    .RenderTransform_Lambda([this]() { return m_Elements[7].Transform; })
                ]
            ]
        ];
    }


    // �X�V�֐�
    void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override
    {
        // ���Ԃ̍X�V
        m_CurrentTime += InDeltaTime;
        if (m_CurrentTime >= m_TotalAnimTime)
        {
            m_CurrentTime     = 0.0f;
            m_SectionEndTime  = 0.2f;
            m_SectionHeadTime = 0.0f;
        }

        // �^�C�����C���L�[�t���[���Ԋu�i0.2�b�j�̍X�V
        if (m_CurrentTime >= m_SectionEndTime)
        {
            m_SectionHeadTime = m_CurrentTime;
            m_SectionEndTime  = m_CurrentTime + 0.2f;
        }


        // ��ԓ��̐i���x
        float alpha = (m_CurrentTime - m_SectionHeadTime) / 0.2f;


        //==================== 1 ====================
        {
            if (m_SectionHeadTime >= 0.2f && m_SectionHeadTime <= 0.4f)
            {
                m_Elements[0].Color.A = FMath::Lerp<float>(1.0f, 0.75f, alpha);
            }
            else if (m_SectionHeadTime >= 0.8f && m_SectionHeadTime <= 1.0f)
            {
                m_Elements[0].Color.A = FMath::Lerp<float>(0.75f, 0.5f, alpha);
            }
            else if (m_SectionHeadTime >= 1.4f && m_SectionHeadTime <= 1.6f)
            {
                m_Elements[0].Color.A = FMath::Lerp<float>(0.5f, 1.0f, alpha);
            }


            if (m_SectionHeadTime >= 0.8f && m_SectionHeadTime <= 1.0f)
            {
                FMatrix2x2 scale(FMath::Lerp<float>(1.0f, 0.5f, alpha));
                FMatrix2x2 rot(FQuat2D(FMath::DegreesToRadians(45.0f)));

                m_Elements[0].Transform = FTransform2D(scale.Concatenate(rot));
            }
            else if (m_SectionHeadTime >= 1.4f && m_SectionHeadTime <= 1.6f)
            {
                FMatrix2x2 scale(FMath::Lerp<float>(0.5f, 1.0f, alpha));
                FMatrix2x2 rot(FQuat2D(FMath::DegreesToRadians(45.0f)));

                m_Elements[0].Transform = FTransform2D(scale.Concatenate(rot));
            }
        }
        //==================== 2 ====================
        {
            if (m_SectionHeadTime >= 0.0f && m_SectionHeadTime <= 0.2f)
            {
                m_Elements[1].Color.A = FMath::Lerp<float>(0.5f, 1.0f, alpha);
            }
            else if (m_SectionHeadTime >= 0.4f && m_SectionHeadTime <= 0.6f)
            {
                m_Elements[1].Color.A = FMath::Lerp<float>(1.0f, 0.75f, alpha);
            }
            else if (m_SectionHeadTime >= 1.0f && m_SectionHeadTime <= 1.2f)
            {
                m_Elements[1].Color.A = FMath::Lerp<float>(0.75f, 0.5f, alpha);
            }


            if (m_SectionHeadTime >= 0.0f && m_SectionHeadTime <= 0.2f)
            {
                FMatrix2x2 scale(FMath::Lerp<float>(0.5f, 1.0f, alpha));
                FMatrix2x2 rot(FQuat2D(FMath::DegreesToRadians(45.0f)));

                m_Elements[1].Transform = FTransform2D(scale.Concatenate(rot));
            }
            else if (m_SectionHeadTime >= 1.0f && m_SectionHeadTime <= 1.2f)
            {
                FMatrix2x2 scale(FMath::Lerp<float>(1.0f, 0.5f, alpha));
                FMatrix2x2 rot(FQuat2D(FMath::DegreesToRadians(45.0f)));

                m_Elements[1].Transform = FTransform2D(scale.Concatenate(rot));
            }
        }
        //==================== 3 ====================
        {
            if (m_SectionHeadTime >= 0.2f && m_SectionHeadTime <= 0.4f)
            {
                m_Elements[2].Color.A = FMath::Lerp<float>(0.5f, 1.0f, alpha);
            }
            else if (m_SectionHeadTime >= 0.6f && m_SectionHeadTime <= 0.8f)
            {
                m_Elements[2].Color.A = FMath::Lerp<float>(1.0f, 0.75f, alpha);
            }
            else if (m_SectionHeadTime >= 1.2f && m_SectionHeadTime <= 1.4f)
            {
                m_Elements[2].Color.A = FMath::Lerp<float>(0.75f, 0.5f, alpha);
            }


            if (m_SectionHeadTime >= 0.2f && m_SectionHeadTime <= 0.4f)
            {
                FMatrix2x2 scale(FMath::Lerp<float>(0.5f, 1.0f, alpha));
                FMatrix2x2 rot(FQuat2D(FMath::DegreesToRadians(45.0f)));

                m_Elements[2].Transform = FTransform2D(scale.Concatenate(rot));
            }
            else if (m_SectionHeadTime >= 1.2f && m_SectionHeadTime <= 1.4f)
            {
                FMatrix2x2 scale(FMath::Lerp<float>(1.0f, 0.5f, alpha));
                FMatrix2x2 rot(FQuat2D(FMath::DegreesToRadians(45.0f)));

                m_Elements[2].Transform = FTransform2D(scale.Concatenate(rot));
            }
        }
        //==================== 4 ====================
        {
            if (m_SectionHeadTime >= 0.4f && m_SectionHeadTime <= 0.6f)
            {
                m_Elements[3].Color.A = FMath::Lerp<float>(0.5f, 1.0f, alpha);
            }
            else if (m_SectionHeadTime >= 0.8f && m_SectionHeadTime <= 1.0f)
            {
                m_Elements[3].Color.A = FMath::Lerp<float>(1.0f, 0.75f, alpha);
            }
            else if (m_SectionHeadTime >= 1.4f && m_SectionHeadTime <= 1.6f)
            {
                m_Elements[3].Color.A = FMath::Lerp<float>(0.75f, 0.5f, alpha);
            }


            if (m_SectionHeadTime >= 0.4f && m_SectionHeadTime <= 0.6f)
            {
                FMatrix2x2 scale(FMath::Lerp<float>(0.5f, 1.0f, alpha));
                FMatrix2x2 rot(FQuat2D(FMath::DegreesToRadians(45.0f)));

                m_Elements[3].Transform = FTransform2D(scale.Concatenate(rot));
            }
            else if (m_SectionHeadTime >= 1.4f && m_SectionHeadTime <= 1.6f)
            {
                FMatrix2x2 scale(FMath::Lerp<float>(1.0f, 0.5f, alpha));
                FMatrix2x2 rot(FQuat2D(FMath::DegreesToRadians(45.0f)));

                m_Elements[3].Transform = FTransform2D(scale.Concatenate(rot));
            }
        }
        //==================== 5 ====================
        {
            if (m_SectionHeadTime >= 0.0f && m_SectionHeadTime <= 0.2f)
            {
                m_Elements[4].Color.A = FMath::Lerp<float>(0.75f, 0.5f, alpha);
            }
            else if (m_SectionHeadTime >= 0.6f && m_SectionHeadTime <= 0.8f)
            {
                m_Elements[4].Color.A = FMath::Lerp<float>(0.5f, 1.0f, alpha);
            }
            else if (m_SectionHeadTime >= 1.0f && m_SectionHeadTime <= 1.2f)
            {
                m_Elements[4].Color.A = FMath::Lerp<float>(1.0f, 0.75f, alpha);
            }


            if (m_SectionHeadTime >= 0.0f && m_SectionHeadTime <= 0.2f)
            {
                FMatrix2x2 scale(FMath::Lerp<float>(1.0f, 0.5f, alpha));
                FMatrix2x2 rot(FQuat2D(FMath::DegreesToRadians(45.0f)));

                m_Elements[4].Transform = FTransform2D(scale.Concatenate(rot));
            }
            else if (m_SectionHeadTime >= 0.6f && m_SectionHeadTime <= 0.8f)
            {
                FMatrix2x2 scale(FMath::Lerp<float>(0.5f, 1.0f, alpha));
                FMatrix2x2 rot(FQuat2D(FMath::DegreesToRadians(45.0f)));

                m_Elements[4].Transform = FTransform2D(scale.Concatenate(rot));
            }
        }
        //==================== 6 ====================
        {
            if (m_SectionHeadTime >= 0.2f && m_SectionHeadTime <= 0.4f)
            {
                m_Elements[5].Color.A = FMath::Lerp<float>(0.75f, 0.5f, alpha);
            }
            else if (m_SectionHeadTime >= 0.8f && m_SectionHeadTime <= 1.0f)
            {
                m_Elements[5].Color.A = FMath::Lerp<float>(0.5f, 1.0f, alpha);
            }
            else if (m_SectionHeadTime >= 1.2f && m_SectionHeadTime <= 1.4f)
            {
                m_Elements[5].Color.A = FMath::Lerp<float>(1.0f, 0.75f, alpha);
            }


            if (m_SectionHeadTime >= 0.2f && m_SectionHeadTime <= 0.4f)
            {
                FMatrix2x2 scale(FMath::Lerp<float>(1.0f, 0.5f, alpha));
                FMatrix2x2 rot(FQuat2D(FMath::DegreesToRadians(45.0f)));

                m_Elements[5].Transform = FTransform2D(scale.Concatenate(rot));
            }
            else if (m_SectionHeadTime >= 0.8f && m_SectionHeadTime <= 1.0f)
            {
                FMatrix2x2 scale(FMath::Lerp<float>(0.5f, 1.0f, alpha));
                FMatrix2x2 rot(FQuat2D(FMath::DegreesToRadians(45.0f)));

                m_Elements[5].Transform = FTransform2D(scale.Concatenate(rot));
            }
        }
        //==================== 7 ====================
        {
            if (m_SectionHeadTime >= 0.4f && m_SectionHeadTime <= 0.6f)
            {
                m_Elements[6].Color.A = FMath::Lerp<float>(0.75f, 0.5f, alpha);
            }
            else if (m_SectionHeadTime >= 1.0f && m_SectionHeadTime <= 1.2f)
            {
                m_Elements[6].Color.A = FMath::Lerp<float>(0.5f, 1.0f, alpha);
            }
            else if (m_SectionHeadTime >= 1.4f && m_SectionHeadTime <= 1.6f)
            {
                m_Elements[6].Color.A = FMath::Lerp<float>(1.0f, 0.75f, alpha);
            }


            if (m_SectionHeadTime >= 0.4f && m_SectionHeadTime <= 0.6f)
            {
                FMatrix2x2 scale(FMath::Lerp<float>(1.0f, 0.5f, alpha));
                FMatrix2x2 rot(FQuat2D(FMath::DegreesToRadians(45.0f)));

                m_Elements[6].Transform = FTransform2D(scale.Concatenate(rot));
            }
            else if (m_SectionHeadTime >= 1.0f && m_SectionHeadTime <= 1.2f)
            {
                FMatrix2x2 scale(FMath::Lerp<float>(0.5f, 1.0f, alpha));
                FMatrix2x2 rot(FQuat2D(FMath::DegreesToRadians(45.0f)));

                m_Elements[6].Transform = FTransform2D(scale.Concatenate(rot));
            }
        }
        //==================== 8 ====================
        {
            if (m_SectionHeadTime >= 0.0f && m_SectionHeadTime <= 0.2f)
            {
                m_Elements[7].Color.A = FMath::Lerp<float>(1.0f, 0.75f, alpha);
            }
            else if (m_SectionHeadTime >= 0.6f && m_SectionHeadTime <= 0.8f)
            {
                m_Elements[7].Color.A = FMath::Lerp<float>(0.75f, 0.5f, alpha);
            }
            else if (m_SectionHeadTime >= 1.2f && m_SectionHeadTime <= 1.4f)
            {
                m_Elements[7].Color.A = FMath::Lerp<float>(0.5f, 1.0f, alpha);
            }


            if (m_SectionHeadTime >= 0.6f && m_SectionHeadTime <= 0.8f)
            {
                FMatrix2x2 scale(FMath::Lerp<float>(1.0f, 0.5f, alpha));
                FMatrix2x2 rot(FQuat2D(FMath::DegreesToRadians(45.0f)));

                m_Elements[7].Transform = FTransform2D(scale.Concatenate(rot));
            }
            else if (m_SectionHeadTime >= 1.2f && m_SectionHeadTime <= 1.4f)
            {
                FMatrix2x2 scale(FMath::Lerp<float>(0.5f, 1.0f, alpha));
                FMatrix2x2 rot(FQuat2D(FMath::DegreesToRadians(45.0f)));

                m_Elements[7].Transform = FTransform2D(scale.Concatenate(rot));
            }
        }
    }


private:

    TSharedPtr<FSlateBrush> m_BackgroundBrush;  // �w�i
    TSharedPtr<FSlateBrush> m_IconElementBrush; // ���[�f�B���A�C�R�����\�������`

    // ���[�f�B���A�C�R�����\�������`
    struct LoadingIconShape
    {
        FTransform2D Transform;
        FLinearColor Color;
    };

    LoadingIconShape m_Elements[8];

    float       m_CurrentTime     = 0.0f; // ���݂̃A�j���[�V�����̌o�ߎ���
    float       m_SectionHeadTime = 0.0f; // ��Ԃ̊J�n����
    float       m_SectionEndTime  = 0.2f; // ��Ԃ̏I������
    const float m_TotalAnimTime   = 1.6f; // �A�j���[�V�����P���[�v�ɂ����鎞��
};




LOADINGSCREEN_API
class FLoadingScreenModule : public ILoadingScreenModule
{
public:

    virtual void StartupModule() override
    {
        if (IsMoviePlayerEnabled())
        {
            CreateScreen();
        }
    }

    virtual bool IsGameModule() const override
    {
        return true;
    }

    virtual void StartInGameLoadingScreen(bool bPlayUntilStopped, float PlayTime) override
    {
        FLoadingScreenAttributes LoadingScreen;
        {
            LoadingScreen.bAutoCompleteWhenLoadingCompletes = !bPlayUntilStopped;  
            LoadingScreen.bWaitForManualStop                = bPlayUntilStopped;   
            LoadingScreen.MinimumLoadingScreenDisplayTime   = PlayTime;            
            LoadingScreen.bAllowEngineTick                  = true;            
            LoadingScreen.WidgetLoadingScreen               = SNew(SLoadingScreen);
        }

        GetMoviePlayer()->SetupLoadingScreen(LoadingScreen);
    }

    virtual void StopInGameLoadingScreen() override
    {
        GetMoviePlayer()->StopMovie();
    }

    virtual void CreateScreen()
    {
        FLoadingScreenAttributes LoadingScreen;
    }

};

IMPLEMENT_GAME_MODULE(FLoadingScreenModule, LoadingScreen);

