#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main()
{
	bool b=true;
	HWND tophwnd;
	DWORD toppid;
	vector<DWORD>white;
	while(1)
	{
		while(1)
		{
			if(GetAsyncKeyState(VK_TAB))break;
			if(GetAsyncKeyState(VK_ESCAPE))
			{
				tophwnd=GetForegroundWindow();
				GetWindowThreadProcessId(tophwnd,&toppid);
				white.push_back(toppid);
			}
		}
		tophwnd=GetForegroundWindow();
		GetWindowThreadProcessId(tophwnd,&toppid);
		for(auto p:white)
		{
			if(p==toppid)
			{
				b=false;
				break;
			}
		}
		if(b)
		{
			HANDLE hproc=OpenProcess(PROCESS_TERMINATE,FALSE,toppid);
			TerminateProcess(hproc,0);
			CloseHandle(hproc);
		}
		b=true;
	}
}
