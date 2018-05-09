object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Test VDS System'
  ClientHeight = 231
  ClientWidth = 683
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button2: TButton
    Left = 8
    Top = 0
    Width = 81
    Height = 25
    Caption = 'List Build'
    TabOrder = 0
    OnClick = ListBuilder
  end
  object Button3: TButton
    Left = 95
    Top = 0
    Width = 81
    Height = 25
    Caption = 'Circle Build'
    TabOrder = 1
  end
  object Button4: TButton
    Left = 182
    Top = 0
    Width = 81
    Height = 25
    Caption = 'Tree Build'
    TabOrder = 2
  end
  object Button5: TButton
    Left = 269
    Top = 0
    Width = 81
    Height = 25
    Caption = 'Bad Pointer'
    TabOrder = 3
  end
  object Button6: TButton
    Left = 600
    Top = 0
    Width = 81
    Height = 25
    Caption = 'Exit'
    TabOrder = 4
    OnClick = Closer
  end
  object Memo1: TMemo
    Left = 8
    Top = 32
    Width = 665
    Height = 193
    Lines.Strings = (
      'Program has started')
    TabOrder = 5
  end
  object ViewBox: TCheckBox
    Left = 360
    Top = 0
    Width = 153
    Height = 25
    Caption = 'View Immediately'
    TabOrder = 6
  end
  object MainMenu1: TMainMenu
    Left = 520
    object File1: TMenuItem
      Caption = '&File'
      object Saveconsole1: TMenuItem
        Caption = '&Save console'
        OnClick = Saver
      end
      object Clear1: TMenuItem
        Caption = '&Clear'
        OnClick = Clarify
      end
      object Exit1: TMenuItem
        Caption = '&Exit'
        OnClick = Closer
      end
    end
    object ests1: TMenuItem
      Caption = '&Tests'
    end
    object Memory1: TMenuItem
      Caption = '&Memory'
    end
    object Help1: TMenuItem
      Caption = '&Help'
      object About1: TMenuItem
        Caption = '&About'
      end
    end
  end
  object SaveDialog1: TSaveDialog
    Left = 568
    Top = 65528
  end
end
