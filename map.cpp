#include"����.h"

int Map[31][31] = {0};

//�ذ�------0
//ǽ--------1
//���------3
//����------4
//��--------5
//�챦��----6
//������----7
//�̱���----8
//��ͷ1-----9
//��ͷ2-----10
//��Կ��----11
//��Կ��----12
//��Կ��----13
//����------14
//��������--15
//��ɽ����--16
//���----17
//���سɴ�--18
//���֮��--19
//�����ĺ챦��----20
//������������----21
//�������̱���----22
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
