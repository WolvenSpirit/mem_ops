#ifndef PROCESS_CLASS_H
#define PROCESS_CLASS_H
#include <windows.h>

class Process_Class
{
    public:
        void OpenProc();
        void Read_Mem();
        void Read_Mem_Byte(int xaddr);
        void Write_Mem();
        int hex_address = 0x2212B0;
        LPCVOID Overwrite_Buffer;
    protected:
        LPCSTR window = "Untitled - Notepad";//"D:\\CPP_code\\cpp_tut\\bin\\Debug\\cpp_tut.exe"; //
        HWND hwnd;
        DWORD ProcessID;
        DWORD Access_Type = PROCESS_ALL_ACCESS;
        HANDLE Process_Handle;
        DWORD Read_Amount = 22;
        LPVOID Local_Buffer[128];
        SIZE_T* Bytes_Written;
    private:
};

#endif // PROCESS_CLASS_H
