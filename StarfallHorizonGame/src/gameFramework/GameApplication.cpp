#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"
#include "config.h"

sh::Application* GetApplication()
{
	return new sh::GameApplication{};
}

namespace sh
{
	GameApplication::GameApplication()
		: Application{ 600, 980, "Starfall Horizon", sf::Style::Titlebar | sf::Style::Close }
	{
		weak<World> newWorld = LoadWorld<World>();
		newWorld.lock()->SpawnActor<Actor>();

		actorToDestroy = newWorld.lock()->SpawnActor<Actor>();
		actorToDestroy.lock()->SetTexture(GetResourceDir() + "SpaceShooterRedux/PNG/playerShip1_blue.png");

		counter = 0;
	}

	void GameApplication::Tick(float deltaTime)
	{
		counter += deltaTime;
		if (counter > 2.f)
		{
			if (actorToDestroy.expired())
			{
				actorToDestroy.lock()->Destroy();
			}
		}
	}
}

