#pragma once
#include <SFML/Graphics.hpp>

namespace sh
{
	class Application
	{
	public:
		Application();
		void Run();
	private:
		void Tick(float deltaTime);
		void Render();

		sf::RenderWindow mWindow;
		float mTargetFramerate;
		sf::Clock mTickClock;
	};
}