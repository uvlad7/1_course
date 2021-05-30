object Form1: TForm1
  Left = 214
  Top = 107
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
  object Button1: TButton
    Left = 232
    Top = 144
    Width = 75
    Height = 25
    Caption = 'DoTotal'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 352
    Top = 144
    Width = 75
    Height = 25
    Caption = 'Button2'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Edit1: TEdit
    Left = 352
    Top = 192
    Width = 121
    Height = 21
    TabOrder = 2
    Text = 'Edit1'
  end
  object btSumArr: TButton
    Left = 520
    Top = 144
    Width = 75
    Height = 25
    Caption = 'SumArr'
    TabOrder = 3
    OnClick = btSumArrClick
  end
  object edSumArr: TEdit
    Left = 520
    Top = 192
    Width = 121
    Height = 21
    TabOrder = 4
  end
  object btSumArrStdCall: TButton
    Left = 232
    Top = 272
    Width = 81
    Height = 25
    Caption = 'SumArrStdCall'
    TabOrder = 5
    OnClick = btSumArrStdCallClick
  end
  object edSumArrStdCall: TEdit
    Left = 232
    Top = 320
    Width = 121
    Height = 21
    TabOrder = 6
  end
  object btSumArrFastCall: TButton
    Left = 416
    Top = 272
    Width = 89
    Height = 25
    Caption = 'SumArrFastCall'
    TabOrder = 7
    OnClick = btSumArrFastCallClick
  end
  object edSumArrFastCall: TEdit
    Left = 416
    Top = 320
    Width = 121
    Height = 21
    TabOrder = 8
  end
  object btSumArrPascal: TButton
    Left = 600
    Top = 272
    Width = 105
    Height = 25
    Caption = 'SUMARRPASCAL'
    TabOrder = 9
    OnClick = btSumArrPascalClick
  end
  object edSumArrPascal: TEdit
    Left = 600
    Top = 320
    Width = 121
    Height = 21
    TabOrder = 10
  end
end
