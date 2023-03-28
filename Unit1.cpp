#define CopyBytes(Dest,Src) memcpy(Dest, (BYTE*)&Src, sizeof(Src))
#include <vcl.h>
#pragma hdrstop
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <string>
#include <string.h>
#include <cstdlib>
#include <stdlib.h>
#include <tlhelp32.h>
#include <Psapi.h>
#include <shlwapi.h>
 #define CREATE_THREAD_ACCESS (PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ)
#define INFO_BUFFER_SIZE 32767
//---------------------------------------------------------------------------
#pragma package(smart_init)

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
HANDLE KO_HANDLE;
Graphics::TBitmap *bmpSomething = new Graphics::TBitmap;
Graphics::TBitmap *bmpSomething2 = new Graphics::TBitmap;
int PLAYER_ACTOR=0;
int etraftakiplayersayisi;
DWORD targetid;
void map();
int banadet=0;
float MAX_DISTANCE_TO_ATTACK=150.0f;
float savex,savey;
void farmbot();
bool TPkontrol();
void girdimi();
void playercek();
void saveCPU();
void wallhack();
void specialWallHack();
void onehit();
float searchRange=0;
bool aktif=false;
TJPEGImage *jpgPicture = new TJPEGImage;
static DWORD dwGetModuleBaseAddress(DWORD dwProcessIdentifier, TCHAR *lpszModuleName);
void EnableDebugPriv();
void AlanCiz(float x,float y);
void MapCiz(float x,float y,int type);
bool AlandakiPlayerler(float x,float y);
BOOL writeyazamk(DWORD point,DWORD val);
void AutoLogin(const char *kadix,const char *pw,const char *ip,int port,int ch);
void MobCiz(float x,float y);
int MobSayi();
void iris();
void irisbypass(DWORD ptr);
DWORD NoKS(DWORD vid);
DWORD mobcek();
bool bWallHack=false;
bool bSpecialWallHack=false;
bool bOneHit=false;
bool bAttackType=false;
void etrafoku();
void BinekBin();
void PmPlayerList();
bool IsInGame();
//////////////////////METIN2 POINTER
DWORD M_FLDB=0x3D3734;  //etraf okuma   3D3734
DWORD M_MobPtr=0x3CB95C;
DWORD M_PlayerPtr=0x3CBB38;
DWORD M_EndMob=M_FLDB+0x4;
DWORD M_SendChatPtr=0x416D5C;
DWORD M_SendChatCall=0x16C190;
DWORD M_SendWhisperPtr=0x416D5C;
DWORD M_SendWhisperCall=0x16C2E0;
DWORD M_SendBattleAttack=0x416D5C;
DWORD M_SendBattleAttackKeyPtr=0x348A38;
DWORD M_SendBattleAttackKeyCall=0xcdf40;
DWORD M_SendBattleCall=0x169B60;
DWORD M_PickCloseItemPtr=0x3CB95C;
DWORD M_PickCloseItemCall=0x18A160;
DWORD M_loginptr=0x0;
DWORD M_RecvMessage=0x42EF1F;
DWORD M_logincall=0x0;
DWORD M_irisbypass=0x0;
//METIN2 OFFSET LIST
DWORD M_WH=0x8F0;
DWORD M_SpecialWH=0x51e;
DWORD M_FARK=0x4;
DWORD M_Horse=0x4;
DWORD M_MyPlayer=0x10;
DWORD M_X=0x290;
DWORD M_Y=0x294;
DWORD M_Z=0x298;
DWORD M_MobRun=0x80;
DWORD M_Target=0x37064;
DWORD M_Name=0x14;
DWORD M_TargetMob=0x36fbc;
DWORD M_Level=0x6c;
DWORD M_Vid=0x8d8;
DWORD M_Type=0x8c;
DWORD M_Myx=0x280;
DWORD M_Myy=0x284;
DWORD M_Myz=0x288;
DWORD M_Onehit=0x764;
DWORD M_MainType=3;
DWORD M_AttackType=0x6a0;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
BOOL writeyazamk(DWORD point,DWORD val)
{
  KO_HANDLE = OpenProcess(PROCESS_ALL_ACCESS,false,GetCurrentProcessId());
	WriteProcessMemory(KO_HANDLE,(LPVOID)point, &val, 1, NULL);
//WriteProcessMemory(KO_HANDLE,(void*)(FinalPointer),&New_Name,sizeof(New_Name),0);

	return true;
}
void target()
{
		while (true)
	{
		DWORD vid=(*(DWORD*)(*(DWORD*)M_MobPtr + 0x3746c));
		   DWORD CallAdress = M_SendBattleCall;
			DWORD a=*(DWORD*)M_SendBattleAttack;




			_asm {
                    mov ecx,a
					push vid
					push 0
					Call CallAdress


				 }
		Sleep(Form1->Edit2->Text.ToInt());
	}
}
void irisbypass(DWORD ptr)
{
	DWORD bytes;
	BYTE examplebytes[5] = {0x90,0x90,0x90,0x90,0x90};
	WriteProcessMemory(KO_HANDLE, (void*)ptr, &examplebytes, sizeof(examplebytes), &bytes);
}
void iriscaptcha(DWORD ptr)
{
	DWORD bytes;
	BYTE examplebytes[109] = {0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90,0x90};
	WriteProcessMemory(KO_HANDLE, (void*)ptr  , examplebytes, sizeof(examplebytes), &bytes);
}

float MesafeHesapla(float x, float y, float Px,float Py){return sqrt((Px-x)*(Px-x)+(Py-y)*(Py-y));}
DWORD ReadLong(DWORD value){ReadProcessMemory(KO_HANDLE,(void*)value,&value,sizeof(value),0);return value;}
DWORD Read2byte(DWORD value){ReadProcessMemory(KO_HANDLE,(void*)value,&value,1,0);return value;}
float Readfloat(DWORD value){float a;ReadProcessMemory(KO_HANDLE,(void*)value,&a,sizeof(a),0);return a;}
void Writefloat(DWORD Addr, float Offset){WriteProcessMemory(KO_HANDLE,(void*)Addr,&Offset,(float)sizeof(Offset),NULL);}
void WriteLong(DWORD Addr, DWORD Offset){WriteProcessMemory(KO_HANDLE,(void*)Addr,&Offset,(DWORD)sizeof(Offset),NULL);}
void kado()
{
DWORD BaseAddress = dwGetModuleBaseAddress(GetCurrentProcessId(),"python27.dll");
DWORD KO_MTID=(DWORD)((DWORD)(BaseAddress +0x244008));

DWORD MTID;
asm {
	MOV EDX,DS:KO_MTID
	MOV EDX, [EDX]
	MOV MTID, EDX
}
HANDLE handle = OpenThread(THREAD_ALL_ACCESS, FALSE, MTID);
while (Form1->CheckBox21->Checked==true)
{
  SuspendThread(handle);
  Sleep(200);
  ResumeThread(handle);
  Sleep(100);
}
}
struct mobliste
{
  char *name;
  int tip;
  float x;
  float y;
  int vid;
  int level;
  float dist;
}mob[255];
struct banlist
{
  int vid;
}ban[255];
struct playerpm
{
	char* nick;
}pmlist[255];
struct player
{
  char* adi;
  float x;
  float y;
  int level;
  int vid;
}player;
int MobSayi()
{
    int yarak;
	try
	{
     yarak = (*reinterpret_cast<DWORD*>(M_EndMob) - *reinterpret_cast<DWORD*>(M_FLDB)) / 4;
	return yarak;
	}
	catch (...)
	{
	}
    return yarak;
}
void iris()
{
   DWORD pidnum=GetCurrentProcessId();
   DWORD BaseAddress = dwGetModuleBaseAddress(pidnum,"metin2client.exe");
   M_FLDB=(DWORD)((DWORD)(BaseAddress +0x042EAF4)); //etraf okuma   3F97EC
   M_MobPtr=(DWORD)((DWORD)(BaseAddress +0x0426e1c));
   M_PlayerPtr=(DWORD)((DWORD)(BaseAddress +0x046BBD8));
   M_SendChatPtr=(DWORD)((DWORD)(BaseAddress +0x047272c));
	M_SendChatCall=(DWORD)((DWORD)(BaseAddress +0x175260));
	M_SendWhisperPtr= (DWORD)((DWORD)(BaseAddress +0x47272c));
	M_SendWhisperCall= (DWORD)((DWORD)(BaseAddress +0x1753b0));
   M_EndMob=M_FLDB+0x4;
   M_loginptr=(DWORD)((DWORD)(BaseAddress +0x0426e00));
   M_logincall=BaseAddress +0x01861f0;
   M_SendBattleAttack=(DWORD)((DWORD)(BaseAddress +0x04714b0));
   M_SendBattleCall=(DWORD)((DWORD)(BaseAddress +0x07dd20));
   DWORD M_irisattack= (DWORD)((DWORD)(BaseAddress +0x172a72));
   M_RecvMessage=(DWORD)((DWORD)(BaseAddress +0x42EF1F));
   M_X=0x7e0;
   M_Y=0x7e4;
   M_Z=0x7e8;
   M_Name=0x14;
   M_MobRun=0x80;
   M_Target=0x3746c;
   M_TargetMob=0x373c4;
   M_SpecialWH=0x536;
   M_Onehit=0x764;
   M_Vid=0x8d4;
   M_Level=0x6C;
   M_Type=0x768;
   M_Myx=0x7e0;
   M_Myy=0x7e4;
   M_Myz=0x7e8;
   M_MyPlayer=0x10;
   M_MainType=2;
   M_WH=0x8f0;
   M_AttackType=0x6a0;
   writeyazamk(M_irisattack,0xEB);
}
void etrafoku()
{
  try
  {
    MapCiz(player.x,player.y,6);
 for (int i = 0; i < MobSayi(); i++)
	{
	  if (mob[i].tip==2)
	  {
		MobCiz(mob[i].x,mob[i].y);
	  }
	}
  } catch (...) {
  }

}
void mobakosfunc(DWORD mobid)
{
  if (IsInGame())
  {
	if (aktif==true)
	 {



  try
  {
	 if (mobid==0)
	 {
	  mobakosfunc(mobcek());
	 }
  else
  {

		(*(DWORD*)(*(DWORD*)M_MobPtr + M_TargetMob))=mobid;
	  //	(*(DWORD*)(*(DWORD*)M_MobPtr + M_Target))=mobid;
		(*(DWORD*)(*(DWORD*)M_MobPtr + M_MobRun))= 0x03;
	   //	Sleep(1000);
		while (true)
			{
				if ((*(DWORD*)(*(DWORD*)M_MobPtr + M_MobRun))== 0x00)
				{
                   break;
				}
			  	Sleep(1000);
			}
		 while ((*(DWORD*)(*(DWORD*)M_MobPtr + M_TargetMob))>0)
			 {
			   if ((*(DWORD*)(*(DWORD*)M_MobPtr + M_Target))>0)
			   {
				(*(DWORD*)(*(DWORD*)M_MobPtr + M_MobRun))= 0x03;

			   }
			   else
			   {
				targetid=0;
					(*(DWORD*)(*(DWORD*)M_MobPtr + M_TargetMob))=0;
					(*(DWORD*)(*(DWORD*)M_MobPtr + M_Target))=0;
					(*(DWORD*)(*(DWORD*)M_MobPtr + M_MobRun))=0;
					break;
			   }

               Sleep(100);

			 }
            	(*(DWORD*)(*(DWORD*)M_MobPtr + M_TargetMob))=0;
					(*(DWORD*)(*(DWORD*)M_MobPtr + M_Target))=0;
					(*(DWORD*)(*(DWORD*)M_MobPtr + M_MobRun))=0;

				mobakosfunc(mobcek());
  }
  }
		catch (...)
		{
		}
	}
  }
}
DWORD mobcek()
{
	 if (IsInGame())
	 {


	 try
	 {
       int i=1;
	 int elemansayisi=0;
	 float diziID[255];
	 float sqDiff;
	 float diziDiff[255];
	 player.adi=(char*)(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_PlayerPtr) + M_MyPlayer) + M_Name);
	 player.x=*reinterpret_cast<FLOAT*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_PlayerPtr) + M_MyPlayer) + M_X);
	 player.y=*reinterpret_cast<FLOAT*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_PlayerPtr) + M_MyPlayer) + M_Y);
	  if (player.y<0)
	 {
	   player.y=player.y*-1;
	 }
	 player.vid=*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_PlayerPtr) + M_MyPlayer) + M_Vid);
	 player.level=*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_PlayerPtr) + M_MyPlayer) + M_Level);
	for (i = 0; i < MobSayi()-1; i++)
	{

	 mob[i].name=(char*)(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_FLDB) + (i*0x4)) + M_Name);
	 mob[i].tip=*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_FLDB) + (i*0x4)) + M_Type);
	 mob[i].x=*reinterpret_cast<FLOAT*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_FLDB) + (i*0x4)) + M_X);
	 mob[i].y=*reinterpret_cast<FLOAT*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_FLDB) + (i*0x4)) + M_Y);
	 if (mob[i].y<0)
	 {
	   mob[i].y=mob[i].y*-1;
	 }
	 mob[i].vid=*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_FLDB) + (i*0x4)) + M_Vid);
	 mob[i].level=*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_FLDB) + (i*0x4)) + M_Level);
	 mob[i].dist=MesafeHesapla(mob[i].x,mob[i].y,player.x,player.y);

	 /*if (mob[i].y<0)
	 {
				   mob[i].y=mob[i].y*-1;
	 }*/
     sqDiff=((mob[i].x-player.x)*(mob[i].x-player.x))+((mob[i].y-player.y)*(mob[i].y-player.y));
	 if (Form1->CheckBox8->Checked==true)
	 {
	   //sqDiff=((mob[i].x-savex)*(mob[i].x-savex))+((mob[i].y-savey)*(mob[i].y-savey));
	   mob[i].dist=MesafeHesapla(mob[i].x,mob[i].y,savex,savey);
	 }

		diziID[elemansayisi]=mob[i].vid;
		diziDiff[elemansayisi]=sqDiff;
		elemansayisi++;




	}

	int tempDiff,tempID,k,y;
    int tip;
	float mobx;
    char *name;
	float moby;
	int vid;
	int level;
	float dist;
	for (k = 1; k < elemansayisi; k++)
	 {
		for (y = 1; y <elemansayisi-k ; y++)
		{

			if (mob[y].dist>mob[y+1].dist)
			{
			  // tempDiff= diziDiff[y];
			 //  tempID= diziID[y] ;
			 name=mob[y].name;
			 tip=mob[y].tip;
			 mobx=mob[y].x;
			 moby=mob[y].y;
			 vid=mob[y].vid;
			 level=mob[y].level;
			 dist=mob[y].dist;
			   //**********************
			   mob[y].name=mob[y+1].name;
			   mob[y].tip=mob[y+1].tip;
			   mob[y].x=mob[y+1].x;
			   mob[y].y=mob[y+1].y;
			   mob[y].vid=mob[y+1].vid;
			   mob[y].level=mob[y+1].level;
			   mob[y].dist=mob[y+1].dist;
			  // diziDiff[y]=  diziDiff[y+1];
			  // diziID[y]=  diziID[y+1];
			   //**********************
               mob[y+1].name=name;
			   mob[y+1].tip=tip;
			   mob[y+1].x=mobx;
			   mob[y+1].y=moby;
			   mob[y+1].vid=vid;
			   mob[y+1].level=level;
			   mob[y+1].dist=dist;

			  // diziDiff[y+1]=  tempDiff;
			  // diziID[y+1]=  tempID;

			}
		}

	}
    
	bool banlistesindevar=false;

     for (int p = 0; p < elemansayisi;p++)
	{
		 banlistesindevar=false;
		 etraftakiplayersayisi=elemansayisi;
		 float distance;
		 if (true)
		 {

			for (int list = 0; list <=banadet; list++)
			{


			   if (mob[p].vid==ban[list].vid)
			   {

				  banlistesindevar=true;
				  break;
			   }

			}
		 }
		 if (mob[p].tip==2 && Form1->CheckBox14->Checked==true && banlistesindevar==false)
		 {

			distance=((mob[p].x-savex)*(mob[p].x-savex))+((mob[p].y-savey)*(mob[p].y-savey));
		   if (mob[p].dist<=(searchRange*100) && AlandakiPlayerler(mob[p].x,mob[p].y)==false )
			{

				if (Form1->CheckBox8->Checked==true)
				{
				  if (mob[p].dist<=distance)
				  {
					 return mob[p].vid;
				  }
				  else
				  {
					  continue;
				  }
				}
				else
				{
				   return mob[p].vid;
				}

			}
		 }
		 else
		 {
		 distance=((mob[p].x-savex)*(mob[p].x-savex))+((mob[p].y-savey)*(mob[p].y-savey));
		   if (mob[p].tip==2 && mob[p].dist<=(searchRange*100)&& banlistesindevar==false)
			{

				if (Form1->CheckBox8->Checked==true)
				{
				  if (mob[p].dist<=distance)
				  {
					 return mob[p].vid;
				  }
				  else
				  {
					  continue;
				  }
				}
				else
				{
				   return mob[p].vid;
				}

			}
            continue;
         }

     continue;
	}

	
	


	 /*
	 for (int b = 1; b < elemansayisi; b++)
	 {
	   if (mob[b].vid==diziID[0])
	   {

		  if (AlandakiPlayerler(mob[b].x,mob[b].y)==false)
		  {

			return mob[b].vid;
		  }
		  else
		  {
			  return 0;
          }
	   }
	 }
	   */

	 } catch (...) {
	 }
	 }
     Sleep(100);
	return 0;
}
bool AlandakiPlayerler(float x,float y)
{
	try
	{
       bool deneme;
	float sqDiff;
	float mobx,moby;
	int tipi,leveli,vidi;
	char *isim;
    int levelsay=0;

	if (IsInGame())
	 {
	   for (int i = 0; i < MobSayi(); i++)
	   {

		  isim=(char*)((*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_FLDB) + (i*0x4)) + M_Name));
		  tipi=*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_FLDB) + (i*0x4)) + M_Type);
		  mobx=*reinterpret_cast<FLOAT*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_FLDB) + (i*0x4)) + M_X);
		  moby=*reinterpret_cast<FLOAT*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_FLDB) + (i*0x4)) + M_Y);
		  vidi=*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_FLDB) + (i*0x4)) + M_Vid);
		  leveli=*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_FLDB) + (i*0x4)) + M_Level);
		  if (moby<0)
			{
				   moby=moby*-1;
			}
		  if (tipi==6 && leveli>0 && vidi!=player.vid)
		  {
			float mesafe = (MesafeHesapla(mobx,moby,x,y));
			if (mesafe<150.0f)
			{

				return true;
			}

		  }

	   }


	   return false;
	 }



	} catch (...) {
	}



}

void EnableDebugPriv()
{
    HANDLE hToken;
	LUID luid;
	TOKEN_PRIVILEGES tkp;

    OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken);

	LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luid);

    tkp.PrivilegeCount = 1;
    tkp.Privileges[0].Luid = luid;
    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

    AdjustTokenPrivileges(hToken, false, &tkp, sizeof(tkp), NULL, NULL);

	CloseHandle(hToken);
}
void MobCiz(float x,float y)
{
 try
 {
   Form1->Image1->Canvas->Brush->Color=clBlue;
 Form1->Image1->Canvas->Pen->Color =  clBlue;
 Form1->Image1->Canvas->Brush->Style=bsSolid;
 float Gelenx=abs(x)/100;
 float Geleny=abs(y)/100;
 Form1->Image1->Canvas->Ellipse(Gelenx,Geleny,Gelenx+10,Geleny+10);

 } catch (...) {
 }


}
void MapCiz(float x,float y,int type)
{
 try
 {

   Form1->Image1->Canvas->Brush->Color=clBlack;
 Form1->Image1->Canvas->FillRect(Form1->Image1->Canvas->ClipRect);

 Form1->Image1->Canvas->Pen->Color =  clWebDarkOrange;
 Form1->Image1->Canvas->Brush->Color=clWebDarkOrange;
 Form1->Image1->Canvas->Brush->Style=bsSolid;

 float Gelenx=abs(player.x)/100;
 float Geleny=abs(player.y)/100;
 Form1->Image1->Canvas->Ellipse(Gelenx,Geleny,Gelenx+5,Geleny+5);
 float haritax=abs((Form1->Panel1->Width/2)+abs(Form1->Image1->Left));
 float haritay=abs((Form1->Panel1->Height/2)+abs(Form1->Image1->Top));
 int xfark=(Gelenx-haritax);
 int yfark=(Geleny-haritay);
 Form1->Image1->Left  -=  xfark;
 Form1->Image1->Top   -=    yfark;
 if (Form1->Image1->Left>0)
 {
	Form1->Image1->Left=0;
 }
 if (Form1->Image1->Top>0)
 {
	Form1->Image1->Top=0;
 }

 } catch (...) {
 }
}
bool TPkontrol()
{
   //  player.x=*reinterpret_cast<FLOAT*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_PlayerPtr) + M_MyPlayer) + M_X);
  //	 player.y=*reinterpret_cast<FLOAT*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_PlayerPtr) + M_MyPlayer) + M_Y);
 //	 player.vid=*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_FLDB) + 0x0) + M_Vid);
	 try {



			player.level=*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_PlayerPtr) + M_MyPlayer) + M_Level);

			if (player.level>0 && player.level<150) {Form1->Label8->Caption="GM Çekti Moruq";return true;}


			exit(-1);

		 }
	 catch (...)
	{
       Form1->Label8->Caption="GM Çekti Moruq";
	   exit(-1);
	}

    return false;
}
bool IsInGame()
{
   //  player.x=*reinterpret_cast<FLOAT*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_PlayerPtr) + M_MyPlayer) + M_X);
  //	 player.y=*reinterpret_cast<FLOAT*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_PlayerPtr) + M_MyPlayer) + M_Y);
 //	 player.vid=*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_FLDB) + 0x0) + M_Vid);
	 try {
            Form1->Caption="";
			player.level=*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_PlayerPtr) + M_MyPlayer) + M_Level);
			Form1->Caption="";
			if (player.level>0 && player.level<150 && player.level!=NULL) {return true;}

			else{return false;}
		 }
	 catch (...)
	{

	}

    return false;
}
void AlanCiz(float x,float y)
{

  try {
     float Gelenx,Geleny;
  Form1->Image1->Canvas->Pen->Color =  clWhite;
  Form1->Image1->Canvas->Brush->Color =  clGreen;
  Form1->Image1->Canvas->Brush->Style = bsDiagCross;
  float alan=Form1->TrackBar1->Position;
  if (Form1->CheckBox8->Checked==true)
  {
  Gelenx=abs(savex)/100;
  Geleny=abs(savey)/100;
  }
  else
  {
  Gelenx=abs(x)/100;
  Geleny=abs(y)/100;
  }

  if (alan>0) {
	Form1->Image1->Canvas->Ellipse(Gelenx-alan, Geleny-alan, Gelenx+alan+5, Geleny+alan+5);
  }

  } catch (...) {
  }

}
//---------------------------------------------------------------------------
static DWORD dwGetModuleBaseAddress(DWORD dwProcessIdentifier, TCHAR *lpszModuleName)
		{
			HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwProcessIdentifier);
			DWORD dwModuleBaseAddress = 0;
			if(hSnapshot != INVALID_HANDLE_VALUE)
			{
				MODULEENTRY32 ModuleEntry32 = {0};
				ModuleEntry32.dwSize = sizeof(MODULEENTRY32);
				if(Module32First(hSnapshot, &ModuleEntry32))
				{
					do
					{
						if(_tcscmp(ModuleEntry32.szModule, lpszModuleName) == 0)
						{
							dwModuleBaseAddress = (DWORD)ModuleEntry32.modBaseAddr;
							break;
						}
					}
					while(Module32Next(hSnapshot, &ModuleEntry32));
				}
				CloseHandle(hSnapshot);
			}
			return dwModuleBaseAddress;

		}
void __fastcall TForm1::FormCreate(TObject *Sender)
{
 EnableDebugPriv();
  KO_HANDLE=OpenProcess(PROCESS_ALL_ACCESS,false,GetCurrentProcessId());
  DWORD BaseAddress = dwGetModuleBaseAddress(GetCurrentProcessId(),"metin2client.exe");
 //  DWORD bytes;
 //	BYTE examplebytes[5] = {0x90,0x90,0x90,0x90,0x90};
  /*	irisbypass((DWORD)((DWORD)(BaseAddress +0x05C3e6))) ;//tarama  1
   irisbypass((DWORD)((DWORD)(BaseAddress +0x05C3f6))) ;//tarama  2
   irisbypass((DWORD)((DWORD)(BaseAddress +0x05C406))) ;//tarama  3
   irisbypass((DWORD)((DWORD)(BaseAddress +0x05C416))) ;//tarama  4
   irisbypass((DWORD)((DWORD)(BaseAddress +0x05C420))) ;//tarama  5
   irisbypass((DWORD)((DWORD)(BaseAddress +0x05C436))) ;//tarama  6
   irisbypass((DWORD)((DWORD)(BaseAddress +0x05C446))) ;//tarama  7
   irisbypass((DWORD)((DWORD)(BaseAddress +0x05C456))) ;//tarama  8
   irisbypass((DWORD)((DWORD)(BaseAddress +0x05C466))) ;//tarama  9
   irisbypass((DWORD)((DWORD)(BaseAddress +0x05C476))) ;//tarama  10
   irisbypass((DWORD)((DWORD)(BaseAddress +0x05C486))) ;//tarama  11
   iriscaptcha((DWORD)((DWORD)(BaseAddress +0x16342a))) ;   */
  iris();
  //	jpgPicture->LoadFromFile("\\map_a2.jpg");
 //	bmpSomething->Assign(jpgPicture);
 //	Image1->Canvas->Draw(0,0,bmpSomething);
  //00C60000 base
	 Form1->Image1->Canvas->Brush->Color=clBlack;
 Form1->Image1->Canvas->FillRect(Form1->Image1->Canvas->ClipRect);
 



     


}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
   	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)map, 0, 0, 0);



}
//---------------------------------------------------------------------------



void __fastcall TForm1::TrackBar1Change(TObject *Sender)
{

		try
		 {
			AlanCiz(player.x,player.y);
			searchRange=TrackBar1->Position;
		} catch (...) {
		}


}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button4Click(TObject *Sender)
{
  KO_HANDLE=OpenProcess(PROCESS_ALL_ACCESS,false,GetCurrentProcessId());
  DWORD BaseAddress = dwGetModuleBaseAddress(GetCurrentProcessId(),"metin2client.exe");
   DWORD bytes;
	BYTE examplebytes[5] = {0x90,0x90,0x90,0x90,0x90};
   irisbypass((DWORD)((DWORD)(BaseAddress +0x05C406))) ;//tarama  3
   irisbypass((DWORD)((DWORD)(BaseAddress +0x05C416))) ;//tarama  4
   irisbypass((DWORD)((DWORD)(BaseAddress +0x05C426))) ;//tarama  5
   irisbypass((DWORD)((DWORD)(BaseAddress +0x05C436))) ;//tarama  6
   irisbypass((DWORD)((DWORD)(BaseAddress +0x05C440))) ;//tarama  7
   irisbypass((DWORD)((DWORD)(BaseAddress +0x05C456))) ;//tarama  8
   irisbypass((DWORD)((DWORD)(BaseAddress +0x05C466))) ;//tarama  9
   irisbypass((DWORD)((DWORD)(BaseAddress +0x05C476))) ;//tarama  10
   irisbypass((DWORD)((DWORD)(BaseAddress +0x05C486))) ;//tarama  11
   irisbypass((DWORD)((DWORD)(BaseAddress +0x05C496))) ;//tarama  11
   irisbypass((DWORD)((DWORD)(BaseAddress +0x05C4a6))) ;//tarama  11
   irisbypass((DWORD)((DWORD)(BaseAddress +0x05C4b6))) ;//tarama  11
   irisbypass((DWORD)((DWORD)(BaseAddress +0x05C4c6))) ;//tarama  11
   irisbypass((DWORD)((DWORD)(BaseAddress +0x1116f6))) ;//tarama  11
   //iriscaptcha((DWORD)((DWORD)(BaseAddress +0x16342a))) ;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button7Click(TObject *Sender)
{
	 DWORD ptr=*(DWORD*)M_loginptr;

	__asm
	{
		mov ecx,ptr
		call M_logincall
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button8Click(TObject *Sender)
{
  HINSTANCE hinstLib;
   BOOL fFreeResult;

   // Get a handle to the DLL module.
   hinstLib = LoadLibrary(TEXT("Project3.dll"));    //1: load the DLL

   // If the handle is valid, unload the DLL
   if (hinstLib != NULL)
   {
       fFreeResult = FreeLibrary(hinstLib);      //2: unload the DLL
   }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button10Click(TObject *Sender)
{
CreateThread(0, 0, (LPTHREAD_START_ROUTINE)target, 0, 0, 0);
}
//---------------------------------------------------------------------------






void __fastcall TForm1::CheckBox21Click(TObject *Sender)
{
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)kado, 0, 0, 0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{
	if (Form1->Button13->Caption=="Baþlat")
	{
		  aktif=true;
          Form1->Button13->Caption="Durdur";
	}
	else
	{
		aktif=false;
        Form1->Button13->Caption="Baþlat";
	}
    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)farmbot, 0, 0, 0);
}
void farmbot()
{
	if (IsInGame())
	 {
		// savex=*reinterpret_cast<FLOAT*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_PlayerPtr) + M_MyPlayer) + M_X);
	   //	savey=*reinterpret_cast<FLOAT*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_PlayerPtr) + M_MyPlayer) + M_Y);
		mobakosfunc(mobcek());

     }
}
void map()
{
   while (true)
   {


       if (IsInGame())
		{

			int a=mobcek();
			etrafoku();
			AlanCiz(player.x,player.y);

		}

      Sleep(1000);
	}
}

//---------------------------------------------------------------------------




void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
try {

	if (IsInGame())
	{

	 mobcek();
	 etrafoku();
	 AlanCiz(player.x,player.y);
	 Form1->Label11->Caption=player.adi;
	 Form1->Label12->Caption=player.level;
	}
	}
	 catch (...) {
	}
}
void playercek()
{
	 try
	 {
		player.adi=(char*)((*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_PlayerPtr) + M_MyPlayer) + M_Name));
	 player.x=*reinterpret_cast<FLOAT*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_PlayerPtr) + M_MyPlayer) + M_X);
	 player.y=*reinterpret_cast<FLOAT*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_PlayerPtr) + M_MyPlayer) + M_Y);
	 if (player.y<0)
	 {
	   player.y=player.y*-1;
	 }
	 player.vid=*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_PlayerPtr) + M_MyPlayer) + M_Vid);
	 player.level=*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_PlayerPtr) + M_MyPlayer) + M_Level);
	 } catch (...) {
	 }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::CheckBox8Click(TObject *Sender)
{
	savex=*reinterpret_cast<FLOAT*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_PlayerPtr) + M_MyPlayer) + M_X);
	savey=*reinterpret_cast<FLOAT*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_PlayerPtr) + M_MyPlayer) + M_Y);
	if (savey<0) {
       savey=savey*-1;
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer2Timer(TObject *Sender)
{

	   TPkontrol();

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button12Click(TObject *Sender)
{
 Form1->ListBox3->Items->Clear();
 banadet=0;
 for (int i = 0; i < banadet; i++)
 {
   ban[i].vid=NULL;
 }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button11Click(TObject *Sender)
{
	Form1->ListBox3->Items->Add((*(DWORD*)(*(DWORD*)M_MobPtr + M_Target)));
	ban[banadet].vid=(*(DWORD*)(*(DWORD*)M_MobPtr + M_Target));
    banadet++;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox13Click(TObject *Sender)
{

	DWORD Addie =*(DWORD*)M_SendChatPtr;
	DWORD pidnum=GetCurrentProcessId();
   DWORD BaseAddress = dwGetModuleBaseAddress(pidnum,"metin2client.exe");
			DWORD addr=BaseAddress+0x175260;
	if (Form1->CheckBox13->Checked==true)
	{
		char* text="/oto_av basla";

				int Modus=0;
				__asm
				{
					mov ecx,Addie
					push 0
					push text
					Call addr

				}
	}
	else
	{
			char* text="/oto_av bitir";

				int Modus=0;
				__asm
				{
					mov ecx,Addie
					push 0
					push text
					Call addr

				}
    }

}
//---------------------------------------------------------------------------




void __fastcall TForm1::CheckBox12Click(TObject *Sender)
{
  // Gm oyuncuyu yanýna çektiðinde veya oyuncu ýþýnlandýðýnda oyun kapanýr.
  if (Form1->CheckBox12->Checked==true)
  {
	 try {
	while (true)
	 {
	  if (TPkontrol()==false)
	  {
         exit(-1);
	  }
      Sleep(1000);
	 }
	 }
	  catch (...)
	 {
	 }
		// tp kontrolü açar
  }
  else
  {
	  TPkontrol(); // tp kontrolü kapatýr
  }
}
void AutoLogin(const char *kadix,const char *sifrex,const char *ip,int port , int ch)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button15Click(TObject *Sender)
{
(*(BYTE*)(*(DWORD*)(*(DWORD*)M_PlayerPtr + M_MyPlayer)+M_WH))=1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button16Click(TObject *Sender)
{
DWORD Addie =*(DWORD*)M_SendChatPtr;
    DWORD pidnum=GetCurrentProcessId();
   DWORD BaseAddress = dwGetModuleBaseAddress(pidnum,"metin2client.exe");
			DWORD addr=BaseAddress+0x175260;
 
  DWORD Adres = *(DWORD*)M_SendChatPtr;
  DWORD serversecmeCall=BaseAddress+0x184cb0;
  DWORD serversecmeCall2=BaseAddress+0x175160;
  DWORD serversecmeCall3=BaseAddress+0x186fc0;
  DWORD serversecmeCall4=BaseAddress+0x105f50; //1. call
  DWORD serversecmeCall5=BaseAddress+0x163220;
  DWORD serversecmeCall6=BaseAddress+0x185600;
  DWORD serversecmeCall7=BaseAddress+0x175160;
  DWORD bilgidogrulama=BaseAddress+0x487870;

  __asm
  {

	  mov ecx,Adres
	  call serversecmeCall2


  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button17Click(TObject *Sender)
{
	DWORD Addie =*(DWORD*)M_SendChatPtr;
    DWORD pidnum=GetCurrentProcessId();
   DWORD BaseAddress = dwGetModuleBaseAddress(pidnum,"metin2client.exe");
			DWORD addr=BaseAddress+0x175260;
  const char *s="Select";
  DWORD Adres = *(DWORD*)M_SendChatPtr;
  DWORD serversecmeCall=BaseAddress+0x187190;
  DWORD serversecmeCall2=BaseAddress+0x185ff0;
  DWORD serversecmeCall3=BaseAddress+0x186fc0;
  DWORD serversecmeCall4=BaseAddress+0x105f50; //1. call
  DWORD serversecmeCall5=BaseAddress+0x163220;
  DWORD serversecmeCall6=BaseAddress+0x185600;
  DWORD serversecmeCall7=BaseAddress+0x175160;
  DWORD bilgidogrulama=BaseAddress+0x118a10;

  __asm
  {

	  mov ecx,Adres           //bu direk karakter seçme ekranýna atýyor beni  //karakter seçme ekranýna atýyor
	  call serversecmeCall3
      



	 
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button18Click(TObject *Sender)
{
DWORD Addie =*(DWORD*)M_SendChatPtr;
    DWORD pidnum=GetCurrentProcessId();
   DWORD BaseAddress = dwGetModuleBaseAddress(pidnum,"metin2client.exe");

DWORD Adres = *(DWORD*)M_SendChatPtr;
  DWORD serversecmeCall=BaseAddress+0x162df0;


  __asm
  {

	 
	  mov ecx,Adres          //aha bu kadar otologin
	  push 1
	  call serversecmeCall

  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button19Click(TObject *Sender)
{
    DWORD Addie =*(DWORD*)M_SendChatPtr;
    DWORD pidnum=GetCurrentProcessId();
   DWORD BaseAddress = dwGetModuleBaseAddress(pidnum,"metin2client.exe");
			DWORD addr=BaseAddress+0x175260;
 
  DWORD Adres = *(DWORD*)M_SendChatPtr;
  DWORD serversecmeCall=BaseAddress+0x184cb0;
  DWORD serversecmeCall2=BaseAddress+0x185ff0;
  DWORD serversecmeCall3=BaseAddress+0x186fc0;
  DWORD serversecmeCall4=BaseAddress+0x105f50; //1. call
  DWORD serversecmeCall5=BaseAddress+0x163220;
  DWORD serversecmeCall6=BaseAddress+0x185600;
  DWORD serversecmeCall7=BaseAddress+0x175160;
  DWORD bilgidogrulama=BaseAddress+0x487870;

  __asm
  {

	  mov ecx,Adres
   	  call serversecmeCall5


	 
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button20Click(TObject *Sender)
{
    DWORD Addie =*(DWORD*)M_SendChatPtr;
	DWORD pidnum=GetCurrentProcessId();
   DWORD BaseAddress = dwGetModuleBaseAddress(pidnum,"metin2client.exe");
			DWORD addr=BaseAddress+0x175260;
  const char *s="Select";
  DWORD Adres = *(DWORD*)M_SendChatPtr;
  DWORD serversecmeCall=BaseAddress+0x184cb0;
  DWORD serversecmeCall2=BaseAddress+0x185ff0;
  DWORD serversecmeCall3=BaseAddress+0x186fc0;
  DWORD serversecmeCall4=BaseAddress+0x105f50; //1. call
  DWORD serversecmeCall5=BaseAddress+0x163220;
  DWORD serversecmeCall6=BaseAddress+0x185600;
  DWORD serversecmeCall7=BaseAddress+0x175160;
  DWORD bilgidogrulama=BaseAddress+0x487870;

  __asm
  {

	  mov ecx,Adres
	  call serversecmeCall6


	 
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button21Click(TObject *Sender)
{
	DWORD Addie =*(DWORD*)M_SendChatPtr;
	DWORD pidnum=GetCurrentProcessId();
   DWORD BaseAddress = dwGetModuleBaseAddress(pidnum,"metin2client.exe");
			DWORD addr=BaseAddress+0x175260;
  const char *s="Loading";
  DWORD Adres = *(DWORD*)M_SendChatPtr;
  DWORD serversecmeCall=BaseAddress+0x184cb0;
  DWORD serversecmeCall2=BaseAddress+0x185ff0;
  DWORD serversecmeCall3=BaseAddress+0x186fc0;
  DWORD serversecmeCall4=BaseAddress+0x105f50; //1. call
  DWORD serversecmeCall5=BaseAddress+0x163220;
  DWORD serversecmeCall6=BaseAddress+0x185600;
  DWORD serversecmeCall7=BaseAddress+0x175160;
  DWORD bilgidogrulama=BaseAddress+0x487870;

  __asm
  {

	  mov ecx,Adres
	  call serversecmeCall7


	  //ip girme
	/*  mov ecx,Adres
	  push serverport
	  push serverip
	  push chport
	  push serverip
	  call serversecmeCall

	  //bilgi girme
	  mov ecx,Adres
	  push sifre
	  push kadi
	  call bilgidogrulama
	 */
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button23Click(TObject *Sender)
{
	if (Form1->Button23->Caption==">>>")
	{
	 Form1->Width=737;
	 Form1->Button23->Caption="<<<";
	}
	else
	{
	 Form1->Width=316;
	 Form1->Button23->Caption=">>>";
    }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button22Click(TObject *Sender)
{
  	DWORD Addie =*(DWORD*)M_SendChatPtr;
	DWORD pidnum=GetCurrentProcessId();
   DWORD BaseAddress = dwGetModuleBaseAddress(pidnum,"metin2client.exe");
			DWORD addr=BaseAddress+0x175260;
  const char *id="";
  const char *pw="";
  int slot=0;
  DWORD Adres = *(DWORD*)M_SendChatPtr;
  DWORD yar=BaseAddress+0x186290;
 
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
	if (CheckBox1->Checked)
	{
	   bWallHack=true;
	}
	else
	{
		bWallHack=false;
	}
    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)wallhack, 0, 0, 0);
}
//---------------------------------------------------------------------------

void wallhack()
{
    (*(BYTE*)(*(DWORD*)(*(DWORD*)M_PlayerPtr + M_MyPlayer)+M_WH))=0;
	while (bWallHack)
	{
	 (*(BYTE*)(*(DWORD*)(*(DWORD*)M_PlayerPtr + M_MyPlayer)+M_WH))=1;
	 Sleep(1000);
   }

}

void specialWallHack()
{
   (*(DWORD*)(*(DWORD*)(*(DWORD*)M_PlayerPtr + M_MyPlayer)+M_SpecialWH))= 16256;
   //karakterin standart boyutu 16256.
	while (bSpecialWallHack)
	{
	DWORD karakterBoyut = (*(DWORD*)(*(DWORD*)(*(DWORD*)M_PlayerPtr + M_MyPlayer)+M_SpecialWH));
	bool isActive = (karakterBoyut == 16256) ? false : true;
    //Þayet 16256 ise karakterin boyutu aktif deðildir. Aktif deðilse aþaðýda aktif ederik.

	if (!isActive)
	{
	  (*(DWORD*)(*(DWORD*)(*(DWORD*)M_PlayerPtr + M_MyPlayer)+M_SpecialWH))= 19256;
	}

   Sleep(1000);
   }
}
void __fastcall TForm1::CheckBox2Click(TObject *Sender)
{
	if(Form1->CheckBox2->Checked)
	 {
		bSpecialWallHack = true;
		Form1->CheckBox1->Checked = true;
	 }
	 else
	 {
		bSpecialWallHack = false;

	 }
	 CreateThread(0, 0, (LPTHREAD_START_ROUTINE)specialWallHack, 0, 0, 0);
}
//---------------------------------------------------------------------------

void onehit()
{
	DWORD mevcutVurus = (*(DWORD*)(*(DWORD*)(*(DWORD*)M_PlayerPtr + M_MyPlayer)+M_Onehit));
    //vurmuyorsa 0x0, vurursa 0x0 'den büyüktür.
	while (bOneHit)
	{
	   mevcutVurus = (*(DWORD*)(*(DWORD*)(*(DWORD*)M_PlayerPtr + M_MyPlayer)+M_Onehit));
	   Form1->Caption="";

	 if (mevcutVurus>=2) {
		 (*(DWORD*)(*(DWORD*)(*(DWORD*)M_PlayerPtr + M_MyPlayer)+M_Onehit))=0x1;
	 }
	
	}
	 (*(DWORD*)(*(DWORD*)(*(DWORD*)M_PlayerPtr + M_MyPlayer)+M_Onehit))=0x0;//buraya
}


void __fastcall TForm1::CheckBox4Click(TObject *Sender)
{
	if(Form1->CheckBox4->Checked==true)
	{
		bOneHit = true;
	}
	else
	{
        (*(DWORD*)(*(DWORD*)(*(DWORD*)M_PlayerPtr + M_MyPlayer)+M_Onehit))=0x0;//buraya
		bOneHit=false;
		Form1->Caption="";
	}
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)onehit, 0, 0, 0);
}
//---------------------------------------------------------------------------

void BinekBin()
{
  	DWORD Addie =*(DWORD*)M_SendChatPtr;
	DWORD pidnum=GetCurrentProcessId();
   DWORD BaseAddress = dwGetModuleBaseAddress(pidnum,"metin2client.exe");
   //DWORD  mevcutdurum = (*(BYTE*)(*(DWORD*)(*(DWORD*)M_PlayerPtr + M_MyPlayer)+M_AttackType));
			DWORD addr=BaseAddress+0x175260;
	while (bAttackType)
	{
		 DWORD  mevcutdurum = (*(BYTE*)(*(DWORD*)(*(DWORD*)M_PlayerPtr + M_MyPlayer)+M_AttackType));
		if (mevcutdurum<10)
		{
		char* text="/ride";

				int Modus=0;
				__asm
				{
					mov ecx,Addie
					push 0
					push text
					Call addr

				}
		}
        Sleep(2500);
	}
}
void __fastcall TForm1::CheckBox18Click(TObject *Sender)
{
  if (Form1->CheckBox18->Checked==true)
  {
	bAttackType=true;
  }
  else
  {
	bAttackType=false;
  }
  CreateThread(0, 0, (LPTHREAD_START_ROUTINE)BinekBin, 0, 0, 0);
}
//---------------------------------------------------------------------------
void PmPlayerList()
{
    if (IsInGame())
	 {
		char *isim;
		DWORD tipi,vidi,leveli;
		Form1->ListBox2->Items->Clear();
	   for (int i = 0; i < MobSayi(); i++)
	   {

		  isim=(char*)((*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_FLDB) + (i*0x4)) + M_Name));
		  tipi=*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_FLDB) + (i*0x4)) + M_Type);
		  vidi=*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_FLDB) + (i*0x4)) + M_Vid);
		  leveli=*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(*reinterpret_cast<DWORD*>(M_FLDB) + (i*0x4)) + M_Level);

		  if (tipi==6 && leveli>0 && vidi!=player.vid)
		  {
		   Form1->ListBox2->Items->Add(isim);
            pmlist[i].nick=isim;

		  }

	   }



	 }
}

void __fastcall TForm1::Button5Click(TObject *Sender)
{
    CreateThread(0, 0, (LPTHREAD_START_ROUTINE)PmPlayerList, 0, 0, 0);
}
//---------------------------------------------------------------------------









