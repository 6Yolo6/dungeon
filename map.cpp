#include"地牢.h"

int Map[31][31] = {0};

//地板------0
//墙--------1
//火把------3
//出口------4
//怪--------5
//红宝箱----6
//蓝宝箱----7
//绿宝箱----8
//骨头1-----9
//骨头2-----10
//红钥匙----11
//蓝钥匙----12
//绿钥匙----13
//罐子------14
//罐子破碎--15
//担山赶月--16
//筋斗云----17
//缩地成寸--18
//金刚之躯--19
//开过的红宝箱----20
//开过的蓝宝箱----21
//开过的绿宝箱----22
void CreateMap()
{
	srand((unsigned)time(NULL));
	memset(Map, 0, sizeof(Map));
	for (int i = 0; i < 31; i++)
	{
		Map[i][0] = 1, Map[i][30] = 1;
	}

	for (int j = 0; j < 31; j++)
	{
		Map[0][j] = 1, Map[30][j] = 1;
	}
	int wall = WALL;
	int chest = CHEST;
	int fire = FIRE;
	int jar = JAR;
	int next = NEXT;
	int bone = BONE;
	int key = KEY;
	int monster = MONSTER;
	int prop = PROP;
	int i, j;
	if (2 <= level)
	{
		chest = 3;
		key = 3;
	}
	while (wall)
	{
		i = (rand() % 30) + 1;
		j = (rand() % 30) + 1;
		if (0 == Map[i][j])
		{
			Map[i][j] = 1;
			wall--;
		}
	}
	while (prop)
	{
		i = (rand() % 29) + 1;
		j = (rand() % 29) + 1;
		if (1 == Map[i][j])
		{
			if (prop == 1)
			{
				Map[i][j] = 16;
				prop--;
			}
			else if (prop == 2)
			{
				Map[i][j] = 17;
				prop--;
			}
			else if (prop == 3)
			{
				Map[i][j] = 18;
				prop--;
			}
			else if (prop == 4)
			{
				Map[i][j] = 19;
				prop--;
			}
			else if (prop == 5)
			{
				Map[i][j] = 17;
				prop--;
			}
			else if (prop == 6)
			{
				Map[i][j] = 16;
				prop--;
			}
			else if (prop == 7)
			{
				Map[i][j] = 17;
				prop--;
			}
			else if (prop == 8)
			{
				Map[i][j] = 18;
				prop--;
			}
		}
	}

	while (chest)
	{
		i = (rand() % 29) + 1;
		j = (rand() % 29) + 1;
		if (1 == Map[i][j])
		{
			if (chest == 1)
			{
				Map[i][j] = 7;
				chest--;
			}
			else if (chest == 2)
			{
				Map[i][j] = 6;
				chest--;
			}
			else if (chest == 3)
			{
				Map[i][j] = 8;
				chest--;
			}
		}
	}
	while (jar)
	{
		i = (rand() % 29) + 1;
		j = (rand() % 29) + 1;
		if (1 == Map[i][j])
		{
			Map[i][j] = 14;
			jar--;
		}
	}
	while (bone)
	{
		i = (rand() % 29) + 1;
		j = (rand() % 29) + 1;
		if (0 == Map[i][j])
		{
			if (bone > 8)
			{
				Map[i][j] = 9;
				bone--;
			}
			else
			{
				Map[i][j] = 10;
				bone--;
			}
		}
	}
	while (key)
	{
		i = (rand() % 29) + 1;
		j = (rand() % 29) + 1;
		if (1 == Map[i][j])
		{
			if (key == 1)
			{
				Map[i][j] = 11;
				key--;
			}
			else if (key == 2)
			{
				Map[i][j] = 12;
				key--;
			}
			else if (key == 3)
			{
				Map[i][j] = 13;
				key--;
			}
		}
	}
	while (fire)
	{
		i = (rand() % 29) + 1;
		j = (rand() % 29) + 1;
		if (1 == Map[i][j])
		{
			Map[i][j] = 3;
			fire--;
		}
	}
	while (next)
	{
		i = (rand() % 29) + 1;
		j = (rand() % 29) + 1;
		if (0 == Map[i][j])
		{
			Map[i][j] = 4;
			next--;
		}
	}

	while (1)
	{
		i = (rand() % 29) + 1;
		j = (rand() % 29) + 1;
		if (0 == Map[i][j])
		{
			Player.x = j;
			Player.y = i;
			break;
		}
	}
	while (1)
	{
		i = (rand() % 29) + 1;
		j = (rand() % 29) + 1;
		if (0 == Map[i][j])
		{
			Enermy.x = j;
			Enermy.y = i;
			break;
		}
	}
}
