#ifndef DATA
#include<bits/stdc++.h>
using namespace std;
class DATA
{
private:
	char thing[5];
	char nowhead; 
	struct node
	{
		int x, y;
		node() {}
		node(int _x, int _y)
		{
			x = _x, y = _y;
		}
		inline friend bool operator==(const node &a,const node &b)
		{
			return a.x == b.x && a.y == b.y;
		}
	} body[2000010];
	char mp[1005][1005];
	int l, r;
	int n, m;
	inline bool judge(node head,char c)
	{
		if(c == 'W')
			--head.x;
		if(c == 'S')
			++head.x;
		if(c == 'A')
			--head.y;
		if(c == 'D')
			++head.y;
		if(head.x < 1 || head.x > n || head.y < 1 || head.y > m)
		{
			printf("获得成就：头破血流");
			return 0;
		}
		for(register int i = l; i < r; ++i)
		{
			if(head == body[i])
			{
				printf("获得成就：我吃我自己");
				return 0; 
			}
		}
		return true;
	}
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
		if(x <= n / 2)
		{
			if(y <= m / 2)
			{
				nowhead = 'S';
			}
			else
			{
				nowhead = 'W';
			}
		}
		else
		{
			if(y <= m / 2)
			{
				nowhead = 'A';
			}
			else
			{
				nowhead = 'W';
			}
		}
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
		if(opt != 'W' && opt != 'A' && opt != 'S' && opt != 'D')
			opt = nowhead;
		else
			nowhead = opt;
		if (opt == 'W')
		{
			if(!judge(body[l],opt))
			{
				return false;
			}
//			if (body[l].x - 1 < 1)
//			{
//				system("cls");
//				puts("GG");
//				return false;
//			}
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
			if(!judge(body[l],opt))
			{
				return false;
			}
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
			if(!judge(body[l],opt))
			{
				return false;
			}
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
			if(!judge(body[l],opt))
			{
				return false;
			}
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
#endif
