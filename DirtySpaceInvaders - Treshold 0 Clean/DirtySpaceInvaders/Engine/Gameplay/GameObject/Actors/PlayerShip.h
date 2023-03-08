#pragma once

#include <string>
#include <Engine/Gameplay/GameObject/GameObject.h>
#include "PlayerLaser.h"

class PlayerShip : public GameObject
{
public:
	PlayerShip();
	~PlayerShip();

	void Update(PlayField& world);
};

