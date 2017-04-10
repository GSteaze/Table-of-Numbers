#include <iostream>
#include <fstream>
#include <iomanip>

#include "TableOfNumbers.h"

using namespace std;

const int kEndOfLine = 1024;
const double kEpsilon = 0.0001;
const int kColumnWidthOne = 20;
const double kSmallestCubeRoot = 2.0;
const double kOneThird = 0.33333333333333333333333;
const double kTwo = 2.0;

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
			int counter = 0;
			bool isGreaterThanEpsilon = (lastGuess - nextGuess) > kEpsilon;
			while (isGreaterThanEpsilon)
			{
				if (counter != 0)
				{
					lastGuess = nextGuess;
				}
				nextGuess = (lastGuess + (number / lastGuess)) / 2;
				if ((lastGuess - nextGuess) < 0)
				{
					isGreaterThanEpsilon = ((lastGuess - nextGuess) * -1 ) > kEpsilon;
				}
				else
				{
					isGreaterThanEpsilon = (lastGuess - nextGuess) > kEpsilon;
				}
				counter++;
			} 
			return nextGuess;
		}
		else
		{
			return 1001;
		}
	
	}

	double Cube(double number)
	{
		return number * number * number;
	}

	double CubeRoot(double number)
	{
		double firstNumber = kSmallestCubeRoot;
		double holderNumber = kSmallestCubeRoot;
		while (holderNumber < number)
		{
			holderNumber = firstNumber;
			holderNumber = Cube(firstNumber);
			if (holderNumber < number)
			{
				firstNumber++;
			}
		}
		double firstGuess = (firstNumber + 1) / firstNumber;

		double nextGuess = 1.0;
		bool isGreaterThanEpsilon = (firstGuess - nextGuess) > kEpsilon;
		int counter = 0;
		
		while (isGreaterThanEpsilon)
		{
			if (counter != 0)
			{
				firstGuess = nextGuess;
			}
			nextGuess = (kOneThird) * ((kTwo * firstGuess) + (number / Square(firstGuess)));
			
			if ((firstGuess - nextGuess) < 0)
			{
				isGreaterThanEpsilon = ((firstGuess - nextGuess) * -1) > kEpsilon;
			}
			else
			{
				isGreaterThanEpsilon = (firstGuess - nextGuess) > kEpsilon;
			}

			counter++;
		}
		return nextGuess;
	}

	bool IsEven(int number)
	{
		bool isEven = number % 2 == 0;
		return isEven;
	}

	void CalculateResults()
	{

	}

	void DisplayResults(double square[], double squareRoot[], double cube[], double cubeRoot[],
		double evenOrOdd[], double primeOrNot[], double perfectOrNot[], int size)
	{
		cout << setw(kColumnWidthOne) << "Square : ";
		for (int index = 0; index < size; index++)
		{
			cout << square[index] << " ";
		}
		cout << endl;

		cout << setw(kColumnWidthOne) << "Square Root : ";
		for (int index = 0; index < size; index++)
		{
			if (squareRoot[index] == 1001)
			{
				cout << "N/A";
			}
			else
			{
				cout << squareRoot[index] << " ";
			}
		}
		cout << endl;

		cout << setw(kColumnWidthOne) << "Cube : ";
		for (int index = 0; index < size; index++)
		{
			cout << cube[index] << " ";
		}
		cout << endl;

		cout << setw(kColumnWidthOne) << "Cube Root : ";
		for (int index = 0; index < size; index++)
		{
			if (cubeRoot[index] == 1001)
			{
				cout << "N/A";
			}
			else
			{
				cout << cubeRoot[index] << " ";
			}
		}
		cout << endl;

		cout << setw(kColumnWidthOne) << "Even or Odd : ";
		for (int index = 0; index < size; index++)
		{
			cout << evenOrOdd[index] << " ";
		}
		cout << endl;

		cout << setw(kColumnWidthOne) << "Prime or Not : ";
		for (int index = 0; index < size; index++)
		{
			cout << primeOrNot[index] << " ";
		}
		cout << endl;

		cout << setw(kColumnWidthOne) << "Perfect or Not : ";
		for (int index = 0; index < size; index++)
		{
			cout << perfectOrNot[index] << " ";
		}
		cout << endl;
	}

	void PrintResults(double square[], double squareRoot[], double cube[], double cubeRoot[],
		double evenOrOdd[], double primeOrNot[], double perfectOrNot[], int size)
	{
		ofstream fout;
		fout.open("Results.txt");

		cout << setw(kColumnWidthOne) << "Square : ";
		for (int index = 0; index < size; index++)
		{
			cout << square[index] << " ";
		}
		cout << endl;

		cout << setw(kColumnWidthOne) << "Square Root : ";
		for (int index = 0; index < size; index++)
		{
			cout << squareRoot[index] << " ";
		}
		cout << endl;

		cout << setw(kColumnWidthOne) << "Cube : ";
		for (int index = 0; index < size; index++)
		{
			cout << cube[index] << " ";
		}
		cout << endl;

		cout << setw(kColumnWidthOne) << "Cube Root : ";
		for (int index = 0; index < size; index++)
		{
			cout << cubeRoot[index] << " ";
		}
		cout << endl;

		cout << setw(kColumnWidthOne) << "Even or Odd : ";
		for (int index = 0; index < size; index++)
		{
			cout << evenOrOdd[index] << " ";
		}
		cout << endl;

		cout << setw(kColumnWidthOne) << "Prime or Not : ";
		for (int index = 0; index < size; index++)
		{
			cout << primeOrNot[index] << " ";
		}
		cout << endl;

		cout << setw(kColumnWidthOne) << "Perfect or Not : ";
		for (int index = 0; index < size; index++)
		{
			cout << perfectOrNot[index] << " ";
		}
		cout << endl;
	}

}