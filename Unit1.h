//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H

//---------------------------------------------------------------------------
#include <Grids.hpp>
 #include <vcl.h>
#include <System.Classes.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.StdCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <SysUtils.hpp>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <VCLTee.Chart.hpp>
#include <VCLTee.Series.hpp>
#include <VclTee.TeeGDIPlus.hpp>
#include <VCLTee.TeEngine.hpp>
#include <VCLTee.TeeProcs.hpp>
#include <Vcl.ExtDlgs.hpp>
#include <Vcl.AppEvnts.hpp>
//---------------------------------------------------------------------------
int CalcGridColWidth(TStringGrid *grid, int colIdx);

class TTForm1 : public TForm
{
__published:	// IDE-managed Components
	TPageControl *PageControl1;
	TTabSheet *SrcData;
	TStringGrid *SrcC;
	TButton *AddColC;
	TButton *DelColC;
	TStringGrid *SrcAL;
	TButton *AddColAL;
	TButton *DelColAL;
	TStringGrid *SrcVsT;
	TStringGrid *SrcNKT;
	TButton *ClearC;
	TStatusBar *sbInfo;
	TButton *dowload;
	TOpenDialog *ODdata;
	TButton *bProc;
	TTabSheet *ResPage;
	TStringGrid *SrcRes;
	TButton *ClearAL;
	TChart *QVgraph;
	TFastLineSeries *Series1;
	TButton *savegrid;
	TSaveDialog *SaveGr;
	TSavePictureDialog *SaveGraph;
	TPanel *Panel1;
	TPanel *Panel2;
	TMemo *Memo1;
	TButton *SaveChart;
	TSplitter *Splitter1;
	TLabel *Label1;
	TCheckBox *cbColRangeSelect;
	TCheckBox *cbColRangeSelectAL;
	TButton *bInsCol;
	TButton *bInsCol2;
	TButton *bDelRangeCol;
	TButton *bDelRangeColAL;
	TPanel *Panel3;
	TPanel *Panel4;
	TFontDialog *fdGrid;
	TButton *bFontC;
	TButton *bFontAL;
	TApplicationEvents *ApplicationEvents1;
	TCheckBox *CheckBox1;
	void __fastcall AddColCClick(TObject *Sender);
	void __fastcall DelColCClick(TObject *Sender);
	void __fastcall AddColALClick(TObject *Sender);
	void __fastcall DelColALClick(TObject *Sender);
	void __fastcall ClearCClick(TObject *Sender);
	void __fastcall dowloadClick(TObject *Sender);
	void __fastcall bProcClick(TObject *Sender);
	void __fastcall SrcCKeyPress(TObject *Sender, System::WideChar &Key);
	void __fastcall ClearALClick(TObject *Sender);
	void __fastcall savegridClick(TObject *Sender);
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
	//void __fastcall SrcCDblClick(TObject *Sender);
	void __fastcall SrcCDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect, TGridDrawState State);
	void __fastcall bFontCClick(TObject *Sender);
	void __fastcall bFontALClick(TObject *Sender);
	void __fastcall ApplicationEvents1hint(TObject *Sender);
	void __fastcall ApplicationEvents1ActionExecute(TBasicAction *Action, bool &Handled);
	void __fastcall CheckBox1Click(TObject *Sender);



private:
	typedef double elemType;
	elemType elem, v1, v2, step, n, k, t;
	typedef DynamicArray<elemType> t2daGrid;
	double size_al, size_C;

	void __fastcall sgFontChanged(TObject *Sender);
	double N, Q;
// User declarations
public:		// User declarations
	__fastcall TTForm1(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TTForm1 *TForm1;
//---------------------------------------------------------------------------
#endif
