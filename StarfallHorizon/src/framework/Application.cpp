#include "framework/Application.h"

namespace sh
{
	Application::Application()
		: mWindow{ sf::VideoMode(900,800), "Starfall Horizon"}
	{
		
	}

	void Application::Run()
	{
		while (mWindow.isOpen())
		{
			sf::Event windowEvent;
			while (mWindow.pollEvent(windowEvent))
			{
				if (windowEvent.type == sf::Event::EventType::Closed)
				{
					mWindow.close();
				}
			}
		}
	}
}