#pragma once
#include "framework/Object.h"
#include "framework/Core.h"
#include "SFML/Graphics.hpp"

namespace sh
{
	class World;
	class Actor : public Object
	{
	public:
		Actor(World* owningWorld, const std::string& texturePath = "");
		virtual ~Actor();

		void BeginPlayInternal();
		void TickInternal(float deltaTime);
		virtual void BeginPlay();
		virtual void Tick(float deltaTime);

		void SetTexture(const std::string& texturePath);
		void Render(sf::RenderWindow& window);

	private:
		World* mOwningWorld;
		bool mHasBeganPlay;

		sf::Sprite mSprite;
		sf::Texture mTexture;
	};
}