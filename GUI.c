#include "GUI.h"
#include <stdio.h>

void showInterface()
{
	printf_s("****************\n ");
	printf_s("����һ���򵥹��ܵļ�����\n");
	printf_s("��ѡ���ܣ�\n");
	printf_s("1:��������\t\n");
	char a = getchar();
	switch (a)
	{
		case 'a':printf_s("���Ǹ������㹦��!\n");
			break;
		default:printf_s("��������ȷ����!\n");
			break;
	}

}