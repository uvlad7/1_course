object Form1: TForm1
  Left = 154
  Top = 89
  Width = 870
  Height = 640
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 136
    Top = 160
    Width = 24
    Height = 13
    Caption = 'Input'
  end
  object Label2: TLabel
    Left = 595
    Top = 218
    Width = 39
    Height = 13
    Caption = '----------->'
  end
  object Label3: TLabel
    Left = 597
    Top = 207
    Width = 2
    Height = 13
    Caption = '|'
  end
  object Label4: TLabel
    Left = 810
    Top = 207
    Width = 2
    Height = 13
    Caption = '|'
  end
  object Label5: TLabel
    Left = 779
    Top = 218
    Width = 33
    Height = 13
    Caption = '<---------'
  end
  object btLongMul: TButton
    Left = 238
    Top = 55
    Width = 75
    Height = 25
    Caption = 'LongMul'
    TabOrder = 0
    OnClick = btLongMulClick
  end
  object Edit1: TEdit
    Left = 238
    Top = 88
    Width = 345
    Height = 21
    TabOrder = 1
    Text = 'Edit1'
  end
  object btSum: TButton
    Left = 272
    Top = 176
    Width = 75
    Height = 25
    Caption = #1057#1091#1084#1084#1072
    TabOrder = 2
    OnClick = btSumClick
  end
  object edSum: TEdit
    Left = 360
    Top = 176
    Width = 161
    Height = 21
    TabOrder = 3
  end
  object edSumIn: TEdit
    Left = 128
    Top = 176
    Width = 121
    Height = 21
    TabOrder = 4
    Text = '5'
  end
  object btLenPlatform: TButton
    Left = 128
    Top = 240
    Width = 113
    Height = 25
    Caption = #1044#1083#1080#1085#1072' '#1087#1083#1086#1097#1072#1076#1082#1080
    TabOrder = 5
    OnClick = btLenPlatformClick
  end
  object edLenPlatform: TEdit
    Left = 256
    Top = 240
    Width = 265
    Height = 21
    TabOrder = 6
  end
  object btSumArr: TButton
    Left = 128
    Top = 280
    Width = 113
    Height = 25
    Caption = #1057#1091#1084#1084#1072' '#1101#1083'. '#1084#1072#1089#1089#1080#1074#1072
    TabOrder = 7
    OnClick = btSumArrClick
  end
  object edSumArr: TEdit
    Left = 256
    Top = 280
    Width = 265
    Height = 21
    TabOrder = 8
  end
  object btPower: TButton
    Left = 128
    Top = 328
    Width = 113
    Height = 25
    Caption = 'a**n'
    TabOrder = 9
    OnClick = btPowerClick
  end
  object edPower: TEdit
    Left = 256
    Top = 328
    Width = 265
    Height = 21
    TabOrder = 10
  end
  object Button2: TButton
    Left = 155
    Top = 392
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 11
    OnClick = Button2Click
  end
  object btSkipBlanks: TButton
    Left = 55
    Top = 437
    Width = 175
    Height = 25
    Caption = #1055#1088#1086#1087#1091#1089#1082' '#1087#1088#1086#1073#1077#1083#1086#1074' '#1087#1077#1088#1077#1076' '#1089#1083#1086#1074#1086#1084
    TabOrder = 12
    OnClick = btSkipBlanksClick
  end
  object Edit2: TEdit
    Left = 232
    Top = 440
    Width = 121
    Height = 21
    TabOrder = 13
    Text = 'Edit2'
  end
  object Button4: TButton
    Left = 8
    Top = 488
    Width = 75
    Height = 25
    Caption = 'Button4'
    TabOrder = 14
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 96
    Top = 488
    Width = 75
    Height = 25
    Caption = 'Button5'
    TabOrder = 15
    OnClick = Button5Click
  end
  object btCnm: TButton
    Left = 440
    Top = 520
    Width = 75
    Height = 25
    Caption = 'C(n,m)'
    TabOrder = 16
    OnClick = btCnmClick
  end
  object btCnmInCpp: TButton
    Left = 581
    Top = 520
    Width = 75
    Height = 25
    Caption = 'C(n,m) '#1080' '#1057'++'
    TabOrder = 17
    OnClick = btCnmInCppClick
  end
  object edCnmInCpp: TEdit
    Left = 581
    Top = 552
    Width = 121
    Height = 21
    TabOrder = 18
  end
  object edCnm: TEdit
    Left = 440
    Top = 552
    Width = 121
    Height = 21
    TabOrder = 19
  end
  object edN: TEdit
    Left = 480
    Top = 480
    Width = 65
    Height = 21
    TabOrder = 20
    Text = '5'
  end
  object edM: TEdit
    Left = 568
    Top = 480
    Width = 65
    Height = 21
    TabOrder = 21
    Text = '2'
  end
  object btCnmInCppF: TButton
    Left = 720
    Top = 520
    Width = 121
    Height = 25
    Caption = 'C(n,m) '#1080' '#1057'++ double'
    TabOrder = 22
    OnClick = btCnmInCppFClick
  end
  object edCnmInCppF: TEdit
    Left = 720
    Top = 552
    Width = 121
    Height = 21
    TabOrder = 23
  end
  object Button6: TButton
    Left = 720
    Top = 432
    Width = 75
    Height = 25
    Caption = 'Button6'
    TabOrder = 24
    OnClick = Button6Click
  end
  object Edit3: TEdit
    Left = 720
    Top = 472
    Width = 121
    Height = 21
    TabOrder = 25
    Text = 'Edit3'
  end
  object btCnmU: TButton
    Left = 280
    Top = 520
    Width = 121
    Height = 25
    Caption = 'C(n,m) '#1073#1077#1079#1079#1085#1072#1082#1086#1074#1086#1077
    TabOrder = 26
    OnClick = btCnmUClick
  end
  object edCnmU: TEdit
    Left = 280
    Top = 552
    Width = 121
    Height = 21
    TabOrder = 27
  end
  object btString: TButton
    Left = 616
    Top = 48
    Width = 145
    Height = 25
    Caption = #1057#1090#1088#1086#1082#1086#1074#1099#1077' '#1082#1086#1084#1072#1085#1076#1099
    TabOrder = 28
    OnClick = btStringClick
  end
  object btScasb: TButton
    Left = 616
    Top = 88
    Width = 75
    Height = 25
    Caption = 'scasb'
    TabOrder = 29
    OnClick = btScasbClick
  end
  object btMultDiv: TButton
    Left = 578
    Top = 176
    Width = 121
    Height = 25
    Caption = #1058#1077#1089#1090'. '#1091#1084#1085#1086#1078' '#1080' '#1076#1077#1083
    TabOrder = 30
    OnClick = btMultDivClick
  end
  object edMult: TEdit
    Left = 635
    Top = 216
    Width = 143
    Height = 21
    TabOrder = 31
  end
  object Button8: TButton
    Left = 656
    Top = 279
    Width = 121
    Height = 25
    Caption = 'Button8'
    TabOrder = 32
    OnClick = Button8Click
  end
  object Edit5: TEdit
    Left = 656
    Top = 319
    Width = 121
    Height = 21
    TabOrder = 33
  end
  object Button9: TButton
    Left = 656
    Top = 359
    Width = 121
    Height = 25
    Caption = 'Button9'
    TabOrder = 34
    OnClick = Button9Click
  end
  object Edit6: TEdit
    Left = 656
    Top = 399
    Width = 121
    Height = 21
    TabOrder = 35
    Text = 'Edit6'
  end
  object btDivOverflow: TButton
    Left = 24
    Top = 528
    Width = 169
    Height = 25
    Caption = #1055#1077#1088#1077#1087#1086#1083#1085#1077#1085#1080#1077' '#1087#1088#1080' '#1076#1077#1083#1077#1085#1080#1080
    TabOrder = 36
    OnClick = btDivOverflowClick
  end
  object edDivOverflow: TEdit
    Left = 24
    Top = 568
    Width = 121
    Height = 21
    TabOrder = 37
  end
  object btLongMul64: TButton
    Left = 342
    Top = 55
    Width = 75
    Height = 25
    Caption = 'LongMul64'
    TabOrder = 38
    OnClick = btLongMul64Click
  end
  object btSumArr2: TButton
    Left = 3
    Top = 279
    Width = 121
    Height = 25
    Caption = #1057#1091#1084#1084#1072' '#1101#1083'. '#1084#1072#1089#1089#1080#1074#1072' 2'
    TabOrder = 39
    OnClick = btSumArr2Click
  end
  object btFMultInt: TButton
    Left = 726
    Top = 176
    Width = 121
    Height = 25
    Caption = #1058#1077#1089#1090' '#1091#1084#1085'. int'
    TabOrder = 40
    OnClick = btFMultIntClick
  end
  object edX: TEdit
    Left = 576
    Top = 147
    Width = 92
    Height = 21
    TabOrder = 41
    Text = '0xFFFFFFFF'
  end
  object edY: TEdit
    Left = 728
    Top = 116
    Width = 92
    Height = 21
    TabOrder = 42
    Text = '0xFFFFFFF'
  end
  object edOverflowMultInt: TEdit
    Left = 635
    Top = 242
    Width = 143
    Height = 21
    TabOrder = 43
  end
  object btFMultInt64: TButton
    Left = 726
    Top = 145
    Width = 121
    Height = 25
    Caption = #1058#1077#1089#1090' '#1091#1084#1085'. __int64'
    TabOrder = 44
    OnClick = btFMultInt64Click
  end
end
