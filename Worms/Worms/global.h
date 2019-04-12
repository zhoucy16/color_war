#ifndef GLOBAL_H
#define GLOBAL_H

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <tchar.h>
#include <math.h>
#include "resource.h"
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

// 定义宏变量，WNDWIDTH、WNDHEIGHT为窗口的宽和高
#define TIMER_ID             1		//计时器ID
#define TIMER_ELAPSE         20		//计时器间隔(ms)
#define WNDWIDTH             800	//窗口的宽
#define WNDHEIGHT            700	//窗口的高
#define TITLEBARHEIGHT       32		//标题栏高

// 定义资源的尺寸
#define HERO_SIZE_X          30		//英雄尺寸
#define HERO_SIZE_Y          40		//英雄尺寸
#define TOMB_SIZE_X          30		//墓碑尺寸
#define TOMB_SIZE_Y          40		//墓碑尺寸
#define FOCUS_SIZE_X		 20		//瞄准镜尺寸
#define FOCUS_SIZE_Y		 20		//瞄准镜尺寸
#define BIU_SIZE_X			 20		//瞄准镜尺寸
#define BIU_SIZE_Y			 20		//瞄准镜尺寸
#define FOCUS_R				 50		//瞄准镜活动半径
#define TAJI_SIZE_X			 1824	//TAJI尺寸
#define TAJI_SIZE_Y			 531	//TAJI尺寸
#define NEWY_SIZE_X			 1440	//NEWY尺寸
#define NEWY_SIZE_Y			 600	//NEWY尺寸
#define SH_SIZE_X			 1184	//SH尺寸
#define SH_SIZE_Y			 600	//SH尺寸
#define BOMB1_SIZE_X		 10		//圆形炸弹尺寸
#define BOMB1_SIZE_Y		 10		//圆形炸弹尺寸
#define BOOM1_SIZE_X		 90		//圆形弹坑尺寸
#define BOOM1_SIZE_Y		 90		//圆形弹坑尺寸
#define LIFE_SIZE_X			 30		//血条尺寸
#define LIFE_SIZE_Y			 3		//血条尺寸
#define HERO_MAX_FRAME_NUM   3		//
#define GAME_START_BUTTON_SIZE_X   1024	//按钮尺寸
#define GAME_START_BUTTON_SIZE_Y   768	//按钮尺寸
#define GAME_HELP_BUTTON_SIZE_X   1024	//按钮尺寸
#define GAME_HELP_BUTTON_SIZE_Y   768	//按钮尺寸
#define GAME_AGAIN_BUTTON_SIZE_X   1024	//按钮尺寸
#define GAME_AGAIN_BUTTON_SIZE_Y   768	//按钮尺寸
#define GAME_BACK_BUTTON_SIZE_X   1024	//按钮尺寸
#define GAME_BACK_BUTTON_SIZE_Y   768	//按钮尺寸
#define GAME_RESUME_BUTTON_SIZE_X   1024	//按钮尺寸
#define GAME_RESUME_BUTTON_SIZE_Y   768	//按钮尺寸
#define GAME_CHTJ_BUTTON_SIZE_X   1024	//按钮尺寸
#define GAME_CHTJ_BUTTON_SIZE_Y   768	//按钮尺寸
#define GAME_CHNY_BUTTON_SIZE_X   1024	//按钮尺寸
#define GAME_CHNY_BUTTON_SIZE_Y   768	//按钮尺寸
#define GAME_CHSH_BUTTON_SIZE_X   1024	//按钮尺寸
#define GAME_CHSH_BUTTON_SIZE_Y   768	//按钮尺寸
#define CLOUD_SIZE_X				200	//云彩尺寸
#define CLOUD_SIZE_Y				60	//云彩尺寸
#define OCEAN_SIZE_X				800	//海洋尺寸
#define OCEAN_SIZE_Y				57	//海洋尺寸
#define TITLE_SIZE_X				500	//标题尺寸
#define TITLE_SIZE_Y				162	//标题尺寸
#define HELP_SIZE_X					1024	//帮助尺寸
#define HELP_SIZE_Y					768	//帮助尺寸
#define CLOCK_SIZE_X				100	//倒计时尺寸
#define CLOCK_SIZE_Y				70	//倒计时尺寸
#define PLANE_SIZE_X				100	//飞机尺寸
#define PLANE_SIZE_Y				35	//飞机尺寸
#define ARROW_SIZE_X				35	//箭头尺寸
#define ARROW_SIZE_Y				35	//箭头尺寸
#define HEIGHT						50	//箭头高度

//定义游戏常量
#define MAX_TERRIAN_NUM      5		//最大地块数量
#define MAX_CLOUD_NUM		 2		//最大云彩数量
#define MAX_BOOM_NUM		 100    //最大爆炸凹陷数量
#define MAX_HERO_NUM         6      //最大英雄数
#define PERHEIGHT			 10		//每次位移高度
#define GRAVITY				 1		//重力
#define HERO_VEL_X			 1		//英雄水平速度
#define HERO_VEL_Y			 10		//英雄竖直速度
#define MAX_VEL_X			 5		//限速
#define MAX_VEL_Y			 20		//限速
#define BOMB1_VEL			 1		//炸弹初始速度
#define FORCE				 1		//原力
#define MAX_FORCE			 30		//最大力
#define TERRIAN_COLOR		 0		//地形颜色
#define HURT				 50		//伤害范围
#define PI					 3.14	//派
#define BOOM_COLOR1			RGB(223, 62, 109)	//色彩
#define BOOM_COLOR2			RGB(240, 112, 49)	//色彩
#define BOOM_COLOR3			RGB(136, 188, 57)	//色彩
#define BOOM_COLOR4			RGB(89, 146, 202)	//色彩
#define BOOM_COLOR5			RGB(82, 91, 151)	//色彩
#define BOOM_COLOR6			RGB(255, 138, 0)	//色彩
#define BOOM_COLOR7			RGB(249, 0, 83)		//色彩
#define BOOM_COLOR8			RGB(0, 147, 254)	//色彩
#define BOOM_COLOR9			RGB(132, 0, 255)	//色彩
#define BOOM_COLOR10		RGB(46, 177, 0)		//色彩
#define BOOM_COLOR11		RGB(136, 42, 0)		//色彩
#define HERO_COLOR61		RGB(25, 0, 185)		//色彩
#define HERO_COLOR62		RGB(236, 49, 40)	//色彩
#define PER					2		//流畅度
#define	FLY_VEL				2		//飞行速度
#define FLY_HEIGHT			0		//飞行高度
#define ZHEN				5		//运动帧数

//定义参数





// 英雄结构体，英雄位图、位置、大小*/
typedef struct
{
	HBITMAP	hBmp;	//英雄图片
	int		step;	//英雄图片序数
	POINT	pos;	//英雄
	POINT   vel;
	SIZE	size;
	int		life;
	int		collision;
	BOOL	jump;
	int     curFrameIndex;
	int     maxFrameSize;
} Hero;

/*飞机结构体*/
typedef struct
{
	HBITMAP hBmp;	//图片
	POINT	pos;	//位置
	POINT	vel;	//速度
	SIZE	size;	//尺寸
} Plane;


/*血条结构体*/
typedef struct
{
	HBITMAP hBmp;
	POINT	pos;
	SIZE    size;
} Life;

/*瞄准器结构体*/
typedef struct
{
	HBITMAP hBmp;
	POINT	pos;
	SIZE	size;
	BOOL	status;
} Focus;

/*风向结构体*/
typedef struct
{
	HBITMAP hBmp;
	POINT	pos;
	SIZE	size;
} Wind;

/*瞬移结构体*/
typedef struct
{
	HBITMAP hBmp;
	POINT	pos;
	POINT	vel;
	SIZE	size;
	BOOL	status;
} Biu;

/*蓄力结构体*/
typedef struct
{
	HBITMAP	hBmp;
	POINT	pos;
	POINT	dir;
	SIZE	size;
	int		status;
} Force;

/*炸弹结构体*/
typedef struct
{
	HBITMAP hBmp;
	POINT	pos;
	SIZE	size;
	POINT	vel;
	int		collision;
} Bomb;

/*地形结构体，地形方块位置、大小*/
typedef struct
{
	HBITMAP hBmp;
	POINT	pos;
	SIZE    size;
} Terrian;

/*海洋结构体，海洋方块位置、大小*/
typedef struct
{
	HBITMAP hBmp;
	POINT	pos;
	SIZE    size;
} Ocean;

/*爆炸凹陷*/
typedef struct
{
	HBITMAP hBmp;
	POINT	pos;
	SIZE    size;
	int		status;
} Boom;

/*按钮结构体*/
typedef struct
{
	HBITMAP	hBmp;	//按钮图片
	POINT   pos;	//按钮位置
	SIZE	size;	//按钮尺寸
	int		status;	//按钮状态
} GameButton;

/*游戏状态结构体*/
typedef struct
{
	HBITMAP	hBmp;	//背景图片
	int	status;	//游戏状态
} GameStatus;

/*倒计时结构体*/
typedef struct
{
	HBITMAP hBmp;	//图片
	POINT	pos;	//位置
	SIZE	size;	//尺寸
} Clock;

/*箭头结构体*/
typedef struct
{
	HBITMAP hBmp;	//图片
	POINT	pos;	//位置
	SIZE	size;	//尺寸
} Arrow;




// 全局函数

/*************************************************
Fucntion : 创建英雄人物
Parameter:
posX、posY表示矩形左上角的坐标
sizeX、sizeY表示矩形的size
hBmp表示位图句柄
curFrameIndex当前帧
maxFrameSize最大帧率
*************************************************/
Hero CreateHero(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp, int curFrameIndex, int maxFrameSize);

/*************************************************
Fucntion : 创建游戏状态
Parameter:
posX、posY表示矩形左上角的坐标
sizeX、sizeY表示矩形的size
hBmp表示位图句柄
*************************************************/
Clock CreateClock(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

/*************************************************
Fucntion : 创建倒计时
Parameter:
posX、posY表示矩形左上角的坐标
sizeX、sizeY表示矩形的size
hBmp表示位图句柄
*************************************************/
GameButton CreateGameButton(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp, int status);

/*************************************************
Fucntion : 创建箭头
Parameter:
posX、posY表示矩形左上角的坐标
sizeX、sizeY表示矩形的size
hBmp表示位图句柄
*************************************************/
Arrow CreateArrow(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

/*************************************************
Fucntion : 创建单个血条
Parameter:
posX、posY表示矩形左上角的坐标
sizeX、sizeY表示矩形的size
*************************************************/
Life CreateLife(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

/*************************************************
Fucntion : 创建单个云彩
Parameter:
posX、posY表示矩形左上角的坐标
sizeX、sizeY表示矩形的size
*************************************************/
Wind CreateWind(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

/*************************************************
Fucntion : 创建单个飞机
Parameter:
posX、posY表示矩形左上角的坐标
sizeX、sizeY表示矩形的size
*************************************************/
Plane CreatePlane(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

/*************************************************
Fucntion : 创建单个地形
Parameter:
posX、posY表示矩形左上角的坐标
sizeX、sizeY表示矩形的size
*************************************************/
Terrian CreateTerrian(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

/*************************************************
Fucntion : 创建单个海洋
Parameter:
posX、posY表示矩形左上角的坐标
sizeX、sizeY表示矩形的size
*************************************************/
Ocean CreateOcean(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

/*************************************************
Fucntion : 创建单个瞄准器
Parameter:
posX、posY表示瞄准器左上角的坐标
sizeX、sizeY表示瞄准器的size
*************************************************/
Focus CreateFocus(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

/*************************************************
Fucntion : 创建单个瞬移
Parameter:
posX、posY表示瞄准器左上角的坐标
sizeX、sizeY表示瞄准器的size
*************************************************/
Biu CreateBiu(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

/*************************************************
Fucntion : 创建单个蓄力
Parameter:
posX、posY表示蓄力中心的坐标
dirX、dirY表示蓄力方向
sizeX、sizeY表示蓄力的大小
*************************************************/
Force CreateForce(LONG posX, LONG posY, LONG dirX, LONG dirY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

/*************************************************
Fucntion : 创建单个炸弹
Parameter:
posX、posY表示圆左上角的坐标
sizeX、sizeY表示圆的size
*************************************************/
Bomb CreateBomb(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

/*************************************************
Fucntion : 创建单个凹陷
Parameter:
posX、posY表示圆左上角的坐标
sizeX、sizeY表示圆的size
*************************************************/
Boom CreateBoom(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

#endif // !GLOBAL_H
