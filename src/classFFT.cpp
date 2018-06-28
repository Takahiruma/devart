#include <iostream>
#include "classFFT.h"

using namespace std;


classFFT::classFFT(CArray &_data)
	:data(_data)
{
	initFFT(data);
}


classFFT::~classFFT()
{}


// ///////////////////////////// //
// TRANSFORMEE DE FOURIER RAPIDE //
// ///////////////////////////// //
bool classFFT::initFFT(CArray &x)
{
	const size_t SIZE = x.size();		//taille du tablal
	if (SIZE <= 1)
		return false;

	//SEPARATION EN DEUX DU TABLAL
	CArray first  = x[slice(0, SIZE / 2, 2)];
	CArray second = x[slice(1, SIZE / 2, 2)];

	//RECURSIVITE
	initFFT(first);
	initFFT(second);

	//COMBINAISON DES RESULTATS
	for (size_t i = 0; i < SIZE / 2; ++i)
	{
		Complex temp = polar(1.0, -2 * PI * i / SIZE) * second[i];
		x[i] = first[i] + temp;
		x[i + SIZE / 2] = first[i] - temp;
	}

	return true;
}


// ////////////////////////////////// //
// AFFICHAGE DES VALEURS TRANSFORMEES //
// ////////////////////////////////// //
void classFFT::printData()
{
	for (size_t i = 0; i < data.size(); ++i) 
		cout << "Fourier " << i << " " << data[i] << endl;
}