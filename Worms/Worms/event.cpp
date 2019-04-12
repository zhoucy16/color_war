#include "event.h"
#include "global.h"
#include "item.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>



//循环参数
int h = 0;	//英雄序号
int b = 0;  //弹坑序号
int p = 0;	//碰撞检测点位置序号

//阶段参数
int c = 0;	//计次序号
int r = 0;	//控制序号
int t = 0;	//计时序号
int o = 0;	//海洋序号
int map = 0; //背景序号

//简化代数
int x = 0;	//水平距离
int y = 0;	//竖直距离
int alpha = 0;	//偏转角度
int ora = 0;	//ora阵营分数
int gre = 0;	//gre阵营分数
int wind = 0;	//风速
int cloudvel = 0;	//云速
int MULTYCOLOR[11] = {BOOM_COLOR1, BOOM_COLOR2, BOOM_COLOR3, BOOM_COLOR4, BOOM_COLOR5, BOOM_COLOR6, BOOM_COLOR7, BOOM_COLOR8, BOOM_COLOR9, BOOM_COLOR10, BOOM_COLOR11};
LONG biux = 0;		//瞬移位置
LONG biuy = 0;		//瞬移位置
BOOL dir = 0;		//飞机方向
int city = 0;		//城市代号

//状态参数
int moving = 0;		//camera状态
BOOL pausing = 0;	//暂停
BOOL winner = 0;	//获胜方
int boo = 0;		//爆炸效果
int	weapon = 0;		//武器切换
int flying = 0;		//炸飞状态
int f = 0;			//炸飞者序号
BOOL go = 0;		//飞机出发
BOOL boomyet = 0;	//空袭完成
BOOL chosen = 0;	//武器选择
int buffer = 0;		//走动动作缓冲
int buffer2 = 0;	//投弹动作缓冲




VOID Init(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	// 加载背景位图
	m_hBackgroundBmp[0] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_COLOR));
	m_hBackgroundBmp[1] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_COLOR2));

	// 加载标题位图
	m_hTitleBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_TITLE));

	// 加载帮助位图
	m_hHelpMapBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_HELPMAP));

	//加载defeat位图
	m_hDefeatBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_DEFEAT));

	//加载victory位图
	m_hVictoryBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_VICTORY));

	// 加载海洋位图
	m_hOceanBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_OCEAN));

	// 加载taji位图
	m_hTajiBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_TAJI));

	// 加载newyork位图
	m_hNewyorkBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_NEWYORK));

	// 加载shanghai位图
	m_hShanghaiBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_SH));

	// 加载Hero位图
	m_hHeroBmp[0] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_H0));
	m_hHeroBmp[1] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_H1));
	m_hHeroBmp[2] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_H2));
	m_hHeroBmp[3] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_H3));
	m_hHeroBmp[4] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_H4));
	m_hHeroBmp[5] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_H5));

	// 加载Arrow位图
	m_hArrowBmp[0] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_J0));
	m_hArrowBmp[1] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_J1));
	m_hArrowBmp[2] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_J2));
	m_hArrowBmp[3] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_J3));
	m_hArrowBmp[4] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_J4));
	m_hArrowBmp[5] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_J5));

	// 加载Tomb位图
	m_hTombBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_TOMB));

	// 加载Boom位图
	m_hBoomBmp[0] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BOOM1));
	m_hBoomBmp[6] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BOOM2));
	m_hBoomBmp[2] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BOOM3));
	m_hBoomBmp[8] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BOOM4));
	m_hBoomBmp[4] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BOOM5));
	m_hBoomBmp[1] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BOOM6));
	m_hBoomBmp[7] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BOOM8));
	m_hBoomBmp[3] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BOOM9));
	m_hBoomBmp[9] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BOOM10));
	m_hBoomBmp[10] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BOOM11));
	m_hBoomBmp[5] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BOOM12));

	//加载倒计时位图
	m_hClockBmp[0] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP1));
	m_hClockBmp[1] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP2));
	m_hClockBmp[2] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP3));
	m_hClockBmp[3] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP4));
	m_hClockBmp[4] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP5));
	m_hClockBmp[5] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP6));
	m_hClockBmp[6] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP7));
	m_hClockBmp[7] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP8));
	m_hClockBmp[8] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP9));
	m_hClockBmp[9] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP10));
	m_hClockBmp[10] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP11));
	m_hClockBmp[11] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP12));
	m_hClockBmp[12] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP13));
	m_hClockBmp[13] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP14));
	m_hClockBmp[14] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP15));
	m_hClockBmp[15] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP16));
	m_hClockBmp[16] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP17));
	m_hClockBmp[17] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP18));
	m_hClockBmp[18] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP19));
	m_hClockBmp[19] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP20));
	m_hClockBmp[20] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP21));
	m_hClockBmp[21] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP22));
	m_hClockBmp[22] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP23));
	m_hClockBmp[23] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP24));
	m_hClockBmp[24] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP25));
	m_hClockBmp[25] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP26));
	m_hClockBmp[26] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP27));
	m_hClockBmp[27] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP28));
	m_hClockBmp[28] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP29));
	m_hClockBmp[29] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP30));
	m_hClockBmp[30] = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BITMAP31));
	
	//加载瞄准器位图
	m_hFocusBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_FOCUS));

	//加载瞄准器位图
	m_hBiuBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_BIU));

	// 加载开始游戏按钮位图
	m_hGameStartButtonBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_START));

	// 加载游戏帮助按钮位图
	m_hGameHelpButtonBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_HELP));

	// 加载重玩游戏按钮位图
	m_hGameAgainButtonBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_AGAIN));

	// 加载回主菜单按钮位图
	m_hGameBackButtonBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_MENU));

	// 加载回主菜单按钮位图
	m_hGameResumeButtonBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_RESUME));

	// 加载开始游戏按钮位图
	m_hGameSHButtonBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_CHSH));

	// 加载纽约按钮位图
	m_hGameNYButtonBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_CHNY));

	// 加载重玩游戏按钮位图
	m_hGameTJButtonBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_CHTJ));

	//加载云彩位图
	m_hCloud1Bmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_CLOUD3));
	m_hCloud2Bmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_CLOUD1));

	//加载飞机位图
	m_hPlaneHBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_H01));
	m_hPlaneTBmp = LoadBitmap(((LPCREATESTRUCT)lParam)->hInstance,
		MAKEINTRESOURCE(IDB_T01));

	//创建云彩
	m_wind1 = CreateWind(0 - CLOUD_SIZE_X, 50, CLOUD_SIZE_X, CLOUD_SIZE_Y, m_hCloud1Bmp);
	m_wind2 = CreateWind(WNDWIDTH, 50, CLOUD_SIZE_X, CLOUD_SIZE_Y, m_hCloud2Bmp);

	//创建飞机
	m_planeH = CreatePlane(-PLANE_SIZE_X, FLY_HEIGHT, PLANE_SIZE_X, PLANE_SIZE_Y, m_hPlaneHBmp);
	m_planeT = CreatePlane(WNDWIDTH, FLY_HEIGHT, PLANE_SIZE_X, PLANE_SIZE_Y, m_hPlaneTBmp);

	//创建海洋
	m_ocean = CreateOcean(0, WNDHEIGHT - OCEAN_SIZE_Y * 0.55, OCEAN_SIZE_X, OCEAN_SIZE_Y, m_hOceanBmp);


	// 创建英雄
	for(h=0;h<MAX_HERO_NUM;h++)
	{
		m_hero[h] = CreateHero(150 + 100 * h, 100 - HERO_SIZE_Y, HERO_SIZE_X, HERO_SIZE_Y, m_hHeroBmp[h], 0, HERO_MAX_FRAME_NUM);
		m_tomb[h] = CreateHero(150 + 100 * h, 100 - HERO_SIZE_Y, TOMB_SIZE_X, TOMB_SIZE_Y, m_hTombBmp, 0, HERO_MAX_FRAME_NUM);
	}

	// 创建箭头
	for(h=0;h<MAX_HERO_NUM;h++)
	{
		m_arrow[h] = CreateArrow(m_hero[h].pos.x + HERO_SIZE_X / 2 - ARROW_SIZE_X / 2, m_hero[h].pos.y - HEIGHT, ARROW_SIZE_X, ARROW_SIZE_Y, m_hArrowBmp[h]);
	}

	//创建倒计时
	for(h=0;h<31;h++)
	{
		m_clock[h] = CreateClock(400 - CLOCK_SIZE_X, 0, CLOCK_SIZE_X, CLOCK_SIZE_Y, m_hClockBmp[h]);
	}

	//创建血条
	for(h=0;h<MAX_HERO_NUM;h++)
	{
		m_life[h] = CreateLife(0,-20,60,2,NULL);
	}

	// 创建地形
	m_terrian[0] = CreateTerrian(0, 0, TAJI_SIZE_X, TAJI_SIZE_Y, m_hTajiBmp);
	m_terrian[1] = CreateTerrian(0, 0, NEWY_SIZE_X, NEWY_SIZE_Y, m_hNewyorkBmp);
	m_terrian[2] = CreateTerrian(0, 0, SH_SIZE_X, SH_SIZE_Y, m_hShanghaiBmp);

	//创建标题
	m_gameTitle = CreateGameButton(400 - TITLE_SIZE_X / 2, 10, TITLE_SIZE_X, TITLE_SIZE_Y, m_hTitleBmp, 0);

	//创建帮助
	m_gameHelp = CreateGameButton(0, 0, 800, 500, m_hHelpMapBmp, 0);

	// 创建游戏开始按钮
	m_gameStartButton = CreateGameButton(200, 200, 400, 250, m_hGameStartButtonBmp,0);
	m_gameStartButton2 = CreateGameButton(400, 500, 400, 250, m_hGameStartButtonBmp,0);
	m_gameStartButton3 = CreateGameButton(400, 500, 400, 250, m_hGameStartButtonBmp,0);

	// 创建游戏帮助按钮
	m_gameHelpButton = CreateGameButton(200, 400, 400, 250, m_hGameHelpButtonBmp,0);

	// 创建游戏重玩按钮
	m_gameAgainButton = CreateGameButton(200, 150, 400, 250, m_hGameAgainButtonBmp,0);

	// 创建返回主菜单按钮
	m_gameBackButton1 = CreateGameButton(-80, 500, 400, 250, m_hGameBackButtonBmp,0);
	m_gameBackButton2 = CreateGameButton(200, 400, 400, 250, m_hGameBackButtonBmp,0);
	m_gameBackButton3 = CreateGameButton(-80, 500, 400, 250, m_hGameBackButtonBmp,0);
	m_gameBackButton4 = CreateGameButton(-80, 500, 400, 250, m_hGameBackButtonBmp,0);

	// 创建继续按钮
	m_gameResumeButton = CreateGameButton(400, 500, 400, 250, m_hGameResumeButtonBmp,0);

	// 创建纽约按钮
	m_gameNYButton = CreateGameButton(200, 0, 400, 250, m_hGameNYButtonBmp,0);

	// 创建泰姬陵按钮
	m_gameTJButton = CreateGameButton(200, 200, 400, 250, m_hGameTJButtonBmp,0);

	// 创建上海按钮
	m_gameSHButton = CreateGameButton(200, 400, 400, 250, m_hGameSHButtonBmp,0);

	//设定初始游戏状态
	gameStatus.status = 0;
	gameStatus.hBmp = m_hBackgroundBmp[map % 2];

	//
	final1.hBmp = m_hDefeatBmp;
	final2.hBmp = m_hVictoryBmp;

	mciSendString(TEXT("open Worms\\Worms\\res\\funny.mp3 alias bgm"), NULL, 0, NULL);

}

VOID Render(HWND hWnd)
{
	//判断游戏状态
	switch(gameStatus.status)
	{
	case 0:
		//绘制开始界面
		Render_Start(hWnd);
		mciSendString(TEXT("stop bgm"), NULL, 0, NULL);
		break;
	case 1:
		//过渡状态
		Render_Start(hWnd);
		Sleep(100);
		m_gameStartButton.status = 0;
		gameStatus.status = 2;
		break;
	case 2:
		//绘制游戏界面
		Render_Game(hWnd);
		srand(time(NULL));
		break;
	case 31:
		//过渡状态
		Render_Start(hWnd);
		Sleep(100);
		m_gameHelpButton.status = 0;
		gameStatus.status = 32;
		InvalidateRect(hWnd, NULL, TRUE);//第三个参数设为TRUE，重画整个画布。
		break;
	case 32:
		Render_Help(hWnd);
		break;
	case 33:
		//过渡状态
		Render_Help(hWnd);
		Sleep(100);
		m_gameBackButton1.status = 0;
		gameStatus.status = 0;
		InvalidateRect(hWnd, NULL, TRUE);//第三个参数设为TRUE，重画整个画布。
		break;
	case 41:
		//过渡状态
		Render_Start(hWnd);
		Sleep(100);
		m_gameStartButton.status = 0;
		gameStatus.status = 42;
		InvalidateRect(hWnd, NULL, TRUE);//第三个参数设为TRUE，重画整个画布。
		break;
	case 42:
		Render_Choose(hWnd);
		break;
	case 43:
		//过渡状态
		Render_Choose(hWnd);
		Sleep(100);
		m_gameBackButton3.status = 0;
		gameStatus.status = 0;
		InvalidateRect(hWnd, NULL, TRUE);//第三个参数设为TRUE，重画整个画布。
		break;
	case 44:
		city = 0;
		//过渡状态
		Render_Choose(hWnd);
		Sleep(100);

		// 启动计时器
		SetTimer(hWnd, TIMER_ID, TIMER_ELAPSE, NULL);
		// 停止计时器
		//KillTimer(hWnd, TIMER_ID);

		//播放音乐

		mciSendString(TEXT("play bgm repeat"), NULL, 0, NULL);


		m_gameTJButton.status = 0;
		gameStatus.status = 2;
		InvalidateRect(hWnd, NULL, TRUE);//第三个参数设为TRUE，重画整个画布。
		break;
	case 45:
		city = 1;
		//过渡状态
		Render_Choose(hWnd);
		Sleep(100);

		// 启动计时器
		SetTimer(hWnd, TIMER_ID, TIMER_ELAPSE, NULL);
		// 停止计时器
		//KillTimer(hWnd, TIMER_ID);

		//播放音乐
		mciSendString(TEXT("play bgm repeat"), NULL, 0, NULL);


		m_gameNYButton.status = 0;
		gameStatus.status = 2;
		InvalidateRect(hWnd, NULL, TRUE);//第三个参数设为TRUE，重画整个画布。
		break;
	case 46:
		city = 2;
		//过渡状态
		Render_Choose(hWnd);
		Sleep(100);

		// 启动计时器
		SetTimer(hWnd, TIMER_ID, TIMER_ELAPSE, NULL);
		// 停止计时器
		//KillTimer(hWnd, TIMER_ID);

		//播放音乐
		mciSendString(TEXT("play bgm repeat"), NULL, 0, NULL);


		m_gameSHButton.status = 0;
		gameStatus.status = 2;
		InvalidateRect(hWnd, NULL, TRUE);//第三个参数设为TRUE，重画整个画布。
		break;
	case 51:
		Render_Pause(hWnd);
		break;
	case 52:
		//过渡状态
		Render_Pause(hWnd);
		Sleep(100);
		m_gameResumeButton.status = 0;
		gameStatus.status = 2;
		InvalidateRect(hWnd, NULL, TRUE);//第三个参数设为TRUE，重画整个画布。
		break;
	case 53:
		//过渡状态
		Render_Pause(hWnd);
		Sleep(100);
		m_gameBackButton4.status = 0;
		gameStatus.status = 0;
		// 创建英雄
		for(h=0;h<MAX_HERO_NUM;h++)
		{
			m_hero[h] = CreateHero(150 + 100 * h, 100 - HERO_SIZE_Y, HERO_SIZE_X, HERO_SIZE_Y, m_hHeroBmp[h], 0, HERO_MAX_FRAME_NUM);
			m_tomb[h] = CreateHero(150 + 100 * h, 100 - HERO_SIZE_Y, TOMB_SIZE_X, TOMB_SIZE_Y, m_hTombBmp, 0, HERO_MAX_FRAME_NUM);
		}
		for(h=0;h<c;h++)
		{
			m_bomb[h].collision = 0;
			m_boom[h].status = 0;
		}
		c = 0;
		r = 0;
		t = 0;
		o = 0;
		ora = 0;
		gre = 0;
		boo = 0;
		boomyet = 0;
		map++;
		gameStatus.hBmp = m_hBackgroundBmp[map % 2];
		InvalidateRect(hWnd, NULL, TRUE);//第三个参数设为TRUE，重画整个画布。
		break;
	case 3:
		Render_Final(hWnd);
		break;
	case 4:
		Render_Final(hWnd);
		Sleep(100);
		m_gameBackButton2.status = 0;
		gameStatus.status = 0;
		// 创建英雄
		for(h=0;h<MAX_HERO_NUM;h++)
		{
			m_hero[h] = CreateHero(150 + 100 * h, 100 - HERO_SIZE_Y, HERO_SIZE_X, HERO_SIZE_Y, m_hHeroBmp[h], 0, HERO_MAX_FRAME_NUM);
			m_tomb[h] = CreateHero(150 + 100 * h, 100 - HERO_SIZE_Y, TOMB_SIZE_X, TOMB_SIZE_Y, m_hTombBmp, 0, HERO_MAX_FRAME_NUM);
		}
		for(h=0;h<c;h++)
		{
			m_bomb[h].collision = 0;
			m_boom[h].status = 0;
		}
		c = 0;
		r = 0;
		t = 0;
		o = 0;
		ora = 0;
		gre = 0;
		boo = 0;
		boomyet = 0;
		map++;
		gameStatus.hBmp = m_hBackgroundBmp[map % 2];
		break;
	case 6:
		Render_Final(hWnd);
		Sleep(100);
		m_gameAgainButton.status = 0;
		gameStatus.status = 2;
		// 创建英雄
		for(h=0;h<MAX_HERO_NUM;h++)
		{
			m_hero[h] = CreateHero(150 + 100 * h, 100 - HERO_SIZE_Y, HERO_SIZE_X, HERO_SIZE_Y, m_hHeroBmp[h], 0, HERO_MAX_FRAME_NUM);
			m_tomb[h] = CreateHero(150 + 100 * h, 100 - HERO_SIZE_Y, TOMB_SIZE_X, TOMB_SIZE_Y, m_hTombBmp, 0, HERO_MAX_FRAME_NUM);
		}
		for(h=0;h<c;h++)
		{
			m_bomb[h].collision = 0;
			m_boom[h].status = 0;
		}
		c = 0;
		r = 0;
		t = 0;
		o = 0;
		ora = 0;
		gre = 0;
		boo = 0;
		boomyet = 0;
		map++;
		gameStatus.hBmp = m_hBackgroundBmp[map % 2];
		mciSendString(TEXT("play bgm repeat"), NULL, 0, NULL);
		break;
	default:
		break;
	}
}

BOOL ButtonClicked(POINT ptMouse, POINT buttonPos, SIZE buttonSize);

VOID Render_Start(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc;
	// 开始绘制
	hdc = BeginPaint(hWnd, &ps);

	HDC	hdcBmp, hdcBuffer;
	HBITMAP	cptBmp;

	cptBmp = CreateCompatibleBitmap(hdc, WNDWIDTH, WNDHEIGHT);
	hdcBmp = CreateCompatibleDC(hdc);
	hdcBuffer = CreateCompatibleDC(hdc);
	

	// 绘制背景到缓存
	SelectObject(hdcBuffer, cptBmp);
	SelectObject(hdcBmp, gameStatus.hBmp);
	BitBlt(hdcBuffer, 0, 0, WNDWIDTH, WNDHEIGHT,
		hdcBmp, 0, 0, SRCCOPY);

	// 绘制标题
	SelectObject(hdcBmp, m_gameTitle.hBmp);
	TransparentBlt(hdcBuffer, m_gameTitle.pos.x, m_gameTitle.pos.y, m_gameTitle.size.cx, m_gameTitle.size.cy,
		hdcBmp, 0, 0,
		TITLE_SIZE_X, TITLE_SIZE_Y, RGB(255, 255, 255));

	// 绘制开始按钮
	SelectObject(hdcBmp, m_gameStartButton.hBmp);
	TransparentBlt(hdcBuffer, m_gameStartButton.pos.x, m_gameStartButton.pos.y, m_gameStartButton.size.cx, m_gameStartButton.size.cy,
		hdcBmp, 0, GAME_START_BUTTON_SIZE_Y * m_gameStartButton.status,
		GAME_START_BUTTON_SIZE_X, GAME_START_BUTTON_SIZE_Y, RGB(255, 255, 255));

	// 绘制帮助按钮
	SelectObject(hdcBmp, m_gameHelpButton.hBmp);
	TransparentBlt(hdcBuffer, m_gameHelpButton.pos.x, m_gameHelpButton.pos.y, m_gameHelpButton.size.cx, m_gameHelpButton.size.cy,
		hdcBmp, 0, GAME_HELP_BUTTON_SIZE_Y * m_gameHelpButton.status,
		GAME_HELP_BUTTON_SIZE_X, GAME_HELP_BUTTON_SIZE_Y, RGB(255, 255, 255));

	// 最后将所有的信息绘制到屏幕上
	BitBlt(hdc, 0, 0, WNDWIDTH, WNDHEIGHT, hdcBuffer, 0, 0, SRCCOPY);

	// 回收资源所占的内存
	DeleteObject(cptBmp);
	DeleteDC(hdcBuffer);
	DeleteDC(hdcBmp);

	// 结束绘制
	EndPaint(hWnd, &ps);
}

VOID Render_Help(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc;
	// 开始绘制
	hdc = BeginPaint(hWnd, &ps);

	HDC	hdcBmp, hdcBuffer;
	HBITMAP	cptBmp;

	cptBmp = CreateCompatibleBitmap(hdc, WNDWIDTH, WNDHEIGHT);
	hdcBmp = CreateCompatibleDC(hdc);
	hdcBuffer = CreateCompatibleDC(hdc);
	

	// 绘制背景到缓存
	SelectObject(hdcBuffer, cptBmp);
	SelectObject(hdcBmp, gameStatus.hBmp);
	BitBlt(hdcBuffer, 0, 0, WNDWIDTH, WNDHEIGHT,
		hdcBmp, 0, 0, SRCCOPY);

	// 绘制帮助
	SelectObject(hdcBmp, m_gameHelp.hBmp);
	TransparentBlt(hdcBuffer, m_gameHelp.pos.x, m_gameHelp.pos.y, m_gameHelp.size.cx, m_gameHelp.size.cy,
		hdcBmp, 0, HELP_SIZE_Y * m_gameHelp.status,
		HELP_SIZE_X, HELP_SIZE_Y, RGB(255, 255, 255));

	// 绘制返回按钮
	SelectObject(hdcBmp, m_gameBackButton1.hBmp);
	TransparentBlt(hdcBuffer, m_gameBackButton1.pos.x, m_gameBackButton1.pos.y, m_gameBackButton1.size.cx, m_gameBackButton1.size.cy,
		hdcBmp, 0, GAME_BACK_BUTTON_SIZE_Y * m_gameBackButton1.status,
		GAME_BACK_BUTTON_SIZE_X, GAME_BACK_BUTTON_SIZE_Y, RGB(255, 255, 255));

	// 最后将所有的信息绘制到屏幕上
	BitBlt(hdc, 0, 0, WNDWIDTH, WNDHEIGHT, hdcBuffer, 0, 0, SRCCOPY);

	// 回收资源所占的内存
	DeleteObject(cptBmp);
	DeleteDC(hdcBuffer);
	DeleteDC(hdcBmp);

	// 结束绘制
	EndPaint(hWnd, &ps);
}

VOID Render_Choose(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc;
	// 开始绘制
	hdc = BeginPaint(hWnd, &ps);

	HDC	hdcBmp, hdcBuffer;
	HBITMAP	cptBmp;

	cptBmp = CreateCompatibleBitmap(hdc, WNDWIDTH, WNDHEIGHT);
	hdcBmp = CreateCompatibleDC(hdc);
	hdcBuffer = CreateCompatibleDC(hdc);
	

	// 绘制背景到缓存
	SelectObject(hdcBuffer, cptBmp);
	SelectObject(hdcBmp, gameStatus.hBmp);
	BitBlt(hdcBuffer, 0, 0, WNDWIDTH, WNDHEIGHT,
		hdcBmp, 0, 0, SRCCOPY);

	// 绘制选择地图按钮
	SelectObject(hdcBmp, m_gameNYButton.hBmp);
	TransparentBlt(hdcBuffer, m_gameNYButton.pos.x, m_gameNYButton.pos.y, m_gameNYButton.size.cx, m_gameNYButton.size.cy,
		hdcBmp, 0, GAME_CHNY_BUTTON_SIZE_Y * m_gameNYButton.status,
		GAME_CHNY_BUTTON_SIZE_X, GAME_CHNY_BUTTON_SIZE_Y, RGB(255, 255, 255));
	SelectObject(hdcBmp, m_gameTJButton.hBmp);
	TransparentBlt(hdcBuffer, m_gameTJButton.pos.x, m_gameTJButton.pos.y, m_gameTJButton.size.cx, m_gameTJButton.size.cy,
		hdcBmp, 0, GAME_CHTJ_BUTTON_SIZE_Y * m_gameTJButton.status,
		GAME_CHTJ_BUTTON_SIZE_X, GAME_CHTJ_BUTTON_SIZE_Y, RGB(255, 255, 255));
	SelectObject(hdcBmp, m_gameSHButton.hBmp);
	TransparentBlt(hdcBuffer, m_gameSHButton.pos.x, m_gameSHButton.pos.y, m_gameSHButton.size.cx, m_gameSHButton.size.cy,
		hdcBmp, 0, GAME_CHSH_BUTTON_SIZE_Y * m_gameSHButton.status,
		GAME_CHSH_BUTTON_SIZE_X, GAME_CHSH_BUTTON_SIZE_Y, RGB(255, 255, 255));


	// 绘制返回按钮
	SelectObject(hdcBmp, m_gameBackButton3.hBmp);
	TransparentBlt(hdcBuffer, m_gameBackButton3.pos.x, m_gameBackButton3.pos.y, m_gameBackButton3.size.cx, m_gameBackButton3.size.cy,
		hdcBmp, 0, GAME_BACK_BUTTON_SIZE_Y * m_gameBackButton3.status,
		GAME_BACK_BUTTON_SIZE_X, GAME_BACK_BUTTON_SIZE_Y, RGB(255, 255, 255));

	// 最后将所有的信息绘制到屏幕上
	BitBlt(hdc, 0, 0, WNDWIDTH, WNDHEIGHT, hdcBuffer, 0, 0, SRCCOPY);

	// 回收资源所占的内存
	DeleteObject(cptBmp);
	DeleteDC(hdcBuffer);
	DeleteDC(hdcBmp);

	// 结束绘制
	EndPaint(hWnd, &ps);
}

VOID Render_Pause(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc;
	// 开始绘制
	hdc = BeginPaint(hWnd, &ps);

	HDC	hdcBmp, hdcBuffer;
	HBITMAP	cptBmp;

	cptBmp = CreateCompatibleBitmap(hdc, WNDWIDTH, WNDHEIGHT);
	hdcBmp = CreateCompatibleDC(hdc);
	hdcBuffer = CreateCompatibleDC(hdc);
	

	// 绘制背景到缓存
	SelectObject(hdcBuffer, cptBmp);
	SelectObject(hdcBmp, gameStatus.hBmp);
	BitBlt(hdcBuffer, 0, 0, WNDWIDTH, WNDHEIGHT,
		hdcBmp, 0, 0, SRCCOPY);

	// 绘制帮助
	SelectObject(hdcBmp, m_gameHelp.hBmp);
	TransparentBlt(hdcBuffer, m_gameHelp.pos.x, m_gameHelp.pos.y, m_gameHelp.size.cx, m_gameHelp.size.cy,
		hdcBmp, 0, HELP_SIZE_Y * m_gameHelp.status,
		HELP_SIZE_X, HELP_SIZE_Y, RGB(255, 255, 255));

	// 绘制继续按钮
	SelectObject(hdcBmp, m_gameResumeButton.hBmp);
	TransparentBlt(hdcBuffer, m_gameResumeButton.pos.x, m_gameResumeButton.pos.y, m_gameResumeButton.size.cx, m_gameResumeButton.size.cy,
		hdcBmp, 0, GAME_RESUME_BUTTON_SIZE_Y * m_gameResumeButton.status,
		GAME_RESUME_BUTTON_SIZE_X, GAME_RESUME_BUTTON_SIZE_Y, RGB(255, 255, 255));

	// 绘制返回按钮
	SelectObject(hdcBmp, m_gameBackButton4.hBmp);
	TransparentBlt(hdcBuffer, m_gameBackButton4.pos.x, m_gameBackButton4.pos.y, m_gameBackButton4.size.cx, m_gameBackButton4.size.cy,
		hdcBmp, 0, GAME_BACK_BUTTON_SIZE_Y * m_gameBackButton4.status,
		GAME_BACK_BUTTON_SIZE_X, GAME_BACK_BUTTON_SIZE_Y, RGB(255, 255, 255));

	// 最后将所有的信息绘制到屏幕上
	BitBlt(hdc, 0, 0, WNDWIDTH, WNDHEIGHT, hdcBuffer, 0, 0, SRCCOPY);

	// 回收资源所占的内存
	DeleteObject(cptBmp);
	DeleteDC(hdcBuffer);
	DeleteDC(hdcBmp);

	// 结束绘制
	EndPaint(hWnd, &ps);
}

VOID Render_Final(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc;
	// 开始绘制
	hdc = BeginPaint(hWnd, &ps);

	HDC	hdcBmp, hdcBuffer;
	HBITMAP	cptBmp;

	cptBmp = CreateCompatibleBitmap(hdc, WNDWIDTH, WNDHEIGHT);
	hdcBmp = CreateCompatibleDC(hdc);
	hdcBuffer = CreateCompatibleDC(hdc);

	//绘制结果
	if(winner == 1)
	{
		SelectObject(hdcBuffer, cptBmp);
		SelectObject(hdcBmp, final1.hBmp);
		BitBlt(hdcBuffer, 0, 0, WNDWIDTH, WNDHEIGHT,
			hdcBmp, 0, 0, SRCCOPY);
	}
	else
	{
		SelectObject(hdcBuffer, cptBmp);
		SelectObject(hdcBmp, final2.hBmp);
		BitBlt(hdcBuffer, 0, 0, WNDWIDTH, WNDHEIGHT,
			hdcBmp, 0, 0, SRCCOPY);
	}

	// 绘制重玩按钮
	SelectObject(hdcBmp, m_gameAgainButton.hBmp);
	TransparentBlt(hdcBuffer, m_gameAgainButton.pos.x, m_gameAgainButton.pos.y, m_gameAgainButton.size.cx, m_gameAgainButton.size.cy,
		hdcBmp, 0, GAME_AGAIN_BUTTON_SIZE_Y * m_gameAgainButton.status,
		GAME_AGAIN_BUTTON_SIZE_X, GAME_AGAIN_BUTTON_SIZE_Y, RGB(255, 255, 255));

	// 绘制返回主菜单按钮
	SelectObject(hdcBmp, m_gameBackButton2.hBmp);
	TransparentBlt(hdcBuffer, m_gameBackButton2.pos.x, m_gameBackButton2.pos.y, m_gameBackButton2.size.cx, m_gameBackButton2.size.cy,
		hdcBmp, 0, GAME_BACK_BUTTON_SIZE_Y * m_gameBackButton2.status,
		GAME_BACK_BUTTON_SIZE_X, GAME_BACK_BUTTON_SIZE_Y, RGB(255, 255, 255));
	
	// 最后将所有的信息绘制到屏幕上
	BitBlt(hdc, 0, 0, WNDWIDTH, WNDHEIGHT, hdcBuffer, 0, 0, SRCCOPY);

	// 回收资源所占的内存
	DeleteObject(cptBmp);
	DeleteDC(hdcBuffer);
	DeleteDC(hdcBmp);

	// 结束绘制
	EndPaint(hWnd, &ps);
}

VOID Render_Game(HWND hWnd)
{
	PAINTSTRUCT ps;
	HDC hdc;
	// 开始绘制
	hdc = BeginPaint(hWnd, &ps);

	HDC	hdcBmp, hdcBuffer;
	HBITMAP	cptBmp;

	cptBmp = CreateCompatibleBitmap(hdc, WNDWIDTH, WNDHEIGHT);
	hdcBmp = CreateCompatibleDC(hdc);
	hdcBuffer = CreateCompatibleDC(hdc);
	

	// 绘制背景到缓存
	SelectObject(hdcBuffer, cptBmp);
	SelectObject(hdcBmp, gameStatus.hBmp);
	BitBlt(hdcBuffer, 0, 0, WNDWIDTH, WNDHEIGHT,
		hdcBmp, 0, 0, SRCCOPY);

	//绘制云彩
	if(cloudvel > 0)
	{
		SelectObject(hdcBmp, m_wind1.hBmp);
		TransparentBlt(
			hdcBuffer, m_wind1.pos.x, m_wind1.pos.y,
			m_wind1.size.cx, m_wind1.size.cy,
			hdcBmp, 0, 0, CLOUD_SIZE_X, CLOUD_SIZE_Y,
			RGB(255,255,255)
		);
	}
	else if(cloudvel < 0)
	{
		SelectObject(hdcBmp, m_wind2.hBmp);
		TransparentBlt(
			hdcBuffer, m_wind2.pos.x, m_wind2.pos.y,
			m_wind2.size.cx, m_wind2.size.cy,
			hdcBmp, 0, 0, CLOUD_SIZE_X, CLOUD_SIZE_Y,
			RGB(255,255,255)
		);
	}

	// 绘制地形
	o = c / 6;
	SelectObject(hdcBmp, m_terrian[city].hBmp);
	TransparentBlt(
		hdcBuffer, m_terrian[city].pos.x, m_terrian[city].pos.y+o*PERHEIGHT,
		m_terrian[city].size.cx, m_terrian[city].size.cy,
		hdcBmp, 0, 0, m_terrian[city].size.cx, m_terrian[city].size.cy,
		RGB(255,255,255)
	);

	//判断爆炸
	if((GetPixel(hdc, m_bomb[c].pos.x, m_bomb[c].pos.y+m_bomb[c].size.cy) == TERRIAN_COLOR || 
		GetPixel(hdc, m_bomb[c].pos.x+m_bomb[c].size.cx, m_bomb[c].pos.y+m_bomb[c].size.cy) == TERRIAN_COLOR ||
		GetPixel(hdc, m_bomb[c].pos.x, m_bomb[c].pos.y) == TERRIAN_COLOR || 
		GetPixel(hdc, m_bomb[c].pos.x+m_bomb[c].size.cx, m_bomb[c].pos.y) == TERRIAN_COLOR) &&
		m_bomb[c].collision == 1)
	{
		m_bomb[c].collision = 2;
	}

	if(m_bomb[c].collision == 2 && boomyet == 0)
	{

		//创建弹坑
		m_boom[c] = CreateBoom(m_bomb[c].pos.x + BOMB1_SIZE_X / 2 - BOOM1_SIZE_X / 2, m_bomb[c].pos.y + BOMB1_SIZE_Y / 2 - BOOM1_SIZE_Y / 2, BOOM1_SIZE_X, BOOM1_SIZE_Y, m_hBoomBmp[r]);
		SelectObject(hdcBmp, m_boom[c].hBmp);
		TransparentBlt(
			hdcBuffer, m_boom[c].pos.x, m_boom[c].pos.y + o * PERHEIGHT,
			m_boom[c].size.cx, m_boom[c].size.cy,
			hdcBmp, 0, m_boom[c].size.cy * boo, m_boom[b].size.cx, m_boom[b].size.cy,
			RGB(255,255,255)
		);
		boo++;
	}

	if(boo == 3 && boomyet == 0)
	{
		if(weapon == 0)
		{
		m_boom[c].status = 1;
		boo = 0;
		for(h=0;h<MAX_HERO_NUM;h++)
		{
			x = m_hero[h].pos.x + m_hero[h].size.cx / 2 - m_bomb[c].pos.x - BOMB1_SIZE_X / 2;
			y = m_hero[h].pos.y + m_hero[h].size.cy / 2 - m_bomb[c].pos.y - BOMB1_SIZE_Y / 2;
			if(x * x + y * y < HURT * HURT)
			{
				//伤害
				m_hero[h].life -= 100 - (x*x+y*y)/30; 
				if(m_hero[h].life < 0)
				{
					m_hero[h].life = 0;
				}
				//击飞
				m_hero[h].vel.x = 10 / (x+0.1);
				m_hero[h].vel.y = 10 / (y+0.1);
				m_hero[h].jump = 1;
			}
		}


			//瞄准镜恢复
			m_focus.status = 0;

			//控制权切换
			while(1)
			{
				c++;
				r = c % 6;
				if(m_hero[r].life != 0)
				{
					wind = -4 + rand() % 9;
					break;
				}
			}
			t = 0;
			weapon = 0;
			chosen = 0;
		}

		else if(weapon == 2)
		{
			boomyet = 1;
			for(h=0;h<MAX_HERO_NUM;h++)
		{
			x = m_hero[h].pos.x + m_hero[h].size.cx / 2 - m_bomb[c].pos.x - BOMB1_SIZE_X / 2;
			y = m_hero[h].pos.y + m_hero[h].size.cy / 2 - m_bomb[c].pos.y - BOMB1_SIZE_Y / 2;
			if(x * x + y * y < HURT * HURT)
			{
				//伤害
				m_hero[h].life -= 100 - (x*x+y*y)/30; 
				if(m_hero[h].life < 0)
				{
					m_hero[h].life = 0;
				}
				//击飞
				m_hero[h].vel.x = 10 / (x+0.1);
				m_hero[h].vel.y = 10 / (y+0.1);
				m_hero[h].jump = 1;
			}
		}
		}
	}

	if(boomyet == 1)
	{
		//创建弹坑
		m_boom[c] = CreateBoom(m_bomb[c].pos.x + BOMB1_SIZE_X / 2 - BOOM1_SIZE_X / 2, m_bomb[c].pos.y + BOMB1_SIZE_Y / 2 - BOOM1_SIZE_Y / 2, BOOM1_SIZE_X, BOOM1_SIZE_Y, m_hBoomBmp[r]);
		SelectObject(hdcBmp, m_boom[c].hBmp);
		TransparentBlt(
			hdcBuffer, m_boom[c].pos.x, m_boom[c].pos.y + o * PERHEIGHT,
			m_boom[c].size.cx, m_boom[c].size.cy,
			hdcBmp, 0, m_boom[c].size.cy * boo, m_boom[b].size.cx, m_boom[b].size.cy,
			RGB(255,255,255)
		);
		m_boom[c].status = 1;
	}

	if(r % 2 == 0 && m_planeH.pos.x > WNDWIDTH && boomyet == 1)
	{
		//瞄准镜恢复
			m_focus.status = 0;

			//控制权切换
			while(1)
			{
				c++;
				r = c % 6;
				if(m_hero[r].life != 0)
				{
					wind = -4 + rand() % 9;
					break;
				}
			}
			t = 0;
			weapon = 0;
			boomyet = 0;
			boo = 0;
			chosen = 0;
	}
	else if(r % 2 == 1 && m_planeT.pos.y + m_planeT.size.cy < 0 && boomyet == 1)
	{
		//瞄准镜恢复
			m_focus.status = 0;

			//控制权切换
			while(1)
			{
				c++;
				r = c % 6;
				if(m_hero[r].life != 0)
				{
					wind = -4 + rand() % 9;
					break;
				}
			}
			t = 0;
			weapon = 0;
			boomyet = 0;
			boo = 0;
			chosen = 0;
	}

	if(m_bomb[c].pos.y > WNDHEIGHT)
	{
		m_bomb[c].collision = 2;

		//瞄准镜恢复
		m_focus.status = 0;

		//控制权切换
		while(1)
		{
			c++;
			r = c % 6;
			if(m_hero[r].life != 0)
			{
				wind = -4 + rand() % 9;
				break;
			}
		}
		t = 0;
		weapon = 0;
		boo = 0;
		chosen = 0;
	}

	for (b = 0; b < c; b++)
	{
		if(m_boom[b].status == 1)
		{
		SelectObject(hdcBmp, m_boom[b].hBmp);
	TransparentBlt(
		hdcBuffer, m_boom[b].pos.x, m_boom[b].pos.y + o * PERHEIGHT,
		m_boom[b].size.cx, m_boom[b].size.cy,
		hdcBmp, 0, m_boom[b].size.cy * 3, m_boom[b].size.cx, m_boom[b].size.cy,
		RGB(255,255,255)
		);
		}
	}


	//绘制英雄
	for(h=0;h<MAX_HERO_NUM;h++)
	{
		//
		if(m_hero[h].pos.y > WNDHEIGHT - HERO_SIZE_Y - 10 && m_hero[h].life != 0)
		{
			m_hero[h].life = 0;
			if(h == r)
			{
				//控制权切换
				while(1)
				{
					c++;
					r = c % 6;
					if(m_hero[r].life != 0)
					{
						wind = -4 + rand() % 9;
						break;
					}
				}
				t = 0;
				weapon = 0;
				//瞄准镜恢复
				m_focus.status = 0;
				chosen = 0;
			}
		}
		
		if(moving == 0)
		{
			//判断碰撞
	
			m_hero[h].collision = 0;

			//拔起
			for(p = m_hero[h].pos.x + m_hero[h].size.cx / 3; p <= m_hero[h].pos.x + m_hero[h].size.cx * 2 / 3; p++)
			{
				if(GetPixel(hdc, p, m_hero[h].pos.y + m_hero[h].size.cy + 2) == TERRIAN_COLOR && 
					GetPixel(hdc, p, m_hero[h].pos.y + m_hero[h].size.cy + 1) == TERRIAN_COLOR)
				{
					while(GetPixel(hdc, p, m_hero[h].pos.y + m_hero[h].size.cy + 2) == TERRIAN_COLOR && 
					GetPixel(hdc, p, m_hero[h].pos.y + m_hero[h].size.cy + 1) == TERRIAN_COLOR)
					{
						m_hero[h].vel.y = 0;
						m_hero[h].pos.y--;
					}
					m_hero[h].collision = 1;
					m_hero[h].jump = 0;
				}
			}
		
			for(p = m_hero[h].pos.x + m_hero[h].size.cx / 3; p <= m_hero[h].pos.x + m_hero[h].size.cx * 2 / 3; p++)
			{
				if(GetPixel(hdc, p, m_hero[h].pos.y + m_hero[h].size.cy + 2) == TERRIAN_COLOR)
				{
					m_hero[h].collision = 2;
				}
				else if(GetPixel(hdc, p, m_hero[h].pos.y + m_hero[h].size.cy + 2) == CLR_INVALID)
				{
					m_hero[h].vel.x = 0;
					m_hero[h].vel.y = 0;
				}
			}

			if(m_hero[h].collision == 2 && m_hero[h].jump == 0)
				m_hero[h].vel.y = 0;

			//左边
			for(p = m_hero[h].pos.y; p <= m_hero[h].pos.y + m_hero[h].size.cy * 3 / 5; p++)
			{
				if(GetPixel(hdc, m_hero[h].pos.x-1, p) == TERRIAN_COLOR && m_hero[h].vel.x < 0)
				{
					m_hero[h].vel.x = 0;
				}
			}
			//右边
			for(p = m_hero[h].pos.y; p <= m_hero[h].pos.y + m_hero[h].size.cy * 3 / 5; p++)
			{
				if(GetPixel(hdc, m_hero[h].pos.x + m_hero[h].size.cx+1, p) == TERRIAN_COLOR && m_hero[h].vel.x > 0)
				{
					m_hero[h].vel.x = 0;
				}
			}

			//更新HERO状态

			m_hero[h].pos.x += m_hero[h].vel.x;
			m_hero[h].pos.y += m_hero[h].vel.y;
			m_hero[h].vel.y += GRAVITY;
			if(m_hero[h].vel.y > MAX_VEL_Y)
			{
				m_hero[h].vel.y--;
			}
			if(m_hero[h].vel.y < -MAX_VEL_Y)
			{
				m_hero[h].vel.y++;
			}
			if(m_hero[h].vel.x > MAX_VEL_X)
			{
				m_hero[h].vel.x--;
			}
			if(m_hero[h].vel.x < -MAX_VEL_X)
			{
				m_hero[h].vel.x++;
			}
			
		}

		if(m_hero[h].life == 0)
		{
			// 绘制Tomb到缓存
			SelectObject(hdcBmp, m_tomb[h].hBmp);
			TransparentBlt(
				hdcBuffer, m_hero[h].pos.x, m_hero[h].pos.y+18,
				27, 22,
				hdcBmp, 0, 0, 273, 220,
				RGB(255,255,255)
			);
		}
		else
		{
			// 绘制Hero到缓存
			SelectObject(hdcBmp, m_hero[h].hBmp);
			TransparentBlt(
				hdcBuffer, m_hero[h].pos.x, m_hero[h].pos.y,
				m_hero[h].size.cx, m_hero[h].size.cy,
				hdcBmp, 0, m_hero[h].step * 800, 600, 800,
				RGB(255,255,255)
			);
		}
	}

	// 绘制Arrow到缓存
			SelectObject(hdcBmp, m_arrow[r].hBmp);
			TransparentBlt(
				hdcBuffer, m_hero[r].pos.x + HERO_SIZE_X / 2 - ARROW_SIZE_X / 2, m_hero[r].pos.y - HEIGHT - (t % 9),
				m_arrow[r].size.cx, m_arrow[r].size.cy,
				hdcBmp, 0, 0, 1024, 768,
				RGB(255,255,255)
				);

	//绘制炸弹
	if(m_bomb[c].collision == 1 && weapon == 0)
	{

		SelectObject(hdcBuffer, GetStockObject(NULL_PEN));
		HBRUSH bombBrush = CreateSolidBrush(MULTYCOLOR[r]);
		SelectObject(hdcBuffer, bombBrush);
		Bomb *bomb = &m_bomb[c];
		Ellipse(hdcBuffer, m_bomb[c].pos.x, m_bomb[c].pos.y,
				m_bomb[c].pos.x + m_bomb[c].size.cx, m_bomb[c].pos.y + m_bomb[c].size.cy);
		DeleteObject(bombBrush);
	}

	if(m_focus.status == 1 && weapon == 0)
	{
		//创建瞄准器
		m_focus = CreateFocus(m_hero[r].pos.x + HERO_SIZE_X / 2 - FOCUS_SIZE_X / 2 + m_focus.pos.x,  m_hero[r].pos.y + HERO_SIZE_X / 2 - FOCUS_SIZE_Y / 2 - m_focus.pos.y, FOCUS_SIZE_X, FOCUS_SIZE_Y, m_hFocusBmp);
		// 绘制瞄准器到缓存
		SelectObject(hdcBmp, m_focus.hBmp);
		TransparentBlt(
			hdcBuffer, m_focus.pos.x, m_focus.pos.y,
			m_focus.size.cx, m_focus.size.cy,
			hdcBmp, 0, 0, 300, 300,
			RGB(255,255,255)
		);
	}

	if(weapon == 1 || (weapon == 2 && go == 0))
	{
		//创建瞬移
		m_biu = CreateBiu(m_hero[r].pos.x + HERO_SIZE_X / 2 - BIU_SIZE_X / 2 + biux,  m_hero[r].pos.y + BIU_SIZE_X / 2 - BIU_SIZE_Y / 2 + biuy, BIU_SIZE_X, BIU_SIZE_Y, m_hBiuBmp);
		// 绘制瞬移到缓存
		SelectObject(hdcBmp, m_biu.hBmp);
		TransparentBlt(
			hdcBuffer, m_biu.pos.x, m_biu.pos.y,
			m_biu.size.cx, m_biu.size.cy,
			hdcBmp, 0, 0, 30, 30,
			RGB(255,255,255)
		);
	}

	if(weapon == 2 && go == 1)
	{
		if(r % 2 == 0)
		{
			// 绘制轰炸机到缓存
			SelectObject(hdcBmp, m_planeH.hBmp);
			TransparentBlt(
				hdcBuffer, m_planeH.pos.x, m_planeH.pos.y,
				m_planeH.size.cx, m_planeH.size.cy,
				hdcBmp, 0, 0, 340, 255,
				RGB(255,255,255)
			);

			x = - m_planeH.pos.x - PLANE_SIZE_X / 2 + m_biu.pos.x + BIU_SIZE_X / 2;
			y = - m_planeH.pos.y - PLANE_SIZE_Y / 2 + m_biu.pos.y + BIU_SIZE_Y / 2;

			if(x * x * GRAVITY < 2 * FLY_VEL * FLY_VEL * y)
			{
				//绘制炸弹
				SelectObject(hdcBuffer, GetStockObject(NULL_PEN));
				HBRUSH bombBrush = CreateSolidBrush(MULTYCOLOR[1]);
				SelectObject(hdcBuffer, bombBrush);
				Bomb *bomb = &m_bomb[c];
				Ellipse(hdcBuffer, m_bomb[c].pos.x, m_bomb[c].pos.y,
					m_bomb[c].pos.x + m_bomb[c].size.cx, m_bomb[c].pos.y + m_bomb[c].size.cy);
				DeleteObject(bombBrush);
				dir = 1;
			}
		}
		else
		{
			// 绘制直升机到缓存
			SelectObject(hdcBmp, m_planeT.hBmp);
			TransparentBlt(
				hdcBuffer, m_planeT.pos.x, m_planeT.pos.y,
				m_planeT.size.cx, m_planeT.size.cy,
				hdcBmp, 0, 0, 340, 255,
				RGB(255,255,255)
			);

			if(m_planeT.pos.x + m_planeT.size.cx / 2 < m_biu.pos.x + BIU_SIZE_X / 2)
			{
				//绘制炸弹
				SelectObject(hdcBuffer, GetStockObject(NULL_PEN));
				HBRUSH bombBrush = CreateSolidBrush(MULTYCOLOR[1]);
				SelectObject(hdcBuffer, bombBrush);
				Bomb *bomb = &m_bomb[c];
				Ellipse(hdcBuffer, m_bomb[c].pos.x, m_bomb[c].pos.y,
					m_bomb[c].pos.x + m_bomb[c].size.cx, m_bomb[c].pos.y + m_bomb[c].size.cy);
				DeleteObject(bombBrush);
				dir = 1;
			}
		}
	}


	//绘制蓄力
	if(m_force.status == 1)
	{
		//
		m_force = CreateForce(m_hero[r].pos.x + m_hero[r].size.cx / 2, m_hero[r].pos.y, m_focus.pos.x, m_focus.pos.y, m_force.size.cx, m_force.size.cy, NULL);
		//
		SelectObject(hdcBuffer, GetStockObject(NULL_PEN));
		HBRUSH forceBrush = CreateSolidBrush(RGB(209, 0, 11));
		SelectObject(hdcBuffer, forceBrush);
		Force force = m_force;
		Pie(hdcBuffer, m_force.pos.x - m_force.size.cx, m_force.pos.y - m_force.size.cy, m_force.pos.x + m_force.size.cx, m_force.pos.y + m_force.size.cy,
			m_force.pos.x + (int)(FOCUS_R * sin((alpha+10) * PI / 180)), m_force.pos.y - (int)(FOCUS_R * cos((alpha+10) * PI / 180)),m_force.pos.x + (int)(FOCUS_R * sin((alpha-10) * PI / 180)), m_force.pos.y - (int)(FOCUS_R * cos((alpha-10) * PI / 180)));
		DeleteObject(forceBrush);

	}

	//绘制血条
	SelectObject(hdcBuffer, GetStockObject(NULL_PEN));
	for (h = 0; h < MAX_HERO_NUM; h++)
	{
		Life *life= &m_life[h];
		if(h % 2 == 0)
		{
			HBRUSH lifeBrush1 = CreateSolidBrush(HERO_COLOR61);
			SelectObject(hdcBuffer, lifeBrush1);
			Rectangle(hdcBuffer, (2*m_hero[h].pos.x + m_hero[h].size.cx - life->size.cx)/2, m_hero[h].pos.y + life->pos.y,
				(2*m_hero[h].pos.x + m_hero[h].size.cx - life->size.cx)/2 + (double)m_hero[h].life / 100 * life->size.cx, m_hero[h].pos.y + life->pos.y + life->size.cy);
			DeleteObject(lifeBrush1);
		}
		else
		{
			HBRUSH lifeBrush2 = CreateSolidBrush(HERO_COLOR62);
			SelectObject(hdcBuffer, lifeBrush2);
			Rectangle(hdcBuffer, (2*m_hero[h].pos.x + m_hero[h].size.cx - life->size.cx)/2, m_hero[h].pos.y + life->pos.y,
				(2*m_hero[h].pos.x + m_hero[h].size.cx - life->size.cx)/2 + (double)m_hero[h].life / 100 * life->size.cx, m_hero[h].pos.y + life->pos.y + life->size.cy);
			DeleteObject(lifeBrush2);
		}
	}

	

	ora = 0;
	gre = 0;
	for(h = 0; h < MAX_HERO_NUM; h++)
	{
		if(m_hero[h].life == 0 && h % 2 == 0)
			ora++;
		else if(m_hero[h].life == 0 && h % 2 == 1)
			gre++;
	}

	if(ora == 3)
	{
		winner = 0;
		gameStatus.status = 3;
	}
	else if(gre == 3)
	{
		winner = 1;
		gameStatus.status = 3;
	}

	// 绘制分数
	TCHAR	szDist[13];
	SetTextColor(hdcBuffer, RGB(209, 0, 11));
	SetBkMode(hdcBuffer, TRANSPARENT);
	wsprintf(szDist, _T("%d : %d"), ora, gre);
	TextOut(hdcBuffer, WNDWIDTH - 100, 15, szDist, _tcslen(szDist));

	//绘制海洋

	SelectObject(hdcBmp, m_ocean.hBmp);
	TransparentBlt(
		hdcBuffer, m_ocean.pos.x,m_ocean.pos.y,
		m_ocean.size.cx, m_ocean.size.cy,
		hdcBmp, 0, 0, OCEAN_SIZE_X, OCEAN_SIZE_Y,
		RGB(255,255,255)
	);

	// 绘倒计时到缓存
	SelectObject(hdcBmp, m_clock[30-(t/50)].hBmp);
	TransparentBlt(
		hdcBuffer, m_clock[30-(t/50)].pos.x, m_clock[30-(t/50)].pos.y,
		m_clock[30-(t/50)].size.cx, m_clock[30-(t/50)].size.cy,
		hdcBmp, 0, 0, 1024, 768,
		RGB(255,255,255)
	);

	// 最后将所有的信息绘制到屏幕上
	BitBlt(hdc, 0, 0, WNDWIDTH, WNDHEIGHT, hdcBuffer, 0, 0, SRCCOPY);

	

	// 回收资源所占的内存
	DeleteObject(cptBmp);
	DeleteDC(hdcBuffer);
	DeleteDC(hdcBmp);

	// 结束绘制
	EndPaint(hWnd, &ps);
}


VOID TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	if(pausing == 0)
	{
		if(t / 50 == 30)
		{
			//控制权切换
			while(1)
			{
				c++;
				r = c % 6;
				if(m_hero[r].life != 0)
				{
					wind = -4 + rand() % 9;
					break;
				}
			}
			t = 0;
		}
		else
		{
			t++;
		}
		TerrianUpdate();
		CloudUpdate();
		PlaneUpdate();
		LifeUpdate();
		HeroUpdate();
		BombUpdate();
		FocusUpdate();
		BiuUpdate();
		GameStatusUpdate();
		InvalidateRect(hWnd, NULL, FALSE);
	}
}




VOID HeroUpdate()
{
	//m_hero.step = (m_hero.step + 1) % 3;
	buffer2++;
	if(buffer2 > 3*ZHEN)
		buffer2 = 0;

	if(m_hero[r].step == 5)
		m_hero[r].step = 0;
	else if(buffer2 >= ZHEN && m_hero[r].step == 4)
	{
		m_hero[r].step = 5;
		//创建炸弹
		if(m_force.status == 1 && weapon == 0)
		{
		m_bomb[c] = CreateBomb(m_bomb[c].pos.x, m_bomb[c].pos.y, BOMB1_SIZE_X, BOMB1_SIZE_Y, NULL);
		chosen = 1;	
		m_bomb[c].collision = 1;
		m_bomb[c].vel.x = (int)(BOMB1_VEL * sin(alpha * PI / 180) * m_force.size.cx);
		m_bomb[c].vel.y = -(int)(BOMB1_VEL * cos(alpha * PI / 180) * m_force.size.cy);
		m_force.size.cx = 0;
		m_force.size.cy = 0;
		}
		m_force.status = 0;
	}
	else if(m_hero[r].step == 7)
		m_hero[r].step = 2;
	else if(buffer2 >= ZHEN && m_hero[r].step == 6)
	{
		m_hero[r].step = 7;
		//创建炸弹
		if(m_force.status == 1 && weapon == 0)
		{
		m_bomb[c] = CreateBomb(m_bomb[c].pos.x, m_bomb[c].pos.y, BOMB1_SIZE_X, BOMB1_SIZE_Y, NULL);
		chosen = 1;	
		m_bomb[c].collision = 1;
		m_bomb[c].vel.x = (int)(BOMB1_VEL * sin(alpha * PI / 180) * m_force.size.cx);
		m_bomb[c].vel.y = -(int)(BOMB1_VEL * cos(alpha * PI / 180) * m_force.size.cy);
		m_force.size.cx = 0;
		m_force.size.cy = 0;
		}
		m_force.status = 0;
	}

		

	// TODO
	//更新英雄位置、动作
}

VOID LifeUpdate()
{
	//
}

VOID TerrianUpdate() 
{
	// TODO
	if(moving == 0)
	{
		for(h = 0; h < MAX_HERO_NUM; h++)
		{
			if(m_hero[h].jump == 1)
			{
				flying = 1;
				f = h;
			}
		}
		if(flying == 1 && (m_hero[f].pos.x + m_hero[f].size.cx / 2 < WNDWIDTH / 4) && m_hero[f].life != 0)
		{
			m_terrian[city].pos.x += PER;
			for(h = 0; h < MAX_HERO_NUM; h++)
			{
				m_hero[h].pos.x += PER;
//				m_hero[h].vel.y = 0;
			}
			for(h = 0; h <= c; h++)
			{
				m_boom[h].pos.x += PER;
			}
		}
		else if(weapon == 1 && m_biu.pos.x < WNDWIDTH * 1 / 4)
		{
			m_terrian[city].pos.x += PER;
			for(h = 0; h < MAX_HERO_NUM; h++)
			{
				m_hero[h].pos.x += PER;
//				m_hero[h].vel.y = 0;
			}
			for(h = 0; h <= c; h++)
			{
				m_boom[h].pos.x += PER;
			}
		}
		else if(weapon == 1 && m_biu.pos.x > WNDWIDTH * 3 / 4)
		{
			m_terrian[city].pos.x -= PER;
			for(h = 0; h < MAX_HERO_NUM; h++)
			{
				m_hero[h].pos.x -= PER;
//				m_hero[h].vel.y = 0;
			}
			for(h = 0; h <= c; h++)
			{
				m_boom[h].pos.x -= PER;
			}
		}
		else if(flying == 1 && (m_hero[f].pos.x + m_hero[f].size.cx / 2 > WNDWIDTH * 3 / 4) && m_hero[f].life != 0)
		{
			m_terrian[city].pos.x -= PER;
			for(h = 0; h < MAX_HERO_NUM; h++)
			{
				m_hero[h].pos.x -= PER;
//				m_hero[h].vel.y = 0;
			}
			for(h = 0; h <= c; h++)
			{
				m_boom[h].pos.x -= PER;
			}
		}
		else if(m_hero[r].pos.x + m_hero[r].size.cx / 2 < WNDWIDTH / 4 && m_bomb[c].collision != 1 && weapon == 0)
		{
			m_terrian[city].pos.x += PER;
			for(h = 0; h < MAX_HERO_NUM; h++)
			{
				m_hero[h].pos.x += PER;
//				m_hero[h].vel.y = 0;
			}
			for(h = 0; h <= c; h++)
			{
				m_boom[h].pos.x += PER;
			}
		}
		else if(m_hero[r].pos.x + m_hero[r].size.cx / 2 > WNDWIDTH * 3 / 4 && m_bomb[c].collision != 1 && weapon == 0)
		{
			m_terrian[city].pos.x -= PER;
			for(h = 0; h < MAX_HERO_NUM; h++)
			{
				m_hero[h].pos.x -= PER;
//				m_hero[h].vel.y = 0;
			}
			for(h = 0; h <= c; h++)
			{
				m_boom[h].pos.x -= PER;
			}
		}
		else if((m_bomb[c].pos.x < WNDWIDTH * 1 / 4 || m_bomb[c].pos.x > WNDWIDTH * 3 / 4) && m_bomb[c].collision == 1)
		{
			m_terrian[city].pos.x -= m_bomb[c].vel.x;
			for(h = 0; h < MAX_HERO_NUM; h++)
			{
				m_hero[h].pos.x -= m_bomb[c].vel.x;
//				m_hero[h].vel.y = 0;
			}
			for(h = 0; h <= c; h++)
			{
				m_boom[h].pos.x -= m_bomb[c].vel.x;
			}
		}
		else if(weapon != 0 && m_biu.pos.x < WNDWIDTH / 4)
		{
			m_terrian[city].pos.x += PER;
			for(h = 0; h < MAX_HERO_NUM; h++)
			{
				m_hero[h].pos.x += PER;
//				m_hero[h].vel.y = 0;
			}
			for(h = 0; h <= c; h++)
			{
				m_boom[h].pos.x += PER;
			}
		}
		else if(weapon != 0 && m_biu.pos.x > WNDWIDTH * 3 / 4)
		{
			m_terrian[city].pos.x -= PER;
			for(h = 0; h < MAX_HERO_NUM; h++)
			{
				m_hero[h].pos.x -= PER;
//				m_hero[h].vel.y = 0;
			}
			for(h = 0; h <= c; h++)
			{
				m_boom[h].pos.x -= PER;
			}
		}
		flying = 0;
	}
	//更新地形
}

VOID CloudUpdate()
{
	if(m_wind1.pos.x > WNDWIDTH || m_wind2.pos.x < -CLOUD_SIZE_X || cloudvel == 0)
	{
		cloudvel = wind;
		m_wind1.pos.x = -CLOUD_SIZE_X;
		m_wind2.pos.x = WNDWIDTH;
	}
	if(cloudvel > 0)
	{
		m_wind1.pos.x += cloudvel;
	}
	else if(cloudvel < 0)
	{
		m_wind2.pos.x += cloudvel;
	}
}

VOID BoomUpdate()
{
	//m_boom[c].pos.x = m_bomb[c].pos.x;
	//m_boom[c].pos.y = m_bomb[c].pos.y;
}

VOID BombUpdate()
{
	if(weapon == 0)
	{
		switch(m_bomb[c].collision)
		{
		case 0:
			m_bomb[c].pos.x = m_hero[r].pos.x + m_hero[r].size.cx / 2;
			m_bomb[c].pos.y = m_hero[r].pos.y + m_hero[r].size.cy / 2;
			break;
		case 1:
			m_bomb[c].pos.x = m_bomb[c].pos.x + m_bomb[c].vel.x;
			m_bomb[c].pos.y = m_bomb[c].pos.y + m_bomb[c].vel.y;
			m_bomb[c].vel.x += cloudvel / 4;
			m_bomb[c].vel.y += GRAVITY;
			if(m_bomb[c].vel.x > MAX_VEL_X)
			{
				m_bomb[c].vel.x--;
			}
			if(m_bomb[c].vel.x < -MAX_VEL_X)
			{
				m_bomb[c].vel.x++;
			}
			if(m_bomb[c].vel.y > MAX_VEL_Y)
			{
				m_bomb[c].vel.y--;
			}
			if(m_bomb[c].vel.y < -MAX_VEL_Y)
			{
				m_bomb[c].vel.y++;
			}
			break;
		case 2:
			break;
		default:
			break;
		}
	}
	else if(weapon == 2 && boomyet == 0 && boo == 0)
	{
		if(r % 2 == 0)
		{
			if(dir == 0)
			{
				m_bomb[c].pos.x = m_planeH.pos.x + m_planeH.size.cx / 2;
				m_bomb[c].pos.y = m_planeT.pos.y + m_planeH.size.cy / 2;
				m_bomb[c].vel.x = FLY_VEL;
				m_bomb[c].vel.y = 0;
			}
			else
			{
				m_bomb[c].collision = 1;
				m_bomb[c].pos.x = m_bomb[c].pos.x + m_bomb[c].vel.x;
				m_bomb[c].pos.y = m_bomb[c].pos.y + m_bomb[c].vel.y;
				m_bomb[c].vel.x += cloudvel / 4;
				m_bomb[c].vel.y += GRAVITY;
				if(m_bomb[c].vel.x > MAX_VEL_X)
				{
					m_bomb[c].vel.x--;
				}
				if(m_bomb[c].vel.x < -MAX_VEL_X)
				{
					m_bomb[c].vel.x++;
				}
				if(m_bomb[c].vel.y > MAX_VEL_Y)
				{
					m_bomb[c].vel.y--;
				}
				if(m_bomb[c].vel.y < -MAX_VEL_Y)
				{
					m_bomb[c].vel.y++;
				}
			}
		}
		else
		{
			if(dir == 0)
			{
				m_bomb[c].pos.x = m_planeT.pos.x + m_planeT.size.cx / 2;
				m_bomb[c].pos.y = m_planeT.pos.y + m_planeT.size.cy / 2;
				m_bomb[c].vel.y = 0;
			}
			else
			{
				m_bomb[c].collision = 1;
				m_bomb[c].vel.y += GRAVITY;
				m_bomb[c].pos.y = m_bomb[c].pos.y + m_bomb[c].vel.y;
				if(m_bomb[c].vel.x > MAX_VEL_X)
				{
					m_bomb[c].vel.x--;
				}
				if(m_bomb[c].vel.x < -MAX_VEL_X)
				{
					m_bomb[c].vel.x++;
				}
				if(m_bomb[c].vel.y > MAX_VEL_Y)
				{
					m_bomb[c].vel.y--;
				}
				if(m_bomb[c].vel.y < -MAX_VEL_Y)
				{
					m_bomb[c].vel.y++;
				}
			}
		}
	}
}

VOID FocusUpdate()
{
	m_focus.pos.x = (int)(FOCUS_R * sin(alpha * PI / 180));
	m_focus.pos.y = (int)(FOCUS_R * cos(alpha * PI / 180));
}

VOID BiuUpdate()
{
	if(m_biu.pos.y < 0) m_biu.pos.y = 0;
	else if(m_biu.pos.y > WNDWIDTH) m_biu.pos.y = WNDWIDTH;
}

VOID PlaneUpdate()
{
	if(weapon == 2 && go == 1 && r % 2 == 0)
	{
		m_planeH.pos.x += m_planeH.vel.x;
	}
	else if(weapon == 2 && go == 1 && r % 2 == 1)
	{
		if(dir == 0)
		{
			m_planeT.pos.x += m_planeT.vel.x;
		}
		else
		{
			m_planeT.pos.y--;
		}
	}
}

VOID GameStatusUpdate()
{
	// TODO

	//更新游戏状态
}

BOOL ButtonClicked(POINT ptMouse, POINT buttonPos, SIZE buttonSize)
{
	RECT rectButton;
	rectButton.left = buttonPos.x;
	rectButton.top = buttonPos.y;
	rectButton.right = buttonPos.x + buttonSize.cx;
	rectButton.bottom = buttonPos.y + buttonSize.cy;

	return PtInRect(&rectButton, ptMouse);
}

VOID KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	// TODO
	switch (wParam)
	{
	case 'W':	
		if(r % 2 == 0)
		{
		if(m_hero[r].collision != 0 && weapon == 0)
		{
			m_hero[r].vel.y = -HERO_VEL_Y;
			m_hero[r].jump = 1;
		}
		}
		break;
	case 'A':
		if(r % 2 == 0)
		{
		if(m_focus.status == 1)
		{
			alpha--;
		}
		else if(weapon == 0 && chosen == 0)
		{
		m_hero[r].vel.x = -HERO_VEL_X;
		buffer++;
		if(buffer >= ZHEN)
		{
			buffer = 0;
			switch(m_hero[r].step)
			{
			case 2:
				m_hero[r].step = 3;
				break;
			case 0:
			case 3:
				m_hero[r].step = 2;
				break;
			default:
				break;
			}
		}
		}
		}
		break;
	case 'D':
		if(r % 2 == 0)
		{
		if(m_focus.status == 1)
		{
			alpha++;
		}
		else if(weapon == 0 && chosen == 0)
		{
			m_hero[r].vel.x = HERO_VEL_X;
			buffer++;
			if(buffer >= ZHEN)
			{
				buffer = 0;
				switch(m_hero[r].step)
				{
				case 0:
					m_hero[r].step = 1;
					break;
				case 1:
				case 2:
					m_hero[r].step = 0;
					break;
				default:
					break;
				}
			}
		}
		}
		break;
	case 'F':
		if(r % 2 == 0)
		{
		m_focus.status = 1 - m_focus.status;
		alpha = 0;
		}
		break;
	case 'I':
		if(r % 2 == 1)
		{
		if(m_hero[r].collision != 0 && weapon == 0)
		{
			m_hero[r].vel.y = -HERO_VEL_Y;
			m_hero[r].jump = 1;
		}
		}
		break;
	case 'J':
		if(r % 2 == 1)
		{
		if(m_focus.status == 1)
		{
			alpha--;
		}
		else if(weapon == 0 && chosen == 0)
		{
		m_hero[r].vel.x = -HERO_VEL_X;
		buffer++;
		if(buffer >= ZHEN)
		{
			buffer = 0;
			switch(m_hero[r].step)
			{
			case 2:
				m_hero[r].step = 3;
				break;
			case 0:
			case 3:
				m_hero[r].step = 2;
				break;
			default:
				break;
			}
		}
		}
		}
		break;
	case 'L':
		if(r % 2 == 1)
		{
		if(m_focus.status == 1)
		{
			alpha++;
		}
		else if(weapon == 0 && chosen == 0)
		{
			m_hero[r].vel.x = HERO_VEL_X;
			buffer++;
			if(buffer >= ZHEN)
			{
				buffer = 0;
				switch(m_hero[r].step)
				{
				case 0:
					m_hero[r].step = 1;
					break;
				case 1:
				case 2:
					m_hero[r].step = 0;
					break;
				default:
					break;
				}
			}
		}
		}
		break;
	case 'H':
		if(r % 2 == 1)
		{
		m_focus.status = 1 - m_focus.status;
		alpha = 0;
		}
		break;
	case ' ':
		if(weapon == 0)
		{
			if(m_hero[r].jump == 0)
			{
				if(m_force.size.cx < MAX_FORCE && m_force.status != 2)
				{
				m_force.status = 1;
				m_force.size.cx++;
				m_force.size.cy++;
				}
				else if(m_force.status == 1)
				{
				m_bomb[c] = CreateBomb(m_bomb[c].pos.x, m_bomb[c].pos.y, BOMB1_SIZE_X, BOMB1_SIZE_Y, NULL);
				m_bomb[c].collision = 1;
				m_bomb[c].vel.x = (int)(BOMB1_VEL * sin(alpha * PI / 180) * m_force.size.cx);
				m_bomb[c].vel.y = -(int)(BOMB1_VEL * cos(alpha * PI / 180) * m_force.size.cy);
				m_force.status = 2;
				m_force.size.cx = 0;
				m_force.size.cy = 0;
				chosen = 1;	
				}
			}
		}
		else if(weapon == 1)
		{
			m_hero[r].pos = m_biu.pos;
			biux = 0;
			biuy = 0;
			m_focus.status = 0;
			//控制权切换
			while(1)
			{
				c++;
				r = c % 6;
				if(m_hero[r].life != 0)
				{
					wind = -4 + rand() % 9;
					break;
				}
			}
			t = 0;
			chosen = 0;
			weapon = 0;
		}
		else if(weapon == 2 && chosen == 0)
		{
			chosen = 1;
			go = 1;
			dir = 0;
			boomyet = 0;
			m_planeH.pos.x = -m_planeH.size.cx;
			m_planeT.pos.x = WNDWIDTH;
			m_planeT.pos.y = FLY_HEIGHT;
			//创建炸弹
			m_bomb[c] = CreateBomb(m_bomb[c].pos.x, m_bomb[c].pos.y, BOMB1_SIZE_X, BOMB1_SIZE_Y, NULL);
			if(r % 2 == 0)
			{
				m_planeH.vel.x = FLY_VEL;
			}
			else if(r % 2 == 1)
			{
				m_planeT.vel.x = -FLY_VEL;
			}
		}
		break;
	case VK_RIGHT:
		if(weapon == 0)
		{
			moving = 1;
			m_terrian[city].pos.x--;
			for(h = 0; h < MAX_HERO_NUM; h++)
				{
			m_hero[h].pos.x--;
//				m_hero[h].vel.y = 0;
			}
			for(h = 0; h < c; h++)
			{
				m_boom[h].pos.x--;
			}
		}
		else if(weapon == 1 || weapon == 2)
		{
			biux += 2;
		}
		break;
	case VK_LEFT:
		if(weapon == 0)
		{
			moving = 1;
			m_terrian[city].pos.x++;
			for(h = 0; h < MAX_HERO_NUM; h++)
			{
				m_hero[h].pos.x++;
//				m_hero[h].vel.y = 0;
			}
			for(h = 0; h <= c; h++)
			{
				m_boom[h].pos.x++;
			}
		}
		else if(weapon == 1 || weapon == 2)
		{
			biux -= 2;
		}
		break;
	case VK_UP:
		biuy -= 2;
		break;
	case VK_DOWN:
		biuy += 2;
		break;
	case VK_TAB:
		if(chosen == 0)
		{
		//控制权切换
		while(1)
		{
			c++;
			r = c % 6;
			if(m_hero[r].life != 0)
			{
				wind = -4 + rand() % 9;
				break;
			}
		}
		t = 0;
		weapon = 0;
		chosen = 0;
		}
		break;
	case 'P':
		if(pausing == 0)
		{
			pausing = 1;
			gameStatus.status = 51;
			InvalidateRect(hWnd, NULL, TRUE);//第三个参数设为TRUE，重画整个画布。
			mciSendString(TEXT("pause bgm"), NULL, 0, NULL);
		}
		else if(pausing == 1)
		{
			pausing = 0;
			gameStatus.status = 2;
			InvalidateRect(hWnd, NULL, TRUE);//第三个参数设为TRUE，重画整个画布。
			mciSendString(TEXT("resume bgm"), NULL, 0, NULL);
		}
		break;
	case '1':
		if(chosen == 0)
		{
		weapon = 0;
		boo = 0;
		}
		break;
	case '2':
		if(chosen == 0)
		{
		weapon = 1;
		}
		biux = 0;
		biuy = 0;
		m_focus.status = 0;
		break;
	case '3':
		if(chosen == 0)
		{
		weapon = 2;
		boo = 0;
		dir = 0;
		go = 0;
		boomyet = 0;
		m_planeH.pos.x = -m_planeH.size.cx;
		m_planeT.pos.x = WNDWIDTH;
		m_planeT.pos.y = FLY_HEIGHT;
		}
		biux = 0;
		biuy = 0;
	//	m_focus.status = 0;
		break;
	default:
		break;
	}
}

VOID KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	// TODO
	switch (wParam)
	{
	case 'A':
		if(r % 2 == 0)
		{
		m_hero[r].vel.x = 0;
		m_hero[r].step = 2;
		}
		break;
	case 'D':
		if(r % 2 == 0)
		{
		m_hero[r].vel.x = 0;
		m_hero[r].step = 0;
		}
		break;
	case 'J':
		if(r % 2 == 1)
		{
		m_hero[r].vel.x = 0;
		m_hero[r].step = 2;
		}
		break;
	case 'L':
		if(r % 2 == 1)
		{
		m_hero[r].vel.x = 0;
		m_hero[r].step = 0;
		}
		break;
	case ' ':
		if(weapon == 0 && chosen == 0)
		{
			if(m_hero[r].step == 0 || m_hero[r].step == 1)
			{
				buffer2 = 0;
				m_hero[r].step = 4;
			}
			else if(m_hero[r].step == 2 || m_hero[r].step == 3)
			{
				buffer2 = 0;
				m_hero[r].step = 6;
			}
				
		}
		break;
	case VK_LEFT:
		moving = 0;
	case VK_RIGHT:
		moving = 0;
	default:
		break;
	}
}

VOID LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	POINT ptMouse; // 鼠标点击的坐标
	ptMouse.x = LOWORD(lParam);
	ptMouse.y = HIWORD(lParam);

	//如果点击了游戏开始图标
	if (gameStatus.status == 0 && ButtonClicked(ptMouse, m_gameStartButton.pos, m_gameStartButton.size))
	{
		

		// 更改游戏状态
		gameStatus.status = 41;
		m_gameStartButton.status = 1;

		InvalidateRect(hWnd, NULL, TRUE);//第三个参数设为TRUE，重画整个画布。
	}

	
	//如果点击了游戏帮助图标
	if (gameStatus.status == 0 && ButtonClicked(ptMouse, m_gameHelpButton.pos, m_gameHelpButton.size))
	{

		// 更改游戏状态
		gameStatus.status = 31;
		m_gameHelpButton.status = 1;

		InvalidateRect(hWnd, NULL, TRUE);//第三个参数设为TRUE，重画整个画布。
	}

	//如果点击了游戏帮助中返回主菜单图标
	if (gameStatus.status == 32 && ButtonClicked(ptMouse, m_gameBackButton1.pos, m_gameBackButton1.size))
	{

		// 更改游戏状态
		gameStatus.status = 33;
		m_gameBackButton1.status = 1;

		InvalidateRect(hWnd, NULL, TRUE);//第三个参数设为TRUE，重画整个画布。
	}

	//如果点击了地图选择中返回主菜单图标
	if (gameStatus.status == 42 && ButtonClicked(ptMouse, m_gameBackButton3.pos, m_gameBackButton3.size))
	{

		// 更改游戏状态
		gameStatus.status = 43;
		m_gameBackButton3.status = 1;

		InvalidateRect(hWnd, NULL, TRUE);//第三个参数设为TRUE，重画整个画布。
	}

	//如果点击了地图选择中纽约图标
	if (gameStatus.status == 42 && ButtonClicked(ptMouse, m_gameNYButton.pos, m_gameNYButton.size))
	{

		// 更改游戏状态
		gameStatus.status = 45;
		m_gameNYButton.status = 1;

		InvalidateRect(hWnd, NULL, TRUE);//第三个参数设为TRUE，重画整个画布。
	}

	//如果点击了地图选择中泰姬陵图标
	if (gameStatus.status == 42 && ButtonClicked(ptMouse, m_gameTJButton.pos, m_gameTJButton.size))
	{

		// 更改游戏状态
		gameStatus.status = 44;
		m_gameTJButton.status = 1;

		InvalidateRect(hWnd, NULL, TRUE);//第三个参数设为TRUE，重画整个画布。
	}

	//如果点击了地图选择上海图标
	if (gameStatus.status == 42 && ButtonClicked(ptMouse, m_gameSHButton.pos, m_gameSHButton.size))
	{

		// 更改游戏状态
		gameStatus.status = 46;
		m_gameSHButton.status = 1;

		InvalidateRect(hWnd, NULL, TRUE);//第三个参数设为TRUE，重画整个画布。
	}

	//如果点击了暂停中的继续图标
	if (gameStatus.status == 51 && ButtonClicked(ptMouse, m_gameResumeButton.pos, m_gameResumeButton.size))
	{

		// 更改游戏状态
		gameStatus.status = 52;
		m_gameResumeButton.status = 1;
		pausing = 0;
		mciSendString(TEXT("resume bgm"), NULL, 0, NULL);

		InvalidateRect(hWnd, NULL, TRUE);//第三个参数设为TRUE，重画整个画布。
	}

	//如果点击了暂停中的返回主菜单图标
	if (gameStatus.status == 51 && ButtonClicked(ptMouse, m_gameBackButton4.pos, m_gameBackButton4.size))
	{

		// 更改游戏状态
		gameStatus.status = 53;
		m_gameBackButton4.status = 1;
		pausing = 0;

		InvalidateRect(hWnd, NULL, TRUE);//第三个参数设为TRUE，重画整个画布。
	}


	//如果点击了返回主菜单图标
	if (gameStatus.status == 3 && ButtonClicked(ptMouse, m_gameBackButton2.pos, m_gameBackButton2.size))
	{


		// 更改游戏状态
		gameStatus.status = 4;
		m_gameBackButton2.status = 1;

		InvalidateRect(hWnd, NULL, TRUE);//第三个参数设为TRUE，重画整个画布。
	}

	//如果点击了再来一局的图标
	if (gameStatus.status == 3 && ButtonClicked(ptMouse, m_gameAgainButton.pos, m_gameAgainButton.size))
	{


		// 更改游戏状态
		gameStatus.status = 6;
		m_gameAgainButton.status = 1;

		InvalidateRect(hWnd, NULL, TRUE);//第三个参数设为TRUE，重画整个画布。
	}

	
}
