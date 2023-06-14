#include "stdafx.h"
#include "Map.h"

void Map::Init()
{
	for (Object* obj : bgObjs) {
		obj->Init();
	}
}

void Map::Update()
{
	for (Object* obj : bgObjs) {
		obj->Update();
	}
}

void Map::Render()
{
	for (int i = 0; i < 120; i++)
	{
		for (int j = 0; j < 21; j++)
			RENDERMANAGER->Print(i, j, LIGHTCYAN);
	}

	for (Object* obj : bgObjs) {
		obj->Render();
	}

	grand.Render();
}

void Map::Release()
{
	for (Object* obj : bgObjs) {
		delete obj;
	}
}

Map::Map()
{
	system("mode con lines=30 cols=120");
	bgObjs.push_back(new Sun(110, 3, 0, 0.01f));
	bgObjs.push_back(new Mountain(120, 20, 0, 0.1f));
	bgObjs.push_back(new Mountain(0, 20, 0, 0.1f));
	bgObjs.push_back(new Mountain(50, 20, 0, 0.1f));
	bgObjs.push_back(new Cloud(80, 9, 0, 0.2f));
	bgObjs.push_back(new Cloud(100, 4, 0, 0.2f));
	bgObjs.push_back(new Cloud(60, 7, 0, 0.3f));
	bgObjs.push_back(new Cloud(10, 2, 0, 0.4f));
	bgObjs.push_back(new Cloud(110, 6, 0, 0.3f));
}

void Map::SpeedUp()
{
	for (BackGround* obj : bgObjs) {
		obj->SpeedUp();
	}
}

