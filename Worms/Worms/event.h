#ifndef EVENT_H
#define EVENT_H

#include <Windows.h>

// 窗体过程函数
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


// 初始化
VOID Init(HWND hWnd, WPARAM wParam, LPARAM lParam);

//双缓冲绘制
VOID Render(HWND hWnd);
VOID Render_Start(HWND hWnd);//绘制游戏开始界面
VOID Render_Game(HWND hWnd);//绘制游戏界面
VOID Render_Final(HWND hWnd);//绘制结束界面
VOID Render_Help(HWND hWnd);//绘制帮助界面
VOID Render_Choose(HWND hWnd);//绘制选择界面
VOID Render_Pause(HWND hWnd);//绘制暂停界面


//定时器事件
VOID TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam);

//血条更新
VOID LifeUpdate();

//hero更新
VOID HeroUpdate();

//炸弹更新
VOID BombUpdate();

//瞄准镜更新
VOID FocusUpdate();
VOID BiuUpdate();

//蓄力更新
VOID ForceUpdate();

//地形更新
VOID TerrianUpdate();

//云彩更新
VOID CloudUpdate();

//飞机更新
VOID PlaneUpdate();

//游戏状态更新
VOID GameStatusUpdate();

//判断是否点击按钮
BOOL ButtonClicked(POINT, RECT);

//键盘按下事件处理
VOID KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

//键盘松开事件处理
VOID KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

//左鼠标点击事件
VOID LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

#endif // !EVENT_H
