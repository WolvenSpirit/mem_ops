#include "Process_Class.h"
#include <iostream>
#include <windows.h>

using namespace std;

void Process_Class::OpenProc()
{
    hwnd = FindWindowA(NULL,window);

    if(hwnd != NULL)
    {
        cout << "[+] Found specified window." << endl;
        if(GetWindowThreadProcessId(hwnd,&ProcessID))
        {
            cout << "[+] Found pid " << ProcessID << endl;
        }
        else
        {
            cout << GetLastError() << endl;
        }
    }
    else
    {
        cout << GetLastError();
    }
    if(ProcessID != NULL)
    {
        Process_Handle = OpenProcess(Access_Type,false,ProcessID);
    }
}

void Process_Class::Read_Mem()
{

        ReadProcessMemory(Process_Handle,(PCVOID)hex_address,Local_Buffer,Read_Amount,NULL);
        cout << "----------------\nValue: " << (char*)Local_Buffer;

}

void Process_Class::Read_Mem_Byte(int xaddr)
{

        ReadProcessMemory(Process_Handle,(PCVOID)xaddr,Local_Buffer,Read_Amount,NULL);
        cout << (char*)Local_Buffer;
}

void Process_Class::Write_Mem()
{

        WriteProcessMemory(Process_Handle,(LPVOID)hex_address,&Overwrite_Buffer,sizeof(Overwrite_Buffer),NULL);
}
