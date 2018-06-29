#include <iostream>
#include <math.h>
#include <cmath>
#include <stdio.h>
#include "classFFT.h"

using namespace std;


classFFT::classFFT(const sf::Int16 *myarray, const int size)
{
	Complex *temp = new Complex[size];
	for (size_t i = 0; i < size; ++i)
	{
		temp[i] = myarray[i];
	}

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

// /////////////////////////////////////////////////////////// //
// ECRITURE DES MODULES DES FREQUENCES DANS UN FICHIER BINAIRE //
// /////////////////////////////////////////////////////////// //
void classFFT::writeBinary()
{
	FILE *file;

	file = fopen("binaryData.raw", "wb");						//ouverture en mode écriture binaire
	fwrite(&normData, sizeof(normData), normData.size(), file);	//écriture dans le fichier
}


// ////////////////////////////////////////////// //
// OBTENIR LA VALEUR DE LA FREQUENCE FONDAMENTALE //
// ////////////////////////////////////////////// //
int classFFT::getFundFreq()
{
	int fund    = 0;
	int offset  = 0;
	double max = 0.0;
	double temp = 0.0;

	for (int i = 0; i < data.size(); ++i)
	{
		temp = norm(data[i]);
		normData.push_back(temp);
		//temp = data[i].real()*data[i].real() + data[i].imag()*data[i].imag();
		//double temp2 = std::sqrt(2,temp);
		if (temp > max)
		{
			max = temp;
			offset = i;
		}
	}
	
	cout << "Maximum : " << max << " Offset : " << offset << " mon bzi : " << data[offset].real() << endl;
	fund = offset/2;
	return fund;
}
