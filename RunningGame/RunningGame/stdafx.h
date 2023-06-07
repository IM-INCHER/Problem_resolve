#pragma once

#include <iostream>
#include <vector>
#include <time.h>
#include <conio.h>
#include <string>

#include "Vector3.h"
#include "Object.h"

#include "RenderManager.h"
#include "SceneManager.h"

using namespace std;

#define MAXRANKING 5

#define RENDERMANAGER RenderManager::getSingleton()
#define SCENEMANAGER SceneManager::getSingleton()

extern int score;