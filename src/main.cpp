// dev_sound.cpp : définit le point d'entrée pour l'application console.
//
#include <vector>
#include <utility>
#include <string>
#include <time.h>

#include "maman_onde.hpp"

float scale = 1.001;

int rand_a_b(int a, int b)
{
	return rand() % (b - a) + a;
}

int main()
{
	srand(time(nullptr));
	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "SFML test",
		sf::Style::Titlebar | sf::Style::Close);
	window.setVerticalSyncEnabled(true);

	sf::Clock timer;
	GestionOnde GOnde;

	while (window.isOpen()) {
		// Handle events
		sf::Event event;
		while (window.pollEvent(event)) {
			if ((event.type == sf::Event::Closed) ||
				((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
			{
				window.close();
			}

			else if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::R)) {
				Onde onde(400,10,1,5);
				
				onde.setRadius(5);
				onde.setFillColor(sf::Color::Transparent);
				onde.setOutlineColor(sf::Color::Red);
				onde.setOutlineThickness(1);

				int x = rand_a_b(0,window.getSize().x);
				int y = rand_a_b(0, window.getSize().y);

				onde.setPosition(x,y);

				GOnde.addOnde(onde);
			}
		}
		
		GOnde.update();

		GOnde.drawOnde(window);
		window.display();
	}

    return 0;
}

