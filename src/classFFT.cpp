#include <iostream>
#include <math.h>
#include "classFFT.h"

using namespace std;


classFFT::classFFT(const sf::Int16 *myarray, const int size)
{
	Complex *temp = new Complex[size];
	for (size_t i = 0; i < size; ++i)
		temp[i] = myarray[i];

	CArray _data(temp, size);
	delete[] temp;
	data = _data;

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


// ////////////////////////////////////////////// //
// OBTENIR LA VALEUR DE LA FREQUENCE FONDAMENTALE //
// ////////////////////////////////////////////// //
int classFFT::getFundFreq()
{
	int fund    = 0;
	int offset  = 0;
	double max = 0.0;
	int cpt     = 0;
	double temp = 0.0;

	for (auto it = begin(data); it != end(data); ++it)
	{
		temp = norm(*it);
		++cpt;

		if (temp > max)
		{
			max = temp;
			offset = cpt;
		}
	}
	
	cout << "Maximum : " << max << " Offset : " << offset << endl;
	fund = int(offset)/2;
	return fund;
}
