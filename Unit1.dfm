object TForm1: TTForm1
  Left = 0
  Top = 0
  Caption = #1086#1087#1088#1077#1076#1077#1083#1080#1090#1077#1083#1100' '#1087#1088#1086#1087#1091#1089#1082#1085#1086#1081' '#1089#1087#1086#1089#1086#1073#1085#1086#1089#1090#1080' '#1085#1072' '#1087#1077#1088#1077#1075#1086#1085#1077
  ClientHeight = 575
  ClientWidth = 598
  Color = clBtnFace
  Font.Charset = RUSSIAN_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Tahoma'
  Font.Style = []
  Position = poDesigned
  TextHeight = 14
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 598
    Height = 575
    Cursor = crHandPoint
    ActivePage = SrcData
    Align = alClient
    TabOrder = 0
    ExplicitWidth = 588
    ExplicitHeight = 557
    object SrcData: TTabSheet
      Caption = #1048#1089#1093#1086#1076#1085#1099#1077' '#1076#1072#1085#1085#1099#1077
      DesignSize = (
        590
        546)
      object SrcAL: TStringGrid
        Left = 24
        Top = 311
        Width = 401
        Height = 73
        Hint = 'a - '#1088#1072#1089#1089#1090#1086#1103#1085#1080#1077' '#1084#1077#1078#1076#1091' '#1072#1074#1090#1086'; l - '#1101#1084#1087#1080#1088#1080#1095#1077#1089#1082#1080#1081' '#1082#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090
        Anchors = [akLeft, akTop, akRight]
        Color = clInfoBk
        ColCount = 2
        DefaultRowHeight = 18
        FixedColor = clActiveCaption
        RowCount = 3
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goRowSizing, goColSizing, goRowMoving, goColMoving, goEditing, goFixedRowDefAlign]
        ParentShowHint = False
        ScrollBars = ssHorizontal
        ShowHint = True
        TabOrder = 0
        OnDrawCell = SrcCDrawCell
        OnKeyPress = SrcCKeyPress
        OnSetEditText = SrcALSetEditText
        ExplicitWidth = 391
      end
      object SrcVsT: TStringGrid
        Left = 26
        Top = 423
        Width = 193
        Height = 41
        Color = clInfoBk
        ColCount = 3
        Ctl3D = True
        DefaultRowHeight = 18
        FixedColor = clActiveCaption
        FixedCols = 0
        RowCount = 2
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goFixedRowDefAlign]
        ParentCtl3D = False
        ParentShowHint = False
        ScrollBars = ssNone
        ShowHint = False
        TabOrder = 1
        OnDrawCell = SrcCDrawCell
        OnKeyPress = SrcCKeyPress
        OnSetEditText = SrcVsTSetEditText
        ColWidths = (
          64
          64
          64)
      end
      object SrcNKT: TStringGrid
        Left = 231
        Top = 423
        Width = 194
        Height = 41
        Hint = 
          'n - '#1095#1080#1089#1083#1086' '#1087#1086#1083#1086#1089' '#1076#1074#1080#1078#1077#1085#1080#1103'; k - '#1082#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090' '#1087#1083#1086#1090#1085#1086#1089#1090#1080'; t - '#1074#1088#1077#1084#1103' '#1087 +
          #1091#1090#1080
        Anchors = [akTop, akRight]
        Color = clInfoBk
        ColCount = 3
        DefaultRowHeight = 18
        FixedColor = clActiveCaption
        FixedCols = 0
        RowCount = 2
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing, goFixedRowDefAlign]
        ParentShowHint = False
        ScrollBars = ssNone
        ShowHint = True
        TabOrder = 2
        OnDrawCell = SrcCDrawCell
        OnKeyPress = SrcCKeyPress
        OnSetEditText = SrcNKTSetEditText
        ExplicitLeft = 221
      end
      object sbInfo: TStatusBar
        Left = 0
        Top = 511
        Width = 590
        Height = 35
        Panels = <>
        SimplePanel = True
        ExplicitTop = 493
        ExplicitWidth = 580
      end
      object Panel2: TPanel
        Left = 0
        Top = 0
        Width = 590
        Height = 30
        Align = alTop
        BevelInner = bvRaised
        BevelOuter = bvLowered
        ParentBackground = False
        TabOrder = 4
        ExplicitWidth = 580
        object dowload: TButton
          Left = 2
          Top = 2
          Width = 115
          Height = 26
          Cursor = crHandPoint
          Align = alLeft
          Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100'...'
          TabOrder = 0
          OnClick = dowloadClick
        end
        object bProc: TButton
          Left = 473
          Top = 2
          Width = 115
          Height = 26
          Cursor = crHandPoint
          Align = alRight
          Caption = #1054#1073#1088#1072#1073#1086#1090#1072#1090#1100
          TabOrder = 1
          OnClick = bProcClick
          ExplicitLeft = 463
        end
      end
      object Memo1: TMemo
        Left = 112
        Top = 543
        Width = 185
        Height = 1
        Lines.Strings = (
          'M'
          'e'
          'm'
          'o'
          '1')
        TabOrder = 5
      end
      object Panel3: TPanel
        Left = 24
        Top = 55
        Width = 505
        Height = 74
        BevelInner = bvRaised
        BevelOuter = bvLowered
        ParentBackground = False
        TabOrder = 6
        object AddColC: TButton
          Left = 0
          Top = 31
          Width = 113
          Height = 25
          Cursor = crHandPoint
          Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1089#1090#1086#1083#1073#1077#1094
          TabOrder = 0
          OnClick = AddColCClick
        end
        object bDelRangeCol: TButton
          Left = 119
          Top = 0
          Width = 113
          Height = 25
          Caption = #1059#1076#1072#1083#1080#1090#1100' '#1076#1080#1072#1087#1086#1079#1086#1085
          TabOrder = 1
          OnClick = bDelRangeColClick
        end
        object bInsCol: TButton
          Left = 0
          Top = 0
          Width = 113
          Height = 25
          Caption = #1042#1089#1090#1072#1074#1080#1090#1100' '#1089#1090#1086#1083#1073#1077#1094
          TabOrder = 2
          OnClick = bInsColClick
        end
        object cbColRangeSelect: TCheckBox
          Left = 0
          Top = 57
          Width = 193
          Height = 17
          Caption = #1042#1099#1076#1077#1083#1077#1085#1080#1077' '#1076#1080#1072#1087#1072#1079#1086#1085#1072
          TabOrder = 3
          OnClick = cbColRangeSelectClick
        end
        object ClearC: TButton
          Left = 387
          Top = 26
          Width = 113
          Height = 25
          Cursor = crHandPoint
          Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1090#1072#1073#1083#1080#1094#1091
          TabOrder = 4
          OnClick = ClearCClick
        end
        object DelColC: TButton
          Left = 119
          Top = 31
          Width = 113
          Height = 25
          Cursor = crHandPoint
          Caption = #1059#1076#1072#1083#1080#1090#1100' '#1089#1090#1086#1083#1073#1077#1094
          Enabled = False
          TabOrder = 5
          OnClick = DelColCClick
        end
        object bFontC: TButton
          Left = 238
          Top = 0
          Width = 75
          Height = 25
          Caption = #1064#1088#1080#1092#1090
          TabOrder = 6
          OnClick = bFontCClick
        end
      end
      object SrcC: TStringGrid
        Left = 24
        Top = 135
        Width = 401
        Height = 57
        Hint = 'C - '#1082#1086#1101#1092#1092#1080#1094#1080#1077#1085#1090' '#1090#1086#1088#1084#1086#1078#1077#1085#1080#1103
        Anchors = [akLeft, akTop, akRight]
        Color = clInfoBk
        ColCount = 2
        DefaultRowHeight = 18
        FixedColor = clActiveCaption
        RowCount = 2
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goDrawFocusSelected, goRowSizing, goColSizing, goRowMoving, goColMoving, goEditing, goTabs, goAlwaysShowEditor, goThumbTracking, goFixedColClick, goFixedRowClick, goFixedHotTrack, goFixedColDefAlign, goFixedRowDefAlign]
        ParentShowHint = False
        ScrollBars = ssNone
        ShowHint = True
        TabOrder = 7
        OnDrawCell = SrcCDrawCell
        OnKeyPress = SrcCKeyPress
        OnSetEditText = SrcCSetEditText
        ExplicitWidth = 391
        RowHeights = (
          18
          18)
      end
      object Panel4: TPanel
        Left = 24
        Top = 222
        Width = 505
        Height = 83
        ParentBackground = False
        TabOrder = 8
        object AddColAL: TButton
          Left = 0
          Top = 32
          Width = 113
          Height = 25
          Cursor = crHandPoint
          Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1089#1090#1086#1083#1073#1077#1094
          TabOrder = 0
          OnClick = AddColALClick
        end
        object bDelRangeColAL: TButton
          Left = 119
          Top = 0
          Width = 113
          Height = 25
          Caption = #1059#1076#1072#1083#1080#1090#1100' '#1076#1080#1072#1087#1086#1079#1086#1085
          TabOrder = 1
          OnClick = bDelRangeColALClick
        end
        object bInsCol2: TButton
          Left = 0
          Top = 1
          Width = 113
          Height = 25
          Caption = #1042#1089#1090#1072#1074#1080#1090#1100' '#1089#1090#1086#1083#1073#1077#1094
          TabOrder = 2
          OnClick = bInsCol2Click
        end
        object ClearAL: TButton
          Left = 387
          Top = 31
          Width = 113
          Height = 25
          Cursor = crHandPoint
          Caption = #1054#1095#1080#1089#1090#1080#1090#1100' '#1090#1072#1073#1083#1080#1094#1091
          TabOrder = 3
          OnClick = ClearALClick
        end
        object DelColAL: TButton
          Left = 119
          Top = 31
          Width = 113
          Height = 25
          Cursor = crHandPoint
          Caption = #1059#1076#1072#1083#1080#1090#1100' '#1089#1090#1086#1083#1073#1077#1094
          Enabled = False
          TabOrder = 4
          OnClick = DelColALClick
        end
        object cbColRangeSelectAL: TCheckBox
          Left = 0
          Top = 63
          Width = 153
          Height = 17
          Caption = #1042#1099#1076#1077#1083#1077#1085#1080#1077' '#1076#1080#1072#1087#1072#1079#1086#1085#1072
          TabOrder = 5
          OnClick = cbColRangeSelectALClick
        end
        object bFontAL: TButton
          Left = 238
          Top = 0
          Width = 75
          Height = 25
          Caption = #1064#1088#1080#1092#1090
          TabOrder = 6
          OnClick = bFontALClick
        end
      end
    end
    object ResPage: TTabSheet
      Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090#1099
      ImageIndex = 1
      object Splitter1: TSplitter
        Left = 0
        Top = 241
        Width = 590
        Height = 5
        Cursor = crVSplit
        Align = alTop
        AutoSnap = False
        Color = clBtnFace
        MinSize = 40
        ParentColor = False
        ResizeStyle = rsUpdate
        ExplicitTop = 50
        ExplicitWidth = 616
      end
      object Label1: TLabel
        Left = 0
        Top = 33
        Width = 590
        Height = 21
        Align = alTop
        Alignment = taCenter
        Caption = #1055#1088#1086#1087#1091#1089#1085#1072#1103' '#1089#1087#1086#1089#1086#1073#1085#1086#1089#1090#1100' '#1086#1076#1085#1086#1081' '#1087#1086#1083#1086#1089#1099' (N)'
        Font.Charset = RUSSIAN_CHARSET
        Font.Color = clWindowText
        Font.Height = -16
        Font.Name = '@Microsoft YaHei'
        Font.Style = []
        ParentFont = False
        ExplicitWidth = 338
      end
      object SrcRes: TStringGrid
        Left = 0
        Top = 54
        Width = 590
        Height = 187
        Align = alTop
        DefaultColWidth = 100
        TabOrder = 1
        OnDrawCell = SrcCDrawCell
      end
      object QVgraph: TChart
        Left = 0
        Top = 246
        Width = 590
        Height = 300
        Legend.DividingLines.Visible = True
        Legend.DrawBehind = True
        Legend.Font.Height = -24
        Legend.TextStyle = ltsValue
        PrintProportional = False
        Title.Brush.Color = clBlack
        Title.Cursor = crHandPoint
        Title.Emboss.HorizSize = -18
        Title.Emboss.VertSize = -18
        Title.Font.Height = -22
        Title.Font.Name = 'Microsoft YaHei'
        Title.Frame.Width = 0
        Title.Text.Strings = (
          'Q(V)')
        BottomAxis.Title.Caption = #1089#1082#1086#1088#1086#1089#1090#1100', '#1084'/'#1089
        LeftAxis.Title.Caption = #1087#1088#1086#1087#1091#1089#1082#1085#1072#1103' '#1089#1087#1086#1089#1086#1073#1085#1086#1089#1090#1100', '#1072#1074#1090#1086'/'#1095#1072#1089
        View3DWalls = False
        Align = alClient
        TabOrder = 2
        DefaultCanvas = 'TGDIPlusCanvas'
        PrintMargins = (
          15
          10
          15
          15)
        ColorPaletteIndex = 13
        object CheckBox1: TCheckBox
          Left = 432
          Top = 48
          Width = 97
          Height = 17
          Caption = 'CheckBox1'
          TabOrder = 0
          OnClick = CheckBox1Click
        end
        object Series1: TFastLineSeries
          HoverElement = []
          LinePen.Color = 10708548
          XValues.Name = 'X'
          XValues.Order = loAscending
          YValues.Name = 'Y'
          YValues.Order = loNone
        end
      end
      object Panel1: TPanel
        Left = 0
        Top = 0
        Width = 590
        Height = 33
        Align = alTop
        BevelInner = bvRaised
        BevelOuter = bvLowered
        ParentBackground = False
        TabOrder = 0
        object SaveChart: TButton
          Left = 467
          Top = 2
          Width = 121
          Height = 29
          Cursor = crHandPoint
          Align = alRight
          Caption = 'C'#1086#1093#1088#1072#1085#1080#1090#1100' '#1075#1088#1072#1092#1080#1082
          TabOrder = 0
          OnClick = SaveChartClick
        end
        object savegrid: TButton
          Left = 2
          Top = 2
          Width = 115
          Height = 29
          Cursor = crHandPoint
          Align = alLeft
          Caption = 'C'#1086#1093#1088#1072#1085#1080#1090#1100' '#1090#1072#1073#1083#1080#1094#1091
          TabOrder = 1
          OnClick = savegridClick
        end
      end
    end
  end
  object ODdata: TOpenDialog
    DefaultExt = 'bin'
    FileName = 'C:\Users\'#1056#1072#1091#1092'\source\repos1\'#1074' '#1073#1080#1085#1072#1088#1085#1099#1081' '#1092#1072#1081#1083'\proverka2.bin'
    Filter = #1092#1072#1081#1083' '#1089' '#1080#1089#1093#1086#1076#1085#1099#1084#1080' '#1076#1072#1085#1085#1099#1084#1080'|*.bin|'#1074#1089#1077' '#1092#1072#1081#1083#1099'|*.*'
    InitialDir = '.'
    Options = [ofHideReadOnly, ofFileMustExist, ofEnableSizing]
    Title = #1047#1072#1075#1088#1091#1079#1082#1072' '#1080#1089#1093#1086#1076#1085#1099#1093' '#1076#1072#1085#1085#1099#1093' '
    Left = 524
    Top = 498
  end
  object SaveGr: TSaveDialog
    Left = 460
    Top = 442
  end
  object SaveGraph: TSavePictureDialog
    Left = 532
    Top = 442
  end
  object fdGrid: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -18
    Font.Name = 'Segoe UI'
    Font.Style = []
    Left = 460
    Top = 505
  end
  object ApplicationEvents1: TApplicationEvents
    OnActionExecute = ApplicationEvents1ActionExecute
    OnHint = ApplicationEvents1Hint
    Left = 460
    Top = 401
  end
end
