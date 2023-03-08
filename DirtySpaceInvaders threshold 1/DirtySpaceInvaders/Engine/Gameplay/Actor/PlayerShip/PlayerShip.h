#pragma once

#include <Actor/Actor.h>

//#include "PlayerLaser.h"


class PlayerShip : public Actor
{
public:
	PlayerShip(std::string Name = "");
	~PlayerShip();

	virtual void Start() override;
	virtual void Update(float FDeltaTime) override;
	virtual void Destroy() override;

	Sprite* GetSpriteShip() const;

protected:
	void MotorVelocity();
	void LimitPosition();

	void SpawnLaser();

	Sprite* Ship;

};

