//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
#include <MPlayer.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *background1;
        TImage *ImageBall;
        TImage *imagePallete1;
        TImage *imagePallete2;
        TTimer *TimerBall;
        TTimer *up;
        TTimer *down;
        TTimer *up2;
        TTimer *down2;
        TButton *Button1;
        TLabel *countInfo;
        TButton *Button2;
        TLabel *LabelNumberOfHits;
        TLabel *LabelCurrentResult;
        TLabel *LabelInfo;
        TTimer *TimerSpeedingBall;
        TLabel *SpeedInfo;
        TTimer *boostHit;
        TMediaPlayer *MediaPlayer1;
        TTimer *randomNormalHit;
        void __fastcall TimerBallTimer(TObject *Sender);
        void __fastcall upTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall downTimer(TObject *Sender);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall up2Timer(TObject *Sender);
        void __fastcall down2Timer(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall TimerSpeedingBallTimer(TObject *Sender);
        void __fastcall boostHitTimer(TObject *Sender);
        void __fastcall randomNormalHitTimer(TObject *Sender);
        

private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
       
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
