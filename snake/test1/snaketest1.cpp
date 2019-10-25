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
		return 2333;
	}
	if(n < 1 || m < 1)
	{
		printf("��ͼ̫С�˿�������\n");
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
