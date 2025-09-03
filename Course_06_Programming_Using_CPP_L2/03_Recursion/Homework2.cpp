#include <iostream>

using namespace std;

int MyPower(int Base, int Power)
{
	// (Base) case,  Stop case , Terminating case !
	if (Power == 0)
	{
		return 1;
	}
	else
	{
		return (Base * MyPower(Base, Power - 1));
	}
}

int main()
{
	cout << MyPower(2, 4) << endl;

	return 0;
}

