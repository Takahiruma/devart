#include "Amplitude.h"


Amplitude::Amplitude(const sf::Int16 *_buffer, int _size)
	:buffer(_buffer), size(_size)
{
	
}


Amplitude::~Amplitude()
{

}


// //////////////////////// //
// VALEUR MAXIMUM DU BUFFER //
// //////////////////////// //
int Amplitude::getMax()
{
	sf::Int16 max = 0;
	for (size_t i = 0; i < size; ++i)
	{
		if (buffer[i] > max)
			max = buffer[i];
	}

	return max;
}


// //////////////////////// //
// VALEUR MINIMUM DU BUFFER //
// //////////////////////// //
int Amplitude::getMin()
{
	int min = buffer[0];				//première valeur du buffer
	for (size_t i = 0; i < size; ++i)
	{
		if (buffer[i] < min)
			min = buffer[i];
	}

	return min;
}

int Amplitude::getAmplitude()
{
	int max = getMax();
	int min = getMin();
	int amplitude = max - min;

	return amplitude;
}
