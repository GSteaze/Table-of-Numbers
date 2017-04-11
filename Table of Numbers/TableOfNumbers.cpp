#include <iostream>
#include <fstream>
#include <iomanip>

#include "TableOfNumbers.h"

using namespace std;

const int kEndOfLine = 1024;
const double kEpsilon = 0.0001;
const int kColumnWidthOne = 12;
const double kSmallestCubeRoot = 2.0;
const double kOneThird = 0.33333333333333333333333;
const double kTwo = 2.0;
const int kDefaultListSize = 25;

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
		if (number > -1)
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
		else
		{
			return 1001;
		}
	}

	bool IsEven(int number)
	{
		bool isEven = number % 2 == 0;
		return isEven;
	}

	bool IsPrime(int number)
	{
		bool isPrime = 1;
		double halfTheNumber = number / 2;

		for (int index = 2; index <= halfTheNumber; index++)
		{
			if (number % index == 0)
			{
				isPrime = 0;
				return isPrime;
			}
		}
		return isPrime;
	}

	int NumberOfDivisors(int number)
	{
		if (number < 0)
		{
			number = number * -1;
		}

		int counter = 0;

		for (int index = 1; index < number; index++)
		{
			if (number % index == 0)
			{
				counter++;
			}
		}

		return counter;
	}

	void DivisorsOfNumber(int number, double divisors[], int listSize, int numberOfDivisors)
	{
		if (number < 0)
		{
			number = number * -1;
		}

		for (int index = 1; index <= number; index++)
		{
			if (number % index == 0)
			{
				divisors[index - 1] = index;
			}
		}
	}
	
	bool IsPerfect(int number, double divisors[], int listSize)
	{
		int numberOfDivisors = NumberOfDivisors(number);
		DivisorsOfNumber(number, divisors, listSize, numberOfDivisors);
		if (number < 0)
		{
			number = number * -1;
		}

		int sumOfDivisors = 0;
		for (int index = 0; index < numberOfDivisors; index++)
		{
			sumOfDivisors += divisors[index];
		}
		bool isPerfect = number == sumOfDivisors;
		return isPerfect;
	}

	void CalculateResults(double numberOfValues, double square[], double squareRoot[], double cube[], double cubeRoot[],
		double evenOrOdd[], double primeOrNot[], double perfectOrNot[], double divisors[], int size)
	{
		ifstream fin;
		fin.open("NumberTable.txt");

		double number = 0;

		for (int index = 0; index < numberOfValues; index++)
		{
			fin >> number;
			square[index] = Square(number);
			squareRoot[index] = SquareRoot(number);
			cube[index] = Cube(number);
			cubeRoot[index] = CubeRoot(number);
			evenOrOdd[index] = IsEven(number);
			primeOrNot[index] = IsPrime(number);
			perfectOrNot[index] = IsPerfect(number, divisors, kDefaultListSize);
		}

		fin.close();
	}

	void DisplayResults(double square[], double squareRoot[], double cube[], double cubeRoot[],
		double evenOrOdd[], double primeOrNot[], double perfectOrNot[], int size)
	{
		cout << "Square : ";
		for (int index = 0; index < size; index++)
		{
			cout << square[index] << " ";
		}
		cout << endl;

		cout << "Square Root : ";
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

		cout << "Cube : ";
		for (int index = 0; index < size; index++)
		{
			cout << cube[index] << " ";
		}
		cout << endl;

		cout << "Cube Root : ";
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

		cout << "Even or Odd : ";
		for (int index = 0; index < size; index++)
		{
			if (evenOrOdd[index] == 1)
			{
				cout << "Even ";
			}
			else
			{
				cout << "Odd ";
			}
		}
		cout << endl;

		cout << "Prime or Not : ";
		for (int index = 0; index < size; index++)
		{
			if (primeOrNot[index] == 1)
			{
				cout << "True ";
			}
			else
			{
				cout << "False ";
			}
		}
		cout << endl;

		cout << "Perfect or Not : ";
		for (int index = 0; index < size; index++)
		{
			if (perfectOrNot[index] == 1)
			{
				cout << "True ";
			}
			else
			{
				cout << "False ";
			}
		}
		cout << endl;
	}

	void PrintResults(double square[], double squareRoot[], double cube[], double cubeRoot[],
		double evenOrOdd[], double primeOrNot[], double perfectOrNot[], int size)
	{
		ofstream fout;
		fout.open("Results.csv");

		fout << setw(kColumnWidthOne) << "Square : ";
		for (int index = 0; index < size; index++)
		{
			fout << square[index] << ",";
		}
		fout << '\n';

		fout << setw(kColumnWidthOne) << "Square Root : ";
		for (int index = 0; index < size; index++)
		{
			fout << squareRoot[index] << ",";
		}
		fout << '\n';

		fout << setw(kColumnWidthOne) << "Cube : ";
		for (int index = 0; index < size; index++)
		{
			fout << cube[index] << ",";
		}
		fout << '\n';

		fout << setw(kColumnWidthOne) << "Cube Root : ";
		for (int index = 0; index < size; index++)
		{
			fout << cubeRoot[index] << ",";
		}
		fout << '\n';

		fout << setw(kColumnWidthOne) << "Even or Odd : ";
		for (int index = 0; index < size; index++)
		{
			if (evenOrOdd[index] == 1)
			{
				fout << "Even,";
			}
			else
			{
				fout << "Odd,";
			}
		}
		fout << '\n';

		fout << setw(kColumnWidthOne) << "Prime or Not : ";
		for (int index = 0; index < size; index++)
		{
			if (primeOrNot[index] == 1)
			{
				fout << "True,";
			}
			else
			{
				fout << "False,";
			}
		}
		fout << '\n';

		fout << setw(kColumnWidthOne) << "Perfect or Not : ";
		for (int index = 0; index < size; index++)
		{
			if (perfectOrNot[index] == 1)
			{
				fout << "True,";
			}
			else
			{
				fout << "False,";
			}
		}
		fout << '\n';
	}

	void TestCode()
	{
		cout << "Testing..." << endl << endl;

		cout << "InitializeList" << endl;
		double listOne[3];
		double listTwo[5];
		InitializeList(listOne, 3, 4);
		InitializeList(listTwo, 5, 2);
		cout << "listOne : ";
		for (int index = 0; index < 3; index++)
		{
			cout << listOne[index] << " ";
		}
		cout << endl << "listTwo : ";
		for (int index = 0; index < 5; index++)
		{
			cout << listTwo[index] << " ";
		}

		cout << endl << "NumberOfDivisors" << endl;
		cout << NumberOfDivisors(2) << " ";
		cout << NumberOfDivisors(4) << " ";

		cout << endl << "DivisorsOfNumber" << endl;
		double testDivisorsOne[kDefaultListSize];
		InitializeList(testDivisorsOne, kDefaultListSize, 0);
		double testDivisorsTwo[kDefaultListSize];
		InitializeList(testDivisorsTwo, kDefaultListSize, 0);
		int numberOfDivisorsSix = NumberOfDivisors(6);
		DivisorsOfNumber(6, testDivisorsOne, kDefaultListSize, numberOfDivisorsSix);
		cout << "Six : ";
		for (int index = 0; index < numberOfDivisorsSix; index++)
		{
			cout << testDivisorsOne[index] << " ";
		}
		cout << endl;
		int numberOfDivisorsFour = NumberOfDivisors(4);
		DivisorsOfNumber(4, testDivisorsTwo, kDefaultListSize, numberOfDivisorsFour);
		cout << "Four : ";
		for (int index = 0; index < numberOfDivisorsFour; index++)
		{
			cout << testDivisorsTwo[index] << " ";
		}
		cout << endl;
		//All other methods tested and shown directly in output of code
	}
}