#include <iostream>
#include <windows.h>
#include <string>
#include "Process_Class.h"

using namespace std;

int main()
{
    Process_Class p;
    p.OpenProc();
    int amount = 22;
    int base_offset_address = 0x2212B0;
    // Notepad may not be an obvious example since it uses unicode
    for(int i = 0; i <= amount;i++)
    {
        p.Read_Mem_Byte(base_offset_address+i);
    }
    return 0;
}
