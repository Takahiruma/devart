#ifndef CLASSFFT
#define CLASSFFT

#include <complex>
#include <valarray>
#include <vector>
#include <SFML/Audio.hpp>



typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
const double PI = 3.141592653589793238460;	//valeur de PI


//Classe FFT : Transformée de Fourier Rapide
class classFFT {
private:
	CArray data;
	std::vector<double> normData;

public:
	classFFT(const sf::Int16 *myarray, const int size);
	~classFFT();

	bool initFFT(CArray &x);
	void printData();
	void writeBinary();

	//GETTERS
	int getFundFreq();
	inline CArray getData() const { return data; } 

};
#endif