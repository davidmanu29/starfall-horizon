#include <iostream>
#include <SFML/graphics.hpp>
int main()
{
	sf::RenderWindow renderWin{ sf::VideoMode(100,100), "MyWindow" };

	std::cout << "Hello Worlds" << std::endl;
}