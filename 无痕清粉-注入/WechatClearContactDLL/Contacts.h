#pragma once
#include <string>
using namespace std;

#define OFFSET_CONTACT_GLOBAL	0x161CF54	//��ϵ��ȫ�ֵ�ַ

struct ContactStruct
{
	wchar_t wcWxId[80];
	wchar_t wcWxName[80];
	int type;
	int verifyFlag;
};

void GetContactsList();
ContactStruct GetWxNameByWxId(wchar_t* pWxId);
