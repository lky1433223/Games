#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
using namespace std;
class DATA
{
private:
	char thing[5];
	struct node
	{
		int x, y;
		node() {}
		node(int _x, int _y)
		{
			x = _x, y = _y;
		}
	} body[2000010];
	char mp[1005][1005];
	int l, r;
	int n, m;

public:
	DATA()
	{
		thing[0] = '@';
		thing[1] = '.';
		thing[2] = 'o';
		thing[3] = 'X';
	}
	DATA(int _n, int _m)
	{
		puts("loading");
		system("cls");
		n = _n, m = _m;
		memset(body, 0, sizeof(body));
		memset(mp, 0, sizeof(mp));
		l = r = 1000000;
		thing[0] = '@';
		thing[1] = '.';
		thing[2] = 'o';
		thing[3] = 'X';
		srand(time(0));
		for (register int i = 1; i <= n; ++i)
		{
			for (register int j = 1; j <= m; ++j)
			{
				int x = rand() % 10 + 1;
				if(x > 8)
					x = 2;
				else
					x = 1;
				mp[i][j] = thing[x];
			}
		}
		int x = rand() % n + 1, y = rand() % m + 1;
		mp[x][y] = thing[0];
		body[l] = node(x, y);
		mp[x][y] = '.';
		puts("begin");
		system("cls");
		out();
	}
	~DATA()
	{
		memset(mp, 0, sizeof(mp));
		memset(body, 0, sizeof(body));
		memset(thing, 0, sizeof(thing));
		l = r = 0;
	}
	inline bool updata(char opt)
	{
		if (opt == 'W')
		{
			if (body[l].x - 1 < 1)
			{
				system("cls");
				puts("GG");
				return false;
			}
			if (mp[body[l].x - 1][body[l].y] == 'o')
			{
				mp[body[l].x - 1][body[l].y] = '.';
				--l;
				body[l] = node(body[l + 1].x - 1, body[l + 1].y);
			}
			else
			{
				l--;
				body[l] = node(body[l + 1].x - 1, body[l + 1].y);
				body[r] = node(0, 0);
				--r;
			}
		}
		else if (opt == 'A')
		{
			if (body[l].y - 1 < 1)
			{
				system("cls");
				puts("GG");
				return false;
			}
			if (mp[body[l].x][body[l].y - 1] == 'o')
			{
				mp[body[l].x][body[l].y - 1] = '.';
				--l;
				body[l] = node(body[l + 1].x, body[l + 1].y - 1);
			}
			else
			{
				l--;
				body[l] = node(body[l + 1].x, body[l + 1].y - 1);
				body[r] = node(0, 0);
				--r;
			}
		}
		if (opt == 'S')
		{
			if (body[l].x + 1 > n)
			{
				system("cls");
				puts("GG");
				return false;
			}
			if (mp[body[l].x + 1][body[l].y] == 'o')
			{
				mp[body[l].x + 1][body[l].y] = '.';
				--l;
				body[l] = node(body[l + 1].x + 1, body[l + 1].y);
			}
			else
			{
				l--;
				body[l] = node(body[l + 1].x + 1, body[l + 1].y);
				body[r] = node(0, 0);
				--r;
			}
		}
		if (opt == 'D')
		{

			if (body[l].y + 1 > m)
			{
				system("cls");
				puts("GG");
				return false;
			}
			if (mp[body[l].x][body[l].y + 1] == 'o')
			{
				mp[body[l].x][body[l].y + 1] = '.';
				--l;
				body[l] = node(body[l + 1].x, body[l + 1].y + 1);
			}
			else
			{
				l--;
				body[l] = node(body[l + 1].x, body[l + 1].y + 1);
				body[r] = node(0, 0);
				--r;
			}
		}
		return true;
	}
	inline void out()
	{
		system("cls");
		for(register int i = 1; i <= n; ++i)
		{
			for(register int j = 1; j <= m; ++j)
			{
				if(mp[i][j] != 'o')
					mp[i][j] = '.';
			}
		}
		for (register int i = l + 1; i <= r; ++i)
		{
			mp[body[i].x][body[i].y] = 'X';
		}
		mp[body[l].x][body[l].y] = '@';
		for (register int i = 1; i <= n; ++i)
			puts(mp[i] + 1);
		cout.flush();
		int t = clock();
		while(clock() - t < n + m);
	}
};
int n, m;
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
		return 2333;
	}
	if(n < 1 || m < 1)
	{
		printf("地图太小了看不到了\n");
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
