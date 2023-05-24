#include "stdafx.h"
#include "mainGame.h"

int main()
{
	system("color f0");

	mainGame mg;
	mg.update();
	mg.release();

	return 0;
}