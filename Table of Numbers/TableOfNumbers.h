#ifndef TABLEOFNUMBERS_H
#define TABLEOFNUMBERS_H

using namespace std;

namespace tableofnumbers
{
	/*
	Fills a specified array with a default value 

	@param list[] the array to be iniatialized
	@param size the size of the array
	@param the default value to be inserted into the array
	*/
	void InitializeList(double list[], int size, double defaultValue);

	/*
	Tests to see if the values are the proper type and within a specified range

	@param variable the input from the user
	@param minimum the minimum value of the desired range
	@param maximum the maximum value of the desired range
	*/
	void InvalidInput(double variable, int min, int max);

	/*
	Prompts the user and extracts the data for table size, starting value, and increment value

	@param userInput[] the array that will hold the extracted data
	@param size the size of the array
	*/
	void InputNumbers(double userInput[], int size);

	/*
	Builds a table using the InputNumbers in file NumberTable.txt

	@param numberOfValues the number of values in the table
	@param firstNumber the starting value in the table
	@param incrementNumber the amount of increment between each number in the table
	*/
	void TableBuilder(double numberOfValues, double firstNumber, double incrementNumber);

	/*
	Finds the square of a given number

	@param number the given number
	*/
	double Square(double number);

	/*
	Finds the square root of a given number

	@param number the given number
	*/
	double SquareRoot(double number);

	/*
	Finds the cube of a given number

	@param number the given number
	*/
	double Cube(double number);

	/*
	Finds the cube root of a given number

	@param number the given number
	*/
	double CubeRoot(double number);

	/*
	Determines if the given number is even or odd

	@param number the given number
	*/
	bool IsEven(int number);

	/*
	Determines if the given number is a prime number

	@param number the given number
	*/
	bool IsPrime(int number);

	/*
	Finds the number of divisors for a given number

	@param number the given number
	*/
	int NumberOfDivisors(int number);

	/*
	Finds the divisors for a given number

	@param number the given number
	*/
	void DivisorsOfNumber(int number, double divisors[], int listSize, int numberOfDivisors);

	/*
	Determines if the given number is a perfect number

	@param number the given number
	@param divisors[] holds the values for the divisors of the given number
	@param listSize the size of the divisors arrray
	*/
	bool IsPerfect(int number, double divisors[], int listSize);

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
		double evenOrOdd[], double primeOrNot[], double perfectOrNot[], double divisors[], int size);

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
		double evenOrOdd[], double primeOrNot[], double perfectOrNot[], int size);

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
		double evenOrOdd[], double primeOrNot[], double perfectOrNot[], int size);

	/*
	Contains code to test methods that are not directly shown in the program
	*/
	void TestCode();
}

#endif

