#include <iostream>
using namespace std;

void ReadGrade(float& Grade)
{
	cout << "Please Enter your Grade : " << endl;
	cin >> Grade;
}

unsigned char DisplayLetterGrade(float Grade)
{
	if (Grade < 50)
	{
		return 'F';
	}
	else {
		if (Grade >= 90 && Grade <= 100)
		{
			return 'A';
		}
		else if (Grade >= 80)
		{
			return 'B';
		}
		else if (Grade >= 70)
		{
			return 'C';
		}
		else if (Grade >= 60)
		{
			return 'D';
		}
		else if (Grade >= 50)
		{
			return 'E';
		}
	}

}
int main()
{
	float Grade;

	ReadGrade(Grade);
	cout << DisplayLetterGrade(Grade) << endl;

	return 0;
}
