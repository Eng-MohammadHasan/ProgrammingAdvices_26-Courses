#include <iostream>
using namespace std;

enum enOperationType { Add = '+', Subtract = '-', Multiply = '*', Divide = '/' };

void ReadNumbers(float Numbers[2])
{
	cout << "Please Enter Number 1 : \n";
	cin >> Numbers[0];

	cout << "Please Enter Number 2 : \n";
	cin >> Numbers[1];
}

enOperationType ReadOperationType()
{
	char op;

	cout << "Please Enter one of these Operations ... ( \" + \" , \" - \" ,\" * \" , \" / \" ) : " << endl;
	cin >> op;

	// casting ...
	return (enOperationType)op;
}

float CalculateResult(float Numbers[2], enOperationType OperationType)
{
	switch (OperationType)
	{

	case enOperationType::Add:
		return Numbers[0] + Numbers[1];
		break;

	case enOperationType::Subtract:
		return Numbers[0] - Numbers[1];
		break;

	case enOperationType::Multiply:
		return Numbers[0] * Numbers[1];
		break;

	case enOperationType::Divide:
		return Numbers[0] / Numbers[1];
		break;
	}
}

int main()
{
	float Numbers[2];
	ReadNumbers(Numbers);

	enOperationType OperationType;
	OperationType = ReadOperationType();

	cout << "The Result = " << CalculateResult(Numbers, OperationType);


	return 0;
}
