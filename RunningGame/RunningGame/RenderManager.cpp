#include "stdafx.h"
#include "RenderManager.h"

void RenderManager::Init()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleOutputCP(CP_UTF8);
	bufferSize = { BUFFERSIZEX, BUFFERSIZEY };
	SetConsoleScreenBufferSize(hConsole, bufferSize);
	buffer = new CHAR_INFO[bufferSize.X * bufferSize.Y];
	GetConsoleScreenBufferInfo(hConsole, &bufferInfo);

	HWND hWnd = GetConsoleWindow();
	SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
	SetWindowPos(hWnd, NULL, 0, 0, 0, 0, SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE);

	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void RenderManager::Release()
{
	delete[] buffer;
}

void RenderManager::Render()
{
	SMALL_RECT writeRect = { 0, 0, bufferSize.X - 1, bufferSize.Y - 1 };
	WriteConsoleOutput(hConsole, buffer, bufferSize, { 0, 0 }, &writeRect);
	Sleep(16);
}

void RenderManager::Print(int x, int y, wchar_t text, int textcolor, int bgColor)
{
	CHAR_INFO& cell = buffer[x + BUFFERSIZEX * y];
	cell.Char.UnicodeChar = text;
	cell.Attributes = textcolor | bgColor * 16;
}

void RenderManager::Print(int x, int y, wchar_t* text, int textcolor, int bgColor)
{
	for (int i = 0; i < wcslen(text); i++)
	{
		CHAR_INFO& cell = buffer[(x + i) + BUFFERSIZEX * y];
		cell.Char.UnicodeChar = text[i];
		cell.Attributes = textcolor | bgColor * 16;
	}
}

void RenderManager::Print(int x, int y, const char* text, int textcolor, int bgColor)
{
	for (int i = 0; i < strlen(text); i++)
	{
		CHAR_INFO& cell = buffer[(x + i) + BUFFERSIZEX * y];
		cell.Char.UnicodeChar = text[i];
		cell.Attributes = textcolor | bgColor * 16;
	}
}

void RenderManager::Print(int x, int y, wchar_t text, int color)
{
	CHAR_INFO& cell = buffer[x + BUFFERSIZEX * y];
	cell.Char.UnicodeChar = text;  // 예시로 '*' 문자로 채움
	cell.Attributes = color | color * 16;
}

void RenderManager::Print(int x, int y, int color)
{
	if (x < 0 || y < 0 || x >= BUFFERSIZEX || y >= BUFFERSIZEY) return;

	CHAR_INFO& cell = buffer[x + BUFFERSIZEX * y];
	cell.Char.UnicodeChar = L'ㅁ';  // 예시로 ' * ' 문자로 채움
	cell.Attributes = color | color * 16;
}
