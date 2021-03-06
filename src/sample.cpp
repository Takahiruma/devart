
////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Audio.hpp>
#include <iostream>
#include <string>


////////////////////////////////////////////////////////////
/// Entry point of application
///
/// \return Application exit code
///
////////////////////////////////////////////////////////////
using namespace std;
int main()
{
	// Wait for user input...
	string name_file;
	std::cout << "please enter the name of the file" << endl;
	std::cin >> name_file;

	sf::SoundBuffer buffer;

	if (buffer.loadFromFile(name_file)) {
		cout << "je charge" << endl;
		const sf::Int16 * samp = new sf::Int16;

		samp = buffer.getSamples();
		for (sf::Int16 i = 0; i < 10; ++i)
			cout << samp[i] << endl;
	}
	else {
		cout << "the file couldn't load sry" << endl;
	}


	// Finished!
	std::cout << std::endl << "Done!" << std::endl;


	return EXIT_SUCCESS;
}
