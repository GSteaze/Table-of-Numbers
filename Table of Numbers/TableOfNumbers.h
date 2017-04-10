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

	double Cube(double number);

	double CubeRoot(double number);

	bool IsEven(int number);

	void CalculateResults();

	void DisplayResults(double square[], double squareRoot[], double cube[], double cubeRoot[],
		double evenOrOdd[], double primeOrNot[], double perfectOrNot[], int size);

	void PrintResults(double square[], double squareRoot[], double cube[], double cubeRoot[],
		double evenOrOdd[], double primeOrNot[], double perfectOrNot[], int size);
}

#endif

