// Ekz.cpp: определяет точку входа для консольного приложения.
//
#define _CRT_SECURE_NO_WARNINGS

#include "Header.h"
#include<windows.h>
#include<CommCtrl.h>
#include <fstream>
#include <map>
#include <vector>
#include <iterator>
#include <ctime>
#include <string>
using namespace std;

extern "C" int* __stdcall SumStd(int, int*);
extern "C" double _fastcall srar(int, int*);
int n;
int *a, *b = new int[15];
double sr;
string sBuf, ssr;

//extern "C" int __fastcall SumFast(int, int);
//extern "C" int __stdcall SumStd(int, int*);
//extern "C" int __cdecl SumCdecl(int*, int);
//PUBLIC _SumCdecl
//_SumCdecl proc
//push ebp
//mov ebp, esp
//mov edi, [ebp + 8];адрес массива
//mov ecx, [ebp + 12];длина массива
//xor eax, eax
//xor esi, esi
//cycle2 :
//add eax, [edi + 4 * esi]
//inc esi
//loop cycle2
//pop ebp
//ret
//_SumCdecl endp

//int main()
//{
//	int a[] = { 1, 6, 7, 8 };
//	int b[] = { 5, 8, 9, 3, 9, 2 };
//	cout << SumFast(a[3], b[5]) << endl;
//	cout << SumStd(4, a) << endl;
//	cout << SumCdecl(b, 6) << endl;
//	system("pause");
//	return 0;
//}

BOOL Line(HDC hdc, int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL); //сделать текущими координаты x1, y1
	return LineTo(hdc, x2, y2); //нарисовать линию
}
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
char szProgName[] = "Castle";
char Buf[10];
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
	w.hIcon = 0;
	w.lpszMenuName = 0;
	w.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	w.style = CS_HREDRAW | CS_VREDRAW;
	w.cbClsExtra = 0;
	w.cbWndExtra = 0;

	if (!RegisterClass(&w))
		return 0;
	SystemParametersInfo(SPI_GETWORKAREA, 0, &actualDesktop, 0);
	hWnd = CreateWindow(szProgName,
		"Это моя программа. Таких программ много, но эта — моя.",
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
	HPEN hPen;
	HBRUSH hBrush;
	static HINSTANCE hInstance;
	static HWND hButton, hStatusWindow;

	switch (messg)
	{
	case WM_CREATE:
	{
		
		hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
		hButton = CreateWindow("BUTTON", "Вычислить", WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			0, 0, 0, 0, hWnd, (HMENU)ID_BUTTON, hInstance, NULL);
		hStatusWindow = CreateWindow(STATUSCLASSNAME, "",
			WS_CHILD | WS_VISIBLE | WS_DISABLED | SBARS_TOOLTIPS | SBS_BOTTOMALIGN | SBS_RIGHTALIGN,
			0, 0, 0, 0, hWnd, NULL, hInstance, NULL);
		GetClientRect(hWnd, &actualDesktop);
		RECT actualStatus;
		GetClientRect(hStatusWindow, &actualStatus);
		int coord[] = { floor(0.4*actualStatus.right), floor(0.7*actualStatus.right), -1 }; /*Площадь новой комнаты*/
		SendMessage(hStatusWindow, SB_SETPARTS, 3, (LPARAM)&coord);
		MoveWindow(hButton, actualDesktop.right - 110, actualDesktop.bottom - 45, 100, 35, 1);
		MoveWindow(hStatusWindow, 10, actualDesktop.bottom - 45, actualDesktop.right - 130, 35, 1);
	}
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case ID_BUTTON:
			SendMessage(hWnd, ID_MESSAGE, 0, 0L);
			break;
		}
		break;
	}
	case ID_MESSAGE:
	{
		ifstream fin("input.txt");
		fin >> n;
		fin.close();
		sBuf.clear();
		a = SumStd(n, b);
		for (int i = a[0]; i > 0; i--)
			sBuf += a[i] + '0';
		SendMessage(hStatusWindow, SB_SETTEXT, 1, (LPARAM)sBuf.c_str());
		sr = srar(a[0], a + 1);
		ssr = to_string(sr);
		SendMessage(hStatusWindow, SB_SETTEXT, 2, (LPARAM)ssr.c_str());
		break;
	}
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		GetClientRect(hWnd, &actualDesktop);
		strcpy(lf.lfFaceName, "Consolas");
		lf.lfHeight = 35;
		lf.lfItalic = 3;
		lf.lfStrikeOut = 0;
		lf.lfUnderline = 0;
		lf.lfWidth = 15;
		lf.lfWeight = 50;
		lf.lfCharSet = DEFAULT_CHARSET;
		lf.lfPitchAndFamily = DEFAULT_PITCH;
		lf.lfEscapement = 0;
		hFont = CreateFontIndirect(&lf);
		SelectObject(hdc, hFont);
		SetTextColor(hdc, RGB(0, 0, 255));
		TextOut(hdc, actualDesktop.right / 2 - 90, 0, "Перевод числа", 13);
		hPen = CreatePen(PS_NULL, 0, 0);
		SelectObject(hdc, hPen);
		COLORREF clr = RGB(1, 1, 1);
		hBrush = CreateSolidBrush(clr);
		SelectObject(hdc, hBrush);
		SendMessage(hStatusWindow, SB_SETTEXT, 0, (LPARAM)"Двоичное представление:");
		SendMessage(hStatusWindow, SB_SETTEXT, 1, (LPARAM)sBuf.c_str());
		SendMessage(hStatusWindow, SB_SETTEXT, 2, (LPARAM)ssr.c_str());
		GetClientRect(hWnd, &actualDesktop);
		RECT actualStatus;
		GetClientRect(hStatusWindow, &actualStatus);
		int coord[] = { floor(0.4*actualStatus.right),floor(0.7*actualStatus.right), -1 }; /*Площадь новой комнаты*/
		SendMessage(hStatusWindow, SB_SETPARTS, 3, (LPARAM)&coord);
		MoveWindow(hButton, actualDesktop.right - 110, actualDesktop.bottom - 45, 100, 35, 1);
		MoveWindow(hStatusWindow, 10, actualDesktop.bottom - 45, actualDesktop.right - 130, 35, 1);
		EndPaint(hWnd, &ps);
		break;
	}
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		hPen = CreatePen(2, 2, RGB(10, 10, 10));
		hFont = CreateFontIndirect(&lf);
		DeleteObject(hPen);
		DeleteObject(hFont);
		break;
	}
	default:
		return(DefWindowProc(hWnd, messg, wParam, lParam));
	}
	return 0;
}