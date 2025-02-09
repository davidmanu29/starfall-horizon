#include "framework/Actor.h"
#include "framework/Core.h"

namespace sh
{
	Actor::Actor(World* owningWorld)
		: mOwningWorld{ owningWorld },
		mHasBeganPlay{ false }
	{

	}

	Actor::~Actor()
	{

	}

	void Actor::BeginPlayInternal()
	{
		if (!mHasBeganPlay)
		{
			mHasBeganPlay = true;
			BeginPlay();
		}
	}

	void Actor::BeginPlay()
	{
		LOG("Actor begin play");
	}

	void Actor::Tick(float deltaTime)
	{
		LOG("Actor tick at: %f", 1.f / deltaTime);
	}
}