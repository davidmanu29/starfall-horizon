#include "framework/Application.h"
#include <iostream>

namespace sh
{
	Application::Application()
		: mWindow{ sf::VideoMode(900,800), "Starfall Horizon" },
		mTargetFramerate(60.f),
		mTickClock{}
	{
		
	}	
	
	void Application::Run()
	{
		mTickClock.restart();
		float accumulatedTime = 0.f;
		float targetDeltaTime = 1.f / mTargetFramerate; // 1 second / 60 fps

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

			accumulatedTime += mTickClock.restart().asSeconds();
			while (accumulatedTime > targetDeltaTime)
			{
				accumulatedTime -= targetDeltaTime;
				Tick(targetDeltaTime);
				Render();
			}
		}
	}

	void Application::Tick(float deltaTime)
	{
		std::cout << "ticking at framerate: " << 1.f / deltaTime << std::endl;
	}

	void Application::Render()
	{

	}
}