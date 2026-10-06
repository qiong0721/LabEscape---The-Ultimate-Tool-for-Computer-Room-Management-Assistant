#include <bits/stdc++.h>
#include <windows.h>
#include <tlhelp32.h>
using namespace std;
int main() {
	while(1)
	{	
	    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	    PROCESSENTRY32W pe{};
    	pe.dwSize = sizeof(pe);
		DWORD pid = 0;
    	if (Process32FirstW(hSnap, &pe)) {
    	    do {
    	        if (_wcsicmp(pe.szExeFile, L"jfglzsn.exe") == 0) {
        	        pid = pe.th32ProcessID;
            	    break;
            	}
        	} while (Process32NextW(hSnap, &pe));
		}	
		CloseHandle(hSnap);
	    HANDLE hProc = OpenProcess(PROCESS_TERMINATE, FALSE, pid);
	    TerminateProcess(hProc,0);
	    CloseHandle(hProc);
	    cout<<pid<<endl;
	}
}
