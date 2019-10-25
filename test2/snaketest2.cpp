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
第一版
该版本源于comet OJ Contest13 B题
没有声音
随机生成地图（不支持种子）
会穿模 
*/
int main()
{
	printf("欢迎来到贪吃蛇内部测试版\n版本: test1\n作者: Shiina-Rikka\n更新时间: ");
	cerr << __DATE__ << " " << __TIME__ << endl;
	printf("该版本源于comet OJ Contest13 B题\n");
	printf("由于是比赛程序 功能较少\n");
	printf("可能考虑更新\n"); 
	printf("\n游戏说明: \n 空白:. \n 食物:o \n 身体:X \n 蛇头:@ \n");
	printf("使用 WASD 控制方向\n\n");
	printf("请输入地图大小\n为保证您的游戏体验\n请确保长宽小于30\n"); 
	cin >> n >> m;
	if(n > 1000 || m > 1000)
	{
		printf("地图过大 游戏崩溃了2333\n");
		wait(3);
		return 2333;
	}
	if(n < 1 || m < 1)
	{
		printf("地图太小了看不到了\n");
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
