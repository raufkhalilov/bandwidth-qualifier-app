//---------------------------------------------------------------------------
#include <memory>
#include <fstream>
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TTForm1 *TForm1;
//---------------------------------------------------------------------------
__fastcall TTForm1::TTForm1(TComponent* Owner)
	: TForm(Owner)
{
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


//	if (SrcNKT->Cells[2][1] != "")
//		bProc -> Enabled=True;
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

	DelColC->Enabled = true;

    size_C++;
	for(int i = 0; i < size_C; i++)
		SrcC->Cells[i+1][0] = IntToStr(i+1);

}
//---------------------------------------------------------------------------
void __fastcall TTForm1::DelColCClick(TObject *Sender)
{
	if(SrcAL->ColWidths[1]==-1)
		return;

	if(SrcC->ColCount>2){
		SrcC -> ColCount--;
		for(int i = SrcC->ColCount; i<SrcC->ColCount; i++){
			SrcC->Cols[i] = SrcC -> Cols[i+1];
		}
	}
	else{
		SrcC->ColWidths[1]=-1;
		SrcC->Options = SrcC->Options>>goEditing;
		DelColC->Enabled = false;
	}

	size_C--;
	for(int i = 0; i < size_C; i++)
		SrcC->Cells[i+1][0] = IntToStr(i+1);


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

	DelColAL->Enabled = true;

	size_al++;
	for(int i = 0; i < size_al; i++)
		SrcAL->Cells[i+1][0] = IntToStr(i+1);
}
//---------------------------------------------------------------------------
void __fastcall TTForm1::DelColALClick(TObject *Sender)
{
	SrcAL -> ColCount -= 1;
}
//---------------------------------------------------------------------------
void __fastcall TTForm1::ClearCClick(TObject *Sender)  //очстка не работает
{
 for (int i = 1; i < SrcC->ColCount; i++) {
	  SrcC ->Cells[i][0] = L"";
	  //delete SrcC->Objects[i][1];
 }
 //SrcC->ColCount=1;
	  SrcC->ColCount=2;
	  SrcC->ColWidths[1]=-1;

}
//---------------------------------------------------------------------------

void __fastcall TTForm1::ClearALClick(TObject *Sender)
{
	for (int i = 1; i < SrcAL->ColCount; i++) {
		for (int j = 0; j < SrcAL->RowCount; j++)
			SrcAL ->Cells[i][j] = L"";
	}
}
//---------------------------------------------------------------------------


void __fastcall TTForm1::dowloadClick(TObject *Sender)
{
	if(!ODdata->Execute()){
		return;
	}
	//bProc->Enabled=false;
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

//	if (SrcNKT->Cells[2][1] != "")
//			bProc -> Enabled=True;

//		fn.close();
//		ShowMessage(L"Файл содержит некорректные данные.");
//		return;
//	}


	cbColRangeSelectClick(NULL);
	DelColC->Enabled = true;

//	if(cbEditAutoWidth->Checked)
//		AdjustGridColWidths(SrcC);

}
//---------------------------------------------------------------------------

void __fastcall TTForm1::bProcClick(TObject *Sender)
{
	for(int i = 0; i <= SrcRes->ColCount; i++){
		for(int j = 0; j <= SrcRes->RowCount; j++){
			SrcRes->Cells[i][j] = L"";
		}
	}

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
			SrcRes->Cells[i - 1][0] = "a= "+SrcAL->Cells[j][1] + "\\"
				+"l= " + SrcAL->Cells[j][2];
			i++;
		}
	}

//	double N, Q;
	for (int i = 1; i < SrcC->ColCount; i++) {
		TLineSeries *series = new TLineSeries(QVgraph);
		QVgraph->AddSeries(series);
		AnsiString legendText = "при С" + IntToStr(i);
		series->Title = legendText;
		for (int j = 1; j < SrcAL->ColCount; j++) {
			for (int v = v1; v < v2 + step; v += step) {
				N = 3600 * v1 / (StrToFloat(SrcAL->Cells[j][1]) +
								 StrToFloat(SrcAL->Cells[j][2]) +
								 v * t + StrToFloat(SrcC->Cells[i][1]) * v * v);
				Q = N * n * k;
				SrcRes->Cells[j + (SrcAL->ColCount)*i - (SrcAL->ColCount)][(v - v1) / step + 1] = N;
				series->AddXY(v, Q);
			}
		}

	}

//---------------------------------------------------------------------------
}
void __fastcall TTForm1::SrcCKeyPress(TObject *Sender, System::WideChar &Key)
{
	if(!((Key >= L'0' && Key <= L'9')  || Key==L'-'  || Key==L'+' || Key == FormatSettings.DecimalSeparator ||
		 Key ==L'e' || Key ==L'E') && Key!=VK_BACK && Key!=VK_RETURN && Key!=3 && Key!=22 &&
		 Key!= 24 && Key!= 26 ){
		 //bProc1->Enabled=false;
		 sbInfo ->SimpleText = L"Недопустимый символ '" + UnicodeString(Key) + L'\'';
		 Key = 0;
	}

	else {
		sbInfo->SimpleText=L"";
	}
}
//---------------------------------------------------------------------------


void __fastcall TTForm1::savegridClick(TObject *Sender)
{
//	 // Выполняем диалог сохранения файла.
//	if (SaveGr->Execute())
//	{
//		// Сначала проверяем, существует ли файл.
//		if (FileExists(SaveGr->FileName))
//		{
//			// Если он существует, выдать исключение.
//			throw(Exception("Файл уже существует. Невозможно перезаписать."));
//		}
//		else
//		{
//			// В противном случае сохраните строки поля заметки в файл.
//			Memo1->Lines->SaveToFile(SaveGr->FileName);
//		}
//	}

//	if (!SaveGr->Execute())
//		return;
//
//
//	for (int i = 1; i < SrcRes->ColCount; i++) {
//		for (int j = 0; j < SrcRes->RowCount; j++) {
//			AnsiString st = SrcRes->Cells[j][i];
//			st.SaveToFile(SaveGr->FileName);
//		}
//	}


//	if (!SaveGraph->Execute())
//		return;
//	SrcRes->SaveToBitmapFile(SaveGraph->FileName);


//	std::auto_ptr<TStringList> SL(new TStringList);
//
//	for(int i=0;i<SrcRes->RowCount;i++)
//	{
//		SrcRes->Rows[i]->Delimiter=L' ';
//		SL->Add(SrcRes->Rows[i]->DelimitedText);
//	}
//	SL->SaveToFile("1.txt");

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


}

//---------------------------------------------------------------------------


void __fastcall TTForm1::SaveChartClick(TObject *Sender)
{
	if (!SaveGraph->Execute())
		return;
	QVgraph->SaveToBitmapFile(SaveGraph->FileName);

 }
//---------------------------------------------------------------------------
void __fastcall TTForm1::SrcCSetEditText(TObject *Sender, int ACol, int ARow, const UnicodeString Value)

{
	float d;
	if (!TryStrToFloat(SrcC->Cells[ACol][ARow], d)) {
	sbInfo -> SimpleText = UnicodeString(L"\"" + SrcC -> Cells[ACol][ARow] + L"\" не является корректным значением");
	}
}
//---------------------------------------------------------------------------
void __fastcall TTForm1::SrcALSetEditText(TObject *Sender, int ACol, int ARow, const UnicodeString Value)

{
	float d;
	if (!TryStrToFloat(SrcAL->Cells[ACol][ARow], d)) {
		sbInfo -> SimpleText = UnicodeString(L"\"" + SrcAL -> Cells[ACol][ARow] + L"\" не является корректным значением");
	}
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::SrcVsTSetEditText(TObject *Sender, int ACol, int ARow, const UnicodeString Value)

{
	float d;
	if (!TryStrToFloat(SrcVsT->Cells[ACol][ARow], d)) {
		sbInfo -> SimpleText = UnicodeString(L"\"" + SrcVsT -> Cells[ACol][ARow] + L"\" не является корректным значением");
	}
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::SrcNKTSetEditText(TObject *Sender, int ACol, int ARow, const UnicodeString Value)

{
	float d;
	if (!TryStrToFloat(SrcNKT->Cells[ACol][ARow], d)) {
		sbInfo -> SimpleText = UnicodeString(L"\"" + SrcNKT -> Cells[ACol][ARow] + L"\" не является корректным значением");
	}
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TTForm1::cbColRangeSelectClick(TObject *Sender)
{
	if(cbColRangeSelect->Checked)
		SrcC->Options = SrcC->Options >> goEditing;
	else
		if(SrcC->ColWidths[1] == -1)
			SrcC->Options=SrcC->Options >> goEditing /*>> goRowSelect*/;
		else
			SrcC->Options=SrcC->Options << goEditing /*<< goRowSelect*/;
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::cbColRangeSelectALClick(TObject *Sender)
{
	 if(cbColRangeSelectAL->Checked)
		SrcAL->Options = SrcAL->Options >> goEditing;
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
		for(int i = SrcC->ColCount-1; i>=SrcC->Col; i--){

			SrcC->Cols[i+1] = SrcC -> Cols[i];
//			SrcC -> ColCount++;

		}

	SrcC->Cols[SrcC->Col] -> Clear();
	SrcC->SetFocus();
	DelColC->Enabled = true;

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
	  SrcC->Options=SrcC->Options>>goEditing;
	  bDelRangeCol->Enabled=true;

	}
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::bDelRangeColALClick(TObject *Sender)
{
	if(SrcAL->ColWidths[1]==-1)
		return;
//	if (Application->MessageBox(Format(L"Вы действительно хотите удалить \"запись\" №%d?",
//		ARRAYOFCONST((SrcC->Col))).c_str(),
//		MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2) != ID_YES)
//
//		return;

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
	  SrcAL->Options=SrcAL->Options>>goEditing;
	  bDelRangeCol->Enabled=true;

	}
}
//---------------------------------------------------------------------------

//const int MIN_COL_WIDTH = 12;
//void __fastcall TTForm1::SrcCDblClick(TObject *Sender)
//{
//	TPoint p;
//	GetCursorPos(&p);
//	p=((TStringGrid*)Sender)->ScreenToClient(p);
//	//p=((TStringGrid*)Sender)->CalCursorPos();
//
//	if(GetCursor()==Screen->Cursors[crHSplit]){
//
//		TGridCoord gc = ((TStringGrid*)Sender)->MouseCoord(p.X-4, p.Y);
//		int w = CalcGridColWidth((TStringGrid*)Sender, gc.X);
//		if(((TStringGrid*)Sender)->ColWidths[gc.X]!=w)
//			((TStringGrid*)Sender)->ColWidths[gc.X]=w;
//		else
//		((TStringGrid*)Sender)->ColWidths[gc.X]= MIN_COL_WIDTH;
//	}
//}
//
////---------------------------------------------------------------------------
//
//  int CalcGridColWidth(TStringGrid *grid, int colIdx){
//
//	if(!grid || colIdx<0 || colIdx >= grid->ColCount)
//		return 0;
//
//	grid -> Canvas -> Font->Assign(grid->Font);
//
//	int maxWidth = 0;
//	for(int i = 0; i < grid->ColCount; i++){
//
//		int textWidth = grid->Canvas->TextWidth(grid->Cells[colIdx][i]);
//		if (textWidth > maxWidth)
//			maxWidth = textWidth;
//	}
//	return maxWidth + MIN_COL_WIDTH;
//  }
//
  //---------------------------------------------------------------------------

void __fastcall TTForm1::SrcCDrawCell(TObject *Sender, int ACol, int ARow, TRect &Rect,
		  TGridDrawState State)
{
	TCanvas *a = ((TStringGrid*)Sender)->Canvas;
    float d;

    // Проверка на выделение ячейки
    if (State.Contains(gdSelected))
    {
        // Установка цвета фона для выделенных ячеек (например, светло-голубой)
        a->Brush->Color = clSkyBlue;
    }
    else
    {
        // Установка цвета фона ячейки в белый по умолчанию
        a->Brush->Color = clWhite;

        // Если ячейка является зафиксированной, установите цвет фона на зеленый
        if (State.Contains(gdFixed))
            a->Brush->Color = clMoneyGreen;

        // Если ячейка не является зафиксированной и пустая, установите цвет фона на светло-желтый
        else if (((TStringGrid*)Sender)->Cells[ACol][ARow] == L"")
            a->Brush->Color = clCream; // TColor(RGB(251, 251, 230));
    }

    // Заполнение фона ячейки выбранным цветом
    a->FillRect(Rect);

    // Определение прямоугольника для отображения текста ячейки
    TRect r = Rect;
    r.left += 2;
    r.top += 2;

    // Рисование текста ячейки по центру
    DrawText(a->Handle, ((TStringGrid*)Sender)->Cells[ACol][ARow].t_str(), -1, (TRect*)&r, DT_CENTER);
}
//---------------------------------------------------------------------------

void __fastcall TTForm1::bFontCClick(TObject *Sender)
{
	fdGrid->Font=SrcC->Font;
	if(!fdGrid->Execute())
		return;
	SrcC->Font=fdGrid->Font;
}
//---------------------------------------------------------------------------
//void __fastcall sgFontChanged(TObject *Sender){
//
//	SrcC->Canvas->Font->Assign(SrcC->Font);
//	SrcC->DefaultRowHeigh=SrcC->Canvas->TextHeight(L"hy")+4;
//	//if()
//}
//---------------------------------------------------------------------------
//__fastcall TForm1::TForm1(TComponent* Owner)
//	: TForm(Owner)
//{
//
//	SrcC->Font->OnChange= sgFontChanged;
//
//}

//---------------------------------------------------------------------------

void __fastcall TTForm1::bFontALClick(TObject *Sender)
{
 fdGrid->Font=SrcAL->Font;
	if(!fdGrid->Execute())
		return;
	SrcAL->Font=fdGrid->Font;

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


//---------------------------------------------------------------------------

void __fastcall TTForm1::CheckBox1Click(TObject *Sender)
{
	if(CheckBox1->Checked==false){


		TChartSeries *series = QVgraph->SeriesList->Items[0];
		series->Clear();



	}
		if(CheckBox1->Checked==true){
           	while (QVgraph->SeriesList->Count > 0) {
				TChartSeries *series = QVgraph->SeriesList->Items[QVgraph->SeriesList->Count - 1];
				series->Clear();
				QVgraph->SeriesList->Delete(QVgraph->SeriesList->Count - 1);
			delete series;
			}


			for (int i = 1; i < SrcC->ColCount; i++) {
				TLineSeries *series = new TLineSeries(QVgraph);
				QVgraph->AddSeries(series);
				AnsiString legendText = "при С" + IntToStr(i);
				series->Title = legendText;
				for (int j = 1; j < SrcAL->ColCount; j++) {
					for (int v = v1; v < v2 + step; v += step) {
						N = 3600 * v1 / (StrToFloat(SrcAL->Cells[j][1]) +
									 StrToFloat(SrcAL->Cells[j][2]) +
								 v * t + StrToFloat(SrcC->Cells[i][1]) * v * v);
						Q = N * n * k;
						SrcRes->Cells[j + (SrcAL->ColCount)*i - (SrcAL->ColCount)][(v - v1) / step + 1] = N;
						series->AddXY(v, Q);
					}
				}

			}
		}





}
//---------------------------------------------------------------------------

