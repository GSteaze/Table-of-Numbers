#ifndef TABLEOFNUMBERS_H
#define TABLEOFNUMBERS_H

using namespace std;

namespace tableofnumbers
{
	void InitializeList(double userInput[], int size, double defaultValue);

	void InvalidInput(double variable, int min, int max);

	void InputNumbers(double userInput[], int size);

	void TableBuilder(double numberOfValues, double firstNumber, double incrementNumber);

	double Square(double number);

	double SquareRoot(double number);
}

#endif

