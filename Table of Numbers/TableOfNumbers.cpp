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
	/*
	Fills a specified array with a default value

	@param list[] the array to be iniatialized
	@param size the size of the array
	@param the default value to be inserted into the array
	*/
	void InitializeList(double list[], int size, double defaultValue)
	{
		for (int index = 0; index < size; index++)
		{
			list[index] = defaultValue;
		}
	}

	/*
	Tests to see if the values are the proper type and within a specified range

	@param variable the input from the user
	@param minimum the minimum value of the desired range
	@param maximum the maximum value of the desired range
	*/
	double InvalidInput(double variable, int min, int max)
	{
		bool isInvalid = cin.fail() || (variable < min || variable > max);
		while (isInvalid)
		{
			cin.clear();
			cin.ignore(kEndOfLine, '\n');
			cout << "Please Try Again : ";
			cin >> variable;
			isInvalid = cin.fail() || (variable < min || variable > max);
		}
		return variable;
	}
	
	/*
	Prompts the user and extracts the data for table size, starting value, and increment value

	@param userInput[] the array that will hold the extracted data
	@param size the size of the array
	*/
	void InputNumbers(double userInput[], int size)
	{
		double numberOfValues = 0;
		double firstValue = 0;
		double incrementNumber = 0;

		cout << "Enter number of values in table (between 1 and 25) : ";
		cin >> numberOfValues;
		numberOfValues = InvalidInput(numberOfValues, 1, 25);

		cout << "Enter the first value in table (between -1,000 and 1,000) : ";
		cin >> firstValue;
		firstValue = InvalidInput(firstValue, -1000, 1000);

		cout << "Enter increment value (between 1 and 20) : ";
		cin >> incrementNumber;
		incrementNumber = InvalidInput(incrementNumber, 1, 20);

		userInput[0] = numberOfValues;
		userInput[1] = firstValue;
		userInput[2] = incrementNumber;
	}

	/*
	Builds a table using the InputNumbers in file NumberTable.txt

	@param numberOfValues the number of values in the table
	@param firstNumber the starting value in the table
	@param incrementNumber the amount of increment between each number in the table
	*/
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
	
	/*
	Finds the square of a given number

	@param number the given number
	*/
	double Square(double number)
	{
		return number * number;
	}

	/*
	Finds the square root of a given number

	@param number the given number
	*/
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

	/*
	Finds the cube of a given number

	@param number the given number
	*/
	double Cube(double number)
	{
		return number * number * number;
	}

	/*
	Finds the cube root of a given number

	@param number the given number
	*/
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

	/*
	Determines if the given number is even or odd

	@param number the given number
	*/
	bool IsEven(int number)
	{
		bool isEven = number % 2 == 0;
		return isEven;
	}

	/*
	Determines if the given number is a prime number

	@param number the given number
	*/
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

	/*
	Finds the number of divisors for a given number

	@param number the given number
	*/
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

	/*
	Finds the divisors for a given number

	@param number the given number
	*/

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
	
	/*
	Determines if the given number is a perfect number

	@param number the given number
	@param divisors[] holds the values for the divisors of the given number
	@param listSize the size of the divisors arrray
	*/
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

	/*
	Calls the functions Square(), SquareRoot(), Cube(), CubeRoot(), IsEven(), IsPrime(), IsPerfect() and stores the values
	in their respective arrays

	@param numberOfValues the total number of values in the table
	@param square[] holds the values of the Square() method
	@param squareRoot[] holds the values of the SquareRoot() method
	@param cube[] holds the values of the Cube() method
	@param cubeRoot[] holds the values of the CubeRoot() method
	@param evenOrOdd[] holds the values of the IsEven() method
	@param primeOrNot[] holds the values of the IsPrime() method
	@param perfectOrNot[] holds the values of the IsPerfect() method
	@param divisors[] holds the values of the divisors of the given number
	@param size the size of the arrays
	*/
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

	/*
	Displays the results on the console of the functions Square(), SquareRoot(), Cube(), CubeRoot(), IsEven(), IsPrime(), IsPerfect() and stores the values
	from their respective arrays

	@param numberOfValues the total number of values in the table
	@param square[] holds the values of the Square() method
	@param squareRoot[] holds the values of the SquareRoot() method
	@param cube[] holds the values of the Cube() method
	@param cubeRoot[] holds the values of the CubeRoot() method
	@param evenOrOdd[] holds the values of the IsEven() method
	@param primeOrNot[] holds the values of the IsPrime() method
	@param perfectOrNot[] holds the values of the IsPerfect() method
	@param size the size of the arrays
	*/
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
				cout << "N/A ";
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
				cout << "N/A ";
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

	/*
	Displays the results on the console of the functions Square(), SquareRoot(), Cube(), CubeRoot(), IsEven(), IsPrime(), IsPerfect() and stores the values
	from their respective arrays

	@param square[] holds the values of the Square() method
	@param squareRoot[] holds the values of the SquareRoot() method
	@param cube[] holds the values of the Cube() method
	@param cubeRoot[] holds the values of the CubeRoot() method
	@param evenOrOdd[] holds the values of the IsEven() method
	@param primeOrNot[] holds the values of the IsPrime() method
	@param perfectOrNot[] holds the values of the IsPerfect() method
	@param size the size of the arrays
	*/
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

	/*
	Contains code to test methods that are not directly shown in the program
	*/
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