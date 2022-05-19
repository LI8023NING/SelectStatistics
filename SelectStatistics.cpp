//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <stdio.h>

#include "SelectStatistics.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
        , _textCharCount (0)
{
    LabelSelectedProportion->Caption = "0%";
    LabelAllCharCount->Caption = "0";
    LabelSelectCharCount->Caption = "0";
}

void __fastcall TMainForm::MemoTextChange(TObject *Sender)
{
    AnsiString context = MemoText->Text;

    _textCharCount = 0;

    for (int i=1; i<=context.Length(); i++){

        if ((context[i]&0x80)>>7) {
            // 是汉字的一前半部分
            ++i;
        }

        _textCharCount++;
    }

    LabelAllCharCount->Caption = IntToStr(_textCharCount);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::MemoTextMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{
    AnsiString context = MemoText->Text;
    AnsiString selectText = context.SubString(1, MemoText->SelStart);

    int selectCharCount = 0;

    for (int i=1; i<=selectText.Length(); i++){

        if ((selectText[i]&0x80)>>7) {
            // 是汉字的一前半部分
            ++i;
        }

        selectCharCount++;
    }

    LabelSelectCharCount->Caption = IntToStr(selectCharCount);

    float result = 0;
    if (selectCharCount != 0 && _textCharCount != 0) {
        result = (1.0 * selectCharCount / _textCharCount) * 100;
    }

    LabelSelectedProportion->Caption = FloatToStrF(result, ffFixed, 8, 1) + "%";
}
//---------------------------------------------------------------------------


