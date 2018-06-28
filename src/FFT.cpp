#include <iostream>
#include "classFFT.h"

using namespace std;


int main()
{
	//VARIABLES 
	const int SIZE = 8;
	const sf::Int16 *test = new sf::Int16[SIZE];	// <--- Là là là les valeurs du buffer là

	//FFT
	cout << "FFT" << endl;
	classFFT FFT(test, SIZE);
	delete [] test;

	FFT.printData();

	//FREQUENCE FONDAMENTALE
	cout << "FREQUENCE FONDAMENTALE : " << FFT.getFundFreq() << endl;

	//PERSISTANCE DE LA CONSOLE
	char c;
	cout << "appuyez sur une touche pour terminer" << endl;
	cin >> c;

	return 0;
}

