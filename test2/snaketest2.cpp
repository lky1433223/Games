#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include "DATA.h"
using namespace std;

int n, m;
inline void wait(int t)
{
	int T = clock();
	while(T + t * 1000 > clock());
}
/*
��һ��
�ð汾Դ��comet OJ Contest13 B��
û������
������ɵ�ͼ����֧�����ӣ�
�ᴩģ 
*/
int main()
{
	printf("��ӭ����̰�����ڲ����԰�\n�汾: test1\n����: Shiina-Rikka\n����ʱ��: ");
	cerr << __DATE__ << " " << __TIME__ << endl;
	printf("�ð汾Դ��comet OJ Contest13 B��\n");
	printf("�����Ǳ������� ���ܽ���\n");
	printf("���ܿ��Ǹ���\n"); 
	printf("\n��Ϸ˵��: \n �հ�:. \n ʳ��:o \n ����:X \n ��ͷ:@ \n");
	printf("ʹ�� WASD ���Ʒ���\n\n");
	printf("�������ͼ��С\nΪ��֤������Ϸ����\n��ȷ������С��30\n"); 
	cin >> n >> m;
	if(n > 1000 || m > 1000)
	{
		printf("��ͼ���� ��Ϸ������2333\n");
		wait(3);
		return 2333;
	}
	if(n < 1 || m < 1)
	{
		printf("��ͼ̫С�˿�������\n");
		wait(3);
		return 3222; 
	}
	DATA snack1(n, m);
	while(1)
	{
		char c = 0;
//		cin >> c;
		c = getch(); 
		if(c >= 'a' && c <= 'z')
			c -= 32; 
		if(!snack1.updata(c))
		{
			int t = clock();
			while(clock() - t < 1000);
			return 0;
		}
		snack1.out();
	}
	return 0;
}
