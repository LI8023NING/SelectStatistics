//---------------------------------------------------------------------------

#ifndef SelectStatisticsH
#define SelectStatisticsH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:	// IDE-managed Components
        TPanel *PanelBackground;
        TMemo *MemoText;
        TLabel *Label1;
        TLabel *LabelSelectedProportion;
        TLabel *Label3;
        TLabel *LabelAllCharCount;
        TLabel *Label5;
        TLabel *LabelSelectCharCount;
        void __fastcall MemoTextChange(TObject *Sender);
    void __fastcall MemoTextMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
private:	// User declarations
public:		// User declarations
        __fastcall TMainForm(TComponent* Owner);

        int     _textCharCount;
};
//---------------------------------------------------------------------------
extern PACKAGE TMainForm *MainForm;
//---------------------------------------------------------------------------
#endif
