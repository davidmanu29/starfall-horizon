#include <iostream>
#include <memory>
#include <SFML/graphics.hpp>

#include "framework/Application.h"

int main()
{
	std::unique_ptr<sh::Application> app = std::make_unique<sh::Application>();
	app->Run();
}