#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	/*
	  time_t: holds the raw time value as the number of seconds since 1/1/1970.

	  ctime(): takes the address of a time_t variable and converts it into a human-readable C-string
			   (array of characters) representing the local time. Returns a pointer to the first character.

	  gmtime(): takes the address of a time_t variable and converts it into a tm structure,
				which breaks the time into individual components (year, month, day, hour, minute, second)
				in UTC/GMT. Returns a pointer to the tm structure.

	  localtime(): works the same as gmtime(), but converts the time into a tm structure in local time,
				   not UTC.

	  asctime(): takes a pointer to a tm structure and converts it back into a C-string in the same
				human-readable style as ctime().
   */

	time_t t = time(0); // get time now

	char* dt = ctime(&t); //convert in string form
	cout << "Local date and time is : " << dt << "\n";

	tm* gmtm = gmtime(&t); // converting now to tm struct for UTC date/time
	dt = asctime(gmtm);
	cout << "UTC date and time is : " << dt;

}
