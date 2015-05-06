#include "Enemy.h"

Enemy::Enemy()
{
	pathIndex = 0;
}

Enemy::~Enemy()
{
}

void Enemy::LoadModel(string filename)
{
	model.LoadMesh(filename);
}


void Enemy::UpdatePosition(Pipeline *p)
{
	light->Enable();


	//static int pathIndex = 0;
	p->Scale(0.1f, 0.1f, 0.1f);
	float x = path->pathPoints[pathIndex].first;
	float z = path->pathPoints[pathIndex].second;
	float y = terrain->GetTerrainHeight(x, z);
	p->Rotate(path->GetRotation(Vector3f(x,y,z),pathIndex));

	p->WorldPos(x,y+1.0,z);
	position = Vector3f(x, y + 1, z);

	light->SetWVP(p->GetWVPTrans());
	model.Render();

	if (++pathIndex >= path->pathPoints.size() - 1)				//obiekt dotar� do celu 
		pathIndex = 0;
}


Vector3f Enemy::GetPosition()
{
	return position;
}