#include "stdafx.h"
#include "Cmd.h"

void SendCmdToSlave(ULONG_PTR dwData, DWORD cbData, PVOID lpData)
{
	//���Ҵ���
	CWnd *pWnd = CWnd::FindWindow(NULL, TEXT(SLAVE_NAME));
	if (NULL == pWnd)
	{
		MessageBoxA(NULL, "�Ҳ���Slave", "����", 0);
		return;
	}

	//��װ����
	COPYDATASTRUCT message;
	message.dwData = dwData;
	message.cbData = cbData;
	message.lpData = lpData;

	pWnd->SendMessage(WM_COPYDATA, NULL, (LPARAM)&message);

	return;
}

extern wstring wsWxId = L"";

void DealCmdFromSlave(ULONG_PTR dwData, DWORD cbData, PVOID lpData)
{
	int messageType = dwData;
	switch (messageType)
	{
	case CT_CONTACT_CHECK:
	{
		ContactInfoStruct contactInfo = *(ContactInfoStruct*)lpData;
		OutputDebugString(contactInfo.wcWxId);
		OutputDebugString(contactInfo.wcWxName);
		OutputDebugString(contactInfo.wcCheckResult);
		OutputDebugString(L"\r\n");
	}
	break;

	case CT_FRIEND_DEL:
	{
		FriendOperStruct friendInfo = *(FriendOperStruct*)lpData;
		OutputDebugString(friendInfo.wcWxId);
		OutputDebugString(L"\r\n");
	}
	break;

	default:
		break;
	}
}
