#include "framework/World.h"
#include <framework/Core.h>

namespace sh
{
	World::World(Application* owningApp)
		:mOwningApp{ owningApp },
		mBeganPlay{ false }
	{

	}

	World::~World()
	{

	}

	void World::BeginPlayInternal()
	{
		if (!mBeganPlay)
		{
			mBeganPlay = true;
			BeginPlay();
		}
	}

	void World::Tick(float deltaTime)
	{
		LOG("Tick at framerate: %f", 1.f/deltaTime);
	}

	void World::TickInternal(float deltaTime)
	{
		Tick(deltaTime);
	}

	void World::BeginPlay()
	{
		LOG("began play");
	}
}
