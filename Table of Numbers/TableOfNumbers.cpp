#include <iostream>
#include <fstream>

#include "TableOfNumbers.h"

using namespace std;

const int kEndOfLine = 1024;

namespace tableofnumbers
{
	void InitializeList(double list[], int size, double defaultValue)
	{
		for (int index = 0; index < size; index++)
		{
			list[index] = defaultValue;
		}
	}

	void InvalidInput(double variable, int min, int max)
	{
		bool isInvalid = cin.fail() || (variable < min || variable > max);
		while (isInvalid)
		{
			cin.clear();
			cin.ignore(kEndOfLine, '\n');
			cout << "Please Try Again : " << endl;
			cin >> variable;
			isInvalid = cin.fail() || (variable < min || variable > max);
		}
	}
	
	void InputNumbers(double userInput[], int size)
	{
		double numberOfValues = 0;
		double firstValue = 0;
		double incrementNumber = 0;

		cout << "Enter a number between 1 and 25 : ";
		cin >> numberOfValues;
		InvalidInput(numberOfValues, 1, 25);

		cout << "Enter the first value in table between -1,000 and 1,000 : ";
		cin >> firstValue;
		InvalidInput(firstValue, -1000, 1000);

		cout << "Enter increment value between 1 and 20 : ";
		cin >> incrementNumber;
		InvalidInput(incrementNumber, 1, 20);

		userInput[0] = numberOfValues;
		userInput[1] = firstValue;
		userInput[2] = incrementNumber;
	}
}