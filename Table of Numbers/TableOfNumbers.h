#ifndef TABLEOFNUMBERS_H
#define TABLEOFNUMBERS_H

using namespace std;

namespace tableofnumbers
{
	void InitializeList(double list[], int size, double defaultValue);

	void InvalidInput(double variable, int min, int max);

	void InputNumbers(double userInput[], int size);

	void TableBuilder(double numberOfValues, double firstNumber, double incrementNumber);

	double Square(double number);

	double SquareRoot(double number);

	double Cube(double number);

	double CubeRoot(double number);

	bool IsEven(int number);

	bool IsPrime(int number);

	int NumberOfDivisors(int number);

	void DivisorsOfNumber(int number, double divisors[], int listSize, int numberOfDivisors);

	bool IsPerfect(int number, double divisors[], int listSize);

	void CalculateResults(double numberOfValues, double square[], double squareRoot[], double cube[], double cubeRoot[],
		double evenOrOdd[], double primeOrNot[], double perfectOrNot[], double divisors[], int size);

	void DisplayResults(double square[], double squareRoot[], double cube[], double cubeRoot[],
		double evenOrOdd[], double primeOrNot[], double perfectOrNot[], int size);

	void PrintResults(double square[], double squareRoot[], double cube[], double cubeRoot[],
		double evenOrOdd[], double primeOrNot[], double perfectOrNot[], int size);

	void TestCode();
}

#endif

