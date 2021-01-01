object Form1: TForm1
  Left = 504
  Top = 230
  Width = 1072
  Height = 658
  Caption = 'ping pong by Adam'
  Color = clBtnFace
  UseDockManager = True
  DockSite = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnKeyUp = FormKeyUp
  PixelsPerInch = 96
  TextHeight = 13
  object background1: TShape
    Left = 0
    Top = 37
    Width = 1056
    Height = 582
    Align = alClient
    Brush.Color = clSilver
    Enabled = False
  end
  object ImageBall: TImage
    Left = 184
    Top = 145
    Width = 32
    Height = 32
    AutoSize = True
    Transparent = True
  end
  object imagePallete1: TImage
    Left = 40
    Top = 216
    Width = 20
    Height = 200
    AutoSize = True
  end
  object imagePallete2: TImage
    Left = 1000
    Top = 216
    Width = 20
    Height = 200
    AutoSize = True
  end
  object countInfo: TLabel
    Left = 448
    Top = 80
    Width = 11
    Height = 46
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -40
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    Transparent = True
    Visible = False
  end
  object LabelNumberOfHits: TLabel
    Left = 384
    Top = 312
    Width = 9
    Height = 37
    Color = clBackground
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object LabelCurrentResult: TLabel
    Left = 0
    Top = 0
    Width = 1056
    Height = 37
    Align = alTop
    Alignment = taCenter
    Color = clSkyBlue
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentColor = False
    ParentFont = False
    Visible = False
  end
  object LabelInfo: TLabel
    Left = 280
    Top = 128
    Width = 561
    Height = 65
    Alignment = taCenter
    AutoSize = False
    Caption = 'Zagrajmy w ping ponga!'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -40
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
  end
  object SpeedInfo: TLabel
    Left = 464
    Top = 96
    Width = 6
    Height = 29
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object Button1: TButton
    Left = 416
    Top = 480
    Width = 193
    Height = 65
    Cursor = crHandPoint
    Caption = 'Nowa gra'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ModalResult = 1
    ParentFont = False
    ParentShowHint = False
    ShowHint = False
    TabOrder = 0
    OnClick = FormCreate
  end
  object Button2: TButton
    Left = 416
    Top = 400
    Width = 193
    Height = 65
    Cursor = crHandPoint
    Caption = 'Kontynuuj'
    Default = True
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -32
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 1
    Visible = False
    OnClick = FormCreate
  end
  object MediaPlayer1: TMediaPlayer
    Left = 176
    Top = 576
    Width = 253
    Height = 30
    Visible = False
    TabOrder = 2
  end
  object TimerBall: TTimer
    Enabled = False
    Interval = 15
    OnTimer = TimerBallTimer
    Left = 456
    Top = 24
  end
  object up: TTimer
    Enabled = False
    Interval = 20
    OnTimer = upTimer
    Left = 16
    Top = 40
  end
  object down: TTimer
    Enabled = False
    Interval = 20
    OnTimer = downTimer
    Left = 48
    Top = 40
  end
  object up2: TTimer
    Enabled = False
    Interval = 20
    OnTimer = up2Timer
    Left = 992
    Top = 48
  end
  object down2: TTimer
    Enabled = False
    Interval = 20
    OnTimer = down2Timer
    Left = 1032
    Top = 48
  end
  object TimerSpeedingBall: TTimer
    Enabled = False
    Interval = 3000
    OnTimer = TimerSpeedingBallTimer
    Left = 784
    Top = 80
  end
  object boostHit: TTimer
    Enabled = False
    Interval = 10
    OnTimer = boostHitTimer
    Left = 544
    Top = 224
  end
  object randomNormalHit: TTimer
    Enabled = False
    Interval = 10
    OnTimer = randomNormalHitTimer
    Left = 320
    Top = 80
  end
end
