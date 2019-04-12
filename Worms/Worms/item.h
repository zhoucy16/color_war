#ifndef ITEM_H
#define ITEM_H

#include "global.h"


//// 全局变量

// 声明位图句柄
HBITMAP m_hBackgroundBmp[2];
HBITMAP m_hTitleBmp;
HBITMAP m_hOceanBmp;
HBITMAP m_hTajiBmp;
HBITMAP m_hNewyorkBmp;
HBITMAP m_hShanghaiBmp;
HBITMAP m_hHeroBmp[6];
HBITMAP m_hArrowBmp[6];
HBITMAP m_hTombBmp;
HBITMAP m_hBoomBmp[11];
HBITMAP m_hFocusBmp;
HBITMAP m_hGameStartButtonBmp;
HBITMAP	m_hGameHelpButtonBmp;
HBITMAP m_hGameAgainButtonBmp;
HBITMAP	m_hGameBackButtonBmp;
HBITMAP m_hGameResumeButtonBmp;
HBITMAP m_hGameNYButtonBmp;
HBITMAP	m_hGameTJButtonBmp;
HBITMAP m_hGameSHButtonBmp;
HBITMAP m_hHelpMapBmp;
HBITMAP	m_hCloud1Bmp;
HBITMAP	m_hCloud2Bmp;
HBITMAP m_hDefeatBmp;
HBITMAP m_hVictoryBmp;
HBITMAP m_hBiuBmp;
HBITMAP m_hClockBmp[31];
HBITMAP	m_hPlaneHBmp;
HBITMAP	m_hPlaneTBmp;


// 声明英雄、建筑、地形、按钮
Hero          m_hero[MAX_HERO_NUM];
Arrow		  m_arrow[MAX_HERO_NUM];
Hero		  m_tomb[MAX_HERO_NUM];
Life          m_life[MAX_HERO_NUM];
Terrian       m_terrian[MAX_TERRIAN_NUM];
Wind		  m_wind1;
Wind		  m_wind2;
Focus		  m_focus;
Biu			  m_biu;
Force		  m_force;
Bomb		  m_bomb[MAX_BOOM_NUM];
Boom		  m_boom[MAX_BOOM_NUM];
GameButton    m_gameStartButton;
GameButton    m_gameStartButton2;
GameButton    m_gameStartButton3;
GameButton	  m_gameHelpButton;
GameButton    m_gameAgainButton;
GameButton	  m_gameBackButton1;
GameButton	  m_gameBackButton2;
GameButton	  m_gameBackButton3;
GameButton	  m_gameBackButton4;
GameButton	  m_gameResumeButton;
GameButton	  m_gameTitle;
GameButton	  m_gameHelp;
GameButton    m_gameNYButton;
GameButton	  m_gameTJButton;
GameButton	  m_gameSHButton;
Ocean		  m_ocean;
Clock		  m_clock[31];
Plane		  m_planeH;
Plane		  m_planeT;

// 声明游戏状态
GameStatus gameStatus;
GameStatus final1;
GameStatus final2;

#endif