#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"

sh::Application* GetApplication()
{
	return new sh::GameApplication{};
}

namespace sh
{
	GameApplication::GameApplication()
	{
		weak<World> newWorld = LoadWorld<World>();
		newWorld.lock()->SpawnActor<Actor>();
	}
}

