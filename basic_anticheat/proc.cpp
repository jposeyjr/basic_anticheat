#include "proc.h"


//use DWORD because the process id is one in windows
DWORD GetProcId(const wchar_t* procName) {
	DWORD procId = 0; //error checking 
	HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0); //getting a snapshot or process
	if (hSnap != INVALID_HANDLE_VALUE) {//make sure it is valid 
		PROCESSENTRY32 procEntery; //save the process id 
		procEntery.dwSize = sizeof(procEntery); //set size to make sure it works

		if (Process32First(hSnap, &procEntery)) { //grabs first process and stores it 
			do
			{
				if (!_wcsicmp(procEntery.szExeFile, procName)) {
					procId = procEntery.th32ProcessID;
					break;
				}
			} while (Process32Next(hSnap, &procEntery)); //looping through them all process id's until we find the one we want
		}
	}
	CloseHandle(hSnap); //prevent memory leaks
	return procId;//close and returns the id to us 
}