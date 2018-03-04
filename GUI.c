#include "GUI.h"
#include <stdio.h>

void showInterface()
{
	printf_s("****************\n ");
	printf_s("这是一个简单功能的计算器\n");
	printf_s("请选择功能：\n");
	printf_s("1:复数计算\t\n");
	char a = getchar();
	switch (a)
	{
		case 'a':printf_s("这是复数计算功能!\n");
			break;
		default:printf_s("请输入正确功能!\n");
			break;
	}

}