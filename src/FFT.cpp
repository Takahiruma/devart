#include <iostream>
#include "classFFT.h"

using namespace std;


int main()
{
	//VARIABLES
	const Complex test[] = { 1.0, 1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0 };
	int size = 8;
	CArray data(test, size);

	//FFT
	cout << "FFT" << endl;
	classFFT FFT(data);

	FFT.printData();

	//PERSISTANCE DE LA CONSOLE
	char c;
	cout << "appuyez sur une touche pour terminer" << endl;
	cin >> c;

	return 0;
}

