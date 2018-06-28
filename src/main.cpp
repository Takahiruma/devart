// dev_sound.cpp : définit le point d'entrée pour l'application console.
//
#include <vector>
#include <utility>
#include <string>
#include <time.h>
#include <string>
#include <cmath>

#include "maman_onde.hpp"
#include "classFFT.h"


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
		std::string name_file;
		std::cout << "please enter the name of the file" << std::endl;
		std::cin >> name_file;

		sf::SoundBuffer buffer;

		/*if (buffer.loadFromFile(name_file)) {
			std::cout << "let's start !!!" << std::endl;

			const sf::Int16 * samp = new sf::Int16[1000];

			samp = buffer.getSamples();
			classFFT fourrier(samp, 1000);

			int fond = fourrier.getFundFreq();*/

		std::cout << "Entrez une frequence>" << std::endl;
		int fond;
		std::cin >> fond;

		float demi_ton = 12.0f * log2(fond / 440.0f);

		float part_virg = demi_ton - int(demi_ton);

		int IntDemiTon;
		if (part_virg > 0.5)
			IntDemiTon = int(demi_ton += 1);
		else
			IntDemiTon = int(demi_ton);

		int reste = IntDemiTon % 12;
		int quotient = IntDemiTon / 12;

		if (reste < 0) {
			reste += 12;
			quotient -= 1;
		}



		std::cout << "IntDemiTon " << IntDemiTon << std::endl;

		/*delete[] samp;
		}
		else {
			std::cout << "the file couldn't load sry" << std::endl;
		}*/
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

