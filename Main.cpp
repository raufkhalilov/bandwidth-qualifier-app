//---------------------------------------------------------------------------
#include <memory>
#include <fstream>
#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTForm1 *TForm1;
//---------------------------------------------------------------------------
__fastcall TTForm1::TTForm1(TComponent* Owner)
	: TForm(Owner)
{

	//QVgraph->Series[1]->Active = true;
	SrcC->Cells[0][0] = "№";
	SrcC->Cells[0][1] = "C";

	SrcAL->Cells[0][0] = "№";
	SrcAL->Cells[1][0] = "1";
	SrcAL->Cells[0][1] = "a";
	SrcAL->Cells[0][2] = "l";

	SrcVsT->Cells[0][0] = "v min";
	SrcVsT->Cells[1][0] = "v max";
	SrcVsT->Cells[2][0] = "шаг";

	SrcNKT->Cells[0][0] = "n";
	SrcNKT->Cells[1][0] = "k";
	SrcNKT->Cells[2][0] = "t";

	if(SrcC->ColCount==2)
		SrcC->ColWidths[1] = -1;

	if(SrcAL->ColCount==2)
		SrcAL->ColWidths[1] = -1;

//	SrcC -> SetFocus();
//	SrcAL -> SetFocus();
	FSortedRowNbr = 0;
	if(a)
		bProc->Enabled=true;
	else
		bProc->Enabled=false;

//	if (SrcNKT->Cells[2][1] != "")
//		bProc -> Enabled=True;
	Application -> Title = "Определитель пропускной способности";
}
//---------------------------------------------------------------------------
void __fastcall TTForm1::AddColCClick(TObject *Sender)
{

	if(SrcC->ColWidths[1]==-1){
	 SrcC->ColWidths[1] = SrcC -> DefaultColWidth;
	 cbColRangeSelectClick(NULL);
	}
	else
		SrcC -> ColCount++;

	SrcC -> Col = SrcC -> ColCount-1;
	SrcC -> Cols[SrcC->Col]-> Clear();
	SrcC -> SetFocus();

	bProc->Enabled=false;
	DelColC->Enabled = true;
	bDelRangeCol->Enabled = true;
	bFontC->Enabled=true;
	ClearC->Enabled=true;

	SrcC->Options = SrcC->Options << goColSizing << goRowSizing;
	N26->Enabled= true;
	//Caption = L"Определитель пропускной способности "+ExtractFileName(SaveGr->FileName) + L"*";
    Caption = "Определитель пропускной способности - " + ExtractFileName(SaveGr->FileName)+ "* ";
	size_C++;
	for(int i = 0; i < size_C; i++)
		SrcC->Cells[i+1][0] = IntToStr(i+1);
	//SrcC->Cells[SrcC->ColCount-1][1] = IntToStr(-1);

}
//---------------------------------------------------------------------------
void __fastcall TTForm1::DelColCClick(TObject *Sender)
{
	if (Application->MessageBox((UnicodeString(L"Вы действительно хотите удалить выделенные столбцы (") +
		SrcC->Selection.Left + L'-' +
		SrcC->Selection.Right + L")?").w_str(),
		L"Определитель пропускной способности", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
			return;


	if(SrcC->ColWidths[1]==-1)
		return;

	if(SrcC->ColCount>2){
		SrcC -> ColCount--;
		for(int i = SrcC->ColCount; i<SrcC->ColCount; i++){
			SrcC->Cols[i] = SrcC -> Cols[i+1];
		}
	}
	else{
		SrcC->ColWidths[1]=-1;
        SrcC->Options = SrcC->Options >> goColSizing >> goRowSizing;
		SrcC->Options = SrcC->Options>>goEditing;
		bProc->Enabled=false;
		DelColC->Enabled = false;
		bDelRangeCol->Enabled = false;
		bFontC->Enabled=false;
		ClearC->Enabled=false;
		N26->Enabled= true;
	}

	size_C--;
	for(int i = 0; i < size_C; i++)
		SrcC->Cells[i+1][0] = IntToStr(i+1);
	Caption = "Определитель пропускной способности - " + ExtractFileName(SaveGr->FileName)+ "* ";

}
//---------------------------------------------------------------------------
void __fastcall TTForm1::AddColALClick(TObject *Sender)
{

	if(SrcAL->ColWidths[1]==-1){
	 SrcAL->ColWidths[1] = SrcAL -> DefaultColWidth;
	 cbColRangeSelectALClick(NULL);
	}
	else
		SrcAL -> ColCount++;
	SrcAL->Cells[(SrcAL->ColCount)-1][0] = IntToStr(SrcAL->ColCount);
	SrcAL -> Col = SrcAL -> ColCount-1;
	SrcAL -> Cols[SrcAL->Col]-> Clear();
	SrcAL -> SetFocus();
    	bProc->Enabled=false;

	DelColAL->Enabled = true;
	bDelRangeColAL->Enabled = true;
	bFontAL->Enabled=true;
	ClearAL->Enabled=true;
	N26->Enabled= true;
	SrcAL->Options = SrcAL->Options << goColSizing << goRowSizing;

	size_al++;
	for(int i = 0; i < size_al; i++)
		SrcAL->Cells[i+1][0] = IntToStr(i+1);
	Caption = "Определитель пропускной способности - " + ExtractFileName(SaveGr->FileName)+ "* ";
//	SrcAL->Cells[SrcAL->ColCount-1][1] = IntToStr(-1);
//	SrcAL->Cells[SrcAL->ColCount-1][2] = IntToStr(-1);

}
//---------------------------------------------------------------------------
void __fastcall TTForm1::DelColALClick(TObject *Sender)
{
	if (Application->MessageBox((UnicodeString(L"Вы действительно хотите удалить выделенные столбцы (") +
		SrcC->Selection.Left + L'-' +
		SrcC->Selection.Right + L")?").w_str(),
		L"Определитель пропускной способности", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
			return;

	if(SrcAL->ColWidths[1]==-1)
		return;
	if(SrcAL->ColCount>2){
		SrcAL -> ColCount--;
		for(int i = SrcAL->ColCount; i < SrcAL->ColCount; i++){
			SrcAL->Cols[i] = SrcAL -> Cols[i+1];
		}
	}
	else{
		SrcAL->ColWidths[1]=-1;
        SrcAL->Options = SrcAL->Options >> goColSizing >> goRowSizing;
		SrcAL->Options = SrcAL->Options>>goEditing;
		bProc->Enabled=false;
		DelColAL->Enabled = false;
		bDelRangeColAL->Enabled = false;
		bFontAL->Enabled=false;
		ClearAL->Enabled=false;
		N26->Enabled= true;

	}
	size_al--;
	for(int i = 0; i < size_al; i++)
		SrcAL->Cells[i+1][0] = IntToStr(i+1);
	Caption = "Определитель пропускной способности - " + ExtractFileName(SaveGr->FileName)+ "* ";
}
//---------------------------------------------------------------------------
void __fastcall TTForm1::ClearCClick(TObject *Sender)  //очстка не работает
{
if (Application->MessageBox(
		UnicodeString(L"Вы действительно хотите полностью очистить таблицу коэф-тов С?").w_str(),
		L"Определитель пропускной способности", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
	return;

 for (int i = 1; i < SrcC->ColCount; i++) {
	  SrcC ->Cells[i][0] = L"";
	  //delete SrcC->Objects[i][1];
 }
 //SrcC->ColCount=1;
	  SrcC->ColCount=2;
	  SrcC->ColWidths[1]=-1;

	  bProc->Enabled=false;
	  DelColC->Enabled = false;
	  bDelRangeCol->Enabled = false;
	  bFontC->Enabled=false;
	  ClearC->Enabled=false;

	  Caption = "Определитель пропускной способности - " + ExtractFileName(SaveGr->FileName)+ "* ";
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::ClearALClick(TObject *Sender)
{
if (Application->MessageBox(
		UnicodeString(L"Вы действительно хотите полностью таблицу от всех значений a и l ?").w_str(),
		L"Определитель пропускной способности", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
	return;

 for (int i = 1; i < SrcAL->ColCount; i++) {
	  SrcAL ->Cells[i][0] = L"";
	  //delete SrcC->Objects[i][1];
 }
 //SrcC->ColCount=1;
	  SrcAL->ColCount=2;
	  SrcAL->ColWidths[1]=-1;

	  bProc->Enabled=false;
	  DelColAL->Enabled = false;
	  bDelRangeColAL->Enabled = false;
	  bFontAL->Enabled=false;
	  ClearAL->Enabled=false;

	 Caption = "Определитель пропускной способности - " + ExtractFileName(SaveGr->FileName)+ "* ";

}

//---------------------------------------------------------------------------


void __fastcall TTForm1::dowloadClick(TObject *Sender)
{
	if(!CheckChangesAndSave())
		return;

	if(!ODdata->Execute()){
		return;
	}
	//bProc->Enabled=false;

	SaveGr->FileName = ODdata->FileName;

	//sbInfo->SimpleText = FileName;
	//String fn = (eFileName -> Text);
	SrcC->ColWidths[1] = SrcC -> DefaultColWidth;
	SrcAL->ColWidths[1] = SrcAL -> DefaultColWidth;
	ifstream fn;
	fn.open(AnsiString(ODdata->FileName).c_str(),ios::binary);
	if(!fn.is_open()){
		 sbInfo->SimpleText=
		   String(L"Ошибка открытия файла: " + (ODdata->FileName) + L", \nкод ошибки: ") + errno;
		 return;
	}

	fn.seekg(0,ios::end);
	int n= fn.tellg();

	Memo1 -> Text = IntToStr(n);

	if (n==0){
		fn.close();
		sbInfo->SimpleText= String(L"Нет данных в\"" + (ODdata->FileName));
		return;
	}


	bool a;
	if (n < sizeof(size_al) || ((n-sizeof(size_al)-sizeof(size_C)) % sizeof(double))) //р-р маленький и не кратный
		a= true;
	else {
		fn.seekg(0);
		fn.read((char*)&size_C,sizeof(size_C));
		fn.read((char*)&size_al,sizeof(size_al));

		if(size_C*sizeof(double)+ size_al*sizeof(double)*2 + 6*sizeof(double)!=
			n-sizeof(size_C)-sizeof(size_al))
				a = true;
	}
	if (a) {
		 fn.close();
		 sbInfo->SimpleText= String(L"Целостность содержимого файла нарушена");
	}

	SrcC -> ColCount = size_C + 1;
	for(int i = 0; i < size_C; i++){
		SrcC->Cells[i+1][0] = IntToStr(i+1);
		fn.read((char*)&elem,sizeof(elemType));
		SrcC->Cells[i+1][1]= FloatToStr(elem);
	}

	int tt=0;
	SrcAL -> ColCount = size_al + 1;
	for(int i = 1; i < 3; i++){
		for(int j=0; j < size_al; j++){
			SrcAL->Cells[tt+1][0]= tt+1;
			tt++;
			fn.read((char*)&elem,sizeof(elemType));
			SrcAL->Cells[j+1][i]= FloatToStr(elem);
		}
	}

	for(int i=0; i < 3; i++){
		fn.read((char*)&elem,sizeof(elemType));
		SrcVsT->Cells[i][1]= FloatToStr(elem);
	}

	for(int i=0; i < 3; i++){
		fn.read((char*)&elem,sizeof(elemType));
		SrcNKT->Cells[i][1]= FloatToStr(elem);
	}

	//if(oshib(SrcC, SrcAL, SrcNKT, SrcVsT, sbInfo, bProc)){
	//	bProc->Enabled=True;
   //	}

//	if (SrcNKT->Cells[2][1] != "")
//			bProc -> Enabled=True;

//		fn.close();
//		ShowMessage(L"Файл содержит некорректные данные.");
//		return;
//	}


	cbColRangeSelectClick(NULL);
	DelColC->Enabled = true;
	bFontC->Enabled=true;
	ClearC->Enabled=true;
	DelColAL->Enabled = true;
	bDelRangeColAL->Enabled = true;
	bFontAL->Enabled=true;
	ClearAL->Enabled=true;
	bProc->Enabled=true;
	FSortedRowNbr = 0;

//	if(cbEditAutoWidth->Checked)
//		AdjustGridColWidths(SrcC);
	if(cbEditAutoWidthC->Checked){
		AdjustGridColWidths(SrcC);
		SrcC->Options = SrcC->Options >> goColSizing;
	}
	else
		SrcC->Options = SrcC->Options << goColSizing;

	if(cbEditAutoWidthAL->Checked){
		AdjustGridColWidths(SrcAL);
		SrcAL->Options = SrcAL->Options >> goColSizing;
	}
	else
		SrcAL->Options = SrcAL->Options << goColSizing;

	a=true;
	b=true;
	c=true;
	d=true;
	bDelRangeCol->Enabled = true;
	N26->Enabled= false;
	Caption = "Определитель пропускной способности - " + ExtractFileName(ODdata->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::bProcClick(TObject *Sender)
{
	ResPage->TabVisible=true;
	PageControl1->Pages[1]->Enabled = true;
	for(int i = 0; i <= SrcRes->ColCount; i++){
		for(int j = 0; j <= SrcRes->RowCount; j++){
			SrcRes->Cells[i][j] = L"";
		}
	}
	CheckBox2 -> Checked =true;
    CheckBox2 -> Checked =false;
	// Очистка всех графиков
	while (QVgraph->SeriesList->Count > 0) {
		TChartSeries *series = QVgraph->SeriesList->Items[QVgraph->SeriesList->Count - 1];
		series->Clear();
		QVgraph->SeriesList->Delete(QVgraph->SeriesList->Count - 1);
		delete series;
	}

	v1= (SrcVsT->Cells[0][1]).ToDouble();

	v2 = (SrcVsT->Cells[1][1]).ToDouble();

	step = (SrcVsT->Cells[2][1]).ToDouble();

	n = (SrcNKT->Cells[0][1]).ToDouble();

	k = (SrcNKT->Cells[1][1]).ToDouble();

	t = (SrcNKT->Cells[2][1]).ToDouble();

	SrcRes -> RowCount = (v2-v1)/step +2;
	for (int i = 0; i <= (v2-v1)/step; i++) {
		SrcRes->Cells[0][i+1]=L"v="+FloatToStr(v1+step*i); /**/
	}


	SrcRes -> ColCount = (SrcAL->ColCount)*((SrcC->ColCount)-1);

	int i = 1;
	for (int k = 1; k < SrcC->ColCount; k++) {
		SrcRes->Cells[i - 1][0] = "C" + IntToStr(k) + " = " + SrcC->Cells[k][1];
		i++;

		for (int j = 1; j < (SrcAL->ColCount); j++) {
			SrcRes->Cells[i - 1][0] = "a= "+SrcAL->Cells[j][1]
				+" l=" + SrcAL->Cells[j][2];
			i++;
		}
	}
	TLineSeries *series = new TLineSeries(QVgraph);
//	double N, Q;

	for (int i = 1; i < SrcC->ColCount; i++) {



		for (int j = 1; j < SrcAL->ColCount; j++) {
			TLineSeries *series = new TLineSeries(QVgraph);
			QVgraph->AddSeries(series);

			AnsiString legendText = "С" + IntToStr(i) + " "+ SrcRes->Cells[j][0];

			series->Title = legendText;
			for (int v = v1; v < v2 + step; v += step) {
				N = 3600 * v1 / (StrToFloat(SrcAL->Cells[j][1]) +
								 StrToFloat(SrcAL->Cells[j][2]) +
								 v * t + StrToFloat(SrcC->Cells[i][1]) * v * v);
				N=N-fmod(N,0.001);
				Q = N * n * k;
				//SrcRes->Cells[j + (SrcAL->ColCount) * i - (SrcAL->ColCount)][(v - v1) / step + 1] = N;
				//SrcRes->Cells[j + (SrcAL->ColCount) * i - (SrcAL->ColCount)][(v - v1) / step + 1] = N;
				SrcRes->Cells[j + (SrcAL->ColCount) * i - (SrcAL->ColCount)][(v - v1) / step + 1] =
					"    " + FormatFloat("#0.00", N);
				series->AddXY(v, Q);
			}
		}

	}

	if(cbEditAutoWidthRes->Checked){
		AdjustGridColWidths(SrcRes);
		SrcRes->Options = SrcRes->Options >> goColSizing;
	}
	else
		SrcRes->Options = SrcRes->Options << goColSizing;

	 sbInfo ->SimpleText = L"Данные обработаны" ;
	 PageControl1->ActivePage = ResPage;

}
//---------------------------------------------------------------------------

void __fastcall TTForm1::SrcCKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (!SrcC->EditorMode)
		return;
	if (Key==VK_ESCAPE && SrcC->EditorMode) {
		SrcC->Cells[SrcC->Col][SrcC->Row]=FCurCellText;
		return;
	}
//if (Key==VK_ESCAPE) {
//	  SrcC->Cells[SrcC->Col][SrcC->Row] = FCurCellText;
//	  if (SrcC->Options.Contains(goAlwaysShowEditor)) {
//		SrcC->EditorMode = false;
//	  }
//  }
//
//	if(!((Key >= L'0' && Key <= L'9')  || Key!=L'-'  || Key==L'+' || Key == FormatSettings.DecimalSeparator ||
//		 Key ==L'e' || Key ==L'E') && Key!=VK_BACK && Key!=VK_RETURN && Key!=3 && Key!=22 &&
//		 Key!= 24 && Key!= 26){
//		 //bProc1->Enabled=false;
//		 sbInfo ->SimpleText = L"Недопустимый символ '" + UnicodeString(Key) + L'\'' +
//			L". Коэффициент должен быть не отрицательным числом.";
//		 Key = 0;
//	}
//	else {
//		sbInfo->SimpleText=L"";
//		bProc->Enabled=true;
//	}
	if (!SrcC->EditorMode)
		return;
	if (Key==VK_ESCAPE && SrcC->EditorMode) {
		SrcC->Cells[SrcC->Col][SrcC->Row]=FCurCellText2;
		return;
	}

	if(!((Key >= L'0' && Key <= L'9') || Key==VK_ESCAPE  || Key !=L'-'  || Key==L'+' || Key == FormatSettings.DecimalSeparator ||
		 Key ==L'e' || Key ==L'E') && Key!=VK_BACK && Key!=VK_RETURN && Key!=3 && Key!=22 &&
		 Key!= 24 && Key!= 26){
		 //bProc1->Enabled=false;
		 sbInfo ->SimpleText = L"Недопустимый символ '" + UnicodeString(Key) + L'\'';
		 Key = 0;
	}
	else {
		sbInfo->SimpleText=L"";
		bProc->Enabled=true;
	}
	SrcC->Cells[0][0] = "№";
	SrcC->Cells[0][1] = "C";
	Caption = "Определитель пропускной способности - " + ExtractFileName(SaveGr->FileName)+ "* ";


}
//---------------------------------------------------------------------------


bool __fastcall TTForm1::savegridClick(TObject *Sender)
{

	WideString str;
		TStringList *sl = new TStringList;
		for(int i = 0 ; i<SrcRes->RowCount ;++i)
		{
			if(i!=1){
				str = "\t";
				sl->Add(str);
			}
			for(int j = 0; j< SrcRes->ColCount;++j)
				str +=SrcRes->Cells[j][i]+ "\t";
				sl->Add(str);
				str = "\r" ;
				str = "";
		}
		if (SaveGr->Execute())
		sl->SaveToFile(SaveGr->FileName + ".txt");
		delete sl;

//	String svdFileName = SaveGr->FileName;
//
//	if(!SaveGr->Execute())
//		return false;
//
//	try{
//		mText->Lines->SaveToFile(SaveGr->FileName);
//	}
//	catch (Exception &e){
//		Application -> MessageBox(Format(L"Ошибка сохранения файла \"%s\": \"%s\"",
//							ARRAYOFCONST((SaveGr->FileName, e.Message))).w_str(),
//							Application->Title.w_str(),
//							MB_OK|MB_ICONERROR);
//		SaveGr->FileName = svdFileName;
//		return false;
//	}
//
//	savegrid->Enabled = false;
//	Caption = S_EDITOR+ L" - " + (SaveGr->FileName);
//	return true;

}

//---------------------------------------------------------------------------


void __fastcall TTForm1::SaveChartClick(TObject *Sender)
{
	if (!SaveGraph->Execute())
		return;
//
	if (Ioutils::TPath::GetExtension(SaveGraph->FileName).IsEmpty()) {
		SaveGraph->FileName += selectedExtension;
	}

	String fileExtension = Ioutils::TPath::GetExtension(SaveGraph->FileName);

	String FileName = String(SaveGraph -> FileName);
	if (fileExtension == L".bmp") {
	  QVgraph->SaveToBitmapFile(UnicodeString(SaveGraph -> FileName));
	}
	if (fileExtension == L".jpeg") {
	TCanvas *Source = new TCanvas();
	  Source->Handle = GetDC(QVgraph->Handle);
      Graphics::TBitmap *bmp = new Graphics::TBitmap();
	  bmp->SetSize(QVgraph->ClientWidth, QVgraph->ClientHeight);
	  RECT src = QVgraph->ClientRect;
	  RECT dst = {0, 0, QVgraph->ClientWidth, QVgraph->ClientHeight};
      bmp->Canvas->CopyRect(dst, Source, src);

      TJPEGImage *jpeg = new TJPEGImage();
      jpeg->Assign(bmp);
	  jpeg->SaveToFile(String(SaveGraph -> FileName));
      jpeg->Free();
      bmp->Free();
	  ReleaseDC(QVgraph->Handle, Source->Handle);
	  Source->Free();
	}


   if (fileExtension == L".gif") {

	  TCanvas *Source = new TCanvas();
	  Source->Handle = GetDC(QVgraph->Handle);
	  Graphics::TBitmap *bmp = new Graphics::TBitmap();
	  bmp->SetSize(QVgraph->ClientWidth, QVgraph->ClientHeight);
	  RECT src = QVgraph->ClientRect;
	  RECT dst = {0, 0, QVgraph->ClientWidth, QVgraph->ClientHeight};
	  bmp->Canvas->CopyRect(dst, Source, src);


	  TGIFImage* gif= new TGIFImage();
	  gif->Assign(bmp);
	  gif->SaveToFile(String(SaveGraph -> FileName));
	  gif->Free();
	  bmp->Free();
	  ReleaseDC(QVgraph->Handle, Source->Handle);
	  Source->Free();
	  //FileName += ".gif";
	}
 }
//---------------------------------------------------------------------------
void __fastcall TTForm1::SrcCSetEditText(TObject *Sender, int ACol, int ARow, const UnicodeString Value)

{
	float d;
	//Caption = FCurCellText +" " + SrcC->Cells[ACol][ARow]  ;
	if(!SrcC->EditorMode && !N26->Enabled && FCurCellText != SrcC->Cells[ACol][ARow]){  //if (!mSave->Enabled && !Table->EditorMode && FCurCellText != Value)
		N26->Enabled= true;
		Caption = "Определитель пропускной способности - " + ExtractFileName(SaveGr->FileName) + "* ";
	}
	if (!TryStrToFloat(SrcC->Cells[ACol][ARow], d)) {
		sbInfo -> SimpleText = UnicodeString(L"\"" + SrcC -> Cells[ACol][ARow] + L"\" не является корректным значением");
	   bProc->Enabled=false;
		return;
	}
	SrcAL->Cells[0][0] = "№";
	SrcAL->Cells[1][0] = "1";
	SrcAL->Cells[0][1] = "a";
	SrcAL->Cells[0][2] = "l";
	if(cbEditAutoWidthC->Checked){
		AdjustGridColWidths(SrcC);
		SrcC->Options = SrcC->Options >> goColSizing >> goRowSizing;
	}
	else
		SrcC->Options = SrcC->Options << goColSizing << goRowSizing;
//    if(cbEditAutoWidthAL->Checked){
//		AdjustGridColWidths(SrcAL);
//		SrcAL->Options = SrcAL->Options >> goColSizing >> goRowSizing;
//	}
//	else
//		SrcAL->Options = SrcAL->Options << goColSizing << goRowSizing;
   //	if(oshib(SrcC, SrcAL, SrcNKT, SrcVsT, sbInfo, bProc)){
	//	bProc->Enabled=True;
	//}

	//Caption = SaveGr->FileName + L"*";
	//bProc->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TTForm1::SrcALSetEditText(TObject *Sender, int ACol, int ARow, const UnicodeString Value)

{
	float d;
	//Caption = FCurCellText2 +" " + SrcAL->Cells[ACol][ARow];
	if(!SrcAL->EditorMode && SrcAL->Cells[ACol][ARow] != FCurCellText2 && !N26->Enabled){  //if (!mSave->Enabled && !Table->EditorMode && FCurCellText != Value)
		N26->Enabled= true;
		Caption = "Определитель пропускной способности - " + ExtractFileName(SaveGr->FileName) + "* ";
	}

	// Проверяем, является ли значение числом
	if (!TryStrToFloat(SrcAL->Cells[ACol][ARow], d)) {
		sbInfo->SimpleText = UnicodeString(L"\"" + SrcAL->Cells[ACol][ARow] + L"\" не является корректным значением");
		bProc->Enabled = false;
		return;
	}

	// Проверяем все строки в столбце
	bool allRowsFilled = true;
	for (int row = 0; row < SrcAL->RowCount; ++row) {
		if (SrcAL->Cells[ACol][row].IsEmpty()) {
			allRowsFilled = false;
			break;
		}
	}

	// Если хотя бы одна строка пуста, отключаем кнопку
	if (!allRowsFilled) {
		sbInfo->SimpleText = L"Не все строки в столбце заполнены";
		bProc->Enabled = false;
	} else {
		// Все строки заполнены, включаем кнопку
		bProc->Enabled = true;
		sbInfo->SimpleText = L"";
	}

	if(cbEditAutoWidthAL->Checked){
		AdjustGridColWidths(SrcAL);
		SrcAL->Options = SrcAL->Options >> goColSizing >> goRowSizing;
	}
	else
		SrcAL->Options = SrcAL->Options << goColSizing << goRowSizing;
//	SrcAL->Cells[ACol][ARow] = prevCellValue;



}
//---------------------------------------------------------------------------

void __fastcall TTForm1::SrcVsTSetEditText(TObject *Sender, int ACol, int ARow, const UnicodeString Value)

{
	float d;
	if(!SrcVsT->EditorMode && SrcVsT->Cells[ACol][ARow] != FCurCellText4 /*&& !N26->Enabled*/){  //if (!mSave->Enabled && !Table->EditorMode && FCurCellText != Value)
		N26->Enabled= true;
		Caption = "Определитель пропускной способности - " + ExtractFileName(SaveGr->FileName) + "* ";
	}
	if (!TryStrToFloat(SrcVsT->Cells[ACol][ARow], d)) {
		sbInfo -> SimpleText = UnicodeString(L"\"" + SrcVsT -> Cells[ACol][ARow]
		+ L"\" не является корректным значением");
		bProc->Enabled=false;
		return;
	}
	d = true;
	//N26->Enabled= true;
	//bProc->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::SrcNKTSetEditText(TObject *Sender, int ACol, int ARow, const UnicodeString Value)

{
	float d;
	//Caption = SrcNKT->Cells[ACol][ARow] + " " + FCurCellText3;
	if(!SrcNKT->EditorMode && SrcNKT->Cells[ACol][ARow] != FCurCellText3 /*&& !N26->Enabled*/){  //if (!mSave->Enabled && !Table->EditorMode && FCurCellText != Value)
		N26->Enabled= true;
		Caption = "Определитель пропускной способности - " + ExtractFileName(SaveGr->FileName) + "* ";
	}

	if (!TryStrToFloat(SrcNKT->Cells[ACol][ARow], d)) {
		sbInfo -> SimpleText = UnicodeString(L"\"" + SrcNKT -> Cells[ACol][ARow]
		+ L"\" не является корректным значением");
	   bProc->Enabled=false;
		return;
	}

	c = true;
	//bProc->Enabled = true;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TTForm1::cbColRangeSelectClick(TObject *Sender)
{
	if(Sender==cbColRangeSelect)
		N16->Checked = cbColRangeSelect->Checked;
	else{
		cbColRangeSelect->OnClick = NULL;
		try{
			cbColRangeSelect->Checked = N16->Checked;
		}
		__finally{
			cbColRangeSelect->OnClick =  cbColRangeSelectClick;
		}
	}
	if(cbColRangeSelect->Checked){
		SrcC->Options = SrcC->Options >> goEditing;
	}
	else
		if(SrcC->ColWidths[1] == -1)
			SrcC->Options=SrcC->Options >> goEditing /*>> goRowSelect*/;
		else
			SrcC->Options=SrcC->Options << goEditing /*<< goRowSelect*/;
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::cbColRangeSelectALClick(TObject *Sender)
{
	if(Sender==cbColRangeSelectAL)
		N21->Checked = cbColRangeSelectAL->Checked;
	else{
		cbColRangeSelectAL->OnClick = NULL;
		try{
			cbColRangeSelectAL->Checked = N21->Checked;
		}
		__finally{
			cbColRangeSelectAL->OnClick =  cbColRangeSelectALClick;
		}
	}

	 if(cbColRangeSelectAL->Checked){
		SrcAL->Options = SrcAL->Options >> goEditing;
		SrcAL -> SetFocus();
	 }
	else
		if(SrcAL->ColWidths[1] == -1)
			SrcAL->Options=SrcAL -> Options >> goEditing /*>> goRowSelect*/;
		else
			SrcAL->Options=SrcAL -> Options << goEditing /*<< goRowSelect*/;
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::bInsColClick(TObject *Sender)
{
	if(SrcC->ColWidths[1]==-1) {
		SrcC->ColWidths[1] = SrcC -> DefaultColWidth;
		cbColRangeSelectClick(NULL);
	}
	else
	SrcC -> ColCount++;
//	SrcC->Cells[0][SrcC -> ColCount] = IntToStr(0);
		SrcC->Cells[SrcC->ColCount-1][1] = IntToStr(-1);
		for(int i = SrcC->ColCount-1; i>=SrcC->Col; i--){
			SrcC->Cols[i+1] = SrcC -> Cols[i];
//			SrcC -> ColCount++;

		}

	SrcC->Cols[SrcC->Col] -> Clear();
	SrcC->SetFocus();
	DelColC->Enabled = true;
	bDelRangeCol->Enabled = true;
	bFontC->Enabled=true;
	ClearC->Enabled=true;
    	bProc->Enabled=false;
	N26->Enabled= true;
	SrcC->Options = SrcC->Options << goColSizing << goRowSizing;
	Caption = "Определитель пропускной способности - " + ExtractFileName(SaveGr->FileName)+ "* ";

	//SrcC->Cells[SrcC->ColCount-1][1] = IntToStr(-1);
	size_C++;
	for(int i = 0; i < size_C; i++)
		SrcC->Cells[i+1][0] = IntToStr(i+1);
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::bInsCol2Click(TObject *Sender)
{
	if(SrcAL->ColWidths[1]==-1) {
		SrcAL->ColWidths[1] = SrcAL -> DefaultColWidth;
		cbColRangeSelectALClick(NULL);
	}
	else
	SrcAL -> ColCount++;
		for(int i = SrcAL->ColCount-1; i>=SrcAL->Col; i--){

			SrcAL->Cols[i+1] = SrcAL -> Cols[i];
//			SrcC -> ColCount++;

		}
	SrcAL->Cols[SrcAL->Col] -> Clear();
	SrcAL->SetFocus();
	DelColAL->Enabled = true;
	bDelRangeColAL->Enabled = true;
	bFontAL->Enabled=true;
	ClearAL->Enabled=true;
	bProc->Enabled=false;
	N26->Enabled= true;
	SrcAL->Options = SrcAL->Options << goColSizing << goRowSizing;
	Caption = "Определитель пропускной способности - " + ExtractFileName(SaveGr->FileName)+ "* ";
	size_al++;
	for(int i = 0; i < size_al; i++)
		SrcAL->Cells[i+1][0] = IntToStr(i+1);
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::bDelRangeColClick(TObject *Sender)
{
	if(SrcC->ColWidths[1]==-1)
		return;

////	if (Application->MessageBox(Format(L"Вы действительно хотите удалить \"запись\" №%d?",
////		ARRAYOFCONST((SrcC->Col))).c_str(),
////		MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != ID_YES)
////
////		return;
//
//
	if (Application->MessageBox((UnicodeString(L"Вы действительно хотите удалить выделенные столбцы (") +
		SrcC->Selection.Left + L'-' +
		SrcC->Selection.Right + L")?").w_str(),
		L"Определитель пропускной способности", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
			return;


	int n = SrcC->Selection.Right - SrcC->Selection.Left + 1;
	if(SrcC->ColCount-n>=2){
		int a = SrcC->Selection.Right;

		for (int i = SrcC->Selection.Left; i <= SrcC->Selection.Right+1; i++){
			if (SrcC->Selection.Left == a)
				SrcC->Cells[i][1] = SrcC->Cells[i+1][1];
			else
				SrcC->Cells[i][1] = SrcC->Cells[i + n][1];
		}
		SrcC->ColCount -= n;
	}
	else {

	  SrcC->ColCount=2;
	  SrcC->ColWidths[1]=-1;
	  SrcC->Options = SrcC->Options >> goColSizing >> goRowSizing;
	  SrcC->Options=SrcC->Options>>goEditing;
	  bProc->Enabled=false;
	  DelColC->Enabled = false;
	  bDelRangeCol->Enabled = false;
	  bFontC->Enabled=false;
	  ClearC->Enabled=false;;
	  N26->Enabled= true;
	  Caption = "Определитель пропускной способности - " + ExtractFileName(SaveGr->FileName)+ "* ";
	}
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::bDelRangeColALClick(TObject *Sender)
{
	if(SrcAL->ColWidths[1]==-1){
		bProc->Enabled=false;
		return;
	}
	if (Application->MessageBox((UnicodeString(L"Вы действительно хотите удалить выделенные столбцы (") +
		SrcAL->Selection.Left + L'-' +
		SrcAL->Selection.Right + L")?").w_str(),
		L"Определитель пропускной способности", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
			return;;

	int n = SrcAL->Selection.Right - SrcAL->Selection.Left + 1;
	if(SrcAL->ColCount-n>=2){


		for (int i = SrcAL->Selection.Left; i <= SrcAL->Selection.Right+1; i++){
			if (SrcAL->Selection.Left == SrcAL->Selection.Right){
				SrcAL->Cells[i][1] = SrcAL->Cells[i+1][1];
				SrcAL->Cells[i][2] = SrcAL->Cells[i+1][2];
			}
			else{
				SrcAL->Cells[i][1] = SrcAL->Cells[i + n][1];
				SrcAL->Cells[i][2] = SrcAL->Cells[i + n][2];
			}
		}
		SrcAL->ColCount -= n;
	}
	else {

	  SrcAL->ColCount=2;
	  SrcAL->ColWidths[1]=-1;
      SrcAL->Options = SrcAL->Options >> goColSizing >> goRowSizing;
	  SrcAL->Options=SrcAL->Options>>goEditing;
	  bProc->Enabled=false;
	  DelColAL->Enabled = false;
	  bDelRangeColAL->Enabled = false;
	  bFontAL->Enabled=false;
	  ClearAL->Enabled=false;


	}
	N26->Enabled= true;
	Caption = "Определитель пропускной способности - " + ExtractFileName(SaveGr->FileName)+ "* ";
}
//---------------------------------------------------------------------------

////---------------------------------------------------------------------------
//

//
  //---------------------------------------------------------------------------

void __fastcall TTForm1::SrcCDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State)
{
	 float d;
  if ((!TryStrToFloat(SrcC->Cells[ACol][ARow], d) || d < 0) && ACol > 0) {
	if(SrcC->Cells[ACol][ARow]==L"") {

	  SrcC->Canvas->Brush->Color = clInfoBk;
	  TRect r = Rect;
	  SrcC->Canvas->TextRect(r,r.Left+6,r.Top+2,SrcC->Cells[ACol][ARow]);
	}
	else {
	  SrcC->Canvas->Brush->Color = (TColor)0x008080FF;
	  TRect r = Rect;
	  SrcC->Canvas->TextRect(r,r.Left+6,r.Top+2,SrcC->Cells[ACol][ARow]);
	}
  }
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::bFontCClick(TObject *Sender)
{
	fdGrid->Font=SrcC->Font;
	if(!fdGrid->Execute())
		return;
	SrcC->Font=fdGrid->Font;
	SrcC->Canvas->Font->Assign(SrcC->Font);
	SrcC->DefaultRowHeight=SrcC->Canvas->TextHeight(L"hy")+4;

	if(cbEditAutoWidthC->Checked){
		AdjustGridColWidths(SrcC);
		SrcC->Options = SrcC->Options >> goColSizing;
	}
	else
		SrcC->Options = SrcC->Options << goColSizing;
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::bFontALClick(TObject *Sender)
{
 fdGrid->Font=SrcAL->Font;
	if(!fdGrid->Execute())
		return;
	SrcAL->Font=fdGrid->Font;
	SrcAL->Font=fdGrid->Font;
	SrcAL->Canvas->Font->Assign(SrcAL->Font);
	SrcAL->DefaultRowHeight=SrcAL->Canvas->TextHeight(L"hy")+4;

	if(cbEditAutoWidthAL->Checked){
		AdjustGridColWidths(SrcAL);
		SrcAL->Options = SrcAL->Options >> goColSizing;
	}
	else
		SrcAL->Options = SrcAL->Options << goColSizing;
}
//---------------------------------------------------------------------------
void __fastcall TTForm1::ApplicationEvents1hint(TObject *Sender)
{
	sbInfo->SimpleText=Application->Hint;
}

void __fastcall TTForm1::ApplicationEvents1ActionExecute(TBasicAction *Action, bool &Handled)

{
    //
}
//---------------------------------------------------------------------------


typedef float TCmpFunc(const UnicodeString &s1, const UnicodeString &s2);

float cmpFunc1 (const UnicodeString &s1, const UnicodeString &s2){
	return   StrToFloat(s1) - StrToFloat(s2);
}
const int MIN_COL_WIDTH = 20;
void __fastcall TTForm1::SrcCDblClick(TObject *Sender)
{
	for(int i = 0; i < size_C; i++){
		if(SrcC->Cells[i+1][1] == "")
			SrcC->Cells[i+1][1] = IntToStr(-1);
	}

	for(int i = 0; i < size_al; i++){
		if(SrcAL->Cells[i+1][1] == "")
			SrcAL->Cells[i+1][1] = IntToStr(-1);
		if(SrcAL->Cells[i+1][2] == "")
			SrcAL->Cells[i+1][2] = IntToStr(-1);
	}
	TPoint p;
	GetCursorPos(&p);
	p=((TStringGrid*)Sender)->ScreenToClient(p);
	//p=((TStringGrid*)Sender)->CalCursorPos();

	if(GetCursor()==Screen->Cursors[crHSplit]){

		TGridCoord gc = ((TStringGrid*)Sender)->MouseCoord(p.X-4, p.Y);
		int w = CalcGridColWidth((TStringGrid*)Sender, gc.X);
		if(((TStringGrid*)Sender)->ColWidths[gc.X]!=w)
			((TStringGrid*)Sender)->ColWidths[gc.X]=w;
		else
		((TStringGrid*)Sender)->ColWidths[gc.X]= MIN_COL_WIDTH;

	}
	else{
//
		TGridCoord gc = ((TStringGrid*)Sender)->MouseCoord(p.X, p.Y);
		if (gc.X==0) {        //заголовок строки

			int i = abs(FSortedRowNbr)-1;
//
		   if(FSortedRowNbr){

			((TStringGrid*)Sender)->Cells[0][i] =
				((TStringGrid*)Sender)->Cells[0][i].SubString(1,
					((TStringGrid*)Sender)->Cells[0][i].Length()-2);

		   }
		   if(cbEditAutoWidthC->Checked)
			((TStringGrid*)Sender)->ColWidths[i]=
				CalcGridColWidth(((TStringGrid*)Sender), i);

              //FCurCellText
//         индекс нового столбца
		   if(FSortedRowNbr && i==gc.Y)
			  FSortedRowNbr = -FSortedRowNbr;
		   else
			FSortedRowNbr = gc.Y+1;
//
		   i=gc.Y;
//
		   if(FSortedRowNbr < 0)
			((TStringGrid*)Sender)->Cells[0][i]=
				((TStringGrid*)Sender)->Cells[0][i] + L" \x25b6";
		   else
			((TStringGrid*)Sender)->Cells[0][i]=
				((TStringGrid*)Sender)->Cells[0][i] + L" \x25c0";

			if(cbEditAutoWidthC->Checked)
				((TStringGrid*)Sender)->ColWidths[i]=
					CalcGridColWidth(((TStringGrid*)Sender), i);

			((TStringGrid*)Sender)->Cols[((TStringGrid*)Sender)->Col]->Objects[0] =
				(TObject*)true;

			SortGridByRow((TStringGrid*)Sender, i, FSortedRowNbr>0,
							cmpFunc1);
									/*? cmpFunc1 : cmpFunc2*/

//
			for (int i = 1; i < ((TStringGrid*)Sender)->ColCount; i++) {
				if (((TStringGrid*)Sender)->Cols[i]->Objects[0]) {
					((TStringGrid*)Sender)->Cols[i]->Objects[0] = (TObject*)false;
					((TStringGrid*)Sender)->Col = i;
					break;
				}
			}

		}
//
//
	}
	for(int i = 0; i < size_C; i++)
		if(SrcC->Cells[i+1][1] == "-1")
			SrcC->Cells[i+1][1] = "";

	for(int i = 0; i < size_al; i++){
		if(SrcAL->Cells[i+1][1] == "-1")
			SrcAL->Cells[i+1][1] = "";
		if(SrcAL->Cells[i+1][2] == "-1")
			SrcAL->Cells[i+1][2] = "";
	}
	N26->Enabled = false;
	//Caption = L"Определитель пропускной способности "+ExtractFileName(SaveGr->FileName) + L"*";
}

  int CalcGridColWidth(TStringGrid *grid, int colIdx){

	if(!grid || colIdx<0 || colIdx >= grid->ColCount)
		return 0;

	grid -> Canvas -> Font->Assign(grid->Font);

	int maxWidth = 0;
	for(int i = 0; i < grid->ColCount; i++){

		int textWidth = grid->Canvas->TextWidth(grid->Cells[colIdx][i]);
		if (textWidth > maxWidth)
			maxWidth = textWidth;
	}
    //Caption = L"Определитель пропускной способности "+ExtractFileName(SaveGr->FileName) + L"*";
	return maxWidth + MIN_COL_WIDTH;
  }



void SortGridByRow(TStringGrid *grid, int rowIdx, bool ascending, TCmpFunc cmpFunc) {
	TStrings *row = grid->Rows[rowIdx];
	TStrings *tmpCol = new TStringList();
	try {
		for (int i = grid->FixedCols; i < grid->ColCount - 1; i++) {
			for (int j = i + 1; j < grid->ColCount; j++) {
				if ((cmpFunc(row->Strings[i], row->Strings[j]) > 0 && ascending) ||
					(cmpFunc(row->Strings[i], row->Strings[j]) < 0 && !ascending)) {
					tmpCol->Assign(grid->Cols[i]);
					grid->Cols[i]->Assign(grid->Cols[j]);
					grid->Cols[j]->Assign(tmpCol);
				}
			}
		}
	} __finally {
		delete tmpCol;
	}
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::cbEditAutoWidthCClick(TObject *Sender)
{
	if(Sender==cbEditAutoWidthC)
		A2->Checked = cbEditAutoWidthC->Checked;
	else{
		cbEditAutoWidthC->OnClick = NULL;
		try{
			cbEditAutoWidthC->Checked = A2->Checked;
		}
		__finally{
			cbEditAutoWidthC->OnClick = cbEditAutoWidthCClick;
		}
	}
	if(cbEditAutoWidthC->Checked){
		AdjustGridColWidths(SrcC);
		SrcC->Options = SrcC->Options >> goColSizing >> goRowSizing;
	}
	else
		SrcC->Options = SrcC->Options << goColSizing << goRowSizing;


}
//---------------------------------------------------------------------------
int AdjustGridColWidths(TStringGrid *grid){

	if(!grid)
		return 0;
	int totalWidth = 0;
	for (int j=0; j<grid->ColCount; j++) {
		int w = CalcGridColWidth(grid, j);
		grid->ColWidths[j] = w;
		totalWidth += w;
	}
	if(!(grid->Options * (TGridOptions() << goFixedVertLine << goVertLine)).Empty())
		totalWidth += grid->ColCount * grid->GridLineWidth;
	return totalWidth;
}

//---------------------------------------------------------------------------
void __fastcall TTForm1::cbEditAutoWidthALClick(TObject *Sender)
{
	if(Sender==cbEditAutoWidthAL)
		A1->Checked = cbEditAutoWidthAL->Checked;
	else{
		cbEditAutoWidthAL->OnClick = NULL;
		try{
			cbEditAutoWidthAL->Checked = A1->Checked;
		}
		__finally{
			cbEditAutoWidthAL->OnClick = cbEditAutoWidthALClick;
		}
	}

	if(cbEditAutoWidthAL->Checked){
		AdjustGridColWidths(SrcAL);
		SrcAL->Options = SrcAL->Options >> goColSizing >> goRowSizing;
	}
	else
		SrcAL->Options = SrcAL->Options << goColSizing << goRowSizing;
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::cbEditAutoWidthResClick(TObject *Sender)
{
	if(cbEditAutoWidthRes->Checked){
		AdjustGridColWidths(SrcRes);
		SrcRes->Options = SrcRes->Options >> goColSizing >> goRowSizing;
	}
	else
		SrcRes->Options = SrcRes->Options << goColSizing << goRowSizing;
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::N6Click(TObject *Sender)
{
   Close();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TTForm1::N2Click(TObject *Sender)
{
	if(!CheckChangesAndSave())
		return;

	SaveGr->FileName = L"";
	N26->Enabled = false;
	Caption = "<Безымянный>";
	for (int i = 1; i < SrcAL->ColCount; i++) {
	  SrcAL ->Cells[i][0] = L"";
	  //delete SrcC->Objects[i][1];
 }
 //SrcC->ColCount=1;
	  SrcAL->ColCount=2;
	  SrcAL->ColWidths[1]=-1;

	  bProc->Enabled=false;
	  DelColAL->Enabled = false;
	  bDelRangeColAL->Enabled = false;
	  bFontAL->Enabled=false;
	  ClearAL->Enabled=false;
	  ////////////////////////////////////////////
	  for (int i = 1; i < SrcC->ColCount; i++) {
	  SrcC ->Cells[i][0] = L"";
	  //delete SrcC->Objects[i][1];
	  }
	  SrcC->ColCount=2;
	  SrcC->ColWidths[1]=-1;

	  bProc->Enabled=false;
	  DelColC->Enabled = false;
	  bDelRangeCol->Enabled = false;
	  bFontC->Enabled=false;
	  ClearC->Enabled=false;


	for (int i = 0; i < SrcVsT->ColCount; i++)
	  SrcVsT ->Cells[i][1] = L"";
	for (int i = 0; i < SrcNKT->ColCount; i++)
	  SrcNKT ->Cells[i][1] = L"";

	  bProc->Enabled=false;
	  DelColAL->Enabled = false;
	  bDelRangeColAL->Enabled = false;
	  bFontAL->Enabled=false;
	  ClearAL->Enabled=false;

	  DelColC->Enabled = false;
	  bDelRangeCol->Enabled = false;
	  bFontC->Enabled=false;
	  ClearC->Enabled=false;


}

//---------------------------------------------------------------------------
void __fastcall TTForm1::CheckBox2Click(TObject *Sender)
{
	if(CheckBox2->Checked == false)
		QVgraph->View3D = false;

	if(CheckBox2->Checked==true)
	   QVgraph->View3D = true;

}
//---------------------------------------------------------------------------

void __fastcall TTForm1::SrcCGetEditText(TObject *Sender, int ACol, int ARow, UnicodeString &Value)

{
	FCurCellText = Value;
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::SrcALKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (!SrcAL->EditorMode)
		return;
	if (Key==VK_ESCAPE && SrcAL->EditorMode) {
		SrcAL->Cells[SrcAL->Col][SrcAL->Row]=FCurCellText2;
		return;
	}
//	if (prevCellValue!= FCurCellText2)
//		Caption = "Определитель пропускной способности - " + ExtractFileName(SaveGr->FileName)+ "* ";

	if(!((Key >= L'0' && Key <= L'9')  || Key!=L'-'  || Key==L'+' || Key == FormatSettings.DecimalSeparator ||
		 Key ==L'e' || Key ==L'E') && Key!=VK_BACK && Key!=VK_RETURN && Key!=3 && Key!=22 &&
		 Key!= 24 && Key!= 26){
		 //bProc1->Enabled=false;
		 sbInfo ->SimpleText = L"Недопустимый символ '" + UnicodeString(Key) + L'\'';
		 Key = 0;
	}
	else {
		sbInfo->SimpleText=L"";
		bProc->Enabled=true;
	}
	SrcAL->Cells[0][0] = "№";
	SrcAL->Cells[1][0] = "1";
	SrcAL->Cells[0][1] = "a";
	SrcAL->Cells[0][2] = "l";
    N26->Enabled = false;
    //Caption = "Определитель пропускной способности - " + ExtractFileName(SaveGr->FileName)+ "* ";
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::SrcALGetEditText(TObject *Sender, int ACol, int ARow, UnicodeString &Value)

{
	FCurCellText2 = Value;
	SrcAL->Cells[0][0] = "№";
	SrcAL->Cells[1][0] = "1";
	SrcAL->Cells[0][1] = "a";
	SrcAL->Cells[0][2] = "l";

}
//---------------------------------------------------------------------------

void __fastcall TTForm1::SrcNKTGetEditText(TObject *Sender, int ACol, int ARow, UnicodeString &Value)

{
	FCurCellText3 = Value;
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::SrcNKTKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (!SrcNKT->EditorMode)
		return;
	if (Key==VK_ESCAPE && SrcNKT->EditorMode) {
		SrcNKT->Cells[SrcNKT->Col][SrcNKT->Row]=FCurCellText3;
		return;
	}

	if(!((Key >= L'0' && Key <= L'9')  || Key==L'-'  || Key==L'+' || Key == FormatSettings.DecimalSeparator ||
		 Key ==L'e' || Key ==L'E') && Key!=VK_BACK && Key!=VK_RETURN && Key!=3 && Key!=22 &&
		 Key!= 24 && Key!= 26){
		 //bProc1->Enabled=false;
		 sbInfo ->SimpleText = L"Недопустимый символ '" + UnicodeString(Key) + L'\'';
		 Key = 0;
	}
	else {
		sbInfo->SimpleText=L"";
        bProc->Enabled=true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::SrcVsTKeyPress(TObject *Sender, System::WideChar &Key)
{
	if (!SrcVsT->EditorMode)
		return;
	if (Key==VK_ESCAPE && SrcVsT->EditorMode) {
		SrcVsT->Cells[SrcVsT->Col][SrcVsT->Row]=FCurCellText4;
		return;
	}

	if(!((Key >= L'0' && Key <= L'9')  || Key==L'-'  || Key==L'+' || Key == FormatSettings.DecimalSeparator ||
		 Key ==L'e' || Key ==L'E') && Key!=VK_BACK && Key!=VK_RETURN && Key!=3 && Key!=22 &&
		 Key!= 24 && Key!= 26){
		 //bProc1->Enabled=false;
		 sbInfo ->SimpleText = L"Недопустимый символ '" + UnicodeString(Key) + L'\'';
		 Key = 0;
	}
	else {
		sbInfo->SimpleText=L"";
		bProc->Enabled=true;
	}
}
//---------------------------------------------------------------------------


void __fastcall TTForm1::SrcVsTGetEditText(TObject *Sender, int ACol, int ARow, UnicodeString &Value)

{
	FCurCellText4 = Value;
}
//---------------------------------------------------------------------------


void __fastcall TTForm1::FormAfterMonitorDpiChanged(TObject *Sender, int OldDPI, int NewDPI)

{
//	if(a and b and c and d)
//		bProc->Enabled=true;
//	else
//		bProc->Enabled=false;
}
//---------------------------------------------------------------------------

//bool oshib(TStringGrid*SrcC,TStringGrid*SrcAL,TStringGrid*SrcNKT,TStringGrid*SrcVsT,
													//TStatusBar*sbInfo, TButton*bProc){
//
// int count=0,count2=0;
//	String uncor,unacc;
//	float alCheck,сСheck,VTcheck,grafCheck;
//
//
//	for (int i=0;i<SrcC->ColCount-1;i++){
//		if(SrcC->Cells[i+1][0]==L""){
//			continue;
//		}
//		try{
//			сСheck=StrToFloat(SrcC->Cells[i+1][0]);
//			if (сСheck<=0){
//				unacc+=L"C["+IntToStr(0)+L"]"+L"["+IntToStr(i+2)+L"] ";
//				count2++;
//			}
//		}
//		catch(EConvertError &e){
//			uncor+=L"C["+IntToStr(0)+L"]"+L"["+IntToStr(i+2)+L"] ";
//			count++;
//		}
//	}
//
//	for (int i=0;i<SrcAL->ColCount-1;i++){
//		for (int j=0;j<SrcAL->RowCount;j++){
//			try{
//				alCheck=StrToFloat(SrcAL->Cells[i+1][j]);
//				if (alCheck<0){
//					unacc+=L"al["+IntToStr(j+1)+L"]"+L"["+IntToStr(i+2)+L"] ";
//					count2++;
//				}
//			}
//			catch(EConvertError &e){
//				uncor+=L"al["+IntToStr(j+1)+L"]"+L"["+IntToStr(i+2)+L"] ";
//				count++;
//			}
//
//		}
//	}
//
//	for (int i=0;i<SrcNKT->ColCount-1;i++){
//		try{
//			VTcheck=StrToFloat(SrcNKT->Cells[i][1]);
//			if(VTcheck<=0){
//				unacc+=L"Интервал,шаг,время["+IntToStr(i)+L"]"+L"["+IntToStr(1)+L"] ";
//				count2++;
//			}
//		}
//		catch(EConvertError &e){
//			uncor+=L"Интервал,шаг,время["+IntToStr(i)+L"]"+L"["+IntToStr(1)+L"] ";
//			count++;
//		}
//	}
//
//	for (int i=0;i<SrcVsT->ColCount-1;i++){
//		try{
//			grafCheck=StrToFloat(SrcVsT->Cells[i][1]);
//			if(grafCheck<0){
//				unacc+=L"График["+IntToStr(i)+L"]"+L"["+IntToStr(1)+L"] ";
//				count2++;
//			}
//		}
//		catch(EConvertError &e){
//			uncor+=L"График["+IntToStr(i)+L"]"+L"["+IntToStr(1)+L"] ";
//			count++;
//		}
//	}
//
//	if(count==0 && count2==0){
//		bProc->Enabled=True;
//		return true;
//
//	}
//	if(count2!=0 && count==0){
//		sbInfo->SimpleText=L"Недопустимые значения в ячейках : "+unacc;
//		bProc->Enabled=False;
//		return false;
//
//	}
//	sbInfo->SimpleText=L"Некорректные значения в ячейках : "+uncor;
//	bProc->Enabled=False;
//	return false;
//
//
//}



void __fastcall TTForm1::SaveGraphTypeChange(TObject *Sender)
{
  switch (static_cast<FileExtensionIndex>(SaveGraph->FilterIndex)) {
	case FileExtensionIndex::GIF:
	  selectedExtension = L".gif";
	  break;
	case FileExtensionIndex::JPEG:
	  selectedExtension = L".jpeg";
	  break;
	case FileExtensionIndex::BMP:
	  selectedExtension = L".bmp";
	  break;
	case FileExtensionIndex::CUSTOM:
	  selectedExtension = L"";
	  break;
  }
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::ODdataShow(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::N26Click(TObject *Sender)
{
   Caption = ExtractFileName(SaveGr->FileName);
   SaveData(SaveGr->FileName.IsEmpty());
}
//---------------------------------------------------------------------------
bool __fastcall TTForm1::SaveData(bool showDialog) {
	String sfname = ODdata->FileName;
	SaveGr->InitialDir = "D:\\";

  if (showDialog) {
		if (!SaveGr->Execute())
			return false;
  }

  try {

	fstream f;
	f.open(AnsiString(SaveGr->FileName).c_str(), std::ios_base::out | std::ios_base::binary);
	size_C = SrcC -> ColCount-1;
	f.write((char*)&size_C,sizeof(size_C));
	size_al = SrcAL -> ColCount-1;
	f.write((char*)&size_al,sizeof(size_al));

	for(int i = 0; i < size_C; i++){
		elem = StrToFloat(SrcC->Cells[i + 1][1]);
		f.write((char*)&elem,sizeof(elemType));
	}

	for (int i = 1; i < 3; i++) {
		for (int j = 0; j < size_al; j++) {
			elem = StrToFloat(SrcAL->Cells[j + 1][i]);
			f.write(reinterpret_cast<const char*>(&elem), sizeof(elemType));
		}
	}

	for (int i = 0; i < 3; i++) {
		elem = StrToFloat(SrcVsT->Cells[i][1]);
		f.write(reinterpret_cast<const char*>(&elem), sizeof(elemType));
	}

	for (int i = 0; i < 3; i++) {
		elem = StrToFloat(SrcNKT->Cells[i][1]);
		f.write(reinterpret_cast<const char*>(&elem), sizeof(elemType));
	}

	f.close();
//
  } catch (Exception &e) {
	Application->MessageBox(Format(L"Ошибка сохранения файла \"%s\": \"%s\"",
				 ARRAYOFCONST((SaveGr->FileName, e.Message))).w_str(),
				Application->Title.w_str(), MB_OK|MB_ICONERROR);
	SaveGr->FileName = sfname;
	return false;
  }
  N26->Enabled=false;
  return true;
}
//---------------------------------------------------------------------------
bool __fastcall TTForm1::CheckChangesAndSave() {
	if(N26->Enabled){
		if(N1->Enabled) {
			String s;
			if(!SaveGr->FileName.IsEmpty())
				s = ExtractFileName(SaveGr->FileName);
			else
				s=L"<Безымянный>";
			switch (Application->MessageBox((UnicodeString(L"Сохранить изменения в \"" + s + L"\"?")).w_str(),
				Application->Title.w_str(), MB_YESNOCANCEL|MB_ICONQUESTION))
{
					case ID_YES:
					if (!SaveData(SaveGr->FileName.IsEmpty()))
					return false;
					break;

					case ID_CANCEL:
					return false;
				}
	}
	}
  return true;
}
//---------------------------------------------------------------------------
void __fastcall TTForm1::N5Click(TObject *Sender)
{
    Caption = SaveGr->FileName;
	SaveData(true);
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::N15Click(TObject *Sender)
{
   //
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::SrcDataContextPopup(TObject *Sender, TPoint &MousePos, bool &Handled)

{
//
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::FormCreate(TObject *Sender)
{
	N26->Enabled= false;
	//Caption = "<<Безымянный>";
	int panelWidth = Panel3->Width;

	bDelRangeCol->Left = (panelWidth - bDelRangeCol->Width) / 2;

	DelColC->Left = (panelWidth - DelColC->Width) / 2;

	ClearC->Left = DelColC->Left + DelColC->Width + 20;
	bFontC ->Left = DelColC->Left + DelColC->Width + 20;

	int distanceFromRight = Panel3->Width - (ClearC->Left + ClearC->Width);

	bInsCol->Left = distanceFromRight;
	AddColC->Left = distanceFromRight;
	////////////
	bDelRangeColAL->Left = (panelWidth - bDelRangeColAL->Width) / 2;

	DelColAL->Left = (panelWidth - DelColAL->Width) / 2;

	ClearAL->Left = DelColC->Left + DelColC->Width + 20;
	bFontAL->Left = DelColC->Left + DelColC->Width + 20;

	int distanceFromRight1 = Panel4->Width - (ClearAL->Left + ClearAL->Width);

	bInsCol2->Left = distanceFromRight;
	AddColAL->Left = distanceFromRight;

	////////////
    // Расстояние между нижней границей Panel3 и нижней границей формы
	int distanceFromBottom3 = TForm1->ClientHeight - Panel3->Top - Panel3->Height;

// Расположение Panel4 так, чтобы она занимала середину между нижней границей Panel3 и нижней границей формы
	Panel4->Top = Panel3->Top + Panel3->Height + (distanceFromBottom3 - Panel4->Height) / 2 - 60;
	////////////
	//SrcAL->Parent = Panel4;

// Устанавливаем выравнивание таблицы по верхней границе панели
	//SrcAL->Align = alTop;

// Устанавливаем расстояние от верхней границы панели до верхней границы таблицы (если нужно)
	SrcAL->Top = Panel4->Top + Panel4->Height;

}
//---------------------------------------------------------------------------

void __fastcall TTForm1::N22Click(TObject *Sender)
{
	WideString str;
	TStringList *sl = new TStringList;
	for(int i = 0 ; i<SrcRes->RowCount ;++i)
	{
		if(i!=1){
			str = "\t";
			sl->Add(str);
		}
		for(int j = 0; j< SrcRes->ColCount;++j)
			str +=SrcRes->Cells[j][i]+ "\t";
			sl->Add(str);
			str = "\r" ;
			str = "";
	}
	if (SaveDialog1->Execute())
	sl->SaveToFile(SaveDialog1->FileName);
	delete sl;
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::N23Click(TObject *Sender)
{
           //         ..
}
//---------------------------------------------------------------------------


void __fastcall TTForm1::ExitClick(TObject *Sender)
{
//	if(!CheckChangesAndSave())
//		CanClose = false;

//   if (Application->MessageBox(
//		UnicodeString(L"Вы действительно хотите выйти?").w_str(),
//		L"Определитель пропускной способности", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != IDYES)
//	return;
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::SaveGrShow(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::MainMenu1Change(TObject *Sender, TMenuItem *Source, bool Rebuild)

{
//
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::SaveGrTypeChange(TObject *Sender)
{
//


}
//---------------------------------------------------------------------------

void __fastcall TTForm1::SaveDialog1Show(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::FormCloseQuery(TObject *Sender, bool &CanClose)
{

if(!CheckChangesAndSave())
	CanClose = false;
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::SrcALDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{
float d;
  if ((!TryStrToFloat(SrcAL->Cells[ACol][ARow], d) || d < 0) && ACol > 0) {
	if(SrcAL->Cells[ACol][ARow]==L"") {//Чтобы не ругался на Ctrl+Z, Enter и т.д

	  SrcAL->Canvas->Brush->Color = clInfoBk;
	  TRect r = Rect;
	  SrcAL->Canvas->TextRect(r,r.Left+6,r.Top+2,SrcAL->Cells[ACol][ARow]);
	}
	else {
	  SrcAL->Canvas->Brush->Color = (TColor)0x008080FF;
	  TRect r = Rect;
	  SrcAL->Canvas->TextRect(r,r.Left+6,r.Top+2,SrcAL->Cells[ACol][ARow]);
	}
  }
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::SrcVsTDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State)
{
 float d;

  if ((!TryStrToFloat(SrcVsT->Cells[ACol][ARow], d) || d < 0) && ACol > 0 && ARow > 0) {
	if(SrcVsT->Cells[ACol][ARow]==L"") {//Чтобы не ругался на Ctrl+Z, Enter и т.д

	  SrcVsT->Canvas->Brush->Color = clInfoBk;
	  TRect r = Rect;
	  SrcVsT->Canvas->TextRect(r,r.Left+6,r.Top+2,SrcVsT->Cells[ACol][ARow]);
	}
	else {
	  SrcVsT->Canvas->Brush->Color = (TColor)0x008080FF;
	  TRect r = Rect;
	  SrcVsT->Canvas->TextRect(r,r.Left+6,r.Top+2,SrcVsT->Cells[ACol][ARow]);
	}
  }
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::SrcNKTClick(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::SrcNKTDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State)
{
		 float d;
  if ((!TryStrToFloat(SrcNKT->Cells[ACol][ARow], d) || d < 0) && ACol > 0 && ARow > 0) {
	if(SrcNKT->Cells[ACol][ARow]==L"") {//Чтобы не ругался на Ctrl+Z, Enter и т.д

	  SrcNKT->Canvas->Brush->Color = clInfoBk;
	  TRect r = Rect;
	  SrcNKT->Canvas->TextRect(r,r.Left+6,r.Top+2,SrcNKT->Cells[ACol][ARow]);
	}
	else {
	  SrcNKT->Canvas->Brush->Color = (TColor)0x008080FF;
	  TRect r = Rect;
	  SrcNKT->Canvas->TextRect(r,r.Left+6,r.Top+2,SrcNKT->Cells[ACol][ARow]);
	}
  }
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::SaveGraphShow(TObject *Sender)
{
//
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------

void __fastcall TTForm1::SrcResDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
          TGridDrawState State)
{
	float d;
  if ((!TryStrToFloat(SrcRes->Cells[ACol][ARow], d) || d < 0) && ACol > 0 && ARow > 0) {
	if(SrcRes->Cells[ACol][ARow]==L"") {

	  SrcRes->Canvas->Brush->Color = clInfoBk;
	  TRect r = Rect;
	  SrcRes->Canvas->TextRect(r,r.Left+6,r.Top+2,SrcRes->Cells[ACol][ARow]);
	}
	else {
	  SrcRes->Canvas->Brush->Color = (TColor)0x008080FF;
	  TRect r = Rect;
	  SrcRes->Canvas->TextRect(r,r.Left+6,r.Top+2,SrcRes->Cells[ACol][ARow]);
	}
  }
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::ScrollBar1Change(TObject *Sender)
{
		// Изменяем положение легенды
		QVgraph->Legend->TopPos = -ScrollBar1->Position; // Можете также использовать Top, Right, Bottom в зависимости от необходимости

		 ScrollBar1->Max = size_C  *  size_al;

		// Обновляем график
		QVgraph->Refresh();
// QVgraph->Legend->TopPos = -ScrollBar1->Position; // Можете также использовать Top, Right, Bottom в зависимости от необходимости
//
//	int totalSize = size_C * size_al;
//	ScrollBar1->Max = (totalSize > 0) ? totalSize - ScrollBar1->PageSize : 0; // Учитываем размер ползунка
//
//	// Обновляем график
//	QVgraph->Refresh();
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TTForm1::SrcCColumnMoved(TObject *Sender, int FromIndex, int ToIndex)

{
		 SrcC->Cells[0][1] = "C";
		 SrcC->Cells[0][0] = "№";
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::SrcALColumnMoved(TObject *Sender, int FromIndex, int ToIndex)

{
   	SrcAL->Cells[0][0] = "№";
	SrcAL->Cells[1][0] = "1";
	SrcAL->Cells[0][1] = "a";
	SrcAL->Cells[0][2] = "l";
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

