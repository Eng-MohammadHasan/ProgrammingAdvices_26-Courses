#include <iostream>
using namespace std;

enum enOperationType { Add = '+', Subtract = '-', Multiply = '*', Divide = '/' };

float ReadNumber(string message)
{
	float Number = 0;

	cout << message << endl;
	cin >> Number;

	return Number;
}

enOperationType ReadOpType()
{
	char OpType = '+'; // initial value (+) 

	cout << "Please Enter Operation Type ( + , - , * , / ): \n";
	cin >> OpType;

	return enOperationType(OpType);
}

float Calculate(float Number1, float Number2, enOperationType OpType)
{
	switch (OpType)
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
	float Number1 = ReadNumber("Please Enter the first number :");
	float Number2 = ReadNumber("Please Enter the second number :");

	enOperationType OpType = ReadOpType();

	cout << endl << "Result = " << Calculate(Number1, Number2, OpType) << endl;

	return 0;
}
