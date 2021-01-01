//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Player.cpp"
#include "mmsystem.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x,y;
const int startBallPositionX = 500;
const int startBallPositionY = 200;
const int startPallete1PositionX = 40;
const int startPallete2PositionX = 1000;
const int startPallete12PositionY = 216;
const int pointsToWin = 6;
const int maxSpeed = 20;
const int maximumAmountOfBoostedHitsFromPallete = 2;
const int maximumSpeedOfBall = 20;
const int minimumSpeedOfBall = 8;
const int minimumSpeedOfPallete1 = 20;
const int minimumSpeedOfPallete2 = 20;

bool reflectedOnPallete1 = false;
bool reflectedOnPallete2 = true;
bool hitFirstTime = true;

int speedMoveOfPallete1= minimumSpeedOfPallete1, speedMoveOfPallete2 =minimumSpeedOfPallete2 ;

Player* player1 = new Player;
Player* player2 = new Player;

bool gameStarted = false;
bool strike = false;

bool ballReflectionFromPallete(TImage *ball, TImage *pallete) {
    if(ball->Left  <= pallete->Left + pallete->Width
            && ball->Left >= pallete->Left - ball->Width
            && ball->Top >= pallete->Top  - ball->Height
            && ball->Top  <= pallete->Top + pallete->Height ) {
        return 1;
    } else
        return 0;
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner) {
    AnsiString welcome = "Witaj w grze pingponga!";
    AnsiString control = "Lewy gracz steruje wciskajac klawisze A oraz Z. Prawy gracz steruje wciskajac strzalki do gory i w dol.";
    AnsiString rules = "Im dluzej odbijasz tym pilka szybciej sie przemiesza.Aby wygrac nalezy zdobyc 6 pkt.\nKazde 2 zdobyte punkty powoduja, ze paletka staje sie krotsza i szybsza w celu urozmaicenia gry.";
    AnsiString rules2 = "Wcisnij spacje aby uderzyc w pilke i poslac ja duzo szybciej to przeciwnika!" ;
    ShowMessage(welcome+"\n\n"+control+"\n\n"+rules+"\n"+rules2);
    PlaySound("soundHi", HInstance, SND_RESOURCE | SND_ASYNC);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerBallTimer(TObject *Sender) {
    SpeedInfo->Caption ="Speed: " + IntToStr(abs(x)) + "0km/h";
    ImageBall->Left += x;
    ImageBall->Top += y;
    //odbij od gornej sciany odbicie od dolnej sciany
    if(ImageBall->Top <= background1->Top || ImageBall->Top  - ImageBall->Height >= background1->Height - 64)
        y = -y;
    //odbicie od lewej palety
    if(ballReflectionFromPallete(ImageBall, imagePallete1) && (reflectedOnPallete2 || hitFirstTime)) {
        x = -x ;
        player2->addHit(1);
        reflectedOnPallete1 = true;
        reflectedOnPallete2 = false;
        hitFirstTime = false;
        PlaySound("soundPlay", HInstance, SND_RESOURCE | SND_ASYNC);
        if(strike)
            randomNormalHit->Enabled = true;
    }
    //odbicie od prawej palety
    if(ballReflectionFromPallete(ImageBall, imagePallete2) && (reflectedOnPallete1 || hitFirstTime) ) {
        x = -x ;
        player1->addHit(1);
        reflectedOnPallete1 = false;
        reflectedOnPallete2 = true;
        hitFirstTime = false;
        PlaySound("soundPlay", HInstance, SND_RESOURCE | SND_ASYNC);
        if(strike)
            randomNormalHit->Enabled = true;
    }
    //odbicie od prawej sciany lub lewej sciany-
    if(ImageBall->Left + ImageBall->Width >= background1->Width || ImageBall->Left - 5 <= background1->Left ) {
        if (player2->getAmountOfHits() > player1->getAmountOfHits()) {
            player2->addPoints(1);
            LabelInfo->Caption = "Punkt Dla Gracza (Prawego) > " ;
        } else {
            player1->addPoints(1);
            LabelInfo->Caption = "< Punkt Dla Gracza (Lewego)" ;
        }
        TimerBall->Enabled = false;
        ImageBall->Visible = false;
        Button1->Visible = true;
        Button2->Visible = true;
        LabelNumberOfHits->Caption = "Amount of Hits: " + IntToStr(player1->getAmountOfHits() + player2->getAmountOfHits());
        LabelNumberOfHits->Visible = true;
        LabelInfo->Visible = true;
        LabelCurrentResult->Caption = "Wynik: " +  IntToStr(player1->getPoints()) + ":" + IntToStr(player2->getPoints());
        player1->setAmountOfHits(0);
        player2->setAmountOfHits(0);
       PlaySound("soundAlert", HInstance, SND_RESOURCE | SND_ASYNC);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::upTimer(TObject *Sender) {
    if(imagePallete1->Top - 10>= background1->Top)
        imagePallete1->Top -= speedMoveOfPallete1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
                                    TShiftState Shift) {
    if(Key == VK_UP)
        up2->Enabled = true;
    if(Key == VK_DOWN)
        down2->Enabled = true;
    if(Key == 65)
        up->Enabled = true;
    if(Key == 90)
        down->Enabled = true;
    if(Key == 32) {
        boostHit->Enabled = true;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::downTimer(TObject *Sender) {
    if(imagePallete1->Top + imagePallete1->Height  <= background1->Height)
        imagePallete1->Top += speedMoveOfPallete1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
                                  TShiftState Shift) {

    if(Key == VK_UP)
        up2->Enabled = false;
    if(Key == VK_DOWN)
        down2->Enabled = false;
    if(Key == 65)
        up->Enabled = false;
    if(Key == 90)
        down->Enabled = false;
    if(Key == 32) {
        boostHit->Enabled = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::up2Timer(TObject *Sender) {
    if(imagePallete2->Top - 10>= background1->Top)
        imagePallete2->Top -= speedMoveOfPallete2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::down2Timer(TObject *Sender) {
    if(imagePallete2->Top + imagePallete2->Height  <= background1->Height)
        imagePallete2->Top += speedMoveOfPallete2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender) {

    LabelNumberOfHits->Visible = false;
    hitFirstTime = true;
    Randomize();
    int randNum = rand()%2;
    if(randNum == 1) {
        x=-minimumSpeedOfBall;
        y=-minimumSpeedOfBall;
    } else {
        x=-minimumSpeedOfBall;
        y=-minimumSpeedOfBall;
    }
    //Button1 - start new game
    if (Sender == Button1) {
        if(!Button1->ModalResult) {
            if(Application->MessageBox("Czy na pewno chcesz zaczac od nowa?","Potwierdz",MB_YESNO) == 6 )  {
                strike=false;
                //amountOFHits = 0;
                player1->setAmountOfHits(0);
                player2->setAmountOfHits(0);
                speedMoveOfPallete1 = minimumSpeedOfPallete1;
                speedMoveOfPallete2 = minimumSpeedOfPallete2;
                player1->setPoints(0);
                player2->setPoints(0);
                LabelCurrentResult->Caption = "";
                LabelInfo->Visible = false;
                gameStarted = true;
            } else
                gameStarted = false;
        } else {
            LabelCurrentResult->Caption = "";
            LabelInfo->Visible = false;
            gameStarted = true;
            Button1->ModalResult = 0;
        }
    } else if (Sender == Button2) {
        LabelInfo->Visible = false;
        gameStarted= true;
    }
    LabelCurrentResult->Visible =  true;
    ImageBall->Top = startBallPositionY;
    ImageBall->Left = startBallPositionX;
    imagePallete1->Left = startPallete1PositionX;
    imagePallete1->Top = startPallete12PositionY;
    imagePallete2->Left = startPallete2PositionX;
    imagePallete2->Top = startPallete12PositionY;
    countInfo->Left = startBallPositionX;
    if(player1->getPoints() == pointsToWin || player2->getPoints() == pointsToWin) {
        gameStarted = false;
        Button2->Visible = false;
        LabelInfo->Font->Size = 24;
        if (player1->getPoints() > player2->getPoints())
            LabelInfo->Caption = "Wygral Gracz po lewej Stronie!";
        else
            LabelInfo->Caption = "Wygral Gracz po prawej Stronie!" ;
        LabelInfo->Visible = true;
        PlaySound("soundWon", HInstance, SND_RESOURCE | SND_ASYNC);
    }
    ImageBall->Visible = true;
    //Start game
    if(gameStarted) {
        countInfo->Visible = false;
        TimerBall->Enabled = true;
        TimerSpeedingBall->Enabled = true;
        Button1->Visible = false;
        Button2->Visible = false;
    }
    //depending on gathered points load shorten palletes
    AnsiString scopeLeftPoints, scopeRightPoints;
    if(player1->getPoints() <=2)
        scopeLeftPoints = "012";
    else if (player1->getPoints() == 3) {
        scopeLeftPoints = "3";
        speedMoveOfPallete1 = 40;
    } else {
        scopeLeftPoints = "45";
        speedMoveOfPallete1 = 50;
    }

    if(player2->getPoints() <=2)
        scopeRightPoints = "012";
    else if (player2->getPoints() == 3) {
        scopeRightPoints = "3";
        speedMoveOfPallete2 = 40;
    } else {
        scopeRightPoints = "45";
        speedMoveOfPallete2 = 50;
    }
    //depend on time playing fasten speed of ball
    ImageBall->Picture->Bitmap->LoadFromResourceName((int)HInstance,"ball");
    imagePallete1->Picture->Bitmap->LoadFromResourceName((int)HInstance,"paddle"+scopeLeftPoints);
    imagePallete2->Picture->Bitmap->LoadFromResourceName((int)HInstance,"paddle"+ scopeRightPoints);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::TimerSpeedingBallTimer(TObject *Sender) {
    if((x > 0 && x < maximumSpeedOfBall) && (y > 0 && y < maximumSpeedOfBall)) {
        x++;
        y++;
    }
    if (x == maxSpeed || y == maxSpeed) {
        TimerSpeedingBall->Enabled = false;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::boostHitTimer(TObject *Sender) {

    if( ballReflectionFromPallete(ImageBall, imagePallete1)
            || ballReflectionFromPallete(ImageBall, imagePallete2) ) {
        strike = true;
        if(x>0 && x < maximumSpeedOfBall && y > 0 && y < maximumSpeedOfBall) {
            x= maximumSpeedOfBall;
            y= maximumSpeedOfBall;
        } else if(x>0 && x < maximumSpeedOfBall && y < 0 && y > -maximumSpeedOfBall) {
            x= maximumSpeedOfBall;
            y= -maximumSpeedOfBall;
        } else if(x < 0 && x > -maximumSpeedOfBall && y > 0 && y < maximumSpeedOfBall) {
            x = -maximumSpeedOfBall;
            y = maximumSpeedOfBall;
        } else if  (x < 0 && x > -maximumSpeedOfBall  && y < 0 && y > -maximumSpeedOfBall) {
            x = -maximumSpeedOfBall;
            y = -maximumSpeedOfBall;
        }
    }
}
//---------------------------------------------------------------------------
//powtorzenie kodu - bardzo podobne funkcje - zastanowic sie
void __fastcall TForm1::randomNormalHitTimer(TObject *Sender) {
    Randomize();
    const int maxValue = maximumSpeedOfBall - 2;
    const int minValue = minimumSpeedOfBall + 2;
    int range =  maxValue - minValue;
    int randomSpeed = rand() % range + minValue;
    strike = false;
    if(x>0 && x <= maximumSpeedOfBall && y > 0 && y <= maximumSpeedOfBall) {
        x = randomSpeed;
        y= randomSpeed;
    } else if(x>0 && x <= maximumSpeedOfBall && y < 0 && y >= -maximumSpeedOfBall) {
        x= randomSpeed;
        y= -randomSpeed;
    } else if(x < 0 && x >= -maximumSpeedOfBall && y > 0 && y <= maximumSpeedOfBall) {
        x = -randomSpeed;
        y = randomSpeed;
    } else if  (x < 0 && x >= -maximumSpeedOfBall  && y < 0 && y >= -maximumSpeedOfBall) {
        x = -randomSpeed;
        y = -randomSpeed;
    }
    randomNormalHit->Enabled = false;
}
//---------------------------------------------------------------------------

