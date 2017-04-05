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
	double numberOfValues = userInput[0];
	double firstNumber = userInput[1];
	double incrementValue = userInput[2];
	TableBuilder(numberOfValues, firstNumber, incrementValue);

	return 0;
}