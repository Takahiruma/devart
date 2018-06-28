// dev_sound.cpp : définit le point d'entrée pour l'application console.
//
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>

#include <vector>
#include <utility>
#include <string>
#include <iostream>

int oui = 0;

int main()
{
	std::vector<std::pair<int, sf::CircleShape>> cir;

	sf::RenderWindow window(sf::VideoMode(800, 600, 32), "SFML test",
		sf::Style::Titlebar | sf::Style::Close);
	window.setVerticalSyncEnabled(true);

	while (window.isOpen()) {
		// Handle events
		sf::Event event;
		while (window.pollEvent(event)) {
			if ((event.type == sf::Event::Closed) ||
				((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape)))
			{
				window.close();
				break;
			}

			if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::R)) {
				sf::CircleShape circle;

				std::cout << "cercle" << std::endl;
				circle.setRadius(100);
				circle.setOutlineColor(sf::Color::Red);
				circle.setOutlineThickness(100);
				circle.setPosition(0, 0);
				std::cout << "radcercle " <<circle.getRadius()<<" position " << circle.getPosition().x<<" "<< circle.getPosition().y <<std::endl;
				cir.push_back(std::make_pair(oui, circle));
				++oui;
				window.draw(circle);
				break;
			}
		}

		if (!cir.empty()) {
			for (std::vector<std::pair<int, sf::CircleShape>>::iterator it = cir.begin(); it != cir.end(); ++it) {
				it->second.setOutlineColor(sf::Color::Green);
				window.draw(it->second);
			}
		}
	}

    return 0;
}

