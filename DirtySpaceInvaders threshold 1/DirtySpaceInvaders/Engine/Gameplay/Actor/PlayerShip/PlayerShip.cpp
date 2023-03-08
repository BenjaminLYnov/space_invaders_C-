#include "PlayerShip.h"
#include <Component/Collider/BoxCollider.h>
#include <Component/Renderer/Renderer.h>
#include <Component/Transform/Transform.h>
#include <Engine/Render/Drawable/Sprite/Sprite.h>
#include <System/Input/InputManager.h>
#include <Engine/GameManager/IGameManager.h>
#include <Engine/Render/Ressource/TextureManager.h>
#include <Engine/Render/Window.h>
#include <Actor/PlayerShip/PlayerLaser.h>
#include <Engine/Scene/Level/Level01.h>

PlayerShip::PlayerShip(std::string Name) : Actor(Name)
{ 
	SpeedMove = 300;
}

PlayerShip::~PlayerShip() { 
	
}

void PlayerShip::Start()
{
	Actor::Start();


	Ship = CRenderer->AddNewDrawable<Sprite>("Ship", sf::Vector2f(0, 0), 0, sf::Vector2f(0.1, 0.1));
	Ship->SetTexture("PlayerShip");

	CoverBoxColliderToSprite(TextureManager::Instance()->textures["PlayerShip"], *Ship);

	// Place on bottom middle
	CTransform->SetWorldPosition(sf::Vector2f(Window::Instance()->GetWindow().getSize().x / 2 + (TextureManager::Instance()->textures["PlayerShip"].getSize().x * Ship->GetLocalScale().x) / 2, Window::Instance()->GetWindow().getSize().y - TextureManager::Instance()->textures["PlayerShip"].getSize().y * Ship->GetLocalScale().y - 50));
}

void PlayerShip::Update(float FDeltaTime)
{
	MotorVelocity();
	PerformMovement(FDeltaTime);
	LimitPosition();

	SpawnLaser();

	Actor::Update(FDeltaTime);
}

void PlayerShip::Destroy()
{
	Actor::Destroy();
}

Sprite* PlayerShip::GetSpriteShip() const
{
	return Ship;
}

void PlayerShip::MotorVelocity()
{
	// The player can only move horizontal
	Velocity.x = InputManager::Instance()->GetAxis(InputAxis::Horizontal);
}

void PlayerShip::LimitPosition()
{
	float bottom = Window::Instance()->GetWindow().getSize().y - TextureManager::Instance()->textures["PlayerShip"].getSize().y * Ship->GetLocalScale().y - 50;
	if (CTransform->GetWorldPosition().x > Window::Instance()->GetWindow().getSize().x - (TextureManager::Instance()->textures["PlayerShip"].getSize().x * Ship->GetLocalScale().x))
		CTransform->SetWorldPosition(sf::Vector2f(Window::Instance()->GetWindow().getSize().x - (TextureManager::Instance()->textures["PlayerShip"].getSize().x * Ship->GetLocalScale().x), bottom));
	else if (CTransform->GetWorldPosition().x < 0)
		CTransform->SetWorldPosition(sf::Vector2f(0, bottom));
}

void PlayerShip::SpawnLaser()
{
	if (InputManager::Instance()->GetActionDown(InputAction::Fire)) {
		PlayerLaser* laser = new PlayerLaser();
		laser->Start();
		sf::Vector2f Pos;
		
		Pos.x = GetComponent<Transform>()->GetWorldPosition().x + (TextureManager::Instance()->textures["PlayerShip"].getSize().x * Ship->GetLocalScale().x) / 2 - (TextureManager::Instance()->textures[laser->GetSpriteLaser()->GetTextureName()].getSize().x * laser->GetSpriteLaser()->GetLocalScale().x) / 2;
		Pos.y = GetComponent<Transform>()->GetWorldPosition().y - (TextureManager::Instance()->textures[laser->GetSpriteLaser()->GetTextureName()].getSize().y * laser->GetSpriteLaser()->GetLocalScale().y) / 2;
		laser->GetComponent<Transform>()->SetWorldPosition(Pos);

		IGameManager::Instance()->GetActiveScene().AddGameObject(laser);
	}
}


