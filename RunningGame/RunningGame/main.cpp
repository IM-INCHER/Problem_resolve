#include "stdafx.h"
#include "mainGame.h"

int main()
{
	srand((unsigned int)time(NULL));

	mainGame mg;
	mg.Run();

	return 0;
}