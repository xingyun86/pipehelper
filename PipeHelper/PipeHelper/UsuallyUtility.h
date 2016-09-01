//////////////////////////////////////////////////////////////////////
//
// Created by ppshuai in 2016-08-22
// Common utility interface.
//	1.Debug Console
//	2.String convert
//	3.Win32 Window show
//	4.Win32 start application

#pragma once

#include <windows.h>
#include <string>
#include <vector>

using namespace std;

#include <iconv.h>
#ifdef WIN32 //x86
#ifdef _DEBUG
#pragma comment(lib, "x86\\debug\\libiconv.lib")
#else
#pragma comment(lib, "x86\\release\\libiconv.lib")
#endif // _DEBUG

#else //WIN64 x64
#ifdef _DEBUG
#pragma comment(lib, "x64\\debug\\libiconv.lib")
#else
#pragma comment(lib, "x64\\release\\libiconv.lib")
#endif // _DEBUG

#endif // WIN32

//初始化调试窗口显示
void InitDebugConsole();

//释放掉调试窗口显示
void ExitDebugConsole();

//ANSI to Unicode
std::wstring ANSIToUnicode(const std::string& str);
//Unicode to ANSI
std::string UnicodeToANSI(const std::wstring& wstr);
//UTF - 8 to Unicode
std::wstring UTF8ToUnicode(const std::string& str);
//Unicode to UTF - 8
std::string UnicodeToUTF8(const std::wstring& wstr);


//utf8 转 Unicode
std::wstring Utf82Unicode(const std::string& utf8string);

//unicode 转为 ascii
std::string WideByte2Acsi(std::wstring& wstrcode);

//utf-8 转 ascii
std::string UTF_82ASCII(std::string& strUtf8Code);

///////////////////////////////////////////////////////////////////////

//ascii 转 Unicode
std::wstring Acsi2WideByte(std::string& strascii);

//Unicode 转 Utf8
std::string Unicode2Utf8(const std::wstring& widestring);

//ascii 转 Utf8
std::string ASCII2UTF_8(std::string& strAsciiCode);

int code_convert(char *from_charset, char *to_charset, const char *inbuf, size_t inlen, char *outbuf, size_t outlen);
/* UTF-8 to GBK  */
int u2g(const char *inbuf, size_t inlen, char *outbuf, size_t outlen);

/* GBK to UTF-8 */
int g2u(const char *inbuf, size_t inlen, char *outbuf, size_t outlen);

//显示在屏幕中央
void CenterWindowInScreen(HWND hWnd);

//显示在父窗口中央
void CenterWindowInParent(HWND hWnd, HWND hParentWnd);

//传入应用程序文件名称、参数、启动类型及等待时间启动程序
typedef enum LaunchType {
	LTYPE_0 = 0, //立即
	LTYPE_1 = 1, //直等
	LTYPE_2 = 2, //延迟(设定等待时间)
}LAUNCHTYPE;
BOOL LaunchAppProg(wstring tsAppProgName, wstring tsArguments = L"", bool bNoUI = true, LAUNCHTYPE type = LTYPE_0, DWORD dwWaitTime = WAIT_TIMEOUT);