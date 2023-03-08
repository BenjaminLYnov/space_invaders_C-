#include "Level01.h"

#include <Engine/Gameplay/GameObject/Actors/Alien.h>
#include <Engine/Gameplay/GameObject/Actors/AlienLaser.h>
#include <Engine/Gameplay/GameObject/Actors/PlayerLaser.h>
#include <Engine/Gameplay/GameObject/Actors/PlayerShip.h>
#include <Engine/Math/Random/RandomNumber.h>

void Level01::StartGame()
{
	Vector2D size(80, 28);
	Renderer consoleRenderer(size);
	PlayField world(size);

	// Populate aliens
	for (int k = 0; k < 10; k++)
	{
		Alien& a = *(new Alien);
		a.pos.x = RandomNumber::RandomFloat(0, (int)size.x - 1);
		a.pos.y = RandomNumber::RandomFloat(0, 10);
		world.AddObject(&a);
	}

	// Add player
	PlayerShip* p = new PlayerShip;
	p->pos = Vector2D(40, 27);
	world.AddObject(p);

	while (true)
	{
		world.Update();

		RenderItemList rl;
		for (auto it : world.GameObjects())
		{
			RenderItem a = RenderItem(Vector2D(it->pos), it->sprite);
			rl.push_back(a);
		}

		consoleRenderer.Update(rl);

		if (world.PlayerIsDead())
		{
			std::cout << "GAME OVER";
			break;
		}

		//Sleep a bit so updates don't run too fast
		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}
}