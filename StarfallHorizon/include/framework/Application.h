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
		sf::RenderWindow mWindow;
	};
}