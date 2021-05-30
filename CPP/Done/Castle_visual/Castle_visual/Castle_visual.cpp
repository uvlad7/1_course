// Castle_visual.cpp: определяет точку входа для консольного приложения.
//
#define _CRT_SECURE_NO_WARNINGS

#include<windows.h>
#include<CommCtrl.h>
#include <fstream>
#include <map>
#include <vector>
#include <iterator>
#include <ctime>
#include <string>
using namespace std;
struct point
{
	int walls;
	int iiId;
};
struct ID
{
	int id = 0;
	int square = 1;
	COLORREF color;
};
enum Direction {
	Left = 0, Up, Right, Down
};
bool isWall(point P, Direction D)
{
	return (((1 << D) & P.walls) == 0);
}
class comp
{
public:
	bool operator()(const int &a, const int &b)
	{
		return (a > b);
	}
};
BOOL Line(HDC hdc, int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL); //сделать текущими координаты x1, y1
	return LineTo(hdc, x2, y2); //нарисовать линию
}
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
char szProgName[] = "Castle";
char Buf[10];
RECT actualDesktop;
vector <ID> vId;
vector <int> ivId;
int m, n;
vector <vector<point>> castle(100, vector<point>(100));
ID tId;
pair <int, int> p1, p2; //x, y
int pnt = 0;

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
		"Замок",
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
		ifstream fin("input.txt");
		fin >> m >> n;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n;j++)
				fin >> castle[i][j].walls;
		fin.close();
		hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
		hButton = CreateWindow("BUTTON", "Нарисовать", WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
			0, 0, 0, 0, hWnd, (HMENU)10, hInstance, NULL);
		hStatusWindow = CreateWindow(STATUSCLASSNAME, "",
			WS_CHILD | WS_VISIBLE | WS_DISABLED | SBARS_TOOLTIPS | SBS_BOTTOMALIGN | SBS_RIGHTALIGN,
			0, 0, 0, 0, hWnd, NULL, hInstance, NULL);
	}
	case WM_SIZE:
	{
		GetClientRect(hWnd, &actualDesktop);
		RECT actualStatus;
		GetClientRect(hStatusWindow, &actualStatus);
		int coord[] = { floor(0.15*actualStatus.right), floor(0.20*actualStatus.right), /*Количество комнат*/
			floor(0.35*actualStatus.right), floor(0.40*actualStatus.right),/*Максимальная площадь*/
			floor(0.60*actualStatus.right), floor(0.65*actualStatus.right), floor(0.70*actualStatus.right),/*Разрушить стену между комнатами*/
			floor(0.95*actualStatus.right), -1 }; /*Площадь новой комнаты*/
		SendMessage(hStatusWindow, SB_SETPARTS, 9, (LPARAM)&coord);
		MoveWindow(hButton, actualDesktop.right - 110, actualDesktop.bottom - 45, 100, 35, 1);
		MoveWindow(hStatusWindow, 10, actualDesktop.bottom - 45, actualDesktop.right - 130, 35, 1);
	}
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case 10:
			SendMessage(hWnd, 11, 0, 0L);
			break;
		}
		break;
	}
	case 11:
	{
		if ((pnt == 0) || (pnt == 2))
		{
			srand(time(NULL));
			tId.id = 1;
			vId.clear();
			ivId.clear();
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
				{
					if ((!isWall(castle[i][j], Left)) && (!isWall(castle[i][j], Up)))
					{
						switch (tId.id % 5)
						{
						case 0:
							tId.color = RGB(rand() % 150 + 100, 0, 0);
							break;
						case 1:
							tId.color = RGB(0, rand() % 150 + 100, 0);
							break;
						case 2:
							tId.color = RGB(0, 0, rand() % 150 + 100);
							break;
						case 3:
							tId.color = RGB(rand() % 150 + 100, rand() % 150 + 100, 0);
							break;
						case 4:
							tId.color = RGB(rand() % 150 + 100, 0, rand() % 150 + 100);
							break;
						}
						vId.push_back(tId);
						tId.id++;
						ivId.push_back(vId.size() - 1);
						castle[i][j].iiId = ivId.size() - 1;
					}
					else
					{
						if ((isWall(castle[i][j], Left)) && (isWall(castle[i][j], Up)))
						{
							if (ivId[castle[i][j - 1].iiId] != ivId[castle[i - 1][j].iiId])
							{
								vId[ivId[castle[i - 1][j].iiId]].square += vId[ivId[castle[i][j - 1].iiId]].square + 1;
								ivId[castle[i][j - 1].iiId] = ivId[castle[i - 1][j].iiId];
							}
							else
								vId[ivId[castle[i - 1][j].iiId]].square++;
							castle[i][j].iiId = castle[i - 1][j].iiId;
						}
						else
						{
							if (isWall(castle[i][j], Left))
							{
								castle[i][j].iiId = castle[i][j - 1].iiId;
								vId[ivId[castle[i][j - 1].iiId]].square++;
							}
							if (isWall(castle[i][j], Up))
							{
								castle[i][j].iiId = castle[i - 1][j].iiId;
								vId[ivId[castle[i - 1][j].iiId]].square++;
							}
						}
					}
				}
			map <int, int> mRoom; //id, square
			map <int, int>::iterator itr, max = mRoom.begin();
			multimap <int, int, comp> mmRoom; //square, id
			multimap <int, int, comp>::iterator it, jt;
			for (unsigned int i = 0; i < ivId.size(); i++)
				mRoom.insert(make_pair(vId[ivId[i]].id, vId[ivId[i]].square));
			SendMessage(hStatusWindow, SB_SETTEXT, 0, (LPARAM)"Количество комнат:");
			_itoa(mRoom.size(), Buf, 10);
			SendMessage(hStatusWindow, SB_SETTEXT, 1, (LPARAM)Buf);
			//cout << "Количество комнат: " << mRoom.size() << endl;
			for (itr = mRoom.begin(); itr != mRoom.end(); advance(itr, 1))
				mmRoom.insert(make_pair(itr->second, itr->first));
			SendMessage(hStatusWindow, SB_SETTEXT, 2, (LPARAM)"Максимальная площадь:");
			_itoa(mmRoom.begin()->first, Buf, 10);
			SendMessage(hStatusWindow, SB_SETTEXT, 3, (LPARAM)Buf);
			//cout << "Максимальная площадь: " << mmRoom.begin()->first << endl;
			if (mmRoom.size() > 1)
			{
				int s = 0;
				for (it = mmRoom.begin(); it != mmRoom.end(); advance(it, 1))
				{
					/*jt = it;
					advance(jt, 1);
					if (s >= it->first + jt->first)
						break;*/
					for (jt = it, advance(jt, 1); jt != mmRoom.end(); advance(jt, 1))
						for (int i = 0; i < m; i++)
							for (int j = 0; j < n; j++)
								if (vId[ivId[castle[i][j].iiId]].square == it->first)
								{
									if ((i != 0) && (vId[ivId[castle[i - 1][j].iiId]].square == jt->first) && !(isWall(castle[i][j], Up)) && (s < it->first + jt->first))
									{
										p2 = make_pair(i, j);
										p1 = make_pair(i - 1, j);
										s = it->first + jt->first;
										goto next;
									}
									if ((j != 0) && (vId[ivId[castle[i][j - 1].iiId]].square == jt->first) && !(isWall(castle[i][j], Left)) && (s < it->first + jt->first))
									{
										p2 = make_pair(i, j);
										p1 = make_pair(i, j - 1);
										s = it->first + jt->first;
										goto next;
									}
									if ((i != m - 1) && (vId[ivId[castle[i + 1][j].iiId]].square == jt->first) && !(isWall(castle[i][j], Down)) && (s < it->first + jt->first))
									{
										p1 = make_pair(i, j);
										p2 = make_pair(i + 1, j);
										s = it->first + jt->first;
										goto next;
									}
									if ((j != n - 1) && (vId[ivId[castle[i][j + 1].iiId]].square == jt->first) && !(isWall(castle[i][j], Right)) && (s < it->first + jt->first))
									{
										p1 = make_pair(i, j);
										p2 = make_pair(i, j + 1);
										s = it->first + jt->first;
										goto next;
									}
								}
next:;
				}
				SendMessage(hStatusWindow, SB_SETTEXT, 4, (LPARAM)"Разрушить стену между клетками:");
				string sBuf;
				sBuf = "(";
				_itoa(p1.first + 1, Buf, 10);
				sBuf += Buf;
				sBuf += ", ";
				_itoa(p1.second + 1, Buf, 10);
				sBuf += Buf;
				sBuf += ")";
				SendMessage(hStatusWindow, SB_SETTEXT, 5, (LPARAM)sBuf.c_str());
				sBuf = "(";
				_itoa(p2.first + 1, Buf, 10);
				sBuf += Buf;
				sBuf += ", ";
				_itoa(p2.second + 1, Buf, 10);
				sBuf += Buf;
				sBuf += ")";
				SendMessage(hStatusWindow, SB_SETTEXT, 6, (LPARAM)sBuf.c_str());
				//cout << "Разрушить стену между клетками (" << p1.first + 1 << ", " << p1.second + 1 << ") и (" << p2.first + 1 << ", " << p2.second + 1 << ")" << endl;
				SendMessage(hStatusWindow, SB_SETTEXT, 7, (LPARAM)"Площадь новой комнаты:");
				_itoa(s, Buf, 10);
				SendMessage(hStatusWindow, SB_SETTEXT, 8, (LPARAM)Buf);
				//cout << "Площадь новой комнаты: " << s << endl;
				pnt = 1;
				SetWindowText(hButton, "Объединить");
			}
			else
			{
				p1 = make_pair(0, 1);
				p1 = make_pair(1, 1);
				SendMessage(hStatusWindow, SB_SETTEXT, 4, (LPARAM)"Разрушить стену между клетками:");
				string sBuf;
				sBuf = "(0, 1)";
				SendMessage(hStatusWindow, SB_SETTEXT, 5, (LPARAM)sBuf.c_str());
				sBuf = "(1, 1)";
				SendMessage(hStatusWindow, SB_SETTEXT, 6, (LPARAM)sBuf.c_str());
				SendMessage(hStatusWindow, SB_SETTEXT, 7, (LPARAM)"Площадь новой комнаты:");
				sBuf = "дофига";
				SendMessage(hStatusWindow, SB_SETTEXT, 8, (LPARAM)sBuf.c_str());
				pnt = 3;
			}
		}
		else if (pnt == 1)
		{
			if (p1.first == p2.first)
			{
				castle[p1.first][p1.second].walls -= 4;
				castle[p2.first][p2.second].walls --;
			}
			else
			{
				castle[p1.first][p1.second].walls -= 8;
				castle[p2.first][p2.second].walls -= 2;
			}
			pnt = 2;
			SetWindowText(hButton, "Нарисовать");
		}
		InvalidateRect(hWnd, &actualDesktop, 0);
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
		TextOut(hdc, actualDesktop.right / 2 - 35, 0, "Замок", 5);
		if (pnt)
		{
			int length = min((actualDesktop.bottom - 150) / m, (actualDesktop.right - 200) / n);
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
				{
					hPen = CreatePen(PS_NULL, 0, 0);
					SelectObject(hdc, hPen);
					hBrush = CreateSolidBrush(vId[ivId[castle[i][j].iiId]].color);
					SelectObject(hdc, hBrush);
					Rectangle(hdc, j * length + (actualDesktop.right - n*length) / 2,
						i * length + (actualDesktop.bottom - m*length) / 2,
						(j + 1) * length + (actualDesktop.right - n*length) / 2,
						(i + 1) * length + (actualDesktop.bottom - m*length) / 2);
					hPen = CreatePen(0, 4, RGB(0, 0, 0));
					SelectObject(hdc, hPen);
					if (!isWall(castle[i][j], Left))
						Line(hdc, j * length + (actualDesktop.right - n*length) / 2, i * length + (actualDesktop.bottom - m*length) / 2,
							j * length + (actualDesktop.right - n*length) / 2, (i + 1) * length + (actualDesktop.bottom - m*length) / 2);
					if (!isWall(castle[i][j], Up))
						Line(hdc, j * length + (actualDesktop.right - n*length) / 2, i * length + (actualDesktop.bottom - m*length) / 2,
						(j + 1) * length + (actualDesktop.right - n*length) / 2, i * length + (actualDesktop.bottom - m*length) / 2);
				}
			hPen = CreatePen(0, 4, RGB(0, 0, 0));
			SelectObject(hdc, hPen);
			MoveToEx(hdc, (actualDesktop.right - n*length) / 2, (actualDesktop.bottom - m*length) / 2, NULL);
			LineTo(hdc, (actualDesktop.right - n*length) / 2 + n*length, (actualDesktop.bottom - m*length) / 2);
			LineTo(hdc, (actualDesktop.right - n*length) / 2 + n*length, (actualDesktop.bottom - m*length) / 2 + m*length);
			LineTo(hdc, (actualDesktop.right - n*length) / 2, (actualDesktop.bottom - m*length) / 2 + m*length);
			LineTo(hdc, (actualDesktop.right - n*length) / 2, (actualDesktop.bottom - m*length) / 2);
			if (pnt == 2)
			{
				if (p1.first == p2.first)
				{
					Line(hdc, p2.second * length + (actualDesktop.right - n*length) / 2, p2.first * length + (actualDesktop.bottom - m*length) / 2,
						p2.second * length + (actualDesktop.right - n*length) / 2, (p2.first + 0.33) * length + (actualDesktop.bottom - m*length) / 2);
					Line(hdc, p2.second * length + (actualDesktop.right - n*length) / 2, (p2.first + 0.33) * length + (actualDesktop.bottom - m*length) / 2,
						(p2.second + 0.3) * length + (actualDesktop.right - n*length) / 2, (p2.first + 0.5) * length + (actualDesktop.bottom - m*length) / 2);
					Line(hdc, p2.second * length + (actualDesktop.right - n*length) / 2, (p2.first + 0.66) * length + (actualDesktop.bottom - m*length) / 2,
						p2.second * length + (actualDesktop.right - n*length) / 2, (p2.first + 1) * length + (actualDesktop.bottom - m*length) / 2);
				}
				else
				{
					Line(hdc, p2.second * length + (actualDesktop.right - n*length) / 2, p2.first * length + (actualDesktop.bottom - m*length) / 2,
						(p2.second + 0.33)* length + (actualDesktop.right - n*length) / 2, p2.first * length + (actualDesktop.bottom - m*length) / 2);
					Line(hdc, (p2.second + 0.33) * length + (actualDesktop.right - n*length) / 2, p2.first * length + (actualDesktop.bottom - m*length) / 2,
						(p2.second + 0.5) * length + (actualDesktop.right - n*length) / 2, (p2.first + 0.3) * length + (actualDesktop.bottom - m*length) / 2);
					Line(hdc, (p2.second + 0.66) * length + (actualDesktop.right - n*length) / 2, p2.first * length + (actualDesktop.bottom - m*length) / 2,
						(p2.second + 1) * length + (actualDesktop.right - n*length) / 2, p2.first * length + (actualDesktop.bottom - m*length) / 2);
				}
			}

		}
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