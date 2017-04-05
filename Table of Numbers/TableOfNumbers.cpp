#include <iostream>
#include <fstream>

#include "TableOfNumbers.h"

using namespace std;

const int kEndOfLine = 1024;
const double kEpsilon = 0.0001;

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

		cout << "Enter number of values in table (between 1 and 25) : ";
		cin >> numberOfValues;
		InvalidInput(numberOfValues, 1, 25);

		cout << "Enter the first value in table (between -1,000 and 1,000) : ";
		cin >> firstValue;
		InvalidInput(firstValue, -1000, 1000);

		cout << "Enter increment value (between 1 and 20) : ";
		cin >> incrementNumber;
		InvalidInput(incrementNumber, 1, 20);

		userInput[0] = numberOfValues;
		userInput[1] = firstValue;
		userInput[2] = incrementNumber;
	}

	void TableBuilder(double numberOfValues, double firstNumber, double incrementNumber)
	{
		ofstream fout;
		fout.open("NumberTable.txt");
		double number = firstNumber;
		fout << firstNumber << endl;
		int index = 0;
		while (numberOfValues > index)
		{
			number += incrementNumber;
			fout << number << endl;
			index++;
		}
		fout.close();
	}
	
	double Square(double number)
	{
		return number * number;
	}

	double SquareRoot(double number)
	{
		 if (number > -1)
		{
			double lastGuess = 1.0;
			double nextGuess = 0.0;
			while ((lastGuess - nextGuess) > kEpsilon)
			{
				nextGuess = ((lastGuess + number) / lastGuess) / 2;
				lastGuess = nextGuess;
			}
			return nextGuess;
		}
		else
		{
			return 1001;
		}
	
	}
}