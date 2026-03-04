#include <iostream>
using namespace std;

enum enOperationType { Add = '+', Subtract = '-', Multiply = '*', Divide = '/' };

void ReadNumbers(float& Number1, float& Number2)
{
	cout << "Please Enter Number 1 :\n ";
	cin >> Number1;

	cout << "Please Enter Number 2 :\n ";
	cin >> Number2;
}

void DisplayOperationTypeMenu()
{
	cout << "~~  Operation Type ~~ " << endl;
	cout << " --------------------" << endl;
	cout << "|   Add (+)        |" << endl;
	cout << "|   Subtract (-)   |" << endl;
	cout << "|   Multiply (*)   |" << endl;
	cout << "|   Divide (/)     |" << endl;
	cout << " ------------------- " << endl;
}

enOperationType ReadOperationType()
{
	char OperationType = '+';

	cout << "Please Enter an Operation Type : \n";
	cin >> OperationType;

	return enOperationType(OperationType);
}

float CalculateResult(float Number1, float Number2, enOperationType OperationType)
{
	switch (OperationType)
	{
	case enOperationType::Add:
		return Number1 + Number2;

	case enOperationType::Subtract:
		return Number1 - Number2;

	case enOperationType::Multiply:
		return Number1 * Number2;

	case enOperationType::Divide:
		return Number1 / Number2;

	default:
		return Number1 + Number2;  // Default case (fallback to addition).
	}
}

int main()
{
	float Number1, Number2;

	ReadNumbers(Number1, Number2);

	DisplayOperationTypeMenu();
	enOperationType OperationType = ReadOperationType();

	cout << "Calculation Result = " << CalculateResult(Number1, Number2, OperationType);

	return 0;
}
