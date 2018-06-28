#ifndef CLASSFFT
#define CLASSFFT

#include <complex>
#include <valarray>
#include <SFML/Audio.hpp>


typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
const double PI = 3.141592653589793238460;	//valeur de PI


//Classe FFT : Transform�e de Fourier Rapide
class classFFT {
private:
	CArray data;

public:
	classFFT(const sf::Int16 *myarray, const int size);
	~classFFT();

	bool initFFT(CArray &x);
	void printData();

	//GETTERS
	double getFundFreq();
	inline CArray getData() const { return data; } 

};
#endif