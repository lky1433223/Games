#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>
#include "DATA.h"
#include "SONG.h"
using namespace std;
int n, m;
int speed;
inline void wait(int t)
{
	int T = clock();
	while (T + t * 1000 > clock())
		;
}
struct Gamedata
{
	int score;
	int n, m, speed;
	unsigned long long tim;
} data;
vector<Gamedata> game;
int main()
{
	printf("Welcome to the Snake(private Beta 6)\nDevelopers: Shiina-Rikka\nDevelopment time: ");
	cout << __DATE__ << " " << __TIME__ << endl;

	loading_qdo_onehalf();
	printf("\nGame instructions: \n Vacancy:. \n Food:o \n Body:X \n Head:@ \n");
	printf(" Please use WASD to control\n\n");
	printf("Press Enter to star\n");
	getchar();
	
	int best_score = 0, Case = 0;
	while (1)
	{
		++Case;
		system("cls");
		printf("Please enter the map size\nTo ensure your gaming experience\nPlease ensure that the length and width are less than 30\n");
		loading_qdo_onehalf();
		cin >> n >> m;
		loading_mi_one();
		printf("Pleas enter the game speed. unit:ms\nRecommendation 500\n");
		cin >> speed;
		loading_so_one();
		bool begingame = 1;
		if (n > 50 || m > 50)
		{
			begingame = 0;
			printf("%d %d is too large for the Snake\n", n, m);
			sys_wrong_sound();
			wait(3);
			return 0;
		}
		if (n < 1 || m < 1)
		{
			begingame = 0;
			printf("%d %d is too small for the Snake\n", n, m);
			sys_wrong_sound();
			wait(3);
			return 0;
		}
		if (speed < 100)
		{
			begingame = 0;
			printf("%d is too fast for the snake\n", speed);
			sys_wrong_sound();
			wait(3);
			return 0;
		}
		SNAKE snack1(n, m);
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
				GAME_OVER_sound();
				int t = clock();
				wait(1);
				system("cls");
				puts("GAME OVER");
				for (register int i = 1; i <= 3; ++i)
					puts("");
				break;
			}
			snack1.new_food();
			system("cls");
			if (snack1.out())
			{
				break;
			}
		}
		//记录本轮信息。
		Gamedata thisgame;
		thisgame.n = n, thisgame.m = m;
		thisgame.score = snack1.get_score();
		thisgame.tim = snack1.get_time();
		thisgame.speed = speed;
		best_score = max(best_score, thisgame.score);
		cout << "#case: " << Case << '\n'
			 << "score: " << thisgame.score << '\n'
			 << "time: " << thisgame.tim /1000.0 << "S" << endl;
		cout << "bestscore: " << best_score << "\n\n\n"
			 << endl;
		game.push_back(thisgame);
		cout.flush();
		printf("next round? (Y/N)\n");
		cout.flush();
		char ntg;
		cin >> ntg;
		if (ntg != 'Y')
			break;
	}
	printf("print your game record?(Y/N)\n");
	char prt;
	cin >> prt;
	if (prt == 'Y')
	{
		printf("please wating\n");
		wait(2);
		printf("finished\n");
		wait(2);
		printf("press Enter to exit\n");
		freopen("game_record.txt", "w", stdout);
		printf("Best score : %d\n", best_score);
		for (register int i = 0; i < game.size(); ++i)
		{
			printf("#Case: %d\n", i + 1);
			printf(" map size: %d %d;\n game speed %d;\n", game[i].n, game[i].m, game[i].speed);
			printf(" score: %d;\n using time %.3lf S;\n\n",game[i].score, (double)game[i].tim / 1000.0);
		}
		fclose(stdout);
	}
	else
	{
		printf("press Enter to exit\n");
	}
	getchar();
	getchar();
	return 0;
}
