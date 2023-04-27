#include <vcl.h>
#pragma hdrstop
#include<stdio.h>
#include<math.h>
#include "Unit1.h"
#include "ps.h"
int lcode=1;
char ms[350],msg[9];
//-------------------------------------------------------------------------—
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//-------------------------------------------------------------------------—
__fastcall TForm1::TForm1(TComponent* Owner)
: TForm(Owner)
{
}
//-------------------------------------------------------------------------—

void __fastcall TForm1::ToolButton4Click(TObject *Sender)
{
    Form1->Close();
}
//-------------------------------------------------------------------------—
void __fastcall TForm1::ToolButton2Click(TObject *Sender)
{
    Edit43->Visible=false;
    Edit44->Visible=false;
    Edit45->Visible=false;
    Edit17->Text="30";
    Edit18->Text="200";
    Edit19->Text="1";
    Edit20->Text="12";
    Edit25->Text="1";
    Edit26->Text="1";
    Edit27->Text="2";
    Edit28->Text="1";
    Edit29->Text="-1";
    Edit30->Text="-1";
    Edit31->Text="0.7";
    Edit32->Text="470";
    Edit6->Text="-1";
    Edit8->Text="1.0";
    Edit37->Text="1440";
    Edit38->Text="0";
    Edit39->Text="1";
    Edit40->Text="0.01";
    Form1->Edit42->Color=clYellow;
    Form1->Edit42->Text=" 2";
    ListBox1->Items->Clear();
    if(lcode==1){
        sprintf(ms,"For the next 24 hours - snow is in instable state; avalanches, having volume of up to 0.1 of amount");
        ListBox1->Items->Add(ms);
        sprintf(ms,"of snow in the site, are possible");
        ListBox1->Items->Add(ms);
    }
    if(lcode==0){
        sprintf(ms,"На последующие сутки - снег находится в неустойчивом состоянии, возможен сход лавин объемом");
        ListBox1->Items->Add(ms);
        sprintf(ms,"до 10 % от количества снега в очаге.");
        ListBox1->Items->Add(ms);
    }
}
//-------------------------------------------------------------------------—

void __fastcall TForm1::ToolButton1Click(TObject *Sender)
{
    ps pss;
    pss.alff=atof(Edit17->Text.c_str());
    pss.all=atof(Edit18->Text.c_str());
    pss.hhh=atof(Edit19->Text.c_str());
    pss.qqq=atof(Edit20->Text.c_str());
    pss.ooo=atof(Edit25->Text.c_str());
    pss.v=atof(Edit26->Text.c_str());
    pss.qf=atof(Edit27->Text.c_str());
    pss.ie=atof(Edit28->Text.c_str());
    pss.t=atof(Edit29->Text.c_str());
    pss.t10=atof(Edit30->Text.c_str());
    pss.h430=atof(Edit31->Text.c_str());
    pss.ro430=atof(Edit32->Text.c_str());
    pss.t24=atof(Edit6->Text.c_str());
    pss.tau=atof(Edit37->Text.c_str());
    pss.h0=atof(Edit38->Text.c_str());
    pss.h10=atof(Edit39->Text.c_str());
    pss.dh=atof(Edit40->Text.c_str());
    pss.p_e=atof(Edit8->Text.c_str());
    pss.frcst();
    sprintf(msg," %d",pss.icod);
    Edit42->Text=msg;
    if(pss.icod==1){
        Form1->Edit42->Color=clLime;
        Edit43->Visible=false;
        Edit44->Visible=false;
        Edit45->Visible=false;
        ListBox1->Items->Clear();
        if(lcode==1){
            sprintf(ms,"No avalanche risk.");
            ListBox1->Items->Add(ms);
        }
        if(lcode==0){
            sprintf(ms,"Нелавиноопасно.");
            ListBox1->Items->Add(ms);
        }
    }
    if(pss.icod==2){
        Form1->Edit42->Color=clYellow;
        Edit43->Visible=false;
        Edit44->Visible=false;
        Edit45->Visible=false;
        ListBox1->Items->Clear();
        if(lcode==1){
            sprintf(ms,"For the next 24 hours - snow is in instable state; avalanches, having volume of up to 0.1 of amount");
            ListBox1->Items->Add(ms);
            sprintf(ms,"of snow in the site, are possible");
            ListBox1->Items->Add(ms);
        }
        if(lcode==0){
            sprintf(ms,"На последующие сутки - снег находится в неустойчивом состоянии, возможен сход лавин объемом");
            ListBox1->Items->Add(ms);
            sprintf(ms,"до 10 % от количества снега в очаге.");
            ListBox1->Items->Add(ms);
        }
    }
    if(pss.icod==3){
        Form1->Edit42->Color=0x004080FF;
        Edit43->Visible=false;
        Edit44->Visible=false;
        Edit45->Visible=false;
        ListBox1->Items->Clear();
        if(lcode==1){
            sprintf(ms,"For the next 24 hours - snow is in instable state; avalanches, having volume of 0.1 - 0.5 of amount");
            ListBox1->Items->Add(ms);
            sprintf(ms,"of snow in the site, are possible. For the next second day - snow is in instable state;
            avalanches,");
            ListBox1->Items->Add(ms);
            sprintf(ms,"having volume of up to 0.1 of amount of snow in the site, are possible.");
            ListBox1->Items->Add(ms);
        }
        if(lcode==0){
            sprintf(ms,"На последующие сутки - снег находится в неустойчивом состоянии, возможен сход лавин значительного объема, равного");
            ListBox1->Items->Add(ms);
            sprintf(ms,"0,1 - 0,5 от количества снега в очаге. На последующие вторые - снег находится в неустойчивом состоянии, возможен");
            ListBox1->Items->Add(ms);
            sprintf(ms,"сход объемом до 10 % от количества снега в очаге.");
            ListBox1->Items->Add(ms);
        }
    }
    if(pss.icod==4){
        Form1->Edit42->Color=clRed;
        Edit43->Visible=false;
        Edit44->Visible=false;
        Edit45->Visible=false;
        ListBox1->Items->Clear();
        if(lcode==1){
            sprintf(ms,"For the next 24 hours - avalanche risk; avalanches, having volume of 0.1 - 0.5 of amount of snow in the site, are");
            ListBox1->Items->Add(ms);
            sprintf(ms,"expected. For the next second day - snow is in instable state; avalanches, having volume of 0.1 - 0.5 of amount of");
            ListBox1->Items->Add(ms);
            sprintf(ms,"snow in the site, are possible. For the next third day - snow is in instable state; avalanches, having volume of");
            ListBox1->Items->Add(ms);
            sprintf(ms,"up to 0.1 of amount of snow in the site, are possible.");
            ListBox1->Items->Add(ms);
        }
        if(lcode==0){
            sprintf(ms,"На последующие сутки - лавиноопасно, ожидается массовый сход лавин значительного объема, равного 0,1 - 0,5");
            ListBox1->Items->Add(ms);
            sprintf(ms,"от количества снега в очаге. На последующие вторые сутки - снег находится в неустойчивом состоянии, возможен");
            ListBox1->Items->Add(ms);
            sprintf(ms,"сход лавин значительного объема, равного 10 - 50 % от количества снега в очаге. На последующие третьи");
            ListBox1->Items->Add(ms);
            sprintf(ms,"сутки - снег находится в неустойчивом состоянии, возможен сход лавин объёмом до 10 % от ");
            ListBox1->Items->Add(ms);
            sprintf(ms,"количества снега в очаге.");
            ListBox1->Items->Add(ms);
        }
    }
    if(pss.icod==5){
        Form1->Edit42->Color=clRed;
        Edit43->Visible=true;
        Edit44->Visible=true;
        Edit45->Visible=true;
        ListBox1->Items->Clear();
        if(lcode==1){
            sprintf(ms,"For the next 24 hours - Extreme avalanche risk; avalanches, having volume of > 0.5 of amount of snow in the site, are");
            ListBox1->Items->Add(ms);
            sprintf(ms,"expected. For the next second and third days - snow is in instable state; avalanches, having volume of 0.1 - 0.5 of");
            ListBox1->Items->Add(ms);
            sprintf(ms,"amount of snow in the site, are possible.");
            ListBox1->Items->Add(ms);
        }
        if(lcode==0){
            sprintf(ms,"На последующие сутки - исключительная лавинная опасность, ожидается сход лавин с объёмом более 50 % от");
            ListBox1->Items->Add(ms);
            sprintf(ms,"количества снега в очаге. На последующие вторые и третьи сутки - снег находится в неустойчивом состоянии,");
            ListBox1->Items->Add(ms);
            sprintf(ms,"возможен сход лавин значительного объема, равного 10 - 50 % количества снега в очаге.");
            ListBox1->Items->Add(ms);
        }
    }
    Edit22->Text=FloatToStrF(pss.p3,ffFixed,7,4);
    if(pss.p3<0.9)Edit24->Text=FloatToStrF(pss.p2,ffFixed,7,4);
    if(pss.p3<0.9&&pss.p2<0.9)Edit47->Text=FloatToStrF(pss.p,ffFixed,7,4);
}
//-------------------------------------------------------------------------—

void __fastcall TForm1::ToolButton3Click(TObject *Sender)
{
    if(lcode==1){
        lcode=0;
        Form1->Caption="Прогнозирование лавинной опасности";
        ToolButton1->Caption="Расчёт";
        ToolButton2->Caption="Пример расчёта";
        ToolButton3->Caption="Английский";
        ToolButton4->Caption="Выход";
        Edit1->Text="Угол склона, градусы";
        Edit2->Text="Длина склона по гипотенузе, м";
        Edit3->Text="Толщина снежного покрова, м";
        Edit4->Text="Сумма осадков за последние сутки, мм";
        Edit9->Text="Средняя интенсивность осадков за последние 3 часа, мм/час";
        Edit10->Text="Максимальная скорость ветра за последние сутки, м/с";
        Edit11->Text="Ожидаемая на последующие сутки сумма осадков, мм/час";
        Edit12->Text="Интенсивность землетрясения, баллы по шкале MSK-81";
        Edit13->Text="Средняя температура воздуха за время наличия снега на склоне,°C";
        Edit14->Text="Средняя температура воздуха за последние 10 дней,°C";
        Edit15->Text="Толщина снега, начинающегося у грунта и имеющего плотность >430 кг/кубометр, м";
        Edit16->Text="Плотность снега, начинающегося у грунта и имеющего плотность >430 кг/кубометр, кг/кубометр";
        Edit5->Text="Средняя температура воздуха за последние сутки, °C";
        Edit33->Text="Время, в течение которого снег находится на склоне, часы";
        Edit34->Text="Начальная толщина снега, м";
        Edit35->Text="Средняя толщина снега за последние 10 дней, м";
        Edit36->Text="Изменение толщины снега за последние сутки, м";
        Label1->Caption="Исходные данные";
        Label2->Caption="Результаты расчёта";
        Label3->Caption="Программа разработана М. И. Зиминым в соответствии с РД 52.37.612-2000 в 2002 г.; e-mail: zimin7@yandex.ru";
        Edit41->Text="Код лавинной опасности";
        Edit7->Text="Вероятность землетрясения заданной интенсивности";
        Edit21->Text="Степень принадлежности ситуации к состоянию исключительной лавинной опасности";
        Edit23->Text="Степень принадлежности ситуации к состоянию лавинной опасности";
        Edit46->Text="Степень принадлежности ситуации к состоянию неустойчивого состояния снега";
        goto m1;
    }
    if(lcode==0){
        lcode=1;
        Form1->Caption="Forecast of Avalanche Risk";
        ToolButton1->Caption="Analysis";
        ToolButton2->Caption="Example of Analysis";
        ToolButton3->Caption="Russian";
        ToolButton4->Caption="Quit";
        Edit1->Text="Angle of the Slope, degrees";
        Edit2->Text="Length of the Slope along Hypotenuse, m";
        Edit3->Text="Thickness of the Snow Mantle, m";
        Edit4->Text="Sum of Precipitation for the last 24 hours, mm";
        Edit9->Text="Avarage Intensity of Precipitation for the last 3 hours, mm/hour";
        Edit10->Text="Maximum Daily Velocity of the Wind, m/sec";
        Edit11->Text="Expected Sum of Precipitation for the next 24 hours, mm";
        Edit12->Text="Earthquake Intensity in degrees on the MSK-81 scale";
        Edit13->Text="Avarage Air Temperature for the Period of Presense Snow on the Slope,°C";
        Edit14->Text="Avarage Air Temperature for last 10 days,°C";
        Edit15->Text="Thickness of the Layer of the Snow, having Density > 430 kg/cbm and beginning at the Ground, m";
        Edit16->Text="Density of Layer of the Snow, having Density > 430 kg/cbm and beginning at the Ground, kg/cbm";
        Edit5->Text="Average Daily Air Temperature, °C";
        Edit33->Text="Period of Presense Snow on the Slope, hours";
        Edit34->Text="Initial Thickness of the Snow, m";
        Edit35->Text="Avarage Thickness of the Snow for last 10 days, m";
        Edit36->Text="Daily Changing of the Thickness of the Snow, m";
        Label1->Caption="Initial Data";
        Label2->Caption="Results of Analysis";
        Edit41->Text="Avalanche Risk Code";
        Edit7->Text="Likelihood of the Earthquake of the Given Intensity";
        Label3->Caption="The software is developed by Mikhail Zimin according to РД 52.37.612-2000 in 2002; e-mail: zimin7@yandex.ru";
        Edit21->Text="Degree of membership of situation to condition of extreme avalanche risk";
        Edit23->Text="Degree of membership of situation to condition of avalanche risk";
        Edit46->Text="Degree of membership of situation to condition of unstability of snow";
    }
m1:;
}
