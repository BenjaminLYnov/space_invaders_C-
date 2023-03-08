#include "PlayField.h"
#include <Engine/Gameplay/GameObject/GameObject.h>

PlayField::PlayField(Vector2D iBounds) : bounds(iBounds) {
	cotrollerInput = new RndInput();
};

std::vector<GameObject*>& PlayField::GameObjects()
{
	return gameObjects;
}

void PlayField::Update()
{
	// Update list of active objects in the world
	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		gameObjects[i]->Update(*this);
	}
}

bool PlayField::PlayerIsDead()
{
	if (!GetPlayerObject()) {
		return true;
	}

	return false;
}

GameObject* PlayField::GetPlayerObject()
{
	auto it = std::find_if(gameObjects.begin(), gameObjects.end(), [](GameObject* in)
		{
			return (strcmp(in->m_objType, "PlayerShip") == 0);
		});

	if (it != gameObjects.end())
		return (*it);

	return nullptr;
}

std::vector<GameObject*> PlayField::GetAliensObject()
{
	std::vector<GameObject*> Aliens;

	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		if (strcmp(gameObjects[i]->m_objType, "AlienShip") == 0)
		{
			Aliens.push_back(gameObjects[i]);
		}
	}

	return Aliens;
}

void PlayField::SpawnLaser(GameObject* newObj)
{
	if (strcmp(newObj->m_objType, "alienLaser") == 0)
		AlienLasers--;

	else if (strcmp(newObj->m_objType, "PlayerLaser") == 0)
		PlayerLasers--;

	AddObject(newObj);
}

void PlayField::DespawnLaser(GameObject* newObj)
{
	if (strcmp(newObj->m_objType, "AlienLaser") == 0)
		AlienLasers++;

	else if (strcmp(newObj->m_objType, "PlayerLaser") == 0)
		PlayerLasers++;

	RemoveObject(newObj);
}


void PlayField::AddObject(GameObject* newObj)
{
	gameObjects.push_back(newObj);
}

void PlayField::RemoveObject(GameObject* newObj)
{
	auto it = std::find_if(gameObjects.begin(), gameObjects.end(), [&](GameObject* in) { return (in == newObj); });
	delete* it;
	gameObjects.erase(it);
}