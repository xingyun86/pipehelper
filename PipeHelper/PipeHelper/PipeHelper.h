#pragma once

class CPipeHelper
{
public:
	CPipeHelper();
	~CPipeHelper();

private:
	HANDLE m_hScriptFile;//脚本句柄

	HANDLE m_hStdInReader;//标准读输入流
	HANDLE m_hStdInWriter;//标准写输入流
	HANDLE m_hStdOutReader;//标准读输出流
	HANDLE m_hStdOutWriter;//标准读输出流

	DWORD m_dwReadTimeout;//读取超时时间,单位为毫秒

	/////////////////////////////////////////////////////////////////////////////////////////////////
	//函数功能:创建子应用进程
	//函数参数:
	//		wstrAppProg	应用程序名称
	//		wstrCmdLine	程序运行参数
	//返回值:
	//	0,		成功
	//	(-1),	创建进程失败
	int CreateChildProcess(std::wstring wstrAppProg, std::wstring wstrCmdLine);

	/////////////////////////////////////////////////////////////////////////////////////////////////
	//函数功能:读取脚本命令执行结果
	//函数参数:
	//返回值:
	void ReadFromPipe(void);

	/////////////////////////////////////////////////////////////////////////////////////////////////
	//函数功能:脚本写入命令
	//函数参数:
	//返回值:
	void WriteToPipe(void);

	/////////////////////////////////////////////////////////////////////////////////////////////////
	//函数功能:写入命令并取得执行结果
	//函数参数:
	//		wstrInputCommand	要写入的命令(内容处理会加入'\r\n')
	//返回值:
	//		失败返回空,成功返回执行结果
	std::wstring WritePipeAndReadPipe(std::wstring wstrInputCommand);

public:

	/////////////////////////////////////////////////////////////////////////////////////////////////
	//函数功能:初始化管道操作类
	//函数参数:
	//		wstrAppProg			应用程序名称
	//		wstrCmdLine			程序运行参数
	//		wstrScriptFileName	脚本文件路径名
	//返回值:
	//	0,		成功
	//	(-1),	打开脚本文件失败
	int Init(std::wstring wstrAppProg, std::wstring wstrCmdLine, std::wstring wstrScriptFileName = L"");

	/////////////////////////////////////////////////////////////////////////////////////////////////
	//函数功能:释放掉管道操作类
	//函数参数:
	//返回值:
	void Exit();

	/////////////////////////////////////////////////////////////////////////////////////////////////
	//函数功能:初始化管道leilei
	//函数参数:
	//		wstrScriptName	脚本文件路径名
	//返回值:
	//	0,		成功
	//	(-1),	打开脚本文件失败
	int InitScript(std::wstring wstrScriptFileName);

	/////////////////////////////////////////////////////////////////////////////////////////////////
	//函数功能:设置管道读超时时间(设置即时生效)
	//函数参数:
	//		dwReadTimeout	超时时间,单位为毫秒
	//返回值:
	void SetReadTimeout(DWORD dwReadTimeout) { this->m_dwReadTimeout = dwReadTimeout; }

	/////////////////////////////////////////////////////////////////////////////////////////////////
	//函数功能:读取脚本命令执行结果
	//函数参数:
	//返回值:
	void Read();

	/////////////////////////////////////////////////////////////////////////////////////////////////
	//函数功能:脚本写入命令
	//函数参数:
	//返回值:
	void Write();
	
	/////////////////////////////////////////////////////////////////////////////////////////////////
	//函数功能:写入命令并取得执行结果
	//函数参数:
	//		wstrInputCommand	要写入的命令(内容处理会加入'\r\n')
	//返回值:
	//		失败返回空,成功返回执行结果
	std::wstring WriteAndRead(std::wstring wstrInputCommand);
};

