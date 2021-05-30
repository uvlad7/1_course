#if defined(UNICODE) && !defined(_UNICODE)
#define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
#define UNICODE
#endif

#include <tchar.h>
#include <windows.h>

#include<string.h>
#include <cstdlib>
#include <ctime>
using namespace std;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
char szProgName[] = "Paint X";
LPCSTR pszIconResource = MAKEINTRESOURCE(42);
RECT actualDesktop;


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASS w;

	w.lpszClassName = szProgName;
	w.hInstance = hInstance;
	w.lpfnWndProc = WndProc;
	w.hCursor = LoadCursor(NULL, IDC_ARROW);
	w.hIcon = LoadIcon(hInstance, pszIconResource);
	w.lpszMenuName = 0;
	w.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	w.style = CS_HREDRAW | CS_VREDRAW;
	w.cbClsExtra = 0;
	w.cbWndExtra = 0;

	if (!RegisterClass(&w))
		return 0;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &actualDesktop, 0);
	hWnd = CreateWindow(szProgName,
		"3д экшон",
		WS_SYSMENU | WS_MINIMIZEBOX,
		0,
		0,
		actualDesktop.right,
		actualDesktop.bottom,
		(HWND)NULL,
		(HMENU)NULL,
		(HINSTANCE)hInstance,
		(HINSTANCE)NULL);

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);
	while (GetMessage(&lpMsg, NULL, 0, 0))
    {
		TranslateMessage(&lpMsg);
		DispatchMessage(&lpMsg);
	}
	return(lpMsg.wParam);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT messg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	LOGFONT lf;
	HFONT hFont;
	HBRUSH hBrush;
	HPEN hPen;

	switch (messg)
	{
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &actualDesktop);
		strcpy(lf.lfFaceName, "Consolas");
		lf.lfHeight = 20;
		lf.lfItalic = 1;
		lf.lfStrikeOut = 0;
		lf.lfUnderline = 0;
		lf.lfWidth = 10;
		lf.lfWeight = 40;
		lf.lfCharSet = DEFAULT_CHARSET;
		lf.lfPitchAndFamily = DEFAULT_PITCH;
		lf.lfEscapement = 0;
		hFont = CreateFontIndirect(&lf);
		SelectObject(hdc, hFont);
		SetTextColor(hdc, RGB(0, 0, 255));
		TextOut(hdc, actualDesktop.right / 2 - 165, 0, "Владимир Ульяницкий, 3 группа 1 курс", 36);
		MoveToEx(hdc, actualDesktop.right / 2, actualDesktop.bottom / 2, NULL);
		int coorx, coory, r, g, b;
		srand(time(NULL));
		coorx = rand() % actualDesktop.right;
		coory = rand() % (actualDesktop.bottom - lf.lfHeight) + lf.lfHeight;
		r = rand() % 255;
		g = rand() % 255;
		b = rand() % 255;
		hPen = CreatePen(2, 2, RGB(r, g, b));
		SelectObject(hdc, hPen);
		for (int i = 0; i < 50; i++)
		{
			LineTo(hdc, coorx, coory);
			coorx = rand() % actualDesktop.right;
			coory = rand() % (actualDesktop.bottom - lf.lfHeight) + lf.lfHeight;
			r = rand() % 255;
			g = rand() % 255;
			b = rand() % 255;
			hPen = CreatePen(2, 2, RGB(r, g, b));
			SelectObject(hdc, hPen);
		}
		LineTo(hdc, actualDesktop.right / 2, actualDesktop.bottom / 2);
		EndPaint(hWnd, &ps);
		break;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		DeleteObject(hPen);
		DeleteObject(hBrush);
		break;
	}
	default:
		return(DefWindowProc(hWnd, messg, wParam, lParam));
	}
	return 0;
}
