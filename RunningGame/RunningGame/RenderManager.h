#pragma once
#include "singletonBase.h"
#include <Windows.h>

#define BUFFERSIZEX 120
#define BUFFERSIZEY 30

enum Color
{
	BLACK = 0x0000, 
	BLUE, 
	GREEN, 
	CYAN, 
	RED, 
	MAGENTA,
	BROWN,
	LIGHTGRAY,
	DARKGRAY, 
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN, 
	LIGHTRED, 
	LIGHTMAGENTA, 
	YELLOW,WHITE, 
};

class RenderManager : public singletonBase<RenderManager>
{
private:
	HANDLE hConsole;
	COORD bufferSize;
	CHAR_INFO* buffer;
	CONSOLE_SCREEN_BUFFER_INFO bufferInfo;

public:
	void Init();
	void Release();
	void Render();

	void Print(int x, int y, wchar_t text, int textcolor, int bgColor);
	void Print(int x, int y, wchar_t* text, int textcolor, int bgColor);
	void Print(int x, int y, const char* text, int textcolor, int bgColor);
	void Print(int x, int y, wchar_t text, int color);
	void Print(int x, int y, int color);
};

