#include <iostream>
#include "classFFT.h"
#include "Amplitude.h"

using namespace std;


int main()
{
	//VARIABLES 
	const int SIZE = 8;
	const sf::Int16 *test = new sf::Int16[SIZE];	// <--- Là là là les valeurs du buffer là

	//FFT
	cout << "FFT" << endl;
	classFFT FFT(test, SIZE);

	FFT.printData();

	//FREQUENCE FONDAMENTALE
	cout << "FREQUENCE FONDAMENTALE : " << FFT.getFundFreq() << endl;

	//ECRITURE FICHIER BINAIRE
	FFT.writeBinary();


	//AMPLITUDE
	Amplitude ampli(test, SIZE);
	cout << "AMPLITUDE : " << ampli.getAmplitude() << endl;

	//PERSISTANCE DE LA CONSOLE
	char c;
	cout << "appuyez sur une touche pour terminer" << endl;
	cin >> c;

	delete [] test;

	return 0;
}

