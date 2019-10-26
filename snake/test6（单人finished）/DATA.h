#ifndef DATA
#define DATA
#include <bits/stdc++.h>
#include "SONG.h"
using namespace std;
class SNAKE
{
private:
	struct node
	{
		int x, y;
		node() {}
		node(int _x, int _y) { x = _x, y = _y; }
		inline friend bool operator==(const node &a, const node &b) { return a.x == b.x && a.y == b.y; }
	} body[7200];
	//地图大小
	int n, m;
	//地图
	char mp[60][60];
	//地图中的四个物品
	char thing[5];
	//当前头部朝向
	int nowhead;
	//记录身体信息
	//头，尾
	int l, r;
	//分数
	int score;
	//初始时间，用于计算游戏时间
	unsigned long long TIME;
	//判断当前是否合法
	inline bool judge_head(node head, char c)
	{
		if (c == 'W')
			--head.x;
		if (c == 'S')
			++head.x;
		if (c == 'A')
			--head.y;
		if (c == 'D')
			++head.y;
		if (head.x < 1 || head.x > n || head.y < 1 || head.y > m)
		{
			puts("Achievement: head broken blood");
			return 0;
		}
		for (register int i = l; i < r; ++i)
		{
			if (head == body[i])
			{
				puts("Achievement: eat myself");
				return 0;
			}
		}
		return true;
	}
	//检查食物位置合法
	inline bool judge_food(const node &fd)
	{
		for (register int i = l; i <= r; ++i)
			if (fd == body[i])
				return false;
		return true;
	}
	//更新地图
	inline void updata_map()
	{
		for (register int i = 1; i <= n; ++i)
		{
			for (register int j = 1; j <= m; ++j)
			{
				if (mp[i][j] != thing[2])
					mp[i][j] = thing[1];
			}
		}
		for (register int i = l + 1; i <= r; ++i)
		{
			if (body[i].x == body[i - 1].x)
				mp[body[i].x][body[i].y] = thing[3];
			if (body[i].y == body[i - 1].y)
				mp[body[i].x][body[i].y] = thing[3];
		}
		mp[body[l].x][body[l].y] = thing[0];
	}

public:
	SNAKE() {}
	SNAKE(int _n, int _m)
	{
		puts("loading");
		loading_sound();
		system("cls");
		n = _n, m = _m;
		memset(body, 0, sizeof(body));
		memset(mp, 0, sizeof(mp));
		l = r = 3600, score = 0;
		thing[0] = '@', thing[1] = '.', thing[2] = 'o', thing[3] = 'X';
		srand(time(0));
		for (register int i = 1; i <= n; ++i)
		{
			for (register int j = 1; j <= m; ++j)
			{
				int x = rand() % 10 + 1;
				if (x > 8)
					x = 2;
				else
					x = 1;
				mp[i][j] = thing[x];
			}
		}
		int x = rand() % n + 1, y = rand() % m + 1;
		if (x <= n / 2)
		{
			if (y <= m / 2)
			{
				nowhead = 'S';
			}
			else
			{
				nowhead = 'A';
			}
		}
		else
		{
			if (y <= m / 2)
			{
				nowhead = 'D';
			}
			else
			{
				nowhead = 'W';
			}
		}
		mp[x][y] = thing[0];
		body[l] = node(x, y);
		mp[x][y] = thing[1];
		for (register int i = 10; i >= 1; --i)
			putchar((char)(i + '0'));
		puts("begin");
		system("cls");
		updata_map();
		TIME = clock();
		out();
	}
	~SNAKE()
	{
		memset(mp, 0, sizeof(mp));
		memset(body, 0, sizeof(body));
		memset(thing, 0, sizeof(thing));
		l = r = m = n = score = nowhead = TIME = 0;
	}
	//input WASD 控制方向
	inline bool control(char opt)
	{
		//错误输入沿原路径
		if (opt != 'W' && opt != 'A' && opt != 'S' && opt != 'D')
			opt = nowhead;
		else
			nowhead = opt;
		//判断方向
		if (opt == 'W')
		{
			if (!judge_head(body[l], opt))
			{
				return false;
			}
			if (mp[body[l].x - 1][body[l].y] == thing[2])
			{
				mp[body[l].x - 1][body[l].y] = thing[1];
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
			if (!judge_head(body[l], opt))
			{
				return false;
			}
			if (mp[body[l].x][body[l].y - 1] == thing[2])
			{
				mp[body[l].x][body[l].y - 1] = thing[1];
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
		else if (opt == 'S')
		{
			if (!judge_head(body[l], opt))
			{
				return false;
			}
			if (mp[body[l].x + 1][body[l].y] == thing[2])
			{
				mp[body[l].x + 1][body[l].y] = thing[1];
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
		else if (opt == 'D')
		{
			if (!judge_head(body[l], opt))
			{
				return false;
			}
			if (mp[body[l].x][body[l].y + 1] == thing[2])
			{
				mp[body[l].x][body[l].y + 1] = thing[1];
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
	//新食物
	inline void new_food()
	{
		updata_map();
		int tim = 0;
		int x = rand() % n + 1, y = rand() % m + 1;
		node fd(x, y);
		while (!judge_food(fd) && ++tim < n * m)
		{
			fd = node(rand() % n + 1, rand() % m + 1);
		}
		mp[fd.x][fd.y] = thing[2];
		updata_map();
	}
	//输出当前地图
	inline bool out()
	{
		updata_map();
		if (r - l + 1 == n * m)
		{
			puts("You Win");
			return 1;
		}
		for (register int i = 1; i <= n; ++i)
			puts(mp[i] + 1);
		puts("");
		if (r - l != score)
			EAT_sound();
		else
			WALK_sound();
		score = r - l;
		cerr << "score:" << r - l << "\ntime:" << (clock() - TIME) / 1000.0 << "s" << endl;
		cout.flush();
		int t = clock();
		while (clock() - t < n + m)
			;
	}
	inline int get_score()
	{
		return score;
	}
	inline unsigned long long get_time()
	{
		return clock() - TIME;
	}
};
#endif
