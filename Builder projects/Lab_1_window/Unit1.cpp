//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
double x, y, z, a, b , rez;
x = StrToFloat(Edit1->Text);
y = StrToFloat(Edit2->Text);
z = StrToFloat(Edit3->Text);
a = pow(y,(x+1))/(pow(fabs(y-2),(1.0/3))+3);
b = (x+(y/2))*pow((x+1),(-1.0/sin(z)))/2/fabs(x+y);

rez = a+b;

Memo1->Lines->Add("Результат = "+FloatToStr(rez));
}
//---------------------------------------------------------------------------
