// Integral.cpp: определяет точку входа для консольного приложения.
//

#pragma comment(lib, "ComCtl32.Lib")

#define _CRT_SECURE_NO_WARNINGS
#include"resource1.h"
#include<windows.h>
#include<CommCtrl.h>
#include<cmath>
#include <vector>
#include<TCHAR.H>
#include <fstream>
#include <sstream>

using namespace std;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK HelpProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam);
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK Razb(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
INT_PTR CALLBACK Pred(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
//Функция рисования линии
BOOL Line(HDC hdc, int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL); //сделать текущими координаты x1, y1
	return LineTo(hdc, x2, y2); //нарисовать линию
}

TCHAR szProgName[] = _T("Это моя программа. Таких программ много, но эта — моя.");

int i, func;
TCHAR Buf[10];
RECT actualDesktop;
bool help = 1;
double integral = 0, max_integral = 0, min_integral = 0;
int top, bottom;
double max, min;
double mx, mn, tp, bt;
double step;
double delx, dely;
int width, height;
double pi = 3.1415926535;
double(*f)(double);
int accuracy, tekhod = 0, koltr = 0;
const int ID_MESSAGE = WM_USER + 1;
vector <double> zn_x, zn_y;
MINMAXINFO * pInfo;
COLORREF color, color1, color2;
CHOOSECOLOR ch_color;
COLORREF cust_colors[16] = { 0 };
OPENFILENAME ofn;       // common dialog box structure
TCHAR szFile[260];       // buffer for filename
POINT *graph;
HRGN reg1, reg2, rtemp;
POINT *lppt;
wstring sIntegral;

double f1(double x)
{
	return cos(x*pi / 180)*sin(x*pi / 180);
}
double f2(double x)
{
	return cos(x*x) + abs(x);
}
double f3(double x)
{
	return x*x*x*x - 3 * x*x*x + 8 * x*x - 7 * x + 7;
}

LRESULT CALLBACK HelpProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static LOGFONT lf;
	TCHAR szText[] = _T("Ну і що тут незрозумілого?");
	lf.lfCharSet = DEFAULT_CHARSET;
	lf.lfPitchAndFamily = DEFAULT_PITCH;
	_tcscpy(lf.lfFaceName, _T("Verdana"));
	lf.lfHeight = 15;
	lf.lfWeight = FW_BOLD;
	HFONT font = CreateFontIndirect(&lf);
	switch (Message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		SetTextColor(hdc, RGB(0, 0, 0));
		SetBkMode(hdc, TRANSPARENT);
		SelectObject(hdc, font);
		TextOut(hdc, 10, 10, szText, _tcslen(szText));
		ValidateRect(hwnd, NULL);
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY:
		help = 1;
		break;
	}
	return DefWindowProc(hwnd, Message, wparam, lparam);
}

HINSTANCE hinst;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
{
	HWND hWnd;
	MSG lpMsg;
	WNDCLASS w;
	HACCEL hac = LoadAccelerators(0, MAKEINTRESOURCE(IDR_ACCELERATOR1));

	w.lpszClassName = szProgName;
	w.hInstance = hInstance;
	w.lpfnWndProc = WndProc;
	w.hCursor = LoadCursor(NULL, IDC_ARROW);
	w.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(42));
	w.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	w.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	w.style = CS_VREDRAW | CS_HREDRAW;
	w.cbClsExtra = 0;
	w.cbWndExtra = 0;

	//Если не удалось зарегистрировать класс окна - выходим
	if (!RegisterClass(&w))
		return 0;

	//Создадим окно в памяти, заполнив аргументы CreateWindow
	SystemParametersInfo(SPI_GETWORKAREA, 0, &actualDesktop, 0);
	hWnd = CreateWindow(szProgName,
		_T("Это моя программа. Таких программ много, но эта — моя."),
		WS_SYSMENU | WS_MINIMIZEBOX | WS_OVERLAPPEDWINDOW,
		0,
		0,
		actualDesktop.right,
		actualDesktop.bottom,
		(HWND)NULL,
		(HMENU)NULL,
		(HINSTANCE)hInstance,
		(HINSTANCE)NULL);
	//Выводим окно из памяти на экран
	ShowWindow(hWnd, nCmdShow);
	//Обновим содержимое окна
	UpdateWindow(hWnd);

	//Цикл обработки сообщений

	while (GetMessage(&lpMsg, NULL, 0, 0)) { //Получаем сообщение из очереди
		if (!TranslateAccelerator(hWnd, hac, &lpMsg))
		{
			TranslateMessage(&lpMsg); //Преобразует сообщения клавиш в символы
			DispatchMessage(&lpMsg); //Передаёт сообщение соответствующей функции окна
		}
	}
	return(lpMsg.wParam);
}

//Функция окна
LRESULT CALLBACK WndProc(HWND hWnd, UINT messg,
	WPARAM wParam, LPARAM lParam)
{
	static HINSTANCE hInstance;
	HDC hdc, chdc; //создаём контекст устройства
	HWND Help;
	static LOGFONT lf;
	static HMENU hmenu;
	HBITMAP bmpMem;
	static HWND hButton, hStatusWindow;
	PAINTSTRUCT ps; //создаём экземпляр структуры графического вывода
	static HPEN hPen; //создаём перо
	static HBRUSH hBrush;
	// file handle
	//Цикл обработки сообщений
	switch (messg)
	{

	case WM_CREATE:
	{
		hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
		hButton = CreateWindow(_T("BUTTON"), _T("Вычислить"), WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			0, 0, 0, 0, hWnd, (HMENU)ID_BUTTON, hInstance, NULL);
		hStatusWindow = CreateWindow(STATUSCLASSNAME, _T(""),
			WS_CHILD | WS_VISIBLE | WS_DISABLED | SBARS_TOOLTIPS | SBS_BOTTOMALIGN | SBS_RIGHTALIGN,
			0, 0, 0, 0, hWnd, NULL, hInstance, NULL);
		int coord[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1 };
		SendMessage(hStatusWindow, SB_SETPARTS, 12, (LPARAM)&coord);
		SendMessage(hStatusWindow, SB_SETTEXT, 1, (LPARAM)_T("Пределы:"));
		SendMessage(hStatusWindow, SB_SETTEXT, 4, (LPARAM)_T("Точность, 10ⁿ:"));
		SendMessage(hStatusWindow, SB_SETTEXT, 6, (LPARAM)_T("Текущий ход:"));
		SendMessage(hStatusWindow, SB_SETTEXT, 8, (LPARAM)_T("Количество трапеций:"));
		SendMessage(hStatusWindow, SB_SETTEXT, 10, (LPARAM)_T("Интеграл:"));
		hmenu = GetMenu(hWnd);
		CheckMenuItem(hmenu, ID_F1, MF_CHECKED);
		ch_color = { 0 };
		ch_color.lStructSize = sizeof(CHOOSECOLOR);
		ch_color.hwndOwner = hWnd;
		ch_color.rgbResult = RGB(148, 228, 0);
		ch_color.Flags = CC_ANYCOLOR | CC_RGBINIT;
		ch_color.lpCustColors = cust_colors;
		ofn.lpstrFile = _T("Settings.stn");
		ifstream fin(ofn.lpstrFile);
		fin >> top >> bottom >> accuracy >> func >>
			std::hex >> color >> std::hex >> color1 >> std::hex >> color2;
		fin.close();
		sIntegral = to_wstring(integral);
		SendMessage(hStatusWindow, SB_SETTEXT, 11, (LPARAM)sIntegral.c_str());
		_itot(accuracy, Buf, 10);
		SendMessage(hStatusWindow, SB_SETTEXT, 5, (LPARAM)Buf);
		_itot(tekhod, Buf, 10);
		SendMessage(hStatusWindow, SB_SETTEXT, 7, (LPARAM)Buf);
		_itot(koltr, Buf, 10);
		SendMessage(hStatusWindow, SB_SETTEXT, 9, (LPARAM)Buf);
		_itot(bottom, Buf, 10);
		SendMessage(hStatusWindow, SB_SETTEXT, 2, (LPARAM)Buf);
		_itot(top, Buf, 10);
		SendMessage(hStatusWindow, SB_SETTEXT, 3, (LPARAM)Buf);
		switch (func)
		{
		case 1:
			SendMessage(hStatusWindow, SB_SETTEXT, 0, (LPARAM)_T("Функция: y = sinx*cosx"));
			break;
		case 2:
			SendMessage(hStatusWindow, SB_SETTEXT, 0, (LPARAM)_T("Функция: y = cos(x²) + |x|"));
			break;
		case 3:
			SendMessage(hStatusWindow, SB_SETTEXT, 0, (LPARAM)_T("Функция: y = x⁴ - 3x³ + 8x² - 7x + 7"));
			break;
		}
		SendMessage(hWnd, WM_COMMAND, MAKEWPARAM(40002 + func, 0), 0);
		break;
	}
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case ID_BUTTON:
			SendMessage(hWnd, ID_MESSAGE, 0, 0L);
			break;
		case ID_40024:
			DialogBox(hinst, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, (DLGPROC)Razb);
			break;
		case ID_40001:
			DialogBox(hinst, MAKEINTRESOURCE(IDD_DIALOG3), hWnd, (DLGPROC)Pred);
			break;
		case ID_40012:
			if (help)
			{
				help = 0;
				WNDCLASS w;
				memset(&w, 0, sizeof(WNDCLASS));
				w.lpfnWndProc = HelpProc;
				w.hInstance = hinst;
				w.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
				w.lpszClassName = _T("HelpWClass");
				w.hCursor = LoadCursor(NULL, IDC_HELP);
				w.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(42));
				RegisterClass(&w);

				Help = CreateWindowEx(0, _T("HelpWClass"), _T("Help"),
					WS_CAPTION | WS_SYSMENU, 250, 50,
					220, 100, hWnd, 0, hinst, NULL);
				ShowWindow(Help, SW_NORMAL);
				UpdateWindow(Help);
			}
			break;
		case ID_40013:
			DialogBox(hinst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, (DLGPROC)About);
			break;
		case ID_F1:
			CheckMenuItem(hmenu, ID_F1, MF_CHECKED);
			CheckMenuItem(hmenu, ID_F2, MF_UNCHECKED);
			CheckMenuItem(hmenu, ID_F3, MF_UNCHECKED);
			func = 1;
			f = &f1;
			break;
		case  ID_F2:
			CheckMenuItem(hmenu, ID_F2, MF_CHECKED);
			CheckMenuItem(hmenu, ID_F1, MF_UNCHECKED);
			CheckMenuItem(hmenu, ID_F3, MF_UNCHECKED);
			f = &f2;
			func = 2;
			break;
		case  ID_F3:
			CheckMenuItem(hmenu, ID_F3, MF_CHECKED);
			CheckMenuItem(hmenu, ID_F1, MF_UNCHECKED);
			CheckMenuItem(hmenu, ID_F2, MF_UNCHECKED);
			f = &f3;
			func = 3;
			break;
		case ID_40008:
			if (ChooseColor(&ch_color))
			{
				color = ch_color.rgbResult;
				InvalidateRect(hWnd, &actualDesktop, 0);
				SendMessage(hWnd, WM_PAINT, wParam, lParam);
			}
			break;
		case ID_40009:
			if (ChooseColor(&ch_color))
			{
				color1 = ch_color.rgbResult;
				InvalidateRect(hWnd, &actualDesktop, 0);
				SendMessage(hWnd, WM_PAINT, wParam, lParam);
			}
			break;
		case ID_40010:
			if (ChooseColor(&ch_color))
			{
				color2 = ch_color.rgbResult;
				InvalidateRect(hWnd, &actualDesktop, 0);
				SendMessage(hWnd, WM_PAINT, wParam, lParam);
			}
			break;
		case ID_40007:
			// Initialize OPENFILENAME
			ZeroMemory(&ofn, sizeof(OPENFILENAME));
			ofn.lStructSize = sizeof(OPENFILENAME);
			ofn.hwndOwner = hWnd;
			ofn.lpstrFile = szFile;
			ofn.lpstrFile[0] = '\0';
			ofn.nMaxFile = sizeof(szFile);
			ofn.lpstrFilter = _T("Settings\0*.stn\0");
			ofn.nFilterIndex = 1;
			ofn.lpstrFileTitle = NULL;
			ofn.nMaxFileTitle = 0;
			ofn.lpstrInitialDir = NULL;
			ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

			// Display the Open dialog box.

			if (GetOpenFileName(&ofn) == TRUE)
			{
				ifstream fin(ofn.lpstrFile);
				fin >> top >> bottom >> accuracy >> func >>
					std::hex >> color >> std::hex >> color1 >> std::hex >> color2;
				fin.close();
				SendMessage(hWnd, WM_COMMAND, MAKEWPARAM(40002 + func, 0), 0);
				SendMessage(hWnd, ID_MESSAGE, 0, 0L);
			}
			break;
		case ID_40006:
			if (ofn.lpstrFile)
			{
				ofstream fout(ofn.lpstrFile);
				fout << top << " " << bottom << " " << accuracy << " " << func
					<< " " << std::hex << color << " " << std::hex << color1 << " " << std::hex << color2;
				fout.close();
			}
			break;
		case ID_40011:
			// Initialize OPENFILENAME
			ZeroMemory(&ofn, sizeof(OPENFILENAME));
			ofn.lStructSize = sizeof(OPENFILENAME);
			ofn.hwndOwner = hWnd;
			ofn.lpstrFile = szFile;
			ofn.lpstrFile[0] = '\0';
			ofn.nMaxFile = sizeof(szFile);
			ofn.lpstrFilter = _T("Settings\0*.stn\0");
			ofn.nFilterIndex = 1;
			ofn.lpstrFileTitle = NULL;
			ofn.nMaxFileTitle = 0;
			ofn.lpstrInitialDir = NULL;
			ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

			// Display the Save dialog box.

			if (GetSaveFileName(&ofn) == TRUE)
			{
				ofstream fout(ofn.lpstrFile);
				fout << top << " " << bottom << " " << accuracy << " " << func
					<< " " << std::hex << color << " " << std::hex << color1 << " " << std::hex << color2;
				fout.close();
			}
			break;
		}
		break;
	}
	case ID_MESSAGE:
	{
		KillTimer(hWnd, 1);
		reg1 = CreateRectRgn(0, 0, 0, 0);
		reg2 = CreateRectRgn(0, 0, 0, 0);
		GetClientRect(hWnd, &actualDesktop);
		zn_x.clear();
		zn_y.clear();
		max = -1000000;
		min = 1000000;
		step = 0.0001 * (top - bottom);
		for (double j = bottom; j <= top; j += step)
		{
			zn_x.push_back(j);
			zn_y.push_back(f(j));
		}
		for (i = 0; i < zn_y.size(); i++)
		{
			if (zn_y[i] > max)
				max = zn_y[i];
			if (zn_y[i] < min)
				min = zn_y[i];
		}
		mx = max(max, 0);
		mn = min(min, 0);
		tp = max(top, 0);
		bt = min(bottom, 0);
		delx = pow(10, floor(log10(max(abs(bt), tp))));
		if (abs(delx - max(abs(bt), tp)) <= 0.1*max(abs(bt), tp))
			delx /= 10;
		dely = pow(10, floor(log10(max(abs(mn), mx))));
		if (abs(dely - max(abs(mn), mx)) <= 0.1*max(abs(mn), mx))
			dely /= 10;
		tekhod = 0;
		koltr = 1;
		integral = 0;
		max_integral = 0;
		min_integral = 0;
		graph = new POINT[zn_x.size()];
		for (i = 0; i < zn_x.size(); i++)
		{
			graph[i].x = (int)(zn_x[i]*width / (tp - bt));
			graph[i].y = (int)(zn_y[i]*height / (mx - mn));
		}
		SetTimer(hWnd, 1, 2000, NULL);
		sIntegral = to_wstring(integral);
		SendMessage(hStatusWindow, SB_SETTEXT, 11, (LPARAM)sIntegral.c_str());
		_itot(accuracy, Buf, 10);
		SendMessage(hStatusWindow, SB_SETTEXT, 5, (LPARAM)Buf);
		_itot(tekhod, Buf, 10);
		SendMessage(hStatusWindow, SB_SETTEXT, 7, (LPARAM)Buf);
		_itot(0, Buf, 10);
		SendMessage(hStatusWindow, SB_SETTEXT, 9, (LPARAM)Buf);
		_itot(bottom, Buf, 10);
		SendMessage(hStatusWindow, SB_SETTEXT, 2, (LPARAM)Buf);
		_itot(top, Buf, 10);
		SendMessage(hStatusWindow, SB_SETTEXT, 3, (LPARAM)Buf);
		switch (func)
		{
		case 1:
			SendMessage(hStatusWindow, SB_SETTEXT, 0, (LPARAM)_T("Функция: y = sinx*cosx"));
			break;
		case 2:
			SendMessage(hStatusWindow, SB_SETTEXT, 0, (LPARAM)_T("Функция: y = cos(x²) + |x|"));
			break;
		case 3:
			SendMessage(hStatusWindow, SB_SETTEXT, 0, (LPARAM)_T("Функция: y = x⁴ - 3x³ + 8x² - 7x + 7"));
			break;
		}
		InvalidateRect(hWnd, &actualDesktop, 0);
		break;
	}
	case WM_TIMER:
	{
		tekhod++;
		reg1 = CreateRectRgn(0, 0, 0, 0);
		reg2 = CreateRectRgn(0, 0, 0, 0);
		max_integral = 0;
		min_integral = 0;
		for (i = 0; i < koltr; i++)
		{
			max_integral += (zn_x[floor((zn_x.size() - 1)*(i + 1) / koltr)]
				- zn_x[floor((zn_x.size() - 1)*i / koltr)])*
				max(zn_y[floor((zn_y.size() - 1)*i / koltr)], zn_y[floor((zn_y.size() - 1)*(i + 1) / koltr)]);
			min_integral += (zn_x[floor((zn_x.size() - 1)*(i + 1) / koltr)]
				- zn_x[floor((zn_x.size() - 1)*i / koltr)])*
				min(zn_y[floor((zn_y.size() - 1)*i / koltr)], zn_y[floor((zn_y.size() - 1)*(i + 1) / koltr)]);
				/*(zn[floor((zn.size() - 1)*i / koltr)].second +
					zn[floor((zn.size() - 1)*(i + 1) / koltr)].second) / 2;*/
			lppt = new POINT[4];
			lppt[0].x = zn_x[floor((zn_x.size() - 1)*i / koltr)]*width / (tp - bt);
			lppt[1].x = zn_x[floor((zn_x.size() - 1)*i / koltr)]*width / (tp - bt);
			lppt[2].x = zn_x[floor((zn_x.size() - 1)*(i + 1) / koltr)]*width / (tp - bt);
			lppt[3].x = zn_x[floor((zn_x.size() - 1)*(i + 1) / koltr)]*width / (tp - bt);
			lppt[0].y = 0;
			lppt[1].y = zn_y[floor((zn_y.size() - 1)*i / koltr)]*height / (mx - mn);
			lppt[2].y = zn_y[floor((zn_y.size() - 1)*(i + 1) / koltr)]*height / (mx - mn);
			lppt[3].y = 0;
			rtemp = CreatePolygonRgn(lppt, 4, WINDING);
			if (i % 2 == 0)
				CombineRgn(reg1, reg1, rtemp, RGN_OR);
			else CombineRgn(reg2, reg2, rtemp, RGN_OR);
		}
		integral = (max_integral + min_integral) / 2;
		if (abs(max_integral - min_integral) <= pow(10, accuracy))
			KillTimer(hWnd, 1);
		sIntegral = to_wstring(integral);
		SendMessage(hStatusWindow, SB_SETTEXT, 11, (LPARAM)sIntegral.c_str());
		_itot(tekhod, Buf, 10);
		SendMessage(hStatusWindow, SB_SETTEXT, 7, (LPARAM)Buf);
		_itot(koltr, Buf, 10);
		SendMessage(hStatusWindow, SB_SETTEXT, 9, (LPARAM)Buf);
		InvalidateRect(hWnd, &actualDesktop, 0);
		koltr *= 2;
		break;
	}
		//сообщение рисования
	case WM_SIZE:
	{
		GetClientRect(hWnd, &actualDesktop);
		width = actualDesktop.right - 90;
		height = actualDesktop.bottom - 100;
		MoveWindow(hButton, actualDesktop.right - 110, actualDesktop.bottom - 45, 100, 35, 1);
		/*SendMessage(hStatusWindow, WM_SIZE, 0, 0);*/
		MoveWindow(hStatusWindow, 10, actualDesktop.bottom - 45, actualDesktop.right - 130, 35, 1);
		RECT actualStatus;
		GetClientRect(hStatusWindow, &actualStatus);
		int coord[] = { floor(0.17*actualStatus.right),/*функция*/
			floor(0.24*actualStatus.right), floor(0.29*actualStatus.right), floor(0.34*actualStatus.right), //пределы
			floor(0.44*actualStatus.right), floor(0.47*actualStatus.right),/*количество ходов*/
			floor(0.55*actualStatus.right), floor(0.58*actualStatus.right),/*текущий ход*/
			floor(0.71*actualStatus.right), floor(0.75*actualStatus.right),/*количество трапеций*/
			floor(0.82*actualStatus.right), -1 };/*интеграл*/
		SendMessage(hStatusWindow, SB_SETPARTS, 12, (LPARAM)&coord);

		if (!zn_x.empty())
		{
			for (i = 0; i < zn_x.size(); i++)
			{
				graph[i].x = (int)(zn_x[i]*width / (tp - bt));
				graph[i].y = (int)(zn_y[i]*height / (mx - mn));
			}
			reg1 = CreateRectRgn(0, 0, 0, 0);
			reg2 = CreateRectRgn(0, 0, 0, 0);
			for (i = 0; i < koltr; i++)
			{
				lppt = new POINT[4];
				lppt[0].x = zn_x[floor((zn_x.size() - 1)*i / koltr)]*width / (tp - bt);
				lppt[1].x = zn_x[floor((zn_x.size() - 1)*i / koltr)]*width / (tp - bt);
				lppt[2].x = zn_x[floor((zn_x.size() - 1)*(i + 1) / koltr)]*width / (tp - bt);
				lppt[3].x = zn_x[floor((zn_x.size() - 1)*(i + 1) / koltr)]*width / (tp - bt);
				lppt[0].y = 0;
				lppt[1].y = zn_y[floor((zn_y.size() - 1)*i / koltr)]*height / (mx - mn);
				lppt[2].y = zn_y[floor((zn_y.size() - 1)*(i + 1) / koltr)]*height / (mx - mn);
				lppt[3].y = 0;
				rtemp = CreatePolygonRgn(lppt, 4, WINDING);
				if (i % 2 == 0)
					CombineRgn(reg1, reg1, rtemp, RGN_OR);
				else CombineRgn(reg2, reg2, rtemp, RGN_OR);
			}
		}
		InvalidateRect(hWnd, &actualDesktop, 0);
		break;
	}
	case WM_PAINT:
	{
		hdc = BeginPaint(hWnd, &ps);
		chdc = CreateCompatibleDC(hdc);
		bmpMem = CreateCompatibleBitmap(hdc, actualDesktop.right, actualDesktop.bottom);
		SelectObject(chdc, bmpMem);
		SetMapMode(hdc, MM_ISOTROPIC); //логические единицы отображаем, как физические
		SetWindowExtEx(hdc, width, height, NULL); //Длина осей
		SetViewportExtEx(hdc, width, -height, NULL); //Определяем облась вывода
		SetViewportOrgEx(hdc, width * (0 - bt) / (tp - bt) + 40, height * (mx) / (mx - mn) + 10, NULL); //Начало координат
		SetMapMode(chdc, MM_ISOTROPIC); //логические единицы отображаем, как физические
		SetWindowExtEx(chdc, width, height, NULL); //Длина осей
		SetViewportExtEx(chdc, width, -height, NULL); //Определяем облась вывода
		SetViewportOrgEx(chdc, width * (0 - bt) / (tp - bt) + 40, height * (mx) / (mx - mn) + 10, NULL); //Начало координат
		RECT temp;
		hBrush = CreateSolidBrush(RGB(255, 255, 255));
		temp.left = -width * (0 - bt) / (tp - bt) - 40;
		temp.top = -height + height * (mx) / (mx - mn) - 90;
		temp.right = width - width * (0 - bt) / (tp - bt) + 90;
		temp.bottom = height * (mx) / (mx - mn) + 100;
		FillRect(chdc, &temp, hBrush);
		if (!zn_x.empty())
		{			
			hBrush = CreateSolidBrush(color1);
			SelectObject(chdc, hBrush);
			PaintRgn(chdc, reg1);
			hBrush = CreateSolidBrush(color2);
			SelectObject(chdc, hBrush);
			PaintRgn(chdc, reg2);
			//Создание  пера
			hPen = CreatePen(0, 3, color);
			SelectObject(chdc, hPen);
			Polyline(
				chdc,             // идентификатор контекста отображения
				graph,// указатель на массив структур POINT
				zn_x.size());
			//Делаем перо снова чёрным
			hPen = CreatePen(0, 1, RGB(0, 0, 0));
			SelectObject(chdc, hPen);
			//Рисуем оси координат
			Line(chdc, 0, height * (mx) / (mx - mn), 0, -height + height * (mx) / (mx - mn));//ось У
			Line(chdc, -width * (0 - bt) / (tp - bt), 0, width - width * (0 - bt) / (tp - bt) + 40, 0);//ось Х
			Line(chdc, width - width * (0 - bt) / (tp - bt) + 40, 0, width - width * (0 - bt) / (tp - bt) + 15, 10);
			Line(chdc, width - width * (0 - bt) / (tp - bt) + 40, 0, width - width * (0 - bt) / (tp - bt) + 15, -10);
			Line(chdc, 0, height * (mx) / (mx - mn), -10, height * (mx) / (mx - mn) - 25);
			Line(chdc, 0, height * (mx) / (mx - mn), 10, height * (mx) / (mx - mn) - 25);

			//Наносим деления
			lf.lfCharSet = DEFAULT_CHARSET;
			lf.lfPitchAndFamily = DEFAULT_PITCH;
			_tcscpy(lf.lfFaceName, _T("Lucida Console"));
			lf.lfHeight = 14;
			lf.lfWeight = FW_NORMAL;
			HFONT font = CreateFontIndirect(&lf);
			SetTextColor(chdc, RGB(0, 0, 0));
			SetBkMode(chdc, TRANSPARENT);
			SelectObject(chdc, font);
			for (i = -9; i*delx < tp*0.9; i++)
			{
				if (i*delx > bt*0.95)
				{
					if (i != 0)
					{
						Line(chdc, i*delx*width / (tp - bt), 3, i*delx*width / (tp - bt), -3);
						if (log10(delx) < 0)
						{
							int j;
							int k = 0;
							if (i < 0)
							{
								k = 1;
								Buf[0] = _T('-');
							}
							Buf[0 + k] = _T('0');
							Buf[1 + k] = _T('.');
							for (j = 2 + k; j < 10, j <= abs(log10(delx)) + k; j++)
								Buf[j] = _T('0');
							Buf[j] = abs(i) + '0';
							Buf[j + 1] = _T('\0');
						}
						else
							_itot(i * delx, Buf, 10);
						TextOut(chdc, i*delx*width / (tp - bt) - _tcslen(Buf) * 5, -5, Buf, _tcslen(Buf));
					}
				}
			}
			for (i = -9; i*dely < mx*0.9; i++)
			{
				if (i*dely > mn*0.95)
				{
					if (i != 0)
					{
						Line(chdc, -3, i*dely*height / (mx - mn), 3, i*dely*height / (mx - mn));
						if (log10(dely) < 0)
						{
							int j;
							int k = 0;
							if (i < 0)
							{
								k = 1;
								Buf[0] = _T('-');
							}
							Buf[0 + k] = _T('0');
							Buf[1 + k] = _T('.');
							for (j = 2 + k; j < 10, j <= abs(log10(dely)) + k; j++)
								Buf[j] = _T('0');
							Buf[j] = abs(i) + '0';
							Buf[j + 1] = _T('\0');
						}
						else
							_itot(i * dely, Buf, 10);
						TextOut(chdc, -1 * _tcslen(Buf) * 10, i*dely*height / (mx - mn) + 7, Buf, _tcslen(Buf));
					}
				}
			}
			TextOut(chdc, -8, -5, _T("0"), 1);
			StretchBlt(
				hdc,
				-actualDesktop.right, -actualDesktop.bottom, 2 * actualDesktop.right, 2 * actualDesktop.bottom,
				chdc,
				-actualDesktop.right, -actualDesktop.bottom, 2 * actualDesktop.right, 2 * actualDesktop.bottom,
				SRCCOPY
			);
		}
		EndPaint(hWnd, &ps);
		UpdateWindow(hWnd); //Обновляем экран
		break;
	}
	case WM_GETMINMAXINFO:
		pInfo = (MINMAXINFO*)lParam;
		pInfo->ptMinTrackSize.x = 400;
		pInfo->ptMinTrackSize.y = 300;
		break;
		//сообщение выхода - разрушение окна
	case WM_DESTROY:
		KillTimer(hWnd, 1);
		DeleteObject(hPen);
		DeleteObject(hBrush);
		PostQuitMessage(0); //Посылаем сообщение выхода с кодом 0 - нормальное завершение
		break;

	default:
		return(DefWindowProc(hWnd, messg, wParam, lParam)); //освобождаем очередь приложения от нераспознаных
	}
	return 0;
}
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:

		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;

	}
	return (INT_PTR)FALSE;
}
INT_PTR CALLBACK Razb(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	static HWND edit, spin;
	switch (message)
	{
	case WM_INITDIALOG:
		edit = GetDlgItem(hDlg, IDC_EDIT1);
		spin = GetDlgItem(hDlg, IDC_SPIN4);
		SendMessage(spin, UDM_SETRANGE, 0, MAKELPARAM(4, 1));
		SendMessage(spin, UDM_SETPOS, 0, MAKELPARAM(accuracy + 3, 0));
		_itot(accuracy, Buf, 10);
		SetWindowText(edit, Buf);
		return (INT_PTR)TRUE;
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON1:
			accuracy = GetDlgItemInt(hDlg, IDC_EDIT1, NULL, 0);
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		}
		break;
	case WM_VSCROLL:
		LRESULT lr = SendMessage(spin, UDM_GETPOS, 0, 0);
		i = LOWORD(lr) - 3;
		_itot(i, Buf, 10);
		SetWindowText(edit, Buf);
		break;
	}
	return (INT_PTR)FALSE;
}
INT_PTR CALLBACK Pred(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	static HWND edit1, edit2, spin4, spin5;
	switch (message)
	{
	case WM_INITDIALOG:
		edit1 = GetDlgItem(hDlg, IDC_EDIT1);
		edit2 = GetDlgItem(hDlg, IDC_EDIT2);
		_itot(bottom, Buf, 10);
		SetWindowText(edit1, Buf);
		_itot(top, Buf, 10);
		SetWindowText(edit2, Buf);
		return (INT_PTR)TRUE;
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDC_BUTTON1:
			GetWindowText(edit1, Buf, 10);
			bottom = _ttof(Buf);
			GetWindowText(edit2, Buf, 10);
			top = _ttof(Buf);
			if (bottom > top)
				swap(top, bottom);
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
			break;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
