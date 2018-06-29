#ifndef AMPLITUDE_H
#define AMPLITUDE_H

#include <SFML/Audio.hpp>


class Amplitude
{
private:
	const sf::Int16 *buffer;
	int size;

public:
	Amplitude(const sf::Int16 *_buffer, int _size);
	~Amplitude();

	//GETTER
	int getMax();
	int getMin();
	int getAmplitude();
};
#endif 
