#include "PlayerLaser.h"
#include <Component/Collider/BoxCollider.h>
#include <Component/Renderer/Renderer.h>
#include <Component/Transform/Transform.h>
#include <Engine/Render/Drawable/Sprite/Sprite.h>
#include <Engine/Render/Ressource/TextureManager.h>
#include <Engine/Render/Window.h>

PlayerLaser::PlayerLaser(std::string Name) : Actor(Name)
{
	SpeedMove = 500;
	Velocity = sf::Vector2f(0, -1);
}

PlayerLaser::~PlayerLaser() { 
}


void PlayerLaser::Start()
{
	Actor::Start();

	Laser = CRenderer->AddNewDrawable<Sprite>("Laser", sf::Vector2f(0, 0), 0, sf::Vector2f(0.5, 0.5));
	Laser->SetTexture("Laser");

	CoverBoxColliderToSprite(TextureManager::Instance()->textures["Laser"], *Laser);
	CTransform->SetWorldPosition(sf::Vector2f(200, 100));
}

void PlayerLaser::Update(float FDeltaTime)
{
	PerformMovement(FDeltaTime);
	Actor::Update(FDeltaTime);
}

void PlayerLaser::Destroy()
{
	Actor::Destroy();
}

Sprite* PlayerLaser::GetSpriteLaser() const
{
	return Laser;
}
