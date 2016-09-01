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

//��ʼ�����Դ�����ʾ
void InitDebugConsole();

//�ͷŵ����Դ�����ʾ
void ExitDebugConsole();

//ANSI to Unicode
std::wstring ANSIToUnicode(const std::string& str);
//Unicode to ANSI
std::string UnicodeToANSI(const std::wstring& wstr);
//UTF - 8 to Unicode
std::wstring UTF8ToUnicode(const std::string& str);
//Unicode to UTF - 8
std::string UnicodeToUTF8(const std::wstring& wstr);


//utf8 ת Unicode
std::wstring Utf82Unicode(const std::string& utf8string);

//unicode תΪ ascii
std::string WideByte2Acsi(std::wstring& wstrcode);

//utf-8 ת ascii
std::string UTF_82ASCII(std::string& strUtf8Code);

///////////////////////////////////////////////////////////////////////

//ascii ת Unicode
std::wstring Acsi2WideByte(std::string& strascii);

//Unicode ת Utf8
std::string Unicode2Utf8(const std::wstring& widestring);

//ascii ת Utf8
std::string ASCII2UTF_8(std::string& strAsciiCode);

int code_convert(char *from_charset, char *to_charset, const char *inbuf, size_t inlen, char *outbuf, size_t outlen);
/* UTF-8 to GBK  */
int u2g(const char *inbuf, size_t inlen, char *outbuf, size_t outlen);

/* GBK to UTF-8 */
int g2u(const char *inbuf, size_t inlen, char *outbuf, size_t outlen);

//��ʾ����Ļ����
void CenterWindowInScreen(HWND hWnd);

//��ʾ�ڸ���������
void CenterWindowInParent(HWND hWnd, HWND hParentWnd);

//����Ӧ�ó����ļ����ơ��������������ͼ��ȴ�ʱ����������
typedef enum LaunchType {
	LTYPE_0 = 0, //����
	LTYPE_1 = 1, //ֱ��
	LTYPE_2 = 2, //�ӳ�(�趨�ȴ�ʱ��)
}LAUNCHTYPE;
BOOL LaunchAppProg(wstring tsAppProgName, wstring tsArguments = L"", bool bNoUI = true, LAUNCHTYPE type = LTYPE_0, DWORD dwWaitTime = WAIT_TIMEOUT);