#include <iostream>
using namespace std;

struct strInfo
{
	string FristName;
	string LastName;
	unsigned short Age;
	string Phone;
};

int main()
{
	strInfo Person[2];

	Person[0].FristName = "Mohammad";
	Person[0].LastName = "Abu-Hadhoud";
	Person[0].Age = 44;
	Person[0].Phone = "42342432425";

	Person[1].FristName = "Ali";
	Person[1].LastName = "Maher";
	Person[1].Age = 22;
	Person[1].Phone = "423425243323";

	cout << Person[1].LastName << endl;
	return 0;
}
