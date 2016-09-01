// PipeHelper.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "PipeHelper.h"

#include <windows.h> 
#include <tchar.h>
#include <stdio.h> 
#include <strsafe.h>

int _tmain(int argc, TCHAR *argv[])
{
	int result = 0;
	CPipeHelper pipeHelper;
	std::wstring wstrResult = L"";

	_tsetlocale(LC_ALL, _T("chs"));

	result = pipeHelper.Init(L"D:\\android-eclipse\\android-sdk-windows\\platform-tools\\adb.exe", L" shell");
	if (result != 0)
	{
		return (-1);
	}
	//pipeHelper.SetReadTimeout(300);
	
	wstrResult = pipeHelper.WriteAndRead(L"ls");
	printf("%ws\r\n", wstrResult.c_str());

	wstrResult = pipeHelper.WriteAndRead(L"ps");
	printf("%ws\r\n", wstrResult.c_str());

	wstrResult = pipeHelper.WriteAndRead(L"exit");
	printf("%ws\r\n", wstrResult.c_str());

	pipeHelper.Exit();

	result = pipeHelper.Init(L"c:\\windows\\system32\\cmd.exe", L"");
	if (result != 0)
	{
		return (-1);
	}
	//pipeHelper.SetReadTimeout(300);

	wstrResult = pipeHelper.WriteAndRead(L"ls");
	printf("%ws\r\n", wstrResult.c_str());

	wstrResult = pipeHelper.WriteAndRead(L"dir");
	printf("%ws\r\n", wstrResult.c_str());

	wstrResult = pipeHelper.WriteAndRead(L"exit");
	printf("%ws\r\n", wstrResult.c_str());

	pipeHelper.Exit();

	return 0;
}

void ErrorExit(PTSTR lpszFunction)

// Format a readable error message, display a message box, 
// and exit from the application.
{
	LPVOID lpMsgBuf;
	LPVOID lpDisplayBuf;
	DWORD dw = GetLastError();

	FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM |
		FORMAT_MESSAGE_IGNORE_INSERTS,
		NULL,
		dw,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		(LPTSTR)&lpMsgBuf,
		0, NULL);

	lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT,
		(lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR));
	StringCchPrintf((LPTSTR)lpDisplayBuf,
		LocalSize(lpDisplayBuf) / sizeof(TCHAR),
		TEXT("%s failed with error %d: %s"),
		lpszFunction, dw, lpMsgBuf);
	MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);

	LocalFree(lpMsgBuf);
	LocalFree(lpDisplayBuf);
	ExitProcess(1);
}
