#include <iostream>
using namespace std;

void PrintNumbers(int N, int M)
{
	// stop case (base case)
	if (N <= M)
	{
		cout << N << endl;
		PrintNumbers(N + 1, M);
	}
}

int main()
{

	PrintNumbers(1, 5);

	return 0;
}
