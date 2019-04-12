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

// ����������WNDWIDTH��WNDHEIGHTΪ���ڵĿ�͸�
#define TIMER_ID             1		//��ʱ��ID
#define TIMER_ELAPSE         20		//��ʱ�����(ms)
#define WNDWIDTH             800	//���ڵĿ�
#define WNDHEIGHT            700	//���ڵĸ�
#define TITLEBARHEIGHT       32		//��������

// ������Դ�ĳߴ�
#define HERO_SIZE_X          30		//Ӣ�۳ߴ�
#define HERO_SIZE_Y          40		//Ӣ�۳ߴ�
#define TOMB_SIZE_X          30		//Ĺ���ߴ�
#define TOMB_SIZE_Y          40		//Ĺ���ߴ�
#define FOCUS_SIZE_X		 20		//��׼���ߴ�
#define FOCUS_SIZE_Y		 20		//��׼���ߴ�
#define BIU_SIZE_X			 20		//��׼���ߴ�
#define BIU_SIZE_Y			 20		//��׼���ߴ�
#define FOCUS_R				 50		//��׼����뾶
#define TAJI_SIZE_X			 1824	//TAJI�ߴ�
#define TAJI_SIZE_Y			 531	//TAJI�ߴ�
#define NEWY_SIZE_X			 1440	//NEWY�ߴ�
#define NEWY_SIZE_Y			 600	//NEWY�ߴ�
#define SH_SIZE_X			 1184	//SH�ߴ�
#define SH_SIZE_Y			 600	//SH�ߴ�
#define BOMB1_SIZE_X		 10		//Բ��ը���ߴ�
#define BOMB1_SIZE_Y		 10		//Բ��ը���ߴ�
#define BOOM1_SIZE_X		 90		//Բ�ε��ӳߴ�
#define BOOM1_SIZE_Y		 90		//Բ�ε��ӳߴ�
#define LIFE_SIZE_X			 30		//Ѫ���ߴ�
#define LIFE_SIZE_Y			 3		//Ѫ���ߴ�
#define HERO_MAX_FRAME_NUM   3		//
#define GAME_START_BUTTON_SIZE_X   1024	//��ť�ߴ�
#define GAME_START_BUTTON_SIZE_Y   768	//��ť�ߴ�
#define GAME_HELP_BUTTON_SIZE_X   1024	//��ť�ߴ�
#define GAME_HELP_BUTTON_SIZE_Y   768	//��ť�ߴ�
#define GAME_AGAIN_BUTTON_SIZE_X   1024	//��ť�ߴ�
#define GAME_AGAIN_BUTTON_SIZE_Y   768	//��ť�ߴ�
#define GAME_BACK_BUTTON_SIZE_X   1024	//��ť�ߴ�
#define GAME_BACK_BUTTON_SIZE_Y   768	//��ť�ߴ�
#define GAME_RESUME_BUTTON_SIZE_X   1024	//��ť�ߴ�
#define GAME_RESUME_BUTTON_SIZE_Y   768	//��ť�ߴ�
#define GAME_CHTJ_BUTTON_SIZE_X   1024	//��ť�ߴ�
#define GAME_CHTJ_BUTTON_SIZE_Y   768	//��ť�ߴ�
#define GAME_CHNY_BUTTON_SIZE_X   1024	//��ť�ߴ�
#define GAME_CHNY_BUTTON_SIZE_Y   768	//��ť�ߴ�
#define GAME_CHSH_BUTTON_SIZE_X   1024	//��ť�ߴ�
#define GAME_CHSH_BUTTON_SIZE_Y   768	//��ť�ߴ�
#define CLOUD_SIZE_X				200	//�Ʋʳߴ�
#define CLOUD_SIZE_Y				60	//�Ʋʳߴ�
#define OCEAN_SIZE_X				800	//����ߴ�
#define OCEAN_SIZE_Y				57	//����ߴ�
#define TITLE_SIZE_X				500	//����ߴ�
#define TITLE_SIZE_Y				162	//����ߴ�
#define HELP_SIZE_X					1024	//�����ߴ�
#define HELP_SIZE_Y					768	//�����ߴ�
#define CLOCK_SIZE_X				100	//����ʱ�ߴ�
#define CLOCK_SIZE_Y				70	//����ʱ�ߴ�
#define PLANE_SIZE_X				100	//�ɻ��ߴ�
#define PLANE_SIZE_Y				35	//�ɻ��ߴ�
#define ARROW_SIZE_X				35	//��ͷ�ߴ�
#define ARROW_SIZE_Y				35	//��ͷ�ߴ�
#define HEIGHT						50	//��ͷ�߶�

//������Ϸ����
#define MAX_TERRIAN_NUM      5		//���ؿ�����
#define MAX_CLOUD_NUM		 2		//����Ʋ�����
#define MAX_BOOM_NUM		 100    //���ը��������
#define MAX_HERO_NUM         6      //���Ӣ����
#define PERHEIGHT			 10		//ÿ��λ�Ƹ߶�
#define GRAVITY				 1		//����
#define HERO_VEL_X			 1		//Ӣ��ˮƽ�ٶ�
#define HERO_VEL_Y			 10		//Ӣ����ֱ�ٶ�
#define MAX_VEL_X			 5		//����
#define MAX_VEL_Y			 20		//����
#define BOMB1_VEL			 1		//ը����ʼ�ٶ�
#define FORCE				 1		//ԭ��
#define MAX_FORCE			 30		//�����
#define TERRIAN_COLOR		 0		//������ɫ
#define HURT				 50		//�˺���Χ
#define PI					 3.14	//��
#define BOOM_COLOR1			RGB(223, 62, 109)	//ɫ��
#define BOOM_COLOR2			RGB(240, 112, 49)	//ɫ��
#define BOOM_COLOR3			RGB(136, 188, 57)	//ɫ��
#define BOOM_COLOR4			RGB(89, 146, 202)	//ɫ��
#define BOOM_COLOR5			RGB(82, 91, 151)	//ɫ��
#define BOOM_COLOR6			RGB(255, 138, 0)	//ɫ��
#define BOOM_COLOR7			RGB(249, 0, 83)		//ɫ��
#define BOOM_COLOR8			RGB(0, 147, 254)	//ɫ��
#define BOOM_COLOR9			RGB(132, 0, 255)	//ɫ��
#define BOOM_COLOR10		RGB(46, 177, 0)		//ɫ��
#define BOOM_COLOR11		RGB(136, 42, 0)		//ɫ��
#define HERO_COLOR61		RGB(25, 0, 185)		//ɫ��
#define HERO_COLOR62		RGB(236, 49, 40)	//ɫ��
#define PER					2		//������
#define	FLY_VEL				2		//�����ٶ�
#define FLY_HEIGHT			0		//���и߶�
#define ZHEN				5		//�˶�֡��

//�������





// Ӣ�۽ṹ�壬Ӣ��λͼ��λ�á���С*/
typedef struct
{
	HBITMAP	hBmp;	//Ӣ��ͼƬ
	int		step;	//Ӣ��ͼƬ����
	POINT	pos;	//Ӣ��
	POINT   vel;
	SIZE	size;
	int		life;
	int		collision;
	BOOL	jump;
	int     curFrameIndex;
	int     maxFrameSize;
} Hero;

/*�ɻ��ṹ��*/
typedef struct
{
	HBITMAP hBmp;	//ͼƬ
	POINT	pos;	//λ��
	POINT	vel;	//�ٶ�
	SIZE	size;	//�ߴ�
} Plane;


/*Ѫ���ṹ��*/
typedef struct
{
	HBITMAP hBmp;
	POINT	pos;
	SIZE    size;
} Life;

/*��׼���ṹ��*/
typedef struct
{
	HBITMAP hBmp;
	POINT	pos;
	SIZE	size;
	BOOL	status;
} Focus;

/*����ṹ��*/
typedef struct
{
	HBITMAP hBmp;
	POINT	pos;
	SIZE	size;
} Wind;

/*˲�ƽṹ��*/
typedef struct
{
	HBITMAP hBmp;
	POINT	pos;
	POINT	vel;
	SIZE	size;
	BOOL	status;
} Biu;

/*�����ṹ��*/
typedef struct
{
	HBITMAP	hBmp;
	POINT	pos;
	POINT	dir;
	SIZE	size;
	int		status;
} Force;

/*ը���ṹ��*/
typedef struct
{
	HBITMAP hBmp;
	POINT	pos;
	SIZE	size;
	POINT	vel;
	int		collision;
} Bomb;

/*���νṹ�壬���η���λ�á���С*/
typedef struct
{
	HBITMAP hBmp;
	POINT	pos;
	SIZE    size;
} Terrian;

/*����ṹ�壬���󷽿�λ�á���С*/
typedef struct
{
	HBITMAP hBmp;
	POINT	pos;
	SIZE    size;
} Ocean;

/*��ը����*/
typedef struct
{
	HBITMAP hBmp;
	POINT	pos;
	SIZE    size;
	int		status;
} Boom;

/*��ť�ṹ��*/
typedef struct
{
	HBITMAP	hBmp;	//��ťͼƬ
	POINT   pos;	//��ťλ��
	SIZE	size;	//��ť�ߴ�
	int		status;	//��ť״̬
} GameButton;

/*��Ϸ״̬�ṹ��*/
typedef struct
{
	HBITMAP	hBmp;	//����ͼƬ
	int	status;	//��Ϸ״̬
} GameStatus;

/*����ʱ�ṹ��*/
typedef struct
{
	HBITMAP hBmp;	//ͼƬ
	POINT	pos;	//λ��
	SIZE	size;	//�ߴ�
} Clock;

/*��ͷ�ṹ��*/
typedef struct
{
	HBITMAP hBmp;	//ͼƬ
	POINT	pos;	//λ��
	SIZE	size;	//�ߴ�
} Arrow;




// ȫ�ֺ���

/*************************************************
Fucntion : ����Ӣ������
Parameter:
posX��posY��ʾ�������Ͻǵ�����
sizeX��sizeY��ʾ���ε�size
hBmp��ʾλͼ���
curFrameIndex��ǰ֡
maxFrameSize���֡��
*************************************************/
Hero CreateHero(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp, int curFrameIndex, int maxFrameSize);

/*************************************************
Fucntion : ������Ϸ״̬
Parameter:
posX��posY��ʾ�������Ͻǵ�����
sizeX��sizeY��ʾ���ε�size
hBmp��ʾλͼ���
*************************************************/
Clock CreateClock(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

/*************************************************
Fucntion : ��������ʱ
Parameter:
posX��posY��ʾ�������Ͻǵ�����
sizeX��sizeY��ʾ���ε�size
hBmp��ʾλͼ���
*************************************************/
GameButton CreateGameButton(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp, int status);

/*************************************************
Fucntion : ������ͷ
Parameter:
posX��posY��ʾ�������Ͻǵ�����
sizeX��sizeY��ʾ���ε�size
hBmp��ʾλͼ���
*************************************************/
Arrow CreateArrow(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

/*************************************************
Fucntion : ��������Ѫ��
Parameter:
posX��posY��ʾ�������Ͻǵ�����
sizeX��sizeY��ʾ���ε�size
*************************************************/
Life CreateLife(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

/*************************************************
Fucntion : ���������Ʋ�
Parameter:
posX��posY��ʾ�������Ͻǵ�����
sizeX��sizeY��ʾ���ε�size
*************************************************/
Wind CreateWind(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

/*************************************************
Fucntion : ���������ɻ�
Parameter:
posX��posY��ʾ�������Ͻǵ�����
sizeX��sizeY��ʾ���ε�size
*************************************************/
Plane CreatePlane(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

/*************************************************
Fucntion : ������������
Parameter:
posX��posY��ʾ�������Ͻǵ�����
sizeX��sizeY��ʾ���ε�size
*************************************************/
Terrian CreateTerrian(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

/*************************************************
Fucntion : ������������
Parameter:
posX��posY��ʾ�������Ͻǵ�����
sizeX��sizeY��ʾ���ε�size
*************************************************/
Ocean CreateOcean(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

/*************************************************
Fucntion : ����������׼��
Parameter:
posX��posY��ʾ��׼�����Ͻǵ�����
sizeX��sizeY��ʾ��׼����size
*************************************************/
Focus CreateFocus(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

/*************************************************
Fucntion : ��������˲��
Parameter:
posX��posY��ʾ��׼�����Ͻǵ�����
sizeX��sizeY��ʾ��׼����size
*************************************************/
Biu CreateBiu(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

/*************************************************
Fucntion : ������������
Parameter:
posX��posY��ʾ�������ĵ�����
dirX��dirY��ʾ��������
sizeX��sizeY��ʾ�����Ĵ�С
*************************************************/
Force CreateForce(LONG posX, LONG posY, LONG dirX, LONG dirY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

/*************************************************
Fucntion : ��������ը��
Parameter:
posX��posY��ʾԲ���Ͻǵ�����
sizeX��sizeY��ʾԲ��size
*************************************************/
Bomb CreateBomb(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

/*************************************************
Fucntion : ������������
Parameter:
posX��posY��ʾԲ���Ͻǵ�����
sizeX��sizeY��ʾԲ��size
*************************************************/
Boom CreateBoom(LONG posX, LONG posY, LONG sizeX, LONG sizeY, HBITMAP hBmp);

#endif // !GLOBAL_H
