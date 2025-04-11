#include <iostream>
using namespace std;

struct stInfo
{
	short Age;
	bool HasDrivingLisence;
	bool HasRecommendation;
};

stInfo ReadInfo()
{
	stInfo Info;

	cout << "Please Enter your Age : \n";
	cin >> Info.Age;

	cout << "Do you have a driver’s license? (1 for Yes, 0 for No)" << endl;
	cin >> Info.HasDrivingLisence;

	cout << "Do you have a Recommendation? (1 for Yes, 0 for No) \n";
	cin >> Info.HasRecommendation;

	return Info;
}

bool IsAccepted(stInfo Info)
{
	if (Info.HasRecommendation)
	{
		return true;
	}
	else
	{
		return (Info.Age > 21 && Info.HasDrivingLisence);
	}
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