#ifndef CLASSFFT
#define CLASSFFT

#include <complex>
#include <valarray>

typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
const double PI = 3.141592653589793238460;	//valeur de PI


//Classe FFT : Transformée de Fourier Rapide
class classFFT {
private:
	CArray data;

public:
	classFFT(CArray &_data);
	~classFFT();

	bool initFFT(CArray &x);
	void printData();
	inline CArray getData() { return data; }
};
#endif