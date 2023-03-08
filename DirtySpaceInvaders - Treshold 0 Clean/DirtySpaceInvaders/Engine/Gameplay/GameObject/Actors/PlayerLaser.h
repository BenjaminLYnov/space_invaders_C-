#pragma once

#include <Engine/Gameplay/GameObject/GameObject.h>
#include "ConsoleRenderer.h"
#include <Engine/Gameplay/Levels/PlayField.h>

class PlayerLaser : public GameObject
{
public:
	PlayerLaser();
	~PlayerLaser();

	void Update(PlayField& world);
};
