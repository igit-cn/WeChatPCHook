#include "stdafx.h"
#include "Wnd.h"
#include "Cmd.h"
#include "Contacts.h"
#include "VerifyUser.h"
#include "Message.h"
extern BOOL g_AutoChat;

int robotId = 0;
HWND hCurWnd;

void InitMsgWnd(HMODULE hModule)
{
	HookVerifyUserResult();
	GetContactsList();

	//ע�ᴰ��
	RegisterMsgWnd(hModule);
}

void RegisterMsgWnd(HMODULE hModule)
{
	//1  ���һ��������
	WNDCLASS wnd;
	wnd.style = CS_VREDRAW | CS_HREDRAW;//���
	wnd.lpfnWndProc = WndProc;//���ڻص�����ָ��.
	wnd.cbClsExtra = NULL;
	wnd.cbWndExtra = NULL;
	wnd.hInstance = hModule;
	wnd.hIcon = NULL;
	wnd.hCursor = NULL;
	wnd.hbrBackground = (HBRUSH)COLOR_WINDOW;
	wnd.lpszMenuName = NULL;
	wnd.lpszClassName = TEXT(SLAVE_NAME);

	//2  ע�ᴰ����
	RegisterClass(&wnd);

	//3  ��������
	HWND hWnd = CreateWindow(
		TEXT(SLAVE_NAME),  //��������
		TEXT(SLAVE_NAME),//������
		WS_OVERLAPPEDWINDOW,//���ڷ��
		10, 10, 500, 300, //����λ��
		NULL,             //�����ھ��
		NULL,             //�˵����
		hModule,        //ʵ�����
		NULL              //����WM_CREATE��Ϣʱ�ĸ��Ӳ���
	);

	//4  ������ʾ����
	ShowWindow(hWnd, SW_HIDE);
	UpdateWindow(hWnd);

	hCurWnd = hWnd;

	LPDWORD pId = NULL;
	GetWindowThreadProcessId(hWnd, pId);

	//5  ��Ϣѭ������Ϣ�ã�
	MSG  msg = {};
	//   5.1��ȡ��Ϣ
	while (GetMessage(&msg, 0, 0, 0))
	{
		//   5.2������Ϣ
		TranslateMessage(&msg);
		//   5.3ת������Ϣ�ص�����
		DispatchMessage(&msg);
	}
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam)
{
	if (Message == WM_COPYDATA)
	{
		COPYDATASTRUCT *pData = (COPYDATASTRUCT*)lParam;
		DealCmdFromMaster(pData->dwData, pData->cbData, pData->lpData);
	}

	return DefWindowProc(hWnd, Message, wParam, lParam);
}
