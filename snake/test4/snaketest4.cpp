#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include "DATA.h"
using namespace std;
/*
game data wrong return 2333
*/
//地图大小
int n, m;
//游戏速度
int speed;
//暂停 t 秒
inline void wait(int t)
{
	int T = clock();
	while (T + t * 1000 > clock())
		;
}
// test4 use English because developed by VScode
int main()
{
	printf("Welcome to the Snake(Internal beta4)\nDevelopers: Shiina-Rikka\nDevelopment time: ");
	cerr << __DATE__ << " " << __TIME__ << endl;
	printf("\nGame instructions: \n Vacancy:. \n Food:o \n Body:X \n Head:@ \n");
	printf(" Please use WASD to control\n\n");
	printf("Please enter the map size\nTo ensure your gaming experience\nPlease ensure that the length and width are less than 30\n");
	cin >> n >> m;
	printf("Pleas enter the game speed\n");
	cin >> speed;
	if (n > 1000 || m > 1000)
	{
		printf("%d %d is too large for the Snake\n", n, m);
		wait(3);
		return 2333;
	}
	if (n < 1 || m < 1)
	{
		printf("%d %d is too small for the Snake\n", n, m);
		wait(3);
		return 2333;
	}
	if (speed < 100)
	{
		printf("%dis too fast for the snake\n", speed);
		wait(3);
		return 2333;
	}
	DATA snack1(n, m);
	while (1)
	{
		char c = '+';
		bool timeover = 1;
		int T = clock();
		while ((timeover = (clock() - T < speed)) && !kbhit())
			;
		if (timeover)
		{
			c = getch();
		}
		if (c >= 'a' && c <= 'z')
			c -= 32;
		if (!snack1.control(c))
		{
			int t = clock();
			wait(1);
			return 0;
		}
		snack1.new_food();
		snack1.out();
	}
	system("pause");
	return 0;
}
