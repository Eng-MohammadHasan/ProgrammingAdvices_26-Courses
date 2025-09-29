#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct stStudentsInfo
{
	string FirstName = "";
	string LastName = "";
	short Grade = 0;
	short ClassNumber = 0;
	string Address = "";
	long long ContactInfo = 0;
	string HealthCondition = "";
};

int ReadNumber(string message)
{
	int Number = 0;

	cout << message << endl;
	cin >> Number;

	while (cin.fail())
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		cout << "Invalide input , please enter a valid one : \n";
		cin >> Number;
	}

	return Number;
}

stStudentsInfo ReadStudentInfo()
{
	stStudentsInfo StudentInfo;

	cout << "\nPlease enter student first name : \n";
	cin >> StudentInfo.FirstName;

	cout << "\nPlease enter student last name : \n";
	cin >> StudentInfo.LastName;

	StudentInfo.Grade = ReadNumber("\nPlease enter student grade : ");

	StudentInfo.ClassNumber = ReadNumber("\nPlease enter student Class Number : ");

	cout << "\nPlease enter student address : \n";
	cin.ignore(1, '\n');// Clear leftover newline
	getline(cin, StudentInfo.Address);

	StudentInfo.ContactInfo = ReadNumber("\nPlease enter student contact information : ");

	cout << "\nPlease enter student health condition : \n";
	cin.ignore(1, '\n');
	getline(cin, StudentInfo.HealthCondition);

	return StudentInfo;
}

//This function is another way to fill students info...

//vector <stStudentsInfo> FillVectorWithStudentInfo()
//{
//	vector <stStudentsInfo> vStudentInfo;
//	int NumberOfStudents = 0;
//
//	cout << "How many Students do you want to add ? \n";
//	cin >> NumberOfStudents;
//
//	for (int i = 0; i < NumberOfStudents; i++)
//	{
//		vStudentInfo.push_back(ReadStudentInfo());
//	}
//
//	char AddMore = 'Y';
//
//	do
//	{
//		cout << "Do you want to add more students ? (Y/N) ?\n";
//		cin >> AddMore;
//
//		if (AddMore != 'Y' && AddMore != 'y')
//		{
//			break;
//		}
//
//		vStudentInfo.push_back(ReadStudentInfo());
//
//	} while (AddMore == 'Y' || AddMore == 'y');
//
//	return vStudentInfo;
//}


void FillVectorWithStudentsInfo(vector <stStudentsInfo>& vStudentInfo)
{
	int NumberOfStudents = 0;

	cout << "How many Students do you want to add ? \n";
	cin >> NumberOfStudents;

	for (int i = 0; i < NumberOfStudents; i++)
	{
		vStudentInfo.push_back(ReadStudentInfo());
	}

	char AddMore = 'Y';

	do
	{
		cout << "Do you want to add more students ? (Y/N) ?\n";
		cin >> AddMore;

		if (AddMore != 'Y' && AddMore != 'y')
		{
			break;
		}

		vStudentInfo.push_back(ReadStudentInfo());

	} while (AddMore == 'Y' || AddMore == 'y');

}

void PrintStudentsInfo(const vector <stStudentsInfo>& vStudentList)
{
	printf("\n");

	//ranged loop
	for (const stStudentsInfo& StudentInfo : vStudentList)
	{
		printf("----------------------------------------------\n");
		printf("First Name       : %s\n", StudentInfo.FirstName.c_str());
		printf("Last Name        : %s\n", StudentInfo.LastName.c_str());
		printf("Grade            : %d\n", StudentInfo.Grade);
		printf("Class Number     : %d\n", StudentInfo.ClassNumber);
		printf("Address          : %s\n", StudentInfo.Address.c_str());
		printf("Contact Info     : %lld\n", StudentInfo.ContactInfo);
		printf("Health Condition : %s\n", StudentInfo.HealthCondition.c_str());
		printf("----------------------------------------------\n");
	}
	cout << endl;
}

int main()
{
	vector <stStudentsInfo> vStudentInfo;

	FillVectorWithStudentsInfo(vStudentInfo);
	PrintStudentsInfo(vStudentInfo);

	//call for the other solution...
	//PrintStudentsInfo(FillVectorWithStudentInfo());


	return 0;
}
