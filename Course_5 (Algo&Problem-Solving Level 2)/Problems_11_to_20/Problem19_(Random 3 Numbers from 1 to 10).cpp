#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int RandomNumber(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return RandNum;
}

int main()
{
	srand((unsigned)time(NULL));

	cout << RandomNumber(1, 10) << endl;
	cout << RandomNumber(1, 10) << endl;
	cout << RandomNumber(1, 10) << endl;

	return 0;
}
