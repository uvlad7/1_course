#define _CRT_SECURE_NO_WARNINGS
#undef UNICODE
#include<cmath>
#include <Windows.h>
#include"resource.h"
#include <fstream>
using namespace std;
int tR, tY, tG, tM, d;
OPENFILENAME ofn;       // common dialog box structure
char szFile[260];       // buffer for filename
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
char szClassName[] = "ClassName";
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK Time(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE HPrevInst, LPSTR lpCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG msg;
	WNDCLASS wcApp;

	// Заполняем структуру класса окна 
	wcApp.lpszClassName = szClassName;
	wcApp.hInstance = hInstance;
	wcApp.lpfnWndProc = WndProc;
	wcApp.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcApp.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcApp.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	wcApp.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcApp.style = 0;	//CS_HREDRAW | CS_VREDRAW;
	wcApp.cbClsExtra = 0;
	wcApp.cbWndExtra = 0;
	wcApp.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(42));
	HACCEL hac = LoadAccelerators(0, MAKEINTRESOURCE(IDR_ACCELERATOR1));
	// Регистрируем класс окна
	if (!RegisterClass(&wcApp)) {
		MessageBox(NULL, "Class hasn't been registered", "RegisterClass", MB_OK);
		return 0;
	}

	hWnd = CreateWindow(szClassName, "Simple Windows Program", WS_SYSMENU,
		CW_USEDEFAULT, CW_USEDEFAULT, 1000, 600, 0, 0, hInstance, 0);
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	while (GetMessage(&msg, 0, 0, 0)) {
		if (!TranslateAccelerator(hWnd, hac, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (msg.wParam);
}
bool is;
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	static HDC hdc;
	PAINTSTRUCT ps;
	static HBRUSH black;
	static HPEN pen;
	static HBRUSH red;
	static HBRUSH yellow;
	static HBRUSH green;
	static int inter;
	static HINSTANCE hinst;
	int r, y, b, now;
	static RECT rect;
	static HWND hStatusWindow;
	static HMENU hmenucontext, hmenu;
	switch (uMsg) {
	case WM_CREATE:
	{
		ofn.lpstrFile = "settings.txt";
		ifstream fin(ofn.lpstrFile);
		fin >> tR >> tY >> tG >> tM >> is >> d;
		fin.close();
		GetClientRect(hWnd, &rect);
		hinst = GetModuleHandle(NULL);
		Rectangle(hdc, rect.right / 2 - 70, rect.top + 40, rect.right / 2 + 70, rect.bottom - 90);
		SetTimer(hWnd, 1, tR, NULL);
		hmenucontext = LoadMenu(0, MAKEINTRESOURCE(IDR_MENU2));
		hmenucontext = GetSubMenu(hmenucontext, 0);
		hmenu = GetMenu(hWnd);
		CheckMenuItem(hmenu, 40026 - is, MF_CHECKED);
		CheckMenuItem(hmenu, 40025 + is, MF_UNCHECKED);
		inter = 0;
		break;
	}
	case WM_TIMER:
	{
		now = inter % 10;
		if ((now == 0) || (now == 8))
			SetTimer(hWnd, 1, tY, NULL);
		if (now == 1)
			SetTimer(hWnd, 1, tG, NULL);
		if ((now > 1) && (now < 8))
			SetTimer(hWnd, 1, tM, NULL);
		if (now == 9)
			SetTimer(hWnd, 1, tR, NULL);
		inter += 1;
		InvalidateRect(hWnd, &rect, 1);
		break;
	}
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		now = inter % 10;
		r = 0, y = 0, b = 0;
		if ((now == 0))
			r = 1;
		if (now == 1)
		{
			r = 1;
			y = 1;
		}
		if (now == 9)
			y = 1;
		if ((now == 2) || (now == 4) || (now == 6) || (now == 8))
			b = 1;
		if (is)
			black = CreateSolidBrush(RGB(182, 182, 182));
		else
			black = CreateSolidBrush(RGB(82, 82, 82));
		red = CreateSolidBrush(RGB(r * 150 + 50, 0, 0));
		yellow = CreateSolidBrush(RGB(y * 150 + 50, y * 150 + 50, 0));
		green = CreateSolidBrush(RGB(0, b * 150 + 50, 0));
		SelectObject(hdc, black);
		pen = CreatePen(PS_NULL, 0, 0);
		SelectObject(hdc, pen);
		Rectangle(hdc, rect.right / 2 - 7 * d / 8, rect.top + 40, rect.right / 2 + 7 * d / 8, 180 + 3 * d);
		DeleteObject(black);
		SelectObject(hdc, red);
		Ellipse(hdc, rect.right / 2 - d/2, rect.top + 60, rect.right / 2 + d/2, rect.top + 60 + d);
		DeleteObject(red);
		SelectObject(hdc, yellow);
		Ellipse(hdc, rect.right / 2 - d/2, rect.top + 100 + d, rect.right / 2 + d/2, 100 + 2*d);
		DeleteObject(yellow);
		SelectObject(hdc, green);
		Ellipse(hdc, rect.right / 2 - d/2, 140 + 2*d, rect.right / 2 + d/2, 140 + 3*d);
		DeleteObject(green);
		DeleteObject(pen);
		EndPaint(hWnd, &ps);
		break;
	case WM_CONTEXTMENU:
	{
		POINT p;
		p.x = LOWORD(lParam);
		p.y = HIWORD(lParam);
		ScreenToClient(hWnd, &p);
		TrackPopupMenuEx(hmenucontext, 0, p.x, p.y, hWnd, 0);
		break;
	}
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_WHITE:
			is = 1;
			CheckMenuItem(hmenu, 40025, MF_CHECKED);
			CheckMenuItem(hmenu, 40026, MF_UNCHECKED);
			break;
		case ID_BLACK:
			is = 0;
			CheckMenuItem(hmenu, 40025, MF_UNCHECKED);
			CheckMenuItem(hmenu, 40026, MF_CHECKED);
			break;
		case ID_MANAGE_TIME:
			DialogBox(hinst, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, (DLGPROC)Time);
			break;
		case ID_PAUSE:
			KillTimer(hWnd, 1);
			InvalidateRect(hWnd, &rect, 0);
			break;
		case ID_START:
			now = inter % 10;
			if ((now == 0) || (now == 8))
				SetTimer(hWnd, 1, tY, NULL);
			if (now == 1)
				SetTimer(hWnd, 1, tG, NULL);
			if ((now > 1) && (now < 8))
				SetTimer(hWnd, 1, tM, NULL);
			if (now == 9)
				SetTimer(hWnd, 1, tR, NULL);
			inter += 1;
			InvalidateRect(hWnd, &rect, 0);
			break;
		case ID_RED:
			inter = 0;
			KillTimer(hWnd, 1);
			InvalidateRect(hWnd, &rect, 0);
			break;

		case ID_YELLOW:
			inter = 9;
			KillTimer(hWnd, 1);
			InvalidateRect(hWnd, &rect, 0);
			break;

		case ID_GREEN:
			inter = 2;
			KillTimer(hWnd, 1);
			InvalidateRect(hWnd, &rect, 0);
			break;
		case ID_FILE_OPEN:
			// Initialize OPENFILENAME
			ZeroMemory(&ofn, sizeof(OPENFILENAME));
			ofn.lStructSize = sizeof(OPENFILENAME);
			ofn.hwndOwner = hWnd;
			ofn.lpstrFile = szFile;
			ofn.lpstrFile[0] = '\0';
			ofn.nMaxFile = sizeof(szFile);
			ofn.lpstrFilter = "Settings\0*.txt\0";
			ofn.nFilterIndex = 1;
			ofn.lpstrFileTitle = NULL;
			ofn.nMaxFileTitle = 0;
			ofn.lpstrInitialDir = NULL;
			ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

			// Display the Open dialog box.

			if (GetOpenFileName(&ofn) == TRUE)
			{
				ifstream fin(ofn.lpstrFile);
				fin >> tR >> tY >> tG >> tM >> is >> d;
				fin.close();
				SetTimer(hWnd, 1, tR, NULL);
				CheckMenuItem(hmenu, 40026 - is, MF_CHECKED);
				CheckMenuItem(hmenu, 40025 + is, MF_UNCHECKED);
				inter = 0;
				GetClientRect(hWnd, &rect);
				InvalidateRect(hWnd, &rect, 0);
			}
			break;
		case ID_FILE_SAVEAS:
			// Initialize OPENFILENAME
			ZeroMemory(&ofn, sizeof(OPENFILENAME));
			ofn.lStructSize = sizeof(OPENFILENAME);
			ofn.hwndOwner = hWnd;
			ofn.lpstrFile = szFile;
			ofn.lpstrFile[0] = '\0';
			ofn.nMaxFile = sizeof(szFile);
			ofn.lpstrFilter = "Settings\0*.txt\0";
			ofn.nFilterIndex = 1;
			ofn.lpstrFileTitle = NULL;
			ofn.nMaxFileTitle = 0;
			ofn.lpstrInitialDir = NULL;
			ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

			// Display the Save dialog box.

			if (GetSaveFileName(&ofn) == TRUE)
			{
				ofstream fout(ofn.lpstrFile);
				fout << tR <<"\n" << tY << "\n" << tG << "\n" << tM << "\n" << is << "\n" << d;
				fout.close();
			}
			break;
		case ID_FILE_SAVE:
			if (ofn.lpstrFile)
			{
				ofstream fout(ofn.lpstrFile);
				fout << tR << "\n" << tY << "\n" << tG << "\n" << tM << "\n" << is << "\n" << d;
				fout.close();
			}
			break;
		case ID_ABOUT:
			DialogBox(hinst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, (DLGPROC)About);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return (DefWindowProc(hWnd, uMsg, wParam, lParam));
	}
	return (0);
}
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:

		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDC)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
	}
	return (INT_PTR)FALSE;
}
INT_PTR CALLBACK Time(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static HWND edit1, edit2, edit3, edit4, edit5;
	char Buf[15];
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		edit1 = GetDlgItem(hDlg, 1007);
		edit2 = GetDlgItem(hDlg, 1008);
		edit3 = GetDlgItem(hDlg, 1009);
		edit4 = GetDlgItem(hDlg, 1010);
		edit5 = GetDlgItem(hDlg, 1011);
		_itoa(tR, Buf, 10);
		SetWindowText(edit1, Buf);
		_itoa(tY, Buf, 10);
		SetWindowText(edit2, Buf);
		_itoa(tG, Buf, 10);
		SetWindowText(edit3, Buf);
		_itoa(tM, Buf, 10);
		SetWindowText(edit4, Buf);
		_itoa(d, Buf, 10);
		SetWindowText(edit5, Buf);
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		if (LOWORD(wParam) == IDOK)
		{
			GetWindowText(edit1, Buf, 10);
			tR = atoi(Buf);
			GetWindowText(edit2, Buf, 10);
			tY = atoi(Buf);
			GetWindowText(edit3, Buf, 10);
			tG = atoi(Buf);
			GetWindowText(edit4, Buf, 10);
			tM = atoi(Buf);
			GetWindowText(edit5, Buf, 10);
			d = atoi(Buf);
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
	}
	return (INT_PTR)FALSE;
}