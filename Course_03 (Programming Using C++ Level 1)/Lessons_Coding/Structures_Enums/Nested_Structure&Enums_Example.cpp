#include <iostream>
using namespace std;


enum enColor { Red, Green, Yellow, Blue };
enum enGender { Male, Female };
enum enMaritalStatus { Single, Married };




struct stAddress
{
	string StreetName;
	string BuildingNo;
	string POBox;
	string ZipCode;
};




struct stContactInfo
{
	string Phone;
	string Email;
	stAddress Address;
};




struct stPerson
{


	string FirstName;
	string LastName;

	stContactInfo ContactInfo;


	enMaritalStatus MaritalStatus;
	enGendor Gender;
	enColor FavourateColor;
};




int main()
{

	stPerson Person1;


	Person1.FirstName = "Mohammed";
	Person1.LastName = "Abu-Hadhoud";


	Person1.ContactInfo.Email = "xyz@xyz.com";
	Person1.ContactInfo.Phone = "+961000000999";
	Person1.ContactInfo.Address.POBox = "7777";
	Person1.ContactInfo.Address.ZipCode = "11194";
	Person1.ContactInfo.Address.StreetName = "Queen1 Street";
	Person1.ContactInfo.Address.BuildingNo = "313";

	Person1.Gendor = enGendor::Male;
	Person1.MaritalStatus = enMaritalStatus::Married;
	Person1.FavourateColor = enColor::Green;


	cout << Person1.ContactInfo.Address.StreetName << endl;



	return 0;
}
