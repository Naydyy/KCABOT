//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
void listedoldur();
static const char* cpuId(void);
String encrypt(String gelen);
String decrypt(String gelen);
int kadir=0;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
	Form2->Client->Active=true;
}
struct wordlists
{
	String a;
}word[255];
static const char* cpuId(void)
{
	unsigned long s1 = 0;
	unsigned long s2 = 0;
	unsigned long s3 = 0;
	unsigned long s4 = 0;
	__asm
	{
		mov eax, 00h
		xor edx, edx
		cpuid
		mov s1, edx
		mov s2, eax
	}
	__asm
	{
		mov eax, 01h
		xor ecx, ecx
		xor edx, edx
		cpuid
		mov s3, edx
		mov s4, ecx
	}

	static char buf[100];
	sprintf(buf, "%08X%08X%08X%08X", s1, s2, s3, s4);
	return buf;
}
void listedoldur()
{
	  // abcdefghijklmnopqrstuvwxyz
	  word[0].a="a";
	  word[1].a="b";
	  word[2].a="c";
	  word[3].a="d";
	  word[4].a="e";
	  word[5].a="f";
	  word[6].a="g";
	  word[7].a="h";
	  word[8].a="i";
	  word[9].a="j";
	  word[10].a="k";//bu geldi
	  word[11].a="l";
	  word[12].a="m";
	  word[13].a="n";
	  word[14].a="o";
	  word[15].a="p";
	  word[16].a="r";
	  word[17].a="s";
	  word[18].a="t";
	  word[19].a="u";
	  word[20].a="v";
	  word[21].a="w";
	  word[22].a="x";
	  word[23].a="y";
	  word[24].a="z";
	  word[25].a="1";
	  word[26].a="2";
	  word[27].a="3";
	  word[28].a="4";
	  word[29].a="5";
	  word[30].a="6";
	  word[31].a="7";
	  word[32].a="8";
	  word[33].a="9";
	  word[34].a="0";
}

//---------------------------------------------------------------------------
String encrypt(String gelen)
{
  //kendi þifrelemenizi koyun artýk
  String sifrelenmis;
	return sifrelenmis;
}



String decrypt(String gelen)
{
  //kendi þifrelemenizi koyun artýk
  String cozulen;
  return cozulen;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
	ShellExecuteA(0,"open","https://discord.gg/4PyxgyQsTH","","",1);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
    ComboBox1->Text="Select Server";
	ComboBox1->Items->Add("IrisPanel");

}
//---------------------------------------------------------------------------


void __fastcall TForm2::ClientDisconnect(TObject *Sender, TCustomWinSocket *Socket)

{
    exit(-1);
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ClientError(TObject *Sender, TCustomWinSocket *Socket, TErrorEvent ErrorEvent,
          int &ErrorCode)
{
   exit(-1);
}
//---------------------------------------------------------------------------

