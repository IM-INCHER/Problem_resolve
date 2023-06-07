#include "stdafx.h"
#include "MainScene.h"

MainScene::MainScene()
{
}

void MainScene::Init()
{
	count = 0;
	select = 0;
	isFlicker = false;
}

void MainScene::Update()
{
	count++;

	if (_kbhit())
	{
		char input = _getch();

		if (input == 32)
		{
			switch (select)
			{
			case 0:
				SCENEMANAGER->ChangeScene(NUM_GameScene);
				break;
			case 1:
				ExitGame();
				break;
			}
		} 
		else if (input == 72 && select != 0) select--;
		else if (input == 80 && select != 1) select++;
	}

	if (count % 10 == 0)
	{
		isFlicker = !isFlicker;
	}
}

void MainScene::Render()
{
	for (int i = 0; i < BUFFERSIZEX; i++)
	{
		for (int j = 0; j < BUFFERSIZEY; j++)
			RENDERMANAGER->Print(i, j, Color::WHITE);
	}

	if (select == 0)
	{
		if (isFlicker)
		{
			RENDERMANAGER->Print(58, 13, L'S', Color::BLACK, Color::WHITE);
			RENDERMANAGER->Print(59, 13, L'T', Color::BLACK, Color::WHITE);
			RENDERMANAGER->Print(60, 13, L'A', Color::BLACK, Color::WHITE);
			RENDERMANAGER->Print(61, 13, L'R', Color::BLACK, Color::WHITE);
			RENDERMANAGER->Print(62, 13, L'T', Color::BLACK, Color::WHITE);
		}
		RENDERMANAGER->Print(58, 15, L'E', Color::BLACK, Color::WHITE);
		RENDERMANAGER->Print(59, 15, L'X', Color::BLACK, Color::WHITE);
		RENDERMANAGER->Print(60, 15, L'I', Color::BLACK, Color::WHITE);
		RENDERMANAGER->Print(61, 15, L'T', Color::BLACK, Color::WHITE);
	}
	else if (select == 1)
	{
		RENDERMANAGER->Print(58, 13, L'S', Color::BLACK, Color::WHITE);
		RENDERMANAGER->Print(59, 13, L'T', Color::BLACK, Color::WHITE);
		RENDERMANAGER->Print(60, 13, L'A', Color::BLACK, Color::WHITE);
		RENDERMANAGER->Print(61, 13, L'R', Color::BLACK, Color::WHITE);
		RENDERMANAGER->Print(62, 13, L'T', Color::BLACK, Color::WHITE);

		if (isFlicker)
		{
			RENDERMANAGER->Print(58, 15, L'E', Color::BLACK, Color::WHITE);
			RENDERMANAGER->Print(59, 15, L'X', Color::BLACK, Color::WHITE);
			RENDERMANAGER->Print(60, 15, L'I', Color::BLACK, Color::WHITE);
			RENDERMANAGER->Print(61, 15, L'T', Color::BLACK, Color::WHITE);
		}
	}

	//===========================================================================

	Vector3 pos;
	pos.x = 30;
	pos.y = 13;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 4; j++)
			RENDERMANAGER->Print(pos.x + i, pos.y + j, Color::RED);
	}

	RENDERMANAGER->Print(pos.x + 5, pos.y, Color::BLACK);
	RENDERMANAGER->Print(pos.x + 5, pos.y + 1, Color::BLACK);
	RENDERMANAGER->Print(pos.x + 4, pos.y, Color::BLACK);
	RENDERMANAGER->Print(pos.x + 4, pos.y + 1, Color::BLACK);

	RENDERMANAGER->Print(pos.x, pos.y + 4, Color::BLACK);
	RENDERMANAGER->Print(pos.x + 1, pos.y + 4, Color::BLACK);
	RENDERMANAGER->Print(pos.x + 4, pos.y + 4, Color::BLACK);
	RENDERMANAGER->Print(pos.x + 5, pos.y + 4, Color::BLACK);

	RENDERMANAGER->Print(pos.x, pos.y + 5, Color::BLACK);
	RENDERMANAGER->Print(pos.x + 1, pos.y + 5, Color::BLACK);
	RENDERMANAGER->Print(pos.x + 4, pos.y + 5, Color::BLACK);
	RENDERMANAGER->Print(pos.x + 5, pos.y + 5, Color::BLACK);

	//===========================================================================

	for (int i = 5; i < 25; i++)
	{
		RENDERMANAGER->Print(75, i, Color::BLACK);
		RENDERMANAGER->Print(76, i, Color::BLACK);

		RENDERMANAGER->Print(115, i, Color::BLACK);
		RENDERMANAGER->Print(116, i, Color::BLACK);
	}

	for (int i = 75; i < 117; i++)
	{
		RENDERMANAGER->Print(i, 4, Color::BLACK);
		RENDERMANAGER->Print(i, 4, Color::BLACK);

		RENDERMANAGER->Print(i, 25, Color::BLACK);
		RENDERMANAGER->Print(i, 25, Color::BLACK);

		RENDERMANAGER->Print(i, 14, Color::BLACK);
		RENDERMANAGER->Print(i, 14, Color::BLACK);
	}

	RENDERMANAGER->Print(83, 8, "UP, DOWN ARROW", Color::BLACK, Color::WHITE);
	RENDERMANAGER->Print(83, 10, "SELECT : SPACEBAR", Color::BLACK, Color::WHITE);

	RENDERMANAGER->Print(94, 16, "RULE", Color::BLACK, Color::WHITE);
	RENDERMANAGER->Print(83, 18, "JUMP : SPACEBAR", Color::BLACK, Color::WHITE);
	RENDERMANAGER->Print(83, 20, "PAUSE : ESC", Color::BLACK, Color::WHITE);
	RENDERMANAGER->Print(83, 22, "SCORE 300 : SPEED UP!", Color::BLACK, Color::WHITE);
}

void MainScene::Release()
{
}
