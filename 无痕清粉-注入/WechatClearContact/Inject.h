#pragma once

#define TARGET_NAME				"WeChat.exe"
#define DLL_NAME				"WechatClearContactDLL.dll"

BOOL LoadDll(DWORD pid);				//ע��DLL
void UnloadDll(DWORD pid);				//ж��DLL
BOOL IsloadedDll(DWORD pid);			//���DLL�Ƿ��Ѿ�ע��
DWORD FindNotLoadedDllPid();			//����δ����DLL�Ľ���
DWORD FindWeChatPid();					//����δ����DLL�Ľ���
