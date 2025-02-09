#pragma once

namespace sh
{
	class World;
	class Actor
	{
	public:
		Actor(World* owningWorld);
		virtual ~Actor();

		void BeginPlayInternal();
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);

	private:
		World* mOwningWorld;
		bool mHasBeganPlay;
	};
}