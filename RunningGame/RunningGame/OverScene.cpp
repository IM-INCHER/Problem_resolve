#include "stdafx.h"
#include "OverScene.h"

void OverScene::Init()
{
	LoadRankingFromFile();
	SaveRankingToFile();

	count = 0;
	select = 0;
	isFlicker = false;
}

void OverScene::Update()
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

void OverScene::Render()
{
	for (int i = 0; i < BUFFERSIZEX; i++)
	{
		for (int j = 0; j < BUFFERSIZEY; j++)
			RENDERMANAGER->Print(i, j, Color::WHITE);
	}

	
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
	}

	RENDERMANAGER->Print(93, 6, "RANKING", Color::BLACK, Color::WHITE);

	RENDERMANAGER->Print(83, 8, "1st :", Color::BLACK, Color::WHITE);
	RENDERMANAGER->Print(83, 11, "2nd :", Color::BLACK, Color::WHITE);
	RENDERMANAGER->Print(83, 14, "3rd :", Color::BLACK, Color::WHITE);
	RENDERMANAGER->Print(83, 17, "4th :", Color::BLACK, Color::WHITE);
	RENDERMANAGER->Print(83, 20, "5th :", Color::BLACK, Color::WHITE);

	int count = 8;

	for (int ranking : rankings)
	{
		string str = to_string(ranking);
		RENDERMANAGER->Print(90, count, str.c_str(), BLACK, Color::WHITE);

		count += 3;
	}

	RENDERMANAGER->Print(83, 23, "YOUR SCORE : ", Color::BLACK, Color::WHITE);

	string str = to_string(score);
	RENDERMANAGER->Print(96, 23, str.c_str(), Color::BLACK, Color::WHITE);

	//=========================================================================

	if (select == 0)
	{
		if (isFlicker)
		{
			RENDERMANAGER->Print(35, 13, L'R', Color::BLACK, Color::WHITE);
			RENDERMANAGER->Print(36, 13, L'E', Color::BLACK, Color::WHITE);
			RENDERMANAGER->Print(38, 13, L'S', Color::BLACK, Color::WHITE);
			RENDERMANAGER->Print(39, 13, L'T', Color::BLACK, Color::WHITE);
			RENDERMANAGER->Print(40, 13, L'A', Color::BLACK, Color::WHITE);
			RENDERMANAGER->Print(41, 13, L'R', Color::BLACK, Color::WHITE);
			RENDERMANAGER->Print(42, 13, L'T', Color::BLACK, Color::WHITE);
		}
		RENDERMANAGER->Print(35, 15, L'E', Color::BLACK, Color::WHITE);
		RENDERMANAGER->Print(36, 15, L'X', Color::BLACK, Color::WHITE);
		RENDERMANAGER->Print(37, 15, L'I', Color::BLACK, Color::WHITE);
		RENDERMANAGER->Print(38, 15, L'T', Color::BLACK, Color::WHITE);
	}
	else if (select == 1)
	{
		RENDERMANAGER->Print(35, 13, L'R', Color::BLACK, Color::WHITE);
		RENDERMANAGER->Print(36, 13, L'E', Color::BLACK, Color::WHITE);
		RENDERMANAGER->Print(38, 13, L'S', Color::BLACK, Color::WHITE);
		RENDERMANAGER->Print(39, 13, L'T', Color::BLACK, Color::WHITE);
		RENDERMANAGER->Print(40, 13, L'A', Color::BLACK, Color::WHITE);
		RENDERMANAGER->Print(41, 13, L'R', Color::BLACK, Color::WHITE);
		RENDERMANAGER->Print(42, 13, L'T', Color::BLACK, Color::WHITE);

		if (isFlicker)
		{
			RENDERMANAGER->Print(35, 15, L'E', Color::BLACK, Color::WHITE);
			RENDERMANAGER->Print(36, 15, L'X', Color::BLACK, Color::WHITE);
			RENDERMANAGER->Print(37, 15, L'I', Color::BLACK, Color::WHITE);
			RENDERMANAGER->Print(38, 15, L'T', Color::BLACK, Color::WHITE);
		}
	}

}

void OverScene::Release()
{
}


void OverScene::LoadRankingFromFile()
{
	ifstream file("ranking.txt");

	if (file.is_open())
	{
		rankings.clear();

		int ranking;
		while (file >> ranking)
		{
			rankings.push_back(ranking);
		}

		file.close();
	}
	else
	{
		return;
	}
}

void OverScene::SaveRankingToFile()
{
	rankings.push_back(score);
	sort(rankings.begin(), rankings.end(), greater<int>());

	if (rankings.size() > MAXRANKING)
	{
		rankings.pop_back();
	}

	ofstream file("ranking.txt");

	if (file.is_open())
	{
		for (int ranking : rankings)
		{
			file << ranking << std::endl;
		}

		file.close();
	}
	else
	{
		return;
	}
}