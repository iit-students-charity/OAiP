//---------------------------------------------------------------------------
#include <math.h>
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
double S(double, int);
double Y(double);
double Mod(double, int);
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
 RadioGroup1->ItemIndex=0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
int n;
double a,b,h,x;
a=StrToFloat(Edit1->Text);
b=StrToFloat(Edit2->Text);
h=StrToFloat(Edit3->Text);
n=StrToFloat(Edit4->Text);
for(x=a; x<=b; x+=h)
        {
        switch (RadioGroup1->ItemIndex)
                {
                case 0: Memo1->Lines->Add(("x = "+FloatToStrF(x,ffFixed,8,2))+
                " rezultat -  "
          +FloatToStrF(S(x,n),ffFixed,8,4)); break;
                case 1: Memo1->Lines->Add(("x = "+FloatToStrF(x,ffFixed,8,2))+
                " rezultat -  "
          +FloatToStrF(Y(x),ffFixed,8,4)); break;
                case 2: Memo1->Lines->Add(("x = "+FloatToStrF(x,ffFixed,8,2))+
                " rezultat -  "
          +FloatToStrF(Mod(x,n),ffFixed,8,4)); break;
                }
        }
}
//---------------------------------------------------------------------------



double S (double x, int n)
{
int k;
float fct_,fct;
        double rez =0;
        for (k=n; k>=0; k--)
        {
        fct_=1;
        for (fct=1; fct<=2*k+1; fct++)
                  {
                  fct_*=fct;
                  }
        rez+=pow(x,2*k+1)/fct_;
        }
        return rez;
 }

double Y(double x)
{
        double rez=(exp(x)-exp(-x))/2.0;
        return rez;
}

double Mod(double x, int n)
{
 double rez=fabs((Y(x)-S(x,n)));
 return rez;
}



