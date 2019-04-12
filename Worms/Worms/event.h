#ifndef EVENT_H
#define EVENT_H

#include <Windows.h>

// ������̺���
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


// ��ʼ��
VOID Init(HWND hWnd, WPARAM wParam, LPARAM lParam);

//˫�������
VOID Render(HWND hWnd);
VOID Render_Start(HWND hWnd);//������Ϸ��ʼ����
VOID Render_Game(HWND hWnd);//������Ϸ����
VOID Render_Final(HWND hWnd);//���ƽ�������
VOID Render_Help(HWND hWnd);//���ư�������
VOID Render_Choose(HWND hWnd);//����ѡ�����
VOID Render_Pause(HWND hWnd);//������ͣ����


//��ʱ���¼�
VOID TimerUpdate(HWND hWnd, WPARAM wParam, LPARAM lParam);

//Ѫ������
VOID LifeUpdate();

//hero����
VOID HeroUpdate();

//ը������
VOID BombUpdate();

//��׼������
VOID FocusUpdate();
VOID BiuUpdate();

//��������
VOID ForceUpdate();

//���θ���
VOID TerrianUpdate();

//�Ʋʸ���
VOID CloudUpdate();

//�ɻ�����
VOID PlaneUpdate();

//��Ϸ״̬����
VOID GameStatusUpdate();

//�ж��Ƿ�����ť
BOOL ButtonClicked(POINT, RECT);

//���̰����¼�����
VOID KeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

//�����ɿ��¼�����
VOID KeyUp(HWND hWnd, WPARAM wParam, LPARAM lParam);

//��������¼�
VOID LButtonDown(HWND hWnd, WPARAM wParam, LPARAM lParam);

#endif // !EVENT_H
