#pragma once

#include "framework.h"
#include "resource.h"

#define SIZE 32   //尺寸
#define WALL 250  //墙
#define CHEST 2   //宝箱
#define FIRE 15   //火把
#define JAR 10    //罐子
#define NEXT 1    //出口
#define BONE 16	  //骨头
#define KEY 2	  //钥匙
#define MONSTER 5 //小怪
#define PROP 8	  //道具

#define CREATEMAP (WM_USER+1025)

struct play
{
	int x;
	int y;
};

extern struct play Player;  //主角
extern struct play Enermy;  //敌人


extern POINT point;//鼠标
extern int Map[31][31];//地图
extern int level;//关卡
extern bool flag_h;//切换担山赶月/筋斗云
extern bool start, show;
extern int dig, fly, run, strong;
extern bool key1, key2, key3,key_cnt,key1_cnt,key2_cnt,key3_cnt;
extern bool chest1, chest2, chest3;
extern int text_cnt, text_cnt1;
extern bool next_cnt;
extern bool frog_cnt;//迷雾开关

//进入页面
void Init(HDC hdc, HINSTANCE hInst, HDC hMenDC);

//地图创建
void CreateMap();

//地图
void PrintMap1(HDC hdc, HINSTANCE hInst, HDC hMenDC);

//地图背景
void PrintBackGround(HDC hdc, HINSTANCE hInst, HDC hMenDC);

//人物
void PrintPlayer(HDC hdc, HINSTANCE hInst, HDC hMenDC);

//怪物
void PrintEnermy(HDC hdc, HINSTANCE hInst, HDC hMenDC);

//人物移动
void PlayerMove(HWND hWnd, WPARAM wParam);

//数据页面背景
void PrintDataBG(HDC hdc, HINSTANCE hInst, HDC hMenDC);

//数据页面
void PrintData(HDC hdc, HINSTANCE hInst, HDC hMenDC);

//弹出提示
void MassagePrompt1(HWND hWnd,HDC hdc, HINSTANCE hInst, HDC hMenDC);

//剧情对话框
void Show(HDC hdc, HINSTANCE hInst, HDC hMenDC);

//坐标判断
void PosJudge(int y, int x, WPARAM wParam);

//游戏贴图
void game(HWND hWnd,HDC hdc, HINSTANCE hInst);

void autoPathfinding();
