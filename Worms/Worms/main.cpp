#include "global.h"
#include "event.h"

#pragma comment(lib,"msimg32.lib")


TCHAR szWindowClass[] = _T("win32app");
TCHAR szTitle[] = _T("ɫ�ʴ��Ҷ�");


int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	WNDCLASSEX wcex;
	HWND hWnd;
	MSG msg;

	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_ICON1);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_ICON1));

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			_T("Call to RegisterClassEx failed!"),
			_T("Mega Plane"),
			MB_OK);

		return 1;
	}

	// The parameters to CreateWindow explained:
	// szWindowClass: the name of the application
	// szTitle: the text that appears in the title bar
	// WS_OVERLAPPEDWINDOW: the type of window to create,~WS_THICKFRAME  fixed window size
	// CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)
	// WNDWIDTH, WNDHEIGHT: initial size (width, length)
	// NULL: the parent of this window
	// NULL: this application does not have a menu bar
	// hInstance: the first parameter from WinMain
	// NULL: not used in this application
	hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW & ~WS_THICKFRAME & ~WS_MAXIMIZEBOX, // ���ô�����ʽ�����ɸı��С���������
		CW_USEDEFAULT, CW_USEDEFAULT,
		WNDWIDTH, WNDHEIGHT + TITLEBARHEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hWnd)
	{
		MessageBox(NULL,
			_T("Call to CreateWindow failed!"),
			_T("Mega Plane"),
			MB_OK);

		return 1;
	}

	// The parameters to ShowWindow explained:
	// hWnd: the value returned from CreateWindow
	// nCmdShow: the fourth parameter from WinMain
	ShowWindow(hWnd,
		nCmdShow);
	UpdateWindow(hWnd);

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		// ��ʼ��
		Init(hWnd, wParam, lParam);
		break;
	case WM_PAINT:
		// ����
		Render(hWnd);
		break;
	case WM_KEYDOWN:
		// ���̰����¼�
		KeyDown(hWnd, wParam, lParam);
		break;
	case WM_KEYUP:
		// �����ɿ��¼�
		KeyUp(hWnd, wParam, lParam);
		break;
	case WM_LBUTTONDOWN:
		// �������¼�
		LButtonDown(hWnd, wParam, lParam);
		break;
	case WM_TIMER:
		// ��ʱ���¼�
		TimerUpdate(hWnd, wParam, lParam);
		break;
	case WM_DESTROY:
		// �˳������¼�
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}
