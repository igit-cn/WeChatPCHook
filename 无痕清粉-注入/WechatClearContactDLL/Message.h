#pragma once
#define OFFSET_MESSAGE_SEND_CARD_CALL		0x02EB4E0	//������Ƭ
#define OFFSET_MESSAGE_RECEIVE_ADDRESS_HOOK	0x030F337	//������Ϣ
#define OFFSET_MESSAGE_RECEIVE_ADDRESS_DATA	0x127F72C	//������Ϣ

void SendMessageCard(const wchar_t* recieverWxId, const wchar_t* senderWxId, const wchar_t* NickName);

void HookRecievedMessage();
void ListenRecievedMessage();
void DealRecievedMessage();
void UnHookRecievedMessage();
