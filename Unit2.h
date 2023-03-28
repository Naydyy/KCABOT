//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <System.Win.ScktComp.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.pngimage.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TClientSocket *Client;
	TImage *Image1;
	TGroupBox *GroupBox1;
	TEdit *Edit1;
	TButton *Button1;
	TComboBox *ComboBox1;
	TButton *Button2;
	TButton *Button3;
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ClientDisconnect(TObject *Sender, TCustomWinSocket *Socket);
	void __fastcall ClientError(TObject *Sender, TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
