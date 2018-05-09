object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'X3D Tester'
  ClientHeight = 352
  ClientWidth = 546
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
  object Button1: TButton
    Left = 0
    Top = 0
    Width = 97
    Height = 49
    Caption = 'Block Test'
    TabOrder = 0
    OnClick = BlockTest
  end
  object Button2: TButton
    Left = 103
    Top = 0
    Width = 97
    Height = 49
    Caption = 'Block Align Test'
    TabOrder = 1
    OnClick = Aligner
  end
  object Button3: TButton
    Left = 0
    Top = 55
    Width = 97
    Height = 49
    Caption = 'Memory Test'
    TabOrder = 2
    OnClick = MemoryGroup
  end
  object Button4: TButton
    Left = 103
    Top = 55
    Width = 97
    Height = 49
    Caption = 'Containment'
    TabOrder = 3
    OnClick = Contain
  end
  object Button5: TButton
    Left = 400
    Top = 48
    Width = 97
    Height = 49
    Caption = 'Exit'
    TabOrder = 4
    OnClick = Closer
  end
  object Memo1: TMemo
    Left = 8
    Top = 112
    Width = 537
    Height = 241
    Lines.Strings = (
      'The program has started')
    TabOrder = 5
  end
  object MainMenu1: TMainMenu
    Left = 304
    object File1: TMenuItem
      Caption = '&File'
      object Saveconsole1: TMenuItem
        Caption = '&Save console'
        OnClick = SaveConsole
      end
      object Clear1: TMenuItem
        Caption = '&Clear'
        OnClick = Clarify
      end
      object Exit1: TMenuItem
        Caption = '&Exit'
      end
    end
    object ests1: TMenuItem
      Caption = '&Tests'
      object Simple1: TMenuItem
        Caption = '&Simple'
        OnClick = Test1
      end
      object Solids1: TMenuItem
        Caption = '&Solids'
        OnClick = Solids1Click
      end
      object Scene1: TMenuItem
        Caption = '&Scene'
        OnClick = Scene1Click
      end
      object Group1: TMenuItem
        Caption = '&Group'
        OnClick = Groupie
      end
      object Block1: TMenuItem
        Caption = '&Block'
        OnClick = BlockTest
      end
    end
    object Memory1: TMenuItem
      Caption = '&Memory'
      object First1: TMenuItem
        Caption = '&First'
      end
      object Second1: TMenuItem
        Caption = '&Second'
      end
    end
    object About1: TMenuItem
      Caption = '&Help'
      object About2: TMenuItem
        Caption = '&About'
      end
    end
  end
  object SaveDialog1: TSaveDialog
    Left = 240
  end
end
