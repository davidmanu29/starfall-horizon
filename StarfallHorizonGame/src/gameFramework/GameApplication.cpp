#include "gameFramework/GameApplication.h"
#include "framework/World.h"

sh::Application* GetApplication()
{
	return new sh::GameApplication{};
}

namespace sh
{
	GameApplication::GameApplication()
	{
		LoadWorld<World>();
	}
}

