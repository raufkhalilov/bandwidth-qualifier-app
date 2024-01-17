#ifndef MainH
#define MainH
//---------------------------------------------------------------------------
#include <Vcl.Imaging.pngimage.hpp>
#include <pngimage.hpp>
#include <jpeg.hpp>
#include <GIFimg.hpp>
#include <System.IOUtils.hpp>
#include <Vcl.GraphUtil.hpp>
#include "GifImg.hpp"
#include <System.Classes.hpp>
#include <Vcl.AppEvnts.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.StdCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Imaging.GIFImg.hpp>
#include <Grids.hpp>
#include <vcl.h>
#include <SysUtils.hpp>
#include <Vcl.Forms.hpp>

//---------------------------------------------------------------------------
typedef float TCmpFunc(const UnicodeString &s1, const UnicodeString &s2);
int CalcGridColWidth(TStringGrid *grid, int colIdx);
void SortGridByRow(TStringGrid *grid, int rowIdx, bool ascending, TCmpFunc cmpFunc);
int AdjustGridColWidths(TStringGrid *grid);
float cmpFunc1 (const UnicodeString &s1, const UnicodeString &s2);

//bool oshib(TStringGrid*SrcC,TStringGrid*SrcAL,TStringGrid*SrcNKT,TStringGrid*SrcVsT,
												   //	TStatusBar*sbInfo, TButton*bProc);


enum class FileExtensionIndex {
	GIF = 1,
	JPEG =2,
	BMP = 3,
	CUSTOM = 4,
	   };

class TTForm1 : public TForm
{
__published:	// IDE-managed Components
	TOpenDialog *ODdata;
	TSaveDialog *SaveGr;
	TSavePictureDialog *SaveGraph;
	TFontDialog *fdGrid;
	TApplicationEvents *ApplicationEvents1;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N5;
	TMenuItem *N6;
	TPageControl *PageControl1;
	TTabSheet *SrcData;
	TStringGrid *SrcAL;
	TStringGrid *SrcVsT;
	TStringGrid *SrcNKT;
	TStatusBar *sbInfo;
	TPanel *Panel2;
	TButton *dowload;
	TButton *bProc;
	TMemo *Memo1;
	TPanel *Panel3;
	TButton *AddColC;
	TButton *bDelRangeCol;
	TButton *bInsCol;
	TCheckBox *cbColRangeSelect;
	TButton *ClearC;
	TButton *DelColC;
	TCheckBox *cbEditAutoWidthC;
	TStringGrid *SrcC;
	TPanel *Panel4;
	TButton *AddColAL;
	TButton *bDelRangeColAL;
	TButton *bInsCol2;
	TButton *ClearAL;
	TButton *DelColAL;
	TCheckBox *cbColRangeSelectAL;
	TCheckBox *cbEditAutoWidthAL;
	TTabSheet *ResPage;
	TSplitter *Splitter1;
	TLabel *Label1;
	TStringGrid *SrcRes;
	TChart *QVgraph;
	TCheckBox *CheckBox1;
	TPanel *Panel1;
	TButton *SaveChart;
	TButton *savegrid;
	TPanel *Panel5;
	TCheckBox *cbEditAutoWidthRes;
	TMenuItem *Exit;
	TButton *bFontC;
	TButton *bFontAL;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N11;
	TMenuItem *N12;
	TMenuItem *N13;
	TMenuItem *N14;
	TMenuItem *al1;
	TMenuItem *N17;
	TMenuItem *N18;
	TMenuItem *N19;
	TMenuItem *N20;
	TMenuItem *A1;
	TMenuItem *A2;
	TMenuItem *N16;
	TMenuItem *N21;
	TMenuItem *N4;
	TMenuItem *N15;
	TMenuItem *N22;
	TMenuItem *N24;
	TMenuItem *N25;
	TCheckBox *CheckBox2;
	TLineSeries *Series1;
	TMenuItem *N26;
	TMenuItem *N23;
	TSaveDialog *SaveDialog1;
	TScrollBar *ScrollBar1;
	void __fastcall AddColCClick(TObject *Sender);
	void __fastcall DelColCClick(TObject *Sender);
	void __fastcall AddColALClick(TObject *Sender);
	void __fastcall DelColALClick(TObject *Sender);
	void __fastcall ClearCClick(TObject *Sender);
	void __fastcall dowloadClick(TObject *Sender);
	void __fastcall bProcClick(TObject *Sender);
	void __fastcall SrcCKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall ClearALClick(TObject *Sender);
	bool __fastcall savegridClick(TObject *Sender);
	void __fastcall SaveChartClick(TObject *Sender);
	void __fastcall SrcCSetEditText(TObject *Sender, int ACol, int ARow, const UnicodeString Value);
	void __fastcall SrcALSetEditText(TObject *Sender, int ACol, int ARow, const UnicodeString Value);
	void __fastcall SrcVsTSetEditText(TObject *Sender, int ACol, int ARow, const UnicodeString Value);
	void __fastcall SrcNKTSetEditText(TObject *Sender, int ACol, int ARow, const UnicodeString Value);
	void __fastcall cbColRangeSelectClick(TObject *Sender);
	void __fastcall cbColRangeSelectALClick(TObject *Sender);
	void __fastcall bInsColClick(TObject *Sender);
	void __fastcall bInsCol2Click(TObject *Sender);
	void __fastcall bDelRangeColClick(TObject *Sender);
	void __fastcall bDelRangeColALClick(TObject *Sender);
	void __fastcall SrcCDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect, TGridDrawState State);
	void __fastcall bFontCClick(TObject *Sender);
	void __fastcall bFontALClick(TObject *Sender);
	void __fastcall ApplicationEvents1hint(TObject *Sender);
	void __fastcall ApplicationEvents1ActionExecute(TBasicAction *Action, bool &Handled);
	//void __fastcall CheckBox1Click(TObject *Sender);
	void __fastcall SrcCDblClick(TObject *Sender);
	void __fastcall cbEditAutoWidthCClick(TObject *Sender);
	void __fastcall cbEditAutoWidthALClick(TObject *Sender);
	void __fastcall cbEditAutoWidthResClick(TObject *Sender);
	void __fastcall N6Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall CheckBox2Click(TObject *Sender);
	void __fastcall SrcCGetEditText(TObject *Sender, int ACol, int ARow, UnicodeString &Value);
	void __fastcall SrcALKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall SrcALGetEditText(TObject *Sender, int ACol, int ARow, UnicodeString &Value);
	void __fastcall SrcNKTGetEditText(TObject *Sender, int ACol, int ARow, UnicodeString &Value);
	void __fastcall SrcNKTKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall SrcVsTKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall SrcVsTGetEditText(TObject *Sender, int ACol, int ARow, UnicodeString &Value);
	void __fastcall FormAfterMonitorDpiChanged(TObject *Sender, int OldDPI, int NewDPI);
	void __fastcall SaveGraphTypeChange(TObject *Sender);
	void __fastcall ODdataShow(TObject *Sender);
	void __fastcall N26Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall N15Click(TObject *Sender);
	void __fastcall SrcDataContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall N22Click(TObject *Sender);
	void __fastcall N23Click(TObject *Sender);
	void __fastcall ExitClick(TObject *Sender);
	void __fastcall SaveGrShow(TObject *Sender);
	void __fastcall MainMenu1Change(TObject *Sender, TMenuItem *Source, bool Rebuild);
	void __fastcall SaveGrTypeChange(TObject *Sender);
	void __fastcall SaveDialog1Show(TObject *Sender);
	void __fastcall FormCloseQuery(TObject *Sender, bool &CanClose);
	void __fastcall SrcALDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State);
	void __fastcall SrcVsTDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall SrcNKTClick(TObject *Sender);
	void __fastcall SrcNKTDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall SaveGraphShow(TObject *Sender);
	void __fastcall SrcResDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State);
	void __fastcall ScrollBar1Change(TObject *Sender);
	void __fastcall SrcCColumnMoved(TObject *Sender, int FromIndex, int ToIndex);
	void __fastcall SrcALColumnMoved(TObject *Sender, int FromIndex, int ToIndex);


private:
	typedef double elemType;
	elemType elem, v1, v2, step, n, k, t;
	String FCurCellText;
	String FCurCellText2;
	String FCurCellText3;
	String FCurCellText4;
	bool a=false, b=false, c=false, d=false;
	double size_al, size_C;
	 int FSortedRowNbr;
	void __fastcall sgFontChanged(TObject *Sender);
	double N, Q;
	String FileName;
	bool __fastcall SaveData(bool showDialog);
	bool __fastcall CheckChangesAndSave();
	String selectedExtension = L".bmp";

	// User declarations
public:		// User declarations
	__fastcall TTForm1(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TTForm1 *TForm1;
//---------------------------------------------------------------------------
#endif
