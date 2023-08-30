//#include "stdafx.h"
#include "iostream"
#include "ctime"
#include "cstdlib"
using namespace std;
#define N  999 //精度为小数点后面3位
int main()
{
	float num;
	int i;
	float random[10];
	srand(time(NULL));//设置随机数种子，使每次产生的随机序列不同
	for (int i = 0; i < 10; i++)
	{
		random[i] = rand() % (N + 1) / (float)(N + 1);
	}
	for (int i = 0; i < 10; i++)
	{
		cout << random[i] << endl; //输出产生的10个随机数
	}
    return 0;
}