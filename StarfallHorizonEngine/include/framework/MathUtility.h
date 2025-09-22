#pragma once

#include <SFML/Graphics.hpp>

namespace sh
{
	sf::Vector2f RotationToVector(float rotation); //convert rotation -> vector
	float DegreesToRadians(float degrees);
	float RadiansToDegrees(float radians);
}