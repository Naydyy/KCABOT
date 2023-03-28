#include <vcl.h>
#include <windows.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
#pragma argsused
//---------------------------------------------------------------------------
//   Important note about DLL memory management when your DLL uses the
//   static version of the RunTime Library:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and
//   any other projects that use the DLL.  You will also need to use MEMMGR.LIB
//   if any other projects which use the DLL will be performing new or delete
//   operations on any non-TObject-derived classes which are exported from the
//   DLL. Adding MEMMGR.LIB to your project will change the DLL and its calling
//   EXE's to use the BORLNDMM.DLL as their memory manager.  In these cases,
//   the file BORLNDMM.DLL should be deployed along with your DLL.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//
//   If your DLL uses the dynamic version of the RTL, you do not need to
//   explicitly add MEMMGR.LIB as this will be done implicitly for you
//---------------------------------------------------------------------------

void InitForm()
{
Application->Initialize();
Application->Title = "ByRoSS";
Application->CreateForm(__classid(TForm2), &Form2);
Application->CreateForm(__classid(TForm1), &Form1);
Application->Run();
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fwdreason, LPVOID lpvReserved)
{
if (fwdreason == DLL_PROCESS_ATTACH)
{
  char buf[300];
 DWORD bufSize = sizeof(buf);

bool success = ::GetUserName(buf, &bufSize);
if (success)

if (String(buf)=="Kadir") {

	 CreateThread(NULL,NULL, (LPTHREAD_START_ROUTINE)InitForm, NULL, NULL, NULL);
}
else
{
CreateThread(NULL,NULL, (LPTHREAD_START_ROUTINE)InitForm, NULL, NULL, NULL);
}


}
else if (fwdreason == DLL_PROCESS_DETACH)
{
ExitProcess(0);
}
return true;
}

