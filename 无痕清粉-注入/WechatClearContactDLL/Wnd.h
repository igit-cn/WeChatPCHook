#pragma once
#include "stdafx.h"

void InitMsgWnd(HMODULE hModule);			//��ʼ������
void RegisterMsgWnd(HMODULE hModule);		//ע�ᴰ��
LRESULT CALLBACK WndProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);	//���ڻص�
