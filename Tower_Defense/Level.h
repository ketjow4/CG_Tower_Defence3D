#pragma once

#include <list>
#include "Wave.h"
#include "TerrainsContainer.h"
#include "PathsContainer.h"
#include "Engine.h"
#include "Tower.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include "Camera.h"

class Level
{
public:
	Terrain* terrain;
	Path* path;
	Wave * currentWave;
	vector<Tower*> towerList;	//tower list for actual level
	set<pair<float, float>> occupiedTowerPoints;
	Camera* cam;
	list<Wave*> waveList;
	int levelNumber;			//to check if this is last level

	Level();
	~Level();

	void AdvanceToNextWave();
	bool IsWon();
	bool LoadFromFile(const string &filename);
	static string Filename(int level);
private:
	bool Accomplished;
};

