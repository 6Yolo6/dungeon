#include "framework.h"
#include "地牢.h"

int cnt1 = 0;
void PrintMap1(HDC hdc, HINSTANCE hInst, HDC hMenDC)
{
	HBITMAP hBmpwall = nullptr; //位图
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

	//第三步:在内存兼容DC上绘制各种图形
	for (int i = 0; i < 31; i++)
	{
		for (int j = 0; j < 31; j++)
		{
			if (frog_cnt)
			{
				if (abs(j - Player.x) + abs(i - Player.y) < 6)
				{
					StretchBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 8 + 12 * 7, 3 + 12 * 2, 12, 12, SRCCOPY);//在内存DC上贴图
					if (Map[i][j] == 1)
						StretchBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 2 + 12, 1, 12, 12, SRCCOPY);//墙
					else if (Map[i][j] == 3)
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpfire, 20 + 12 * 19, 5 + 4 * 12, 12, 12, RGB(0, 0, 0));//火把
					else if (Map[i][j] == 4)
					{
						//StretchBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 11 + 10 * 12, 1, 12, 12, SRCCOPY);//出口
						if (1 == level && chest1 && chest2)
						{
							static bool cnt = true;
							if (cnt)
							{
								PlaySound(L"Resource\\vv.wav", NULL, SND_FILENAME | SND_ASYNC);
								cnt = false;
							}
							StretchBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 11 + 10 * 12, 1, 12, 12, SRCCOPY);//出口
						}
						else if (2 <= level && chest1 && chest2 && chest3)
						{
							static bool cnt = true;
							if (cnt)
							{
								PlaySound(L"Resource\\vv.wav", NULL, SND_FILENAME | SND_ASYNC);
								cnt = false;
							}
							StretchBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 11 + 10 * 12, 1, 12, 12, SRCCOPY);//出口
						}
					}
					//else if (Map[i][j] == 5)
					//	TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Monster.x) * 32, 300 + (i - Monster.y) * 32, 32, 32, hdcBmpwall, 18 + 17 * 12, 9 + 8 * 12, 12, 12, RGB(0, 0, 0));//怪
					else if (Map[i][j] == 6)
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 38, hdcBmpchest1, 0, 0, 35, 35, RGB(255, 255, 255));//红宝箱
					else if (Map[i][j] == 7)
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 38, hdcBmpchest2, 0, 0, 35, 35, RGB(255, 255, 255));//蓝宝箱
					else if (Map[i][j] == 8)
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 38, hdcBmpchest3, 0, 0, 35, 35, RGB(255, 255, 255));//绿宝箱
					else if (Map[i][j] == 9)
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 7 + 6 * 12, 19 + 18 * 12, 12, 12, RGB(0, 0, 0));//骨头1
					else if (Map[i][j] == 10)
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 9 + 8 * 12, 19 + 18 * 12, 12, 12, RGB(0, 0, 0));//骨头2
					else if (Map[i][j] == 20)
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 38, hdcBmpchest1, 3 * 35, 35, 35, 35, RGB(255, 255, 255));//红宝箱
					else if (Map[i][j] == 21)
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 38, hdcBmpchest2, 3 * 35, 35, 35, 35, RGB(255, 255, 255));//蓝宝箱
					else if (Map[i][j] == 22)
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 38, hdcBmpchest3, 3 * 35, 35, 35, 35, RGB(255, 255, 255));//绿宝箱
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
							TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32 + 2, 300 + (i - Player.y) * 32 - 1, 32, 32, hdcBmpwall, 17 + 16 * 12, 17 + 16 * 12, 12, 12, RGB(0, 0, 0));//罐子
						}
					}
					else if (Map[i][j] == 15)
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32 + 2, 300 + (i - Player.y) * 32 - 1, 32, 32, hdcBmpwall, 6 + 5 * 12, 8 + 7 * 12, 12, 12, RGB(0, 0, 0));//罐子破碎
				}
			}
			else

			{
				StretchBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 8 + 12 * 7, 3 + 12 * 2, 12, 12, SRCCOPY);//在内存DC上贴图
				if (Map[i][j] == 1)
					StretchBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 2 + 12, 1, 12, 12, SRCCOPY);//墙
				else if (Map[i][j] == 3)
					TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpfire, 20 + 12 * 19, 5 + 4 * 12, 12, 12, RGB(0, 0, 0));//火把
				else if (Map[i][j] == 4)
				{
					//StretchBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 11 + 10 * 12, 1, 12, 12, SRCCOPY);//出口
					if (1 == level && chest1 && chest2)
					{
						static bool cnt = true;
						if (cnt)
						{
							PlaySound(L"Resource\\vv.wav", NULL, SND_FILENAME | SND_ASYNC);
							cnt = false;
						}
						StretchBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 11 + 10 * 12, 1, 12, 12, SRCCOPY);//出口
					}
					else if (2 <= level && chest1 && chest2 && chest3)
					{
						static bool cnt = true;
						if (cnt)
						{
							PlaySound(L"Resource\\vv.wav", NULL, SND_FILENAME | SND_ASYNC);
							cnt = false;
						}
						StretchBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 11 + 10 * 12, 1, 12, 12, SRCCOPY);//出口
					}
				}
				//else if (Map[i][j] == 5)
				//	TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Monster.x) * 32, 300 + (i - Monster.y) * 32, 32, 32, hdcBmpwall, 18 + 17 * 12, 9 + 8 * 12, 12, 12, RGB(0, 0, 0));//怪
				else if (Map[i][j] == 6)
					TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 38, hdcBmpchest1, 0, 0, 35, 35, RGB(255, 255, 255));//红宝箱
				else if (Map[i][j] == 7)
					TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 38, hdcBmpchest2, 0, 0, 35, 35, RGB(255, 255, 255));//蓝宝箱
				else if (Map[i][j] == 8)
					TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 38, hdcBmpchest3, 0, 0, 35, 35, RGB(255, 255, 255));//绿宝箱
				else if (Map[i][j] == 9)
					TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 7 + 6 * 12, 19 + 18 * 12, 12, 12, RGB(0, 0, 0));//骨头1
				else if (Map[i][j] == 10)
					TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 32, hdcBmpwall, 9 + 8 * 12, 19 + 18 * 12, 12, 12, RGB(0, 0, 0));//骨头2
				else if (Map[i][j] == 20)
					TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 38, hdcBmpchest1, 3 * 35, 35, 35, 35, RGB(255, 255, 255));//红宝箱
				else if (Map[i][j] == 21)
					TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 38, hdcBmpchest2, 3 * 35, 35, 35, 35, RGB(255, 255, 255));//蓝宝箱
				else if (Map[i][j] == 22)
					TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32, 300 + (i - Player.y) * 32, 32, 38, hdcBmpchest3, 3 * 35, 35, 35, 35, RGB(255, 255, 255));//绿宝箱
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
						TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32 + 2, 300 + (i - Player.y) * 32 - 1, 32, 32, hdcBmpwall, 17 + 16 * 12, 17 + 16 * 12, 12, 12, RGB(0, 0, 0));//罐子
					}
				}
				else if (Map[i][j] == 15)
					TransparentBlt(hMenDC, 180 + 32 + 32 + (j - Player.x) * 32 + 2, 300 + (i - Player.y) * 32 - 1, 32, 32, hdcBmpwall, 6 + 5 * 12, 8 + 7 * 12, 12, 12, RGB(0, 0, 0));//罐子破碎
			}
		}
	}

	//最后不要忘记释放资源
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
	HBITMAP hBmp = nullptr; //位图
	HDC hdcBmp = CreateCompatibleDC(hdc);
	hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP25));
	SelectObject(hdcBmp, hBmp);
	//StretchBlt(hMenDC, 180, 300, 32, 32, hdcBmp, 3*32, 0, SIZE, SIZE, SRCCOPY);//在内存DC上贴图
	TransparentBlt(hMenDC, 180 + 64-8, 280, 40, 52, hdcBmp, 0, 20, 140, 190, RGB(255, 255, 255));
	DeleteObject(hdcBmp);

}
void PrintEnermy(HDC hdc, HINSTANCE hInst, HDC hMenDC)
{
	HBITMAP hBmp = nullptr; //位图
	HDC hdcBmp = CreateCompatibleDC(hdc);
	hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP1));
	SelectObject(hdcBmp, hBmp);
	//StretchBlt(hMenDC, 180, 300, 32, 32, hdcBmp, 3*32, 0, SIZE, SIZE, SRCCOPY);//在内存DC上贴图
	TransparentBlt(hMenDC, 180 + 32 + 32 + (Enermy.x - Player.x) * 32, 300 + (Enermy.y - Player.y) * 32, 32,32, hdcBmp, 8 * 12 + 9, 8*12+9, 12,12, RGB(0,0,0));
	DeleteObject(hdcBmp);
}

void PrintBackGround(HDC hdc, HINSTANCE hInst, HDC hMenDC)
{
	HBITMAP hBmp = nullptr; //位图
	HDC hdcBmp = CreateCompatibleDC(hdc);
	hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP2));
	SelectObject(hdcBmp, hBmp);
	StretchBlt(hMenDC, -250, 0, 3440, 1440, hdcBmp, 0, 0, 3440, 1440, SRCCOPY);//在内存DC上贴图
	DeleteDC(hdcBmp);
	DeleteObject(hBmp);
}

void PrintDataBG(HDC hdc, HINSTANCE hInst, HDC hMenDC)
{
	HBITMAP hBmp = nullptr; //位图
	HDC hdcBmp = CreateCompatibleDC(hdc);
	hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP3));
	SelectObject(hdcBmp, hBmp);
	StretchBlt(hMenDC, -5, -23, 354, 707, hdcBmp, 0, 0, 406, 572, SRCCOPY);//在内存DC上贴图
	DeleteDC(hdcBmp);
	DeleteObject(hBmp);
}

void PrintData(HDC hdc, HINSTANCE hInst, HDC hMenDC)
{
	LOGFONT lf = { 0 };
	lf.lfHeight = 25;
	HFONT hFont = CreateFontIndirect(&lf);
	HFONT hFontOld = (HFONT)SelectObject(hMenDC, hFont);
	SetBkMode(hMenDC, TRANSPARENT); //设置背景为透明,也可以用SetBkColor函数
	SetTextColor(hMenDC, RGB(0, 0, 0)); //设置前景颜色

	TextOutA(hMenDC, 40, 70, "当前持有法诀： ", strlen("当前持有法诀："));
	//TextOutA(hMenDC, 40, 95, "当前持有元素： ", strlen("当前持有元素："));
	TextOutA(hMenDC, 40, 120, "当前持有道具： ", strlen("当前持有道具："));

	HBITMAP hBmpkey1 = nullptr; //位图
	HBITMAP hBmpkey2 = nullptr; //位图
	HBITMAP hBmpkey3 = nullptr; //位图
	HBITMAP hBmpdig = nullptr; //位图
	HBITMAP hBmpfly = nullptr; //位图
	HBITMAP hBmprun = nullptr; //位图
	HBITMAP hBmpstrong = nullptr; //位图


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
		TransparentBlt(hMenDC, 200, 60, 48, 48, hdcBmpkey1, 0, 0, 12, 12, RGB(0, 0, 0));//在内存DC上贴图
	else if (key2)
		TransparentBlt(hMenDC, 200, 60, 48, 48, hdcBmpkey2, 0, 0, 12, 12, RGB(0, 0, 0));//在内存DC上贴图
	else if (key3)
		TransparentBlt(hMenDC, 200, 60, 48, 48, hdcBmpkey3, 0, 0, 12, 12, RGB(0, 0, 0));//在内存DC上贴图
	else
		TextOutA(hMenDC, 200, 70, "无", strlen("无"));
	char Dig[10] = { 0 }, Fly[10] = { 0 }, Run[10] = { 0 }, Strong[10] = { 0 };

	TextOutA(hMenDC, 180, 120, "担山赶月", strlen("担山赶月"));
	TransparentBlt(hMenDC, 265, 120, 20, 20, hdcBmpdig, 0, 0, 32, 32, RGB(255, 255, 255));
	TextOutA(hMenDC, 180, 145, "筋斗云", strlen("筋斗云"));
	TransparentBlt(hMenDC, 265, 145, 20, 20, hdcBmpfly, 0, 0, 24, 24, RGB(255, 255, 255));
	TextOutA(hMenDC, 180, 170, "缩地成寸", strlen("缩地成寸"));
	TransparentBlt(hMenDC, 265, 170, 20, 20, hdcBmprun, 0, 0, 32, 32, RGB(255, 255, 255));
	TextOutA(hMenDC, 180, 195, "金刚之躯", strlen("金刚之躯"));
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
	TextOutA(hMenDC, 40, 250, "当前选中神通：", strlen("当前选中神通："));
	if(flag_h)
	TextOutA(hMenDC, 180, 250, "担山赶月", strlen("担山赶月"));
	else
		TextOutA(hMenDC, 180, 250, "筋斗云", strlen("筋斗云"));

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
	DeleteObject(hFont); //删除对象
}

void MassagePrompt1(HWND hWnd,HDC hdc, HINSTANCE hInst, HDC hMenDC)
{
	if (!show && text_cnt1 == 9)
	{
 		HBITMAP hBmp = nullptr; //位图
		HDC hdcBmp = CreateCompatibleDC(hdc);
		hBmp = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP13));
		SelectObject(hdcBmp, hBmp);
		//StretchBlt(hMenDC, 180, 300, 32, 32, hdcBmp, 3*32, 0, SIZE, SIZE, SRCCOPY);//在内存DC上贴图
		TransparentBlt(hMenDC, 60, 200, 400, 200, hdcBmp, 0, 0, 592, 357, RGB(255, 255, 255));
		DeleteDC(hdcBmp);
		DeleteObject(hBmp);
		LOGFONT lf = { 0 };
		lf.lfHeight = 30;
		HFONT hFont = CreateFontIndirect(&lf);
		HFONT hFontOld = (HFONT)SelectObject(hMenDC, hFont);
		SetBkMode(hMenDC, TRANSPARENT); //设置背景为透明,也可以用SetBkColor函数
		SetTextColor(hMenDC, RGB(255, 255, 255)); //设置前景颜色
		TextOutA(hMenDC, 236, 207, "提示", strlen("提示"));
		lf.lfHeight = 20;
		hFont = CreateFontIndirect(&lf);
		hFontOld = (HFONT)SelectObject(hMenDC, hFont);
		SetTextColor(hMenDC, RGB(0, 0, 0)); //设置前景颜色
		if (text_cnt == 0)
		{
			TextOutA(hMenDC, 100, 270, "操控可通过WASD来移动。h键切换担山赶月和筋", strlen("操控可通过WASD来移动。h键切换担山赶月和筋"));
			TextOutA(hMenDC, 100, 295, "斗云道具使用,j键缩地缩地成寸,k键迷雾开关", strlen("斗云道具使用,j键缩地成寸,k键迷雾开关"));
			TextOutA(hMenDC, 100, 320, ",l键金刚之躯,h键切换担山赶月和筋斗云道具使用。", strlen(",l键金刚之躯,h键切换担山赶月和筋斗云道具使用。"));
		}
		else if (text_cnt == 1)
		{
			TextOutA(hMenDC, 100, 270, "地图上会随机生成宝箱，不同属性的宝箱需要", strlen("地图上会随机生成宝箱，不同属性的宝箱需要"));
			TextOutA(hMenDC, 100, 295, "对应属性的法诀来开启。", strlen("对应属性的钥匙来开启。"));
			TextOutA(hMenDC, 100, 320, "当地图上全部宝箱都开启后，方可打开地道。", strlen("当地图上全部宝箱都开启后，方可打开地道。"));
		}
		else if (text_cnt == 2)
		{
			TextOutA(hMenDC, 100, 270, "有的宝箱会被墙壁包围，这时你可以利用手中", strlen("有的宝箱会被墙壁包围，这时你可以利用手中"));
			TextOutA(hMenDC, 100, 295, "的道具，如果道具不够，可以通过打破罐子获得。", strlen("的道具，如果道具不够，可以通过打破罐子获得。"));
		}
		else if (text_cnt == 5)
		{ 
			TextOutA(hMenDC, 100, 270, "你获得了", strlen("你获得了"));
			SetTextColor(hMenDC, RGB(255, 0, 0)); //设置前景颜色
			TextOutA(hMenDC, 170, 270, "火元素法诀", strlen("火元素法诀"));
		}
		else if (text_cnt == 7)
		{
			TextOutA(hMenDC, 100, 270, "你获得了", strlen("你获得了"));
			SetTextColor(hMenDC, RGB(0, 0, 255)); //设置前景颜色
			TextOutA(hMenDC, 170, 270, "水元素法诀", strlen("水元素法诀"));
		}
		else if (text_cnt == 9)
		{
			TextOutA(hMenDC, 100, 270, "你获得了", strlen("你获得了"));
			SetTextColor(hMenDC, RGB(0, 255, 0)); //设置前景颜色
			TextOutA(hMenDC, 170, 270, "木元素法诀", strlen("木元素法诀"));
		}
		else if (text_cnt == 19)
		{
			TextOutA(hMenDC, 100, 270, "你获得了", strlen("你获得了"));
			TextOutA(hMenDC, 170, 270, "缩地成寸", strlen("缩地成寸"));

		}
		else if (text_cnt == 21)
		{
			TextOutA(hMenDC, 100, 270, "你获得了", strlen("你获得了"));
			TextOutA(hMenDC, 170, 270, "担山赶月", strlen("担山赶月"));

		}
		else if (text_cnt == 23)
		{
			TextOutA(hMenDC, 100, 270, "你获得了", strlen("你获得了"));
			TextOutA(hMenDC, 170, 270, "筋斗云", strlen("筋斗云"));

		}
		else if (text_cnt == 25)
		{
			TextOutA(hMenDC, 100, 270, "你获得了", strlen("你获得了"));
			TextOutA(hMenDC, 170, 270, "金刚之躯", strlen("金刚之躯"));

		}
		else if (text_cnt == 11)
		{
			TextOutA(hMenDC, 100, 270, "你打开了", strlen("你打开了"));
			SetTextColor(hMenDC, RGB(255, 0, 0)); //设置前景颜色
			TextOutA(hMenDC, 170, 270, "火元素宝箱", strlen("火元素宝箱"));
		}
		else if (text_cnt == 13)
		{
			TextOutA(hMenDC, 100, 270, "你打开了", strlen("你打开了"));
			SetTextColor(hMenDC, RGB(0, 0, 255)); //设置前景颜色
			TextOutA(hMenDC, 170, 270, "水元素宝箱", strlen("水元素宝箱"));
		}
		else if (text_cnt == 15)
		{
			TextOutA(hMenDC, 100, 270, "你打开了", strlen("你打开了"));
			SetTextColor(hMenDC, RGB(0, 255, 0)); //设置前景颜色
			TextOutA(hMenDC, 170, 270, "木元素宝箱", strlen("木元素宝箱"));
		}
		else if (text_cnt == 17)
		{
			TextOutA(hMenDC, 100, 270, "地道已经打开了。", strlen("地道已经打开了。"));
		}
		else if (text_cnt == 27)
		{
			TextOutA(hMenDC, 100, 270, "你已进入下一关。", strlen("你已进入下一关。"));
		}
		else if (text_cnt == 29)
		{
			TextOutA(hMenDC, 100, 270, "游戏结束。", strlen("游戏结束。"));
		}
		else if (text_cnt == 31)
		{
			TextOutA(hMenDC, 100, 270, "该死!你被抓住了,请重新再来。",strlen("该死!你被抓住了。请重新再来。"));
		}
		SetTextColor(hMenDC, RGB(0, 0, 0)); //设置前景颜色
		TextOutA(hMenDC, 300, 340, "[>按空格键继续<]", strlen("[>按空格键继续<]"));
		SelectObject(hMenDC, hFontOld);
		DeleteObject(hFont); //删除对象

	}
}

void Show(HDC hdc, HINSTANCE hInst, HDC hMenDC)
{
	HBITMAP hBmpshow = nullptr; //位图
	HBITMAP hBmp1 = nullptr; //位图
	HBITMAP hBmp2 = nullptr; //位图
	HBITMAP hBmp3 = nullptr; //位图

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
	lf.lfHeight = 17;//字体大小
	HFONT hFont = CreateFontIndirect(&lf);
	HFONT hFontOld = (HFONT)SelectObject(hMenDC, hFont);
	SetBkMode(hMenDC, TRANSPARENT); 
	SetTextColor(hMenDC, RGB(0, 0, 0));
	if (text_cnt1 == 0)
	{
		lf.lfHeight = 15;
		hFont = CreateFontIndirect(&lf);
		hFontOld = (HFONT)SelectObject(hMenDC, hFont);
		TransparentBlt(hMenDC, -35, 460, 150, 150, hdcBmp1, 0, 0, 168, 223, RGB(255, 255, 255));//唐僧
		TransparentBlt(hMenDC, 410, 470, 90, 140, hdcBmp3, 0, 0, 65, 85, RGB(255, 255, 255));//三大仙之虎
		TextOutA(hMenDC, 110, 510, "(唐僧被三大仙抓走，孙悟空失去五行之力单人潜入三大仙", strlen("唐僧被三大仙抓走，孙悟空失去五行之力单人潜入三大仙 "));
		TextOutA(hMenDC, 77, 535, "洞穴搭救唐僧。需要获得五行之力来击败三大仙。三大仙把五行", strlen("洞穴搭救唐僧。需要获得五行之力来击败三大仙。三大仙把五行"));
		TextOutA(hMenDC, 77, 560, "之力封印在三个葫芦（宝箱）中。寻找对应的法决（钥匙）打开", strlen("之力封印在三个葫芦（宝箱）中。寻找对应的法决（钥匙）打开"));
		TextOutA(hMenDC, 77, 585, "葫芦（宝箱），获得失去的五行之力来打败虎鹿羊三大仙)", strlen("葫芦（宝箱），获得失去的五行之力来打败虎鹿羊三大仙)"));
	}
	else if (text_cnt1 == 1)
	{
 		TransparentBlt(hMenDC, -30, 460, 150, 150, hdcBmp1, 0, 0, 168, 223, RGB(255, 255, 255));//唐僧
		TransparentBlt(hMenDC, 385, 450, 150, 150, hdcBmp2, 0, 0, 211, 222, RGB(0, 0, 0));//悟空
		TextOutA(hMenDC, 105, 515, "孙悟空和唐僧在家里写课设，忽然一阵妖风", strlen("孙悟空和唐僧在家里写课设，忽然一阵妖"));
		TextOutA(hMenDC, 105, 540, "吹过，眼见那唐僧被那风卷走。", strlen("吹过，眼见那唐僧被那风卷走。"));
	}
	else if (text_cnt1 == 2)
	{
		TransparentBlt(hMenDC, -30, 460, 150, 150, hdcBmp1, 0, 0, 168, 223, RGB(255, 255, 255));//唐僧
		TransparentBlt(hMenDC, 385, 450, 150, 150, hdcBmp2, 0, 0, 211, 222, RGB(0, 0, 0));//悟空
		TextOutA(hMenDC, 105, 515, "唐僧嘴里大喊着：“悟空，救我”。", strlen("唐僧嘴里大喊着：“悟空，救我”。"));
	}
	else if (text_cnt1 == 3)
	{
		TransparentBlt(hMenDC, -10, 450, 150, 150, hdcBmp2, 0, 0, 211, 222, RGB(0, 0, 0));//悟空
		TransparentBlt(hMenDC, 410, 470, 90, 140, hdcBmp3, 0, 0, 65, 85, RGB(255, 255, 255));//三大仙之虎
		TextOutA(hMenDC, 80, 515, "孙悟空（着急的观望，循风一闻，原来是那虎", strlen("孙悟空（着急的观望，循风一闻，原来是那虎"));
		TextOutA(hMenDC, 80, 540, "鹿羊三大仙),大喊：妖怪哪里走！随即追上去。", strlen("鹿羊三大仙),大喊：妖怪哪里走！随即追上去。"));
	}
	else if (text_cnt1 == 4)
	{
		TransparentBlt(hMenDC, 0, 470, 90, 140, hdcBmp3, 0, 0, 65, 85, RGB(255, 255, 255));//三大仙之虎
		TextOutA(hMenDC, 90, 515, "三大仙（抛出捆仙神）大笑：孙悟空，你的五行之力已经", strlen("三大仙（抛出捆仙神）大笑：孙悟空，你的五行之力以及"));
		TextOutA(hMenDC, 90, 540, "被这捆仙神束缚住了。看你还怎么来救你师傅！哈哈哈!", strlen("被这捆仙神束缚住了。看你还怎么来救你师傅！哈哈哈!"));

	}
	else if (text_cnt1 == 5)
	{
		TransparentBlt(hMenDC, 0, 470, 90, 140, hdcBmp3, 0, 0, 65, 85, RGB(255, 255, 255));//三大仙之虎
		TransparentBlt(hMenDC, 385, 450, 150, 150, hdcBmp2, 0, 0, 211, 222, RGB(0, 0, 0));//悟空
		TextOutA(hMenDC, 90, 515, "三大仙（震惊）：孙悟空你失去了五行之力", strlen("三大仙（震惊）：孙悟空你失去了五行之力"));
		TextOutA(hMenDC, 90, 540, "居然能追到这里来？不过只获得了三种残缺", strlen("居然能追到这里来？不过只获得了三种残缺"));
		TextOutA(hMenDC, 90, 565, "五行之力的你，一样战胜不了我们三兄弟的", strlen("五行之力的你，一样战胜不了我们三兄弟的"));
		TextOutA(hMenDC, 90, 590, "。看打！", strlen("。看打！"));
	}
	else if (text_cnt1 == 6)
	{
		TransparentBlt(hMenDC, -10, 450, 150, 150, hdcBmp2, 0, 0, 211, 222, RGB(0, 0, 0));//悟空
		TransparentBlt(hMenDC, 410, 470, 90, 140, hdcBmp3, 0, 0, 65, 85, RGB(255, 255, 255));//三大仙之虎
		TextOutA(hMenDC, 90, 515, "孙悟空（不屑）：区区三只走兽也敢妄称大", strlen("孙悟空（不屑）：区区三只走兽也敢妄称大"));
		TextOutA(hMenDC, 90, 540, "仙？看俺老孙今天怎么教训你们！", strlen("仙？看俺老孙今天怎么教训你们！"));
	}
	else if (text_cnt1 == 7)
	{
		TransparentBlt(hMenDC, 0, 470, 90, 140, hdcBmp3, 0, 0, 65, 85, RGB(255, 255, 255));//三大仙之虎
		TextOutA(hMenDC, 90, 515, "三大仙（被打趴下）：饶命！大圣饶命！唐僧就在后面", strlen("三大仙（被打趴下）：饶命！大圣饶命！唐僧就在后面"));
		TextOutA(hMenDC, 90, 540, "的地牢里！", strlen("的地牢里！"));
	}
	else if (text_cnt1 == 8)
	{
		TransparentBlt(hMenDC, -30, 460, 150, 150, hdcBmp1, 0, 0, 168, 223, RGB(255, 255, 255));//唐僧
		TransparentBlt(hMenDC, 385, 450, 150, 150, hdcBmp2, 0, 0, 211, 222, RGB(0, 0, 0));//悟空
		TextOutA(hMenDC, 105, 515, "孙悟空救回了唐僧，两人高高兴兴的回去", strlen("孙悟空救回了唐僧，两人高高兴兴的回去"));
		TextOutA(hMenDC, 105, 540, "写课设了。", strlen("写课设了。"));
		show = false;
	}

	TextOutA(hMenDC, 340, 620, "[>按空格键继续<]", strlen("[>按空格键继续<]"));
	DeleteObject(hdcBmp1);
	DeleteObject(hdcBmp2);
	DeleteObject(hdcBmp3);

	DeleteObject(hBmp1);
	DeleteObject(hBmp2);
	DeleteObject(hBmp3);
}


void Init(HDC hdc, HINSTANCE hInst, HDC hMenDC)
{
	PlaySound(L"Resource\\开始音乐.wav", NULL, SND_FILENAME | SND_ASYNC);
	HBITMAP hBmp_bk = nullptr; //位图
	HBITMAP hBmp_start = nullptr; //位图
	HBITMAP hBmp_end = nullptr; //位图

	HDC hdcBmp_bk = CreateCompatibleDC(hdc);
	HDC hdcBmp_start = CreateCompatibleDC(hdc);
	HDC hdcBmp_end = CreateCompatibleDC(hdc);

	hBmp_bk = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP14));
	hBmp_start = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP15));
	hBmp_end = LoadBitmap(hInst, MAKEINTRESOURCE(IDB_BITMAP16));

	SelectObject(hdcBmp_bk, hBmp_bk);
	SelectObject(hdcBmp_start, hBmp_start);
	SelectObject(hdcBmp_end, hBmp_end);

	TransparentBlt(hMenDC, -200, -100, 1398, 786, hdcBmp_bk, 0, 0, 1398, 786, SRCCOPY);//在内存DC上贴图
	TransparentBlt(hMenDC, 120, 170, 150, 60, hdcBmp_start, 0, 0, 122, 38, RGB(255, 255, 255));//在内存DC上贴图
	TransparentBlt(hMenDC, 120, 300, 150, 60, hdcBmp_end, 0, 0, 122, 38, RGB(255, 255, 255));//在内存DC上贴图

	DeleteObject(hdcBmp_bk);
	DeleteObject(hdcBmp_start);
	DeleteObject(hdcBmp_end);
}


void PosJudge(int y,int x, WPARAM wParam)
{
	if (Map[Player.y][Player.x] == 6 && key1 && (Map[Player.y][Player.x] = 20))//打开红箱子
	{
		chest1 = true;
		key_cnt = false;
		key1 = false;
		text_cnt = 11;
		Map[Player.y][Player.x] == 20;
		PlaySound(L"Resource\\宝箱.wav", NULL, SND_FILENAME | SND_ASYNC);
	}
	else if (Map[Player.y][Player.x] == 7 && key2 && (Map[Player.y][Player.x] = 21))//打开蓝箱子
	{
		key_cnt = false;
		key2 = false;
		chest2 = true;
		text_cnt = 13;
		PlaySound(L"Resource\\宝箱.wav", NULL, SND_FILENAME | SND_ASYNC);
	}
	else if (Map[Player.y][Player.x] == 8 && key3 && (Map[Player.y][Player.x] = 22))//打开绿箱子
	{
		key_cnt = false;
		key3 = false;
		chest3 = true;
		text_cnt = 15;
		Map[Player.y][Player.x] == 22;
		PlaySound(L"Resource\\宝箱.wav", NULL, SND_FILENAME | SND_ASYNC);

	}
	else if (Map[Player.y][Player.x] == 11 && (key1_cnt = true) && !key_cnt)//持有红钥匙
	{
		PlaySound(L"Resource\\罐子.wav", NULL, SND_FILENAME | SND_ASYNC);
		Map[Player.y][Player.x] = 15;
		key1 = true;
		key_cnt = true;
		text_cnt = 5;
	}
	else if (Map[Player.y][Player.x] == 12 && (key2_cnt = true) && !key_cnt)//持有蓝钥匙
	{
		PlaySound(L"Resource\\罐子.wav", NULL, SND_FILENAME | SND_ASYNC);
		Map[Player.y][Player.x] = 15;
		key2 = true;
		key_cnt = true;
		text_cnt = 7;
	}
	else if (Map[Player.y][Player.x] == 13 && (key3_cnt = true) && !key_cnt)//持有绿钥匙
	{
		PlaySound(L"Resource\\罐子.wav", NULL, SND_FILENAME | SND_ASYNC);
		Map[Player.y][Player.x] = 15;
		key3 = true;
		key_cnt = true;
		text_cnt = 9;
	}
	else if (Map[Player.y][Player.x] == 16)
	{
		PlaySound(L"Resource\\罐子.wav", NULL, SND_FILENAME | SND_ASYNC);
		Map[Player.y][Player.x] = 15;
		dig++;
		text_cnt = 21;
	}
	else if (Map[Player.y][Player.x] == 17)
	{
		PlaySound(L"Resource\\罐子.wav", NULL, SND_FILENAME | SND_ASYNC);
		Map[Player.y][Player.x] = 15;
		fly++;
		text_cnt = 23;
	}
	else if (Map[Player.y][Player.x] == 18)
	{
		PlaySound(L"Resource\\罐子.wav", NULL, SND_FILENAME | SND_ASYNC);
		Map[Player.y][Player.x] = 15;
		text_cnt = 19;
		run++;
	}
	else if (Map[Player.y][Player.x] == 19)
	{
		PlaySound(L"Resource\\罐子.wav", NULL, SND_FILENAME | SND_ASYNC);
		Map[Player.y][Player.x] = 15;
		strong++;
		text_cnt = 25;
	}
	else if (Map[Player.y][Player.x] == 1 && dig > 0 && flag_h)//担山赶月
	{
		Map[Player.y][Player.x] = 0;
		dig--;
	}
	else if (Map[Player.y][Player.x] == 1 && fly > 0 && !flag_h)//筋斗云
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
		PlaySound(L"Resource\\罐子.wav", NULL, SND_FILENAME | SND_ASYNC);
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