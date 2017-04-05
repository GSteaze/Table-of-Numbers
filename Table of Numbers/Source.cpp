#include <iostream>
#include <fstream>

#include "TableOfNumbers.h"

using namespace std;
using namespace tableofnumbers;

int main()
{
	double userInput[3];
	InitializeList(userInput, 3, 0.0);
	InputNumbers(userInput, 3);
	

	return 0;
}