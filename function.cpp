#include "framework.h"
#include "����.h"

int cnt1 = 0;
void PrintMap1(HDC hdc, HINSTANCE hInst, HDC hMenDC)
{
	HBITMAP hBmpwall = nullptr; //λͼ
	HBITMAP hBmpchest1 = nullptr;
	HBITMAP hBmpchest2 = nullptr;
	HBITMAP hBmpchest3 = nullptr;
	HBITMAP hBmpkey1 = nullptr;
	HBITMAP hBmpkey2 = nullptr;
	HBITMAP hBmpkey3 = nullptr;
	HBITMAP hBmpjar = nullptr;
	HBITMAP hBmpfire = nullptr;

	HDC hdcBmpwall = CreateCompatibleDC(hdc);
	HDC hdcBmpchest1 = CreateCompatibleDC(hdc);
	HDC hdcBmpchest2 = CreateCompatibleDC(hdc);
	HDC hdcBmpchest3 = CreateCompatibleDC(hdc);
	HDC hdcBmpkey1 = CreateCompatibleDC(hdc);
	HDC hdcBmpkey2 = CreateCompatibleDC(hdc);
	HDC hdcBmpkey3 = CreateCompatibleDC(hdc);
	HDC hdcBmpfire = CreateCompatibleDC(hdc);

	hBmpchest1 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP6));
	hBmpchest2 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP7));
	hBmpkey1 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP10));
	hBmpkey2 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP11));
	if (2 <= level)
	{
		hBmpchest3 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP8));
		hBmpkey3 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP12));
	}
	hBmpwall = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
	hBmpfire = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP5));

	SelectObject(hdcBmpwall, hBmpwall);
	SelectObject(hdcBmpchest1, hBmpchest1);
	SelectObject(hdcBmpchest2, hBmpchest2);
	SelectObject(hdcBmpchest3, hBmpchest3);
	SelectObject(hdcBmpkey1, hBmpkey1);
	SelectObject(hdcBmpkey2, hBmpkey2);
	SelectObject(hdcBmpkey3, hBmpkey3);
	SelectObject(hdcBmpfire, hBmpfire);

	//������:���ڴ����DC�ϻ��Ƹ���ͼ��
	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			if (frog_cnt)
			{
				if (abs(j - Player.x) + abs(i - Player.y) < 6)
				{
					StretchBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 8 + 12 * 7, 3 + 12 * 2, 12, 12, SRCCOPY);//���ڴ�DC����ͼ
					if (Map[i][j] == 1)
						StretchBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 2 + 12, 1, 12, 12, SRCCOPY);//ǽ
					else if (Map[i][j] == 3)
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpfire, 20 + 12 * 19, 5 + 4 * 12, 12, 12, RGB(0, 0, 0));//���
					else if (Map[i][j] == 4)
					{
						//StretchBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 11 + 10 * 12, 1, 12, 12, SRCCOPY);//����
						if (1 == level && chest1 && chest2)
						{
							static bool cnt = true;
							if (cnt)
							{
								PlaySound(L"Resource\\vv.wav", NULL, SND_FILENAME | SND_ASYNC);
								cnt = false;
							}
							StretchBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 11 + 10 * 12, 1, 12, 12, SRCCOPY);//����
						}
						else if (2 <= level && chest1 && chest2 && chest3)
						{
							static bool cnt = true;
							if (cnt)
							{
								PlaySound(L"Resource\\vv.wav", NULL, SND_FILENAME | SND_ASYNC);
								cnt = false;
							}
							StretchBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 11 + 10 * 12, 1, 12, 12, SRCCOPY);//����
						}
					}
					//else if (Map[i][j] == 5)
					//	TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Monster.x) * 32, 300 + (i - Monster.y) * 32, 32, 32, hdcBmpwall, 18 + 17 * 12, 9 + 8 * 12, 12, 12, RGB(0, 0, 0));//��
					else if (Map[i][j] == 6)
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 38, hdcBmpchest1, 0, 0, 35, 35, RGB(255, 255, 255));//�챦��
					else if (Map[i][j] == 7)
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 38, hdcBmpchest2, 0, 0, 35, 35, RGB(255, 255, 255));//������
					else if (Map[i][j] == 8)
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 38, hdcBmpchest3, 0, 0, 35, 35, RGB(255, 255, 255));//�̱���
					else if (Map[i][j] == 9)
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 7 + 6 * 12, 19 + 18 * 12, 12, 12, RGB(0, 0, 0));//��ͷ1
					else if (Map[i][j] == 10)
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 9 + 8 * 12, 19 + 18 * 12, 12, 12, RGB(0, 0, 0));//��ͷ2
					else if (Map[i][j] == 20)
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 38, hdcBmpchest1, 3 * 35, 35, 35, 35, RGB(255, 255, 255));//�챦��
					else if (Map[i][j] == 21)
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 38, hdcBmpchest2, 3 * 35, 35, 35, 35, RGB(255, 255, 255));//������
					else if (Map[i][j] == 22)
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 38, hdcBmpchest3, 3 * 35, 35, 35, 35, RGB(255, 255, 255));//�̱���
					else if (Map[i][j] == 14 || Map[i][j] == 13 || Map[i][j] == 12 || Map[i][j] == 11 || Map[i][j] == 16 || Map[i][j] == 17 || Map[i][j] == 18 || Map[i][j] == 19)
					{
						if (Map[i][j] == 13 && !key3 && key3_cnt)
						{
							TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpkey3, 0, 0, 12, 12, RGB(0, 0, 0));
						}
						else if (Map[i][j] == 12 && !key2 && key2_cnt)
						{
							TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpkey2, 0, 0, 12, 12, RGB(0, 0, 0));
						}
						else if (Map[i][j] == 11 && !key1 && key1_cnt)
						{
							TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpkey1, 0, 0, 12, 12, RGB(0, 0, 0));
						}
						else {
							TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32 + 2, 300 + (i - Player.y) * 32 - 1, 32, 32, hdcBmpwall, 17 + 16 * 12, 17 + 16 * 12, 12, 12, RGB(0, 0, 0));//����
						}
					}
					else if (Map[i][j] == 15)
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32 + 2, 300 + (i - Player.y) * 32 - 1, 32, 32, hdcBmpwall, 6 + 5 * 12, 8 + 7 * 12, 12, 12, RGB(0, 0, 0));//��������
				}
			}
			else

			{
				StretchBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 8 + 12 * 7, 3 + 12 * 2, 12, 12, SRCCOPY);//���ڴ�DC����ͼ
				if (Map[i][j] == 1)
					StretchBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 2 + 12, 1, 12, 12, SRCCOPY);//ǽ
				else if (Map[i][j] == 3)
					TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpfire, 20 + 12 * 19, 5 + 4 * 12, 12, 12, RGB(0, 0, 0));//���
				else if (Map[i][j] == 4)
				{
					//StretchBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 11 + 10 * 12, 1, 12, 12, SRCCOPY);//����
					if (1 == level && chest1 && chest2)
					{
						static bool cnt = true;
						if (cnt)
						{
							PlaySound(L"Resource\\vv.wav", NULL, SND_FILENAME | SND_ASYNC);
							cnt = false;
						}
						StretchBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 11 + 10 * 12, 1, 12, 12, SRCCOPY);//����
					}
					else if (2 <= level && chest1 && chest2 && chest3)
					{
						static bool cnt = true;
						if (cnt)
						{
							PlaySound(L"Resource\\vv.wav", NULL, SND_FILENAME | SND_ASYNC);
							cnt = false;
						}
						StretchBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 11 + 10 * 12, 1, 12, 12, SRCCOPY);//����
					}
				}
				//else if (Map[i][j] == 5)
				//	TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Monster.x) * 32, 300 + (i - Monster.y) * 32, 32, 32, hdcBmpwall, 18 + 17 * 12, 9 + 8 * 12, 12, 12, RGB(0, 0, 0));//��
				else if (Map[i][j] == 6)
					TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 38, hdcBmpchest1, 0, 0, 35, 35, RGB(255, 255, 255));//�챦��
				else if (Map[i][j] == 7)
					TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 38, hdcBmpchest2, 0, 0, 35, 35, RGB(255, 255, 255));//������
				else if (Map[i][j] == 8)
					TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 38, hdcBmpchest3, 0, 0, 35, 35, RGB(255, 255, 255));//�̱���
				else if (Map[i][j] == 9)
					TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 7 + 6 * 12, 19 + 18 * 12, 12, 12, RGB(0, 0, 0));//��ͷ1
				else if (Map[i][j] == 10)
					TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 9 + 8 * 12, 19 + 18 * 12, 12, 12, RGB(0, 0, 0));//��ͷ2
				else if (Map[i][j] == 20)
					TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 38, hdcBmpchest1, 3 * 35, 35, 35, 35, RGB(255, 255, 255));//�챦��
				else if (Map[i][j] == 21)
					TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 38, hdcBmpchest2, 3 * 35, 35, 35, 35, RGB(255, 255, 255));//������
				else if (Map[i][j] == 22)
					TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 38, hdcBmpchest3, 3 * 35, 35, 35, 35, RGB(255, 255, 255));//�̱���
				else if (Map[i][j] == 14 || Map[i][j] == 13 || Map[i][j] == 12 || Map[i][j] == 11 || Map[i][j] == 16 || Map[i][j] == 17 || Map[i][j] == 18 || Map[i][j] == 19)
				{
					if (Map[i][j] == 13 && !key3 && key3_cnt)
					{
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpkey3, 0, 0, 12, 12, RGB(0, 0, 0));
					}
					else if (Map[i][j] == 12 && !key2 && key2_cnt)
					{
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpkey2, 0, 0, 12, 12, RGB(0, 0, 0));
					}
					else if (Map[i][j] == 11 && !key1 && key1_cnt)
					{
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpkey1, 0, 0, 12, 12, RGB(0, 0, 0));
					}
					else {
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32 + 2, 300 + (i - Player.y) * 32 - 1, 32, 32, hdcBmpwall, 17 + 16 * 12, 17 + 16 * 12, 12, 12, RGB(0, 0, 0));//����
					}
				}
				else if (Map[i][j] == 15)
					TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32 + 2, 300 + (i - Player.y) * 32 - 1, 32, 32, hdcBmpwall, 6 + 5 * 12, 8 + 7 * 12, 12, 12, RGB(0, 0, 0));//��������
			}
		}
	}

	//���Ҫ�����ͷ���Դ
	DeleteObject(hdcBmpwall);
	DeleteObject(hdcBmpchest1);
	DeleteObject(hdcBmpchest2);
	DeleteObject(hdcBmpchest3);
	DeleteObject(hdcBmpkey1);
	DeleteObject(hdcBmpkey2);
	DeleteObject(hdcBmpkey3);
	DeleteObject(hdcBmpfire);
	DeleteDC(hdcBmpwall);
	DeleteDC(hdcBmpchest1);
	DeleteDC(hdcBmpchest2);
	DeleteDC(hdcBmpchest3);
	DeleteDC(hdcBmpkey1);
	DeleteDC(hdcBmpkey2);
	DeleteDC(hdcBmpkey3);
	DeleteDC(hdcBmpfire);
}
void PlayerMove(HWND hWnd, WPARAM wParam)
{
	int x = Player.x, y = Player.y;
	if (wParam == ' ' && text_cnt1 <= 8)
	{
		text_cnt1++;
		return;
	}
	if (!show && text_cnt1 == 9 && wParam == ' ' && (text_cnt < 3 || text_cnt == 5 || text_cnt == 7 || text_cnt == 9 || text_cnt == 11 || text_cnt == 13 || text_cnt == 15 || text_cnt == 17 || text_cnt == 19 || text_cnt == 21 || text_cnt == 23 || text_cnt == 25||text_cnt==29||text_cnt==31))
	{
		text_cnt++;
		return;
	}
	if (text_cnt == 30)
		exit(0);
	if (!(text_cnt < 3 || text_cnt == 5 || text_cnt == 7 || text_cnt == 9 || text_cnt == 11 || text_cnt == 13 || text_cnt == 15 || text_cnt == 17 || text_cnt == 19 || text_cnt == 21 || text_cnt == 23 || text_cnt == 25 || text_cnt == 29))
	{
		if (wParam)
		{
			if (wParam == 'A')
			{
				Player.x -= 1;
				autoPathfinding();
			}
			else if (wParam == 'W')
			{
				Player.y -= 1;
				autoPathfinding();
			}
			else if (wParam == 'D')
			{
				Player.x += 1;
				autoPathfinding();
			}
			else if (wParam == 'S')
			{
				Player.y += 1;
				autoPathfinding();
			}
			else if (wParam == 'K')
			{
				if (frog_cnt)
					frog_cnt = false;
				else
					frog_cnt = true;
			}
			else if (wParam == 'H')
			{
				if (flag_h)
					flag_h = false;
				else
					flag_h = true;
			}
			else if (wParam == 'J'&&run>0)
			{
				while (1)
				{
					int i = (rand() % 29) + 1;
					int j = (rand() % 29) + 1;
					Player.x = i;
					Player.y = j;
					if (Map[Player.y][Player.x] == 0)
						break;
				}
				run--;
			}

		}
		if (Map[Player.y][Player.x] == 4)
		{
			if (1 == level && chest1 && chest2)
			{
				level++;
				next_cnt = false;
				PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
				SendMessage(hWnd, CREATEMAP, 0, 0);

			}
			else if (level && chest1 && chest2 && chest3)
			{
				level++;
				next_cnt = false;
				PlaySound(NULL, NULL, SND_FILENAME | SND_ASYNC);
				SendMessage(hWnd, CREATEMAP, 0, 0);
			}
		}
		PosJudge(y, x, wParam);
	}

}


void PrintPlayer(HDC hdc, HINSTANCE hInst, HDC hMenDC)
{
	HBITMAP hBmp = nullptr; //λͼ
	HDC hdcBmp = CreateCompatibleDC(hdc);
	hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP25));
	SelectObject(hdcBmp, hBmp);
	//StretchBlt(hMenDC, 180, 300, 32, 32, hdcBmp, 3*32, 0, SIZE, SIZE, SRCCOPY);//���ڴ�DC����ͼ
	TransparentBlt(hMenDC, 180 + 64-8, 280, 40, 52, hdcBmp, 0, 20, 140, 190, RGB(255, 255, 255));
	DeleteObject(hdcBmp);

}
void PrintEnermy(HDC hdc, HINSTANCE hInst, HDC hMenDC)
{
	HBITMAP hBmp = nullptr; //λͼ
	HDC hdcBmp = CreateCompatibleDC(hdc);
	hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
	SelectObject(hdcBmp, hBmp);
	//StretchBlt(hMenDC, 180, 300, 32, 32, hdcBmp, 3*32, 0, SIZE, SIZE, SRCCOPY);//���ڴ�DC����ͼ
	TransparentBlt(hMenDC, 180 + 32 + 32 + (Enermy.x - Player.x) * 32, 300 + (Enermy.y - Player.y) * 32, 32,32, hdcBmp, 8 * 12 + 9, 8*12+9, 12,12, RGB(0,0,0));
	DeleteObject(hdcBmp);
}

void PrintBackGround(HDC hdc, HINSTANCE hInst, HDC hMenDC)
{
	HBITMAP hBmp = nullptr; //λͼ
	HDC hdcBmp = CreateCompatibleDC(hdc);
	hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP2));
	SelectObject(hdcBmp, hBmp);
	StretchBlt(hMenDC, -250, 0, 3440, 1440, hdcBmp, 0, 0, 3440, 1440, SRCCOPY);//���ڴ�DC����ͼ
	DeleteDC(hdcBmp);
	DeleteObject(hBmp);
}

void PrintDataBG(HDC hdc, HINSTANCE hInst, HDC hMenDC)
{
	HBITMAP hBmp = nullptr; //λͼ
	HDC hdcBmp = CreateCompatibleDC(hdc);
	hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP3));
	SelectObject(hdcBmp, hBmp);
	StretchBlt(hMenDC, -5, -23, 354, 707, hdcBmp, 0, 0, 406, 572, SRCCOPY);//���ڴ�DC����ͼ
	DeleteDC(hdcBmp);
	DeleteObject(hBmp);
}

void PrintData(HDC hdc, HINSTANCE hInst, HDC hMenDC)
{
	LOGFONT lf = { 0 };
	lf.lfHeight = 25;
	HFONT hFont = CreateFontIndirect(&lf);
	HFONT hFontOld = (HFONT)SelectObject(hMenDC, hFont);
	SetBkMode(hMenDC, TRANSPARENT); //���ñ���Ϊ͸��,Ҳ������SetBkColor����
	SetTextColor(hMenDC, RGB(0, 0, 0)); //����ǰ����ɫ

	TextOutA(hMenDC, 40, 70, "��ǰ���з����� ", strlen("��ǰ���з�����"));
	//TextOutA(hMenDC, 40, 95, "��ǰ����Ԫ�أ� ", strlen("��ǰ����Ԫ�أ�"));
	TextOutA(hMenDC, 40, 120, "��ǰ���е��ߣ� ", strlen("��ǰ���е��ߣ�"));

	HBITMAP hBmpkey1 = nullptr; //λͼ
	HBITMAP hBmpkey2 = nullptr; //λͼ
	HBITMAP hBmpkey3 = nullptr; //λͼ
	HBITMAP hBmpdig = nullptr; //λͼ
	HBITMAP hBmpfly = nullptr; //λͼ
	HBITMAP hBmprun = nullptr; //λͼ
	HBITMAP hBmpstrong = nullptr; //λͼ


	HDC hdcBmpkey1 = CreateCompatibleDC(hdc);
	HDC hdcBmpkey2 = CreateCompatibleDC(hdc);
	HDC hdcBmpkey3 = CreateCompatibleDC(hdc);
	HDC hdcBmpdig = CreateCompatibleDC(hdc);
	HDC hdcBmpfly = CreateCompatibleDC(hdc);
	HDC hdcBmprun = CreateCompatibleDC(hdc);
	HDC hdcBmpstrong = CreateCompatibleDC(hdc);

	hBmpkey1 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP10));
	hBmpkey2 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP11));
	hBmpkey3 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP12));
	hBmpdig = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP21));
	hBmpfly = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP22));
	hBmprun = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP23));
	hBmpstrong = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP24));

	SelectObject(hdcBmpkey1, hBmpkey1);
	SelectObject(hdcBmpkey2, hBmpkey2);
	SelectObject(hdcBmpkey3, hBmpkey3);
	SelectObject(hdcBmpdig, hBmpdig);
	SelectObject(hdcBmpfly, hBmpfly);
	SelectObject(hdcBmprun, hBmprun);
	SelectObject(hdcBmpstrong, hBmpstrong);

	if (key1)
		TransparentBlt(hMenDC, 200, 60, 48, 48, hdcBmpkey1, 0, 0, 12, 12, RGB(0, 0, 0));//���ڴ�DC����ͼ
	else if (key2)
		TransparentBlt(hMenDC, 200, 60, 48, 48, hdcBmpkey2, 0, 0, 12, 12, RGB(0, 0, 0));//���ڴ�DC����ͼ
	else if (key3)
		TransparentBlt(hMenDC, 200, 60, 48, 48, hdcBmpkey3, 0, 0, 12, 12, RGB(0, 0, 0));//���ڴ�DC����ͼ
	else
		TextOutA(hMenDC, 200, 70, "��", strlen("��"));
	char Dig[10] = { 0 }, Fly[10] = { 0 }, Run[10] = { 0 }, Strong[10] = { 0 };

	TextOutA(hMenDC, 180, 120, "��ɽ����", strlen("��ɽ����"));
	TransparentBlt(hMenDC, 265, 120, 20, 20, hdcBmpdig, 0, 0, 32, 32, RGB(255, 255, 255));
	TextOutA(hMenDC, 180, 145, "���", strlen("���"));
	TransparentBlt(hMenDC, 265, 145, 20, 20, hdcBmpfly, 0, 0, 24, 24, RGB(255, 255, 255));
	TextOutA(hMenDC, 180, 170, "���سɴ�", strlen("���سɴ�"));
	TransparentBlt(hMenDC, 265, 170, 20, 20, hdcBmprun, 0, 0, 32, 32, RGB(255, 255, 255));
	TextOutA(hMenDC, 180, 195, "���֮��", strlen("���֮��"));
	TransparentBlt(hMenDC, 265, 195, 20, 20, hdcBmpstrong, 0, 0, 32, 32, RGB(255, 255, 255));
	Dig[0] = dig + '0';
	Fly[0] = fly + '0';
	Run[0] = run + '0';
	Strong[0] = strong + '0';
	TextOutA(hMenDC, 290, 120, "X", strlen("X"));
	TextOutA(hMenDC, 290, 145, "X", strlen("X"));
	TextOutA(hMenDC, 290, 170, "X", strlen("X"));
	TextOutA(hMenDC, 290, 195, "X", strlen("X"));

	TextOutA(hMenDC, 310, 120, Dig, strlen(Dig));

	TextOutA(hMenDC, 310, 145, Fly, strlen(Fly));

	TextOutA(hMenDC, 310, 170, Run, strlen(Run));
	TextOutA(hMenDC, 310, 195, Strong, strlen(Strong));
	TextOutA(hMenDC, 40, 250, "��ǰѡ����ͨ��", strlen("��ǰѡ����ͨ��"));
	if(flag_h)
	TextOutA(hMenDC, 180, 250, "��ɽ����", strlen("��ɽ����"));
	else
		TextOutA(hMenDC, 180, 250, "���", strlen("���"));

	DeleteDC(hdcBmpkey1);
	DeleteDC(hdcBmpkey2);
	DeleteDC(hdcBmpkey3);
	DeleteDC(hdcBmpdig);
	DeleteDC(hdcBmpfly);
	DeleteDC(hdcBmprun);
	DeleteDC(hdcBmpstrong);
	DeleteObject(hBmpkey1);
	DeleteObject(hBmpkey2);
	DeleteObject(hBmpkey3);
	DeleteObject(hBmpdig);
	DeleteObject(hBmpfly);
	DeleteObject(hBmprun);
	DeleteObject(hBmpstrong);
	SelectObject(hMenDC, hFontOld);
	DeleteObject(hFont); //ɾ������
}

void MassagePrompt1(HWND hWnd,HDC hdc, HINSTANCE hInst, HDC hMenDC)
{
	if (!show && text_cnt1 == 9)
	{
 		HBITMAP hBmp = nullptr; //λͼ
		HDC hdcBmp = CreateCompatibleDC(hdc);
		hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP13));
		SelectObject(hdcBmp, hBmp);
		//StretchBlt(hMenDC, 180, 300, 32, 32, hdcBmp, 3*32, 0, SIZE, SIZE, SRCCOPY);//���ڴ�DC����ͼ
		TransparentBlt(hMenDC, 60, 200, 400, 200, hdcBmp, 0, 0, 592, 357, RGB(255, 255, 255));
		DeleteDC(hdcBmp);
		DeleteObject(hBmp);
		LOGFONT lf = { 0 };
		lf.lfHeight = 30;
		HFONT hFont = CreateFontIndirect(&lf);
		HFONT hFontOld = (HFONT)SelectObject(hMenDC, hFont);
		SetBkMode(hMenDC, TRANSPARENT); //���ñ���Ϊ͸��,Ҳ������SetBkColor����
		SetTextColor(hMenDC, RGB(255, 255, 255)); //����ǰ����ɫ
		TextOutA(hMenDC, 236, 207, "��ʾ", strlen("��ʾ"));
		lf.lfHeight = 20;
		hFont = CreateFontIndirect(&lf);
		hFontOld = (HFONT)SelectObject(hMenDC, hFont);
		SetTextColor(hMenDC, RGB(0, 0, 0)); //����ǰ����ɫ
		if (text_cnt == 0)
		{
			TextOutA(hMenDC, 100, 270, "�ٿؿ�ͨ��WASD���ƶ���h���л���ɽ���ºͽ�", strlen("�ٿؿ�ͨ��WASD���ƶ���h���л���ɽ���ºͽ�"));
			TextOutA(hMenDC, 100, 295, "���Ƶ���ʹ��,j���������سɴ�,k��������", strlen("���Ƶ���ʹ��,j�����سɴ�,k��������"));
			TextOutA(hMenDC, 100, 320, ",l�����֮��,h���л���ɽ���ºͽ�Ƶ���ʹ�á�", strlen(",l�����֮��,h���л���ɽ���ºͽ�Ƶ���ʹ�á�"));
		}
		else if (text_cnt == 1)
		{
			TextOutA(hMenDC, 100, 270, "��ͼ�ϻ�������ɱ��䣬��ͬ���Եı�����Ҫ", strlen("��ͼ�ϻ�������ɱ��䣬��ͬ���Եı�����Ҫ"));
			TextOutA(hMenDC, 100, 295, "��Ӧ���Եķ�����������", strlen("��Ӧ���Ե�Կ����������"));
			TextOutA(hMenDC, 100, 320, "����ͼ��ȫ�����䶼�����󣬷��ɴ򿪵ص���", strlen("����ͼ��ȫ�����䶼�����󣬷��ɴ򿪵ص���"));
		}
		else if (text_cnt == 2)
		{
			TextOutA(hMenDC, 100, 270, "�еı���ᱻǽ�ڰ�Χ����ʱ�������������", strlen("�еı���ᱻǽ�ڰ�Χ����ʱ�������������"));
			TextOutA(hMenDC, 100, 295, "�ĵ��ߣ�������߲���������ͨ�����ƹ��ӻ�á�", strlen("�ĵ��ߣ�������߲���������ͨ�����ƹ��ӻ�á�"));
		}
		else if (text_cnt == 5)
		{ 
			TextOutA(hMenDC, 100, 270, "������", strlen("������"));
			SetTextColor(hMenDC, RGB(255, 0, 0)); //����ǰ����ɫ
			TextOutA(hMenDC, 170, 270, "��Ԫ�ط���", strlen("��Ԫ�ط���"));
		}
		else if (text_cnt == 7)
		{
			TextOutA(hMenDC, 100, 270, "������", strlen("������"));
			SetTextColor(hMenDC, RGB(0, 0, 255)); //����ǰ����ɫ
			TextOutA(hMenDC, 170, 270, "ˮԪ�ط���", strlen("ˮԪ�ط���"));
		}
		else if (text_cnt == 9)
		{
			TextOutA(hMenDC, 100, 270, "������", strlen("������"));
			SetTextColor(hMenDC, RGB(0, 255, 0)); //����ǰ����ɫ
			TextOutA(hMenDC, 170, 270, "ľԪ�ط���", strlen("ľԪ�ط���"));
		}
		else if (text_cnt == 19)
		{
			TextOutA(hMenDC, 100, 270, "������", strlen("������"));
			TextOutA(hMenDC, 170, 270, "���سɴ�", strlen("���سɴ�"));

		}
		else if (text_cnt == 21)
		{
			TextOutA(hMenDC, 100, 270, "������", strlen("������"));
			TextOutA(hMenDC, 170, 270, "��ɽ����", strlen("��ɽ����"));

		}
		else if (text_cnt == 23)
		{
			TextOutA(hMenDC, 100, 270, "������", strlen("������"));
			TextOutA(hMenDC, 170, 270, "���", strlen("���"));

		}
		else if (text_cnt == 25)
		{
			TextOutA(hMenDC, 100, 270, "������", strlen("������"));
			TextOutA(hMenDC, 170, 270, "���֮��", strlen("���֮��"));

		}
		else if (text_cnt == 11)
		{
			TextOutA(hMenDC, 100, 270, "�����", strlen("�����"));
			SetTextColor(hMenDC, RGB(255, 0, 0)); //����ǰ����ɫ
			TextOutA(hMenDC, 170, 270, "��Ԫ�ر���", strlen("��Ԫ�ر���"));
		}
		else if (text_cnt == 13)
		{
			TextOutA(hMenDC, 100, 270, "�����", strlen("�����"));
			SetTextColor(hMenDC, RGB(0, 0, 255)); //����ǰ����ɫ
			TextOutA(hMenDC, 170, 270, "ˮԪ�ر���", strlen("ˮԪ�ر���"));
		}
		else if (text_cnt == 15)
		{
			TextOutA(hMenDC, 100, 270, "�����", strlen("�����"));
			SetTextColor(hMenDC, RGB(0, 255, 0)); //����ǰ����ɫ
			TextOutA(hMenDC, 170, 270, "ľԪ�ر���", strlen("ľԪ�ر���"));
		}
		else if (text_cnt == 17)
		{
			TextOutA(hMenDC, 100, 270, "�ص��Ѿ����ˡ�", strlen("�ص��Ѿ����ˡ�"));
		}
		else if (text_cnt == 27)
		{
			TextOutA(hMenDC, 100, 270, "���ѽ�����һ�ء�", strlen("���ѽ�����һ�ء�"));
		}
		else if (text_cnt == 29)
		{
			TextOutA(hMenDC, 100, 270, "��Ϸ������", strlen("��Ϸ������"));
		}
		else if (text_cnt == 31)
		{
			TextOutA(hMenDC, 100, 270, "����!�㱻ץס��,������������",strlen("����!�㱻ץס�ˡ�������������"));
		}
		SetTextColor(hMenDC, RGB(0, 0, 0)); //����ǰ����ɫ
		TextOutA(hMenDC, 300, 340, "[>���ո������<]", strlen("[>���ո������<]"));
		SelectObject(hMenDC, hFontOld);
		DeleteObject(hFont); //ɾ������

	}
}

void Show(HDC hdc, HINSTANCE hInst, HDC hMenDC)
{
	HBITMAP hBmpshow = nullptr; //λͼ
	HBITMAP hBmp1 = nullptr; //λͼ
	HBITMAP hBmp2 = nullptr; //λͼ
	HBITMAP hBmp3 = nullptr; //λͼ

	HDC hdcBmpshow = CreateCompatibleDC(hdc);
	HDC hdcBmp1 = CreateCompatibleDC(hdc);
	HDC hdcBmp2 = CreateCompatibleDC(hdc);
	HDC hdcBmp3 = CreateCompatibleDC(hdc);

	hBmpshow = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP17));
	hBmp1 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP18));
	hBmp2 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP19));
	hBmp3 = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP20));

	SelectObject(hdcBmpshow, hBmpshow);
	SelectObject(hdcBmp1, hBmp1);
	SelectObject(hdcBmp2, hBmp2);
	SelectObject(hdcBmp3, hBmp3);

	TransparentBlt(hMenDC, 0, 475, 1200, 200, hdcBmpshow, 140, 0, 500, 182, RGB(255, 255, 255));

	DeleteObject(hdcBmpshow);
	DeleteObject(hBmpshow);


	LOGFONT lf = { 0 };
	lf.lfHeight = 17;//�����С
	HFONT hFont = CreateFontIndirect(&lf);
	HFONT hFontOld = (HFONT)SelectObject(hMenDC, hFont);
	SetBkMode(hMenDC, TRANSPARENT); 
	SetTextColor(hMenDC, RGB(0, 0, 0));
	if (text_cnt1 == 0)
	{
		lf.lfHeight = 15;
		hFont = CreateFontIndirect(&lf);
		hFontOld = (HFONT)SelectObject(hMenDC, hFont);
		TransparentBlt(hMenDC, -35, 460, 150, 150, hdcBmp1, 0, 0, 168, 223, RGB(255, 255, 255));//��ɮ
		TransparentBlt(hMenDC, 410, 470, 90, 140, hdcBmp3, 0, 0, 65, 85, RGB(255, 255, 255));//������֮��
		TextOutA(hMenDC, 110, 510, "(��ɮ��������ץ�ߣ������ʧȥ����֮������Ǳ��������", strlen("��ɮ��������ץ�ߣ������ʧȥ����֮������Ǳ�������� "));
		TextOutA(hMenDC, 77, 535, "��Ѩ�����ɮ����Ҫ�������֮�������������ɡ������ɰ�����", strlen("��Ѩ�����ɮ����Ҫ�������֮�������������ɡ������ɰ�����"));
		TextOutA(hMenDC, 77, 560, "֮����ӡ��������«�����䣩�С�Ѱ�Ҷ�Ӧ�ķ�����Կ�ף���", strlen("֮����ӡ��������«�����䣩�С�Ѱ�Ҷ�Ӧ�ķ�����Կ�ף���"));
		TextOutA(hMenDC, 77, 585, "��«�����䣩�����ʧȥ������֮������ܻ�¹��������)", strlen("��«�����䣩�����ʧȥ������֮������ܻ�¹��������)"));
	}
	else if (text_cnt1 == 1)
	{
 		TransparentBlt(hMenDC, -30, 460, 150, 150, hdcBmp1, 0, 0, 168, 223, RGB(255, 255, 255));//��ɮ
		TransparentBlt(hMenDC, 385, 450, 150, 150, hdcBmp2, 0, 0, 211, 222, RGB(0, 0, 0));//���
		TextOutA(hMenDC, 105, 515, "����պ���ɮ�ڼ���д���裬��Ȼһ������", strlen("����պ���ɮ�ڼ���д���裬��Ȼһ����"));
		TextOutA(hMenDC, 105, 540, "�������ۼ�����ɮ���Ƿ���ߡ�", strlen("�������ۼ�����ɮ���Ƿ���ߡ�"));
	}
	else if (text_cnt1 == 2)
	{
		TransparentBlt(hMenDC, -30, 460, 150, 150, hdcBmp1, 0, 0, 168, 223, RGB(255, 255, 255));//��ɮ
		TransparentBlt(hMenDC, 385, 450, 150, 150, hdcBmp2, 0, 0, 211, 222, RGB(0, 0, 0));//���
		TextOutA(hMenDC, 105, 515, "��ɮ������ţ�����գ����ҡ���", strlen("��ɮ������ţ�����գ����ҡ���"));
	}
	else if (text_cnt1 == 3)
	{
		TransparentBlt(hMenDC, -10, 450, 150, 150, hdcBmp2, 0, 0, 211, 222, RGB(0, 0, 0));//���
		TransparentBlt(hMenDC, 410, 470, 90, 140, hdcBmp3, 0, 0, 65, 85, RGB(255, 255, 255));//������֮��
		TextOutA(hMenDC, 80, 515, "����գ��ż��Ĺ�����ѭ��һ�ţ�ԭ�����ǻ�", strlen("����գ��ż��Ĺ�����ѭ��һ�ţ�ԭ�����ǻ�"));
		TextOutA(hMenDC, 80, 540, "¹��������),�󺰣����������ߣ��漴׷��ȥ��", strlen("¹��������),�󺰣����������ߣ��漴׷��ȥ��"));
	}
	else if (text_cnt1 == 4)
	{
		TransparentBlt(hMenDC, 0, 470, 90, 140, hdcBmp3, 0, 0, 65, 85, RGB(255, 255, 255));//������֮��
		TextOutA(hMenDC, 90, 515, "�����ɣ��׳������񣩴�Ц������գ��������֮���Ѿ�", strlen("�����ɣ��׳������񣩴�Ц������գ��������֮���Լ�"));
		TextOutA(hMenDC, 90, 540, "��������������ס�ˡ����㻹��ô������ʦ����������!", strlen("��������������ס�ˡ����㻹��ô������ʦ����������!"));

	}
	else if (text_cnt1 == 5)
	{
		TransparentBlt(hMenDC, 0, 470, 90, 140, hdcBmp3, 0, 0, 65, 85, RGB(255, 255, 255));//������֮��
		TransparentBlt(hMenDC, 385, 450, 150, 150, hdcBmp2, 0, 0, 211, 222, RGB(0, 0, 0));//���
		TextOutA(hMenDC, 90, 515, "�����ɣ��𾪣����������ʧȥ������֮��", strlen("�����ɣ��𾪣����������ʧȥ������֮��"));
		TextOutA(hMenDC, 90, 540, "��Ȼ��׷��������������ֻ��������ֲ�ȱ", strlen("��Ȼ��׷��������������ֻ��������ֲ�ȱ"));
		TextOutA(hMenDC, 90, 565, "����֮�����㣬һ��սʤ�����������ֵܵ�", strlen("����֮�����㣬һ��սʤ�����������ֵܵ�"));
		TextOutA(hMenDC, 90, 590, "������", strlen("������"));
	}
	else if (text_cnt1 == 6)
	{
		TransparentBlt(hMenDC, -10, 450, 150, 150, hdcBmp2, 0, 0, 211, 222, RGB(0, 0, 0));//���
		TransparentBlt(hMenDC, 410, 470, 90, 140, hdcBmp3, 0, 0, 65, 85, RGB(255, 255, 255));//������֮��
		TextOutA(hMenDC, 90, 515, "����գ���м����������ֻ����Ҳ�����ƴ�", strlen("����գ���м����������ֻ����Ҳ�����ƴ�"));
		TextOutA(hMenDC, 90, 540, "�ɣ��������������ô��ѵ���ǣ�", strlen("�ɣ��������������ô��ѵ���ǣ�"));
	}
	else if (text_cnt1 == 7)
	{
		TransparentBlt(hMenDC, 0, 470, 90, 140, hdcBmp3, 0, 0, 65, 85, RGB(255, 255, 255));//������֮��
		TextOutA(hMenDC, 90, 515, "�����ɣ�����ſ�£�����������ʥ��������ɮ���ں���", strlen("�����ɣ�����ſ�£�����������ʥ��������ɮ���ں���"));
		TextOutA(hMenDC, 90, 540, "�ĵ����", strlen("�ĵ����"));
	}
	else if (text_cnt1 == 8)
	{
		TransparentBlt(hMenDC, -30, 460, 150, 150, hdcBmp1, 0, 0, 168, 223, RGB(255, 255, 255));//��ɮ
		TransparentBlt(hMenDC, 385, 450, 150, 150, hdcBmp2, 0, 0, 211, 222, RGB(0, 0, 0));//���
		TextOutA(hMenDC, 105, 515, "����վȻ�����ɮ�����˸߸����˵Ļ�ȥ", strlen("����վȻ�����ɮ�����˸߸����˵Ļ�ȥ"));
		TextOutA(hMenDC, 105, 540, "д�����ˡ�", strlen("д�����ˡ�"));
		show = false;
	}

	TextOutA(hMenDC, 340, 620, "[>���ո������<]", strlen("[>���ո������<]"));
	DeleteObject(hdcBmp1);
	DeleteObject(hdcBmp2);
	DeleteObject(hdcBmp3);

	DeleteObject(hBmp1);
	DeleteObject(hBmp2);
	DeleteObject(hBmp3);
}


void Init(HDC hdc, HINSTANCE hInst, HDC hMenDC)
{
	PlaySound(L"Resource\\��ʼ����.wav", NULL, SND_FILENAME | SND_ASYNC);
	HBITMAP hBmp_bk = nullptr; //λͼ
	HBITMAP hBmp_start = nullptr; //λͼ
	HBITMAP hBmp_end = nullptr; //λͼ

	HDC hdcBmp_bk = CreateCompatibleDC(hdc);
	HDC hdcBmp_start = CreateCompatibleDC(hdc);
	HDC hdcBmp_end = CreateCompatibleDC(hdc);

	hBmp_bk = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP14));
	hBmp_start = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP15));
	hBmp_end = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP16));

	SelectObject(hdcBmp_bk, hBmp_bk);
	SelectObject(hdcBmp_start, hBmp_start);
	SelectObject(hdcBmp_end, hBmp_end);

	TransparentBlt(hMenDC, -200, -100, 1398, 786, hdcBmp_bk, 0, 0, 1398, 786, SRCCOPY);//���ڴ�DC����ͼ
	TransparentBlt(hMenDC, 120, 170, 150, 60, hdcBmp_start, 0, 0, 122, 38, RGB(255, 255, 255));//���ڴ�DC����ͼ
	TransparentBlt(hMenDC, 120, 300, 150, 60, hdcBmp_end, 0, 0, 122, 38, RGB(255, 255, 255));//���ڴ�DC����ͼ

	DeleteObject(hdcBmp_bk);
	DeleteObject(hdcBmp_start);
	DeleteObject(hdcBmp_end);
}


void PosJudge(int y,int x, WPARAM wParam)
{
	if (Map[Player.y][Player.x] == 6 && key1 && (Map[Player.y][Player.x] = 20))//�򿪺�����
	{
		chest1 = true;
		key_cnt = false;
		key1 = false;
		text_cnt = 11;
		Map[Player.y][Player.x] == 20;
		PlaySound(L"Resource\\����.wav", NULL, SND_FILENAME | SND_ASYNC);
	}
	else if (Map[Player.y][Player.x] == 7 && key2 && (Map[Player.y][Player.x] = 21))//��������
	{
		key_cnt = false;
		key2 = false;
		chest2 = true;
		text_cnt = 13;
		PlaySound(L"Resource\\����.wav", NULL, SND_FILENAME | SND_ASYNC);
	}
	else if (Map[Player.y][Player.x] == 8 && key3 && (Map[Player.y][Player.x] = 22))//��������
	{
		key_cnt = false;
		key3 = false;
		chest3 = true;
		text_cnt = 15;
		Map[Player.y][Player.x] == 22;
		PlaySound(L"Resource\\����.wav", NULL, SND_FILENAME | SND_ASYNC);

	}
	else if (Map[Player.y][Player.x] == 11 && (key1_cnt = true) && !key_cnt)//���к�Կ��
	{
		PlaySound(L"Resource\\����.wav", NULL, SND_FILENAME | SND_ASYNC);
		Map[Player.y][Player.x] = 15;
		key1 = true;
		key_cnt = true;
		text_cnt = 5;
	}
	else if (Map[Player.y][Player.x] == 12 && (key2_cnt = true) && !key_cnt)//������Կ��
	{
		PlaySound(L"Resource\\����.wav", NULL, SND_FILENAME | SND_ASYNC);
		Map[Player.y][Player.x] = 15;
		key2 = true;
		key_cnt = true;
		text_cnt = 7;
	}
	else if (Map[Player.y][Player.x] == 13 && (key3_cnt = true) && !key_cnt)//������Կ��
	{
		PlaySound(L"Resource\\����.wav", NULL, SND_FILENAME | SND_ASYNC);
		Map[Player.y][Player.x] = 15;
		key3 = true;
		key_cnt = true;
		text_cnt = 9;
	}
	else if (Map[Player.y][Player.x] == 16)
	{
		PlaySound(L"Resource\\����.wav", NULL, SND_FILENAME | SND_ASYNC);
		Map[Player.y][Player.x] = 15;
		dig++;
		text_cnt = 21;
	}
	else if (Map[Player.y][Player.x] == 17)
	{
		PlaySound(L"Resource\\����.wav", NULL, SND_FILENAME | SND_ASYNC);
		Map[Player.y][Player.x] = 15;
		fly++;
		text_cnt = 23;
	}
	else if (Map[Player.y][Player.x] == 18)
	{
		PlaySound(L"Resource\\����.wav", NULL, SND_FILENAME | SND_ASYNC);
		Map[Player.y][Player.x] = 15;
		text_cnt = 19;
		run++;
	}
	else if (Map[Player.y][Player.x] == 19)
	{
		PlaySound(L"Resource\\����.wav", NULL, SND_FILENAME | SND_ASYNC);
		Map[Player.y][Player.x] = 15;
		strong++;
		text_cnt = 25;
	}
	else if (Map[Player.y][Player.x] == 1 && dig > 0 && flag_h)//��ɽ����
	{
		Map[Player.y][Player.x] = 0;
		dig--;
	}
	else if (Map[Player.y][Player.x] == 1 && fly > 0 && !flag_h)//���
	{
		while (Map[Player.y][Player.x] == 1)
		{
			if (wParam == 'W')
				Player.y--;
			else if (wParam == 'A')
				Player.x--;
			else if (wParam == 'S')
				Player.y++;
			else if (wParam == 'D')
				Player.x++;
		}
		fly--;
	}
	else if (Map[Player.y][Player.x] == 1 && dig > 0)
	{
		Map[Player.y][Player.x] = 0;
		dig--;
	}
	else if (1 == level && chest1 && chest2 && !next_cnt)
	{
		next_cnt = true;
		text_cnt = 17;
	}
	else if (2 == level && chest1 && chest2 && chest3 && !next_cnt)
	{
		next_cnt = true;
		text_cnt = 17;
	}else if (Enermy.x==Player.x&&Player.y==Enermy.y && strong > 0)
	{
		while (1)
		{
			int i = (rand() % 29) + 1;
			int j = (rand() % 29) + 1;
			Enermy.x = i;
			Enermy.y = j;
			if (Map[Enermy.y][Enermy.x] == 0)
				break;
		}
		strong--;
	}
	if (Map[Player.y][Player.x] == 14 || Map[Player.y][Player.x] == 16 || Map[Player.y][Player.x] == 17 || Map[Player.y][Player.x] == 18 || Map[Player.y][Player.x] == 19)
	{
		PlaySound(L"Resource\\����.wav", NULL, SND_FILENAME | SND_ASYNC);
		Map[Player.y][Player.x] = 15;
	}
	if (Map[Player.y][Player.x] != 0 && Map[Player.y][Player.x] != 4
		&& Map[Player.y][Player.x] != 9 && Map[Player.y][Player.x] != 10
		&& Map[Player.y][Player.x] != 11 && Map[Player.y][Player.x] != 12
		&& Map[Player.y][Player.x] != 13 && Map[Player.y][Player.x] != 14
		&& Map[Player.y][Player.x] != 15 && Map[Player.y][Player.x] != 16
		&& Map[Player.y][Player.x] != 17 && Map[Player.y][Player.x] != 18
		&& Map[Player.y][Player.x] != 19)
	{
		Player.y = y;
		Player.x = x;
	}
	if (Player.y == Enermy.y && Player.x == Enermy.x)
	{
		text_cnt = 31;
	}
}

void game(HWND hWnd,HDC hdc, HINSTANCE hInst)
{
	HDC hMap = CreateCompatibleDC(hdc);
	HDC hData = CreateCompatibleDC(hdc);
	HDC hInit = CreateCompatibleDC(hdc);

	HBITMAP hMapBmp = CreateCompatibleBitmap(hdc, 500, 720);
	HBITMAP hDataBmp = CreateCompatibleBitmap(hdc, 360, 720);
	HBITMAP hInitBmp = CreateCompatibleBitmap(hdc, 860, 720);

	SelectObject(hMap, hMapBmp);
	SelectObject(hData, hDataBmp);
	SelectObject(hInit, hInitBmp);

	if (start)
	{
		PrintBackGround(hdc, hInst, hMap);
		PrintDataBG(hdc, hInst, hData);
		PrintMap1(hdc, hInst, hMap);
		PrintPlayer(hdc, hInst, hMap);
		PrintEnermy(hdc, hInst, hMap);
		PrintData(hdc, hInst, hData);

		if (show)
		{
			Show(hdc, hInst, hMap);
		}

		if (text_cnt < 3 || text_cnt == 5 || text_cnt == 7 || text_cnt == 9 || text_cnt == 11 || text_cnt == 13 || text_cnt == 15 || text_cnt == 17 || text_cnt == 19 || text_cnt == 21 || text_cnt == 23 || text_cnt == 25 || text_cnt == 29||text_cnt==31)
		{
			MassagePrompt1(hWnd,hdc, hInst, hMap);
		}
		if (text_cnt == 31)
		{
			SendMessage(hWnd, CREATEMAP, 0, 0);
		}
		BitBlt(hdc, 0, 0, 500, 720, hMap, 0, 0, SRCCOPY);
		BitBlt(hdc, 500, 0, 360, 720, hData, 0, 0, SRCCOPY);
	}
	else if (!start)
	{
		Init(hdc, hInst, hInit);
		BitBlt(hdc, 0, 0, 1080, 720, hInit, 0, 0, SRCCOPY);
	}
	DeleteDC(hMap);
	DeleteDC(hData);
	DeleteObject(hDataBmp);
	DeleteObject(hMapBmp);
}