#include <iostream>
using namespace std;

struct stInfo
{
	short Age;
	bool HasDrivingLisence;
};

stInfo ReadInfo()
{
	stInfo Info;

	cout << "Please Enter your Age : \n";
	cin >> Info.Age;

	cout << "Do you have a driver’s license? (1 for Yes, 0 for No)" << endl;
	cin >> Info.HasDrivingLisence;

	return Info;
}

bool IsAccepted(stInfo Info)
{
	return (Info.Age > 21 && Info.HasDrivingLisence);
}

void PrintResult(stInfo Info)
{
	if (IsAccepted(Info))
	{
		cout << "Hired :) \n";
	}
	else
	{
		cout << "Rejected! \n";
	}
}

int main()
{
	PrintResult(ReadInfo());

	return 0;
}
