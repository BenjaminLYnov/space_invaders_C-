#pragma once

#include <vector>
#include <random>
#include <thread>
#include <memory>
#include <string>
#include <iostream>
#include <System/Input/RndInput.h>
#include "Vector.h"

class GameObject;

class PlayField
{
public:

	Input* cotrollerInput;
	Vector2D bounds;

	// Number of available active laser slots for aliens and player
	int AlienLasers = 10;
	int PlayerLasers = 4;

	PlayField(Vector2D iBounds);

	std::vector<GameObject*>& GameObjects();

	void Update();

	bool PlayerIsDead();

	GameObject* GetPlayerObject();


	std::vector<GameObject*> GetAliensObject();

	void SpawnLaser(GameObject* newObj);

	void DespawnLaser(GameObject* newObj);

	void AddObject(GameObject* newObj);

	void RemoveObject(GameObject* newObj);

private:
	std::vector<GameObject*> gameObjects;

};