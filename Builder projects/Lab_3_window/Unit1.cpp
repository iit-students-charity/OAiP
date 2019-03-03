//---------------------------------------------------------------------------
#include <math.h>
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
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
void __fastcall TForm1::FormCreate(TObject *Sender)
{
 Edit1 -> Text="0,1";
 Edit2 -> Text="1";
 Edit3-> Text="0,1";
 Edit4-> Text="3";
 Memo1 -> Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//создание и воод пременых
int k, n;
float fct, fct_;
float a,b,h,x,r,Y;
double S;
a=StrToFloat(Edit1->Text);
b=StrToFloat(Edit2->Text);
h=StrToFloat(Edit3->Text);
n=StrToFloat(Edit4->Text);
//Общие вычисления
        for (x=a; x<=b; x+=h)
        {
        S=0;
        Y=(exp(x)-exp(-x))/2.;
        for (k=n; k>=0; k--)
                 {
                  fct_=1;
                  for (fct=1; fct<=2*k+1; fct++)
                        {
                        fct_*=fct;
                        }
                S+=pow(x,2*k+1)/fct_;
                Y=(exp(x)-exp(-1*x))/2.;
                }
                Memo1->Lines->Add("при x= "+FloatToStrF(x,ffFixed,8,2)
                        +" S= "+FloatToStrF(S,ffFixed,8,5) +" Y= "+FloatToStrF(Y,ffFixed,8,5));
        }



}
//---------------------------------------------------------------------------




