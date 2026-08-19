#include <iostream>
using namespace std;

struct sDate
{
    unsigned short Day;
    unsigned short Month;
    unsigned short Year;
};

bool IsLeapYear(unsigned short Year)
{
    // if year is divisible by 4 AND not divisible by 100
    // OR if year is divisible by 400
    // then it is a leap year
    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);
}

unsigned short NumberOfDaysInAMonth(unsigned short Month, unsigned short Year)
{
    if (Month < 1 || Month > 12)
        return 0;

    const unsigned short DaysInEachMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : DaysInEachMonth[Month - 1];
}

bool IsLastDayInMonth(const sDate& Date)
{
    return (Date.Day == NumberOfDaysInAMonth(Date.Month, Date.Year));
}

bool IsLastMonthInYear(unsigned short Month)
{
    return (Month == 12);
}

unsigned short ReadMonth()
{
    unsigned short Month;

    do
    {
        cout << "Please enter a Month (1-12): ";
        cin >> Month;

    } while (Month < 1 || Month > 12);

    return Month;
}

unsigned short ReadYear()
{
    unsigned short Year;

    cout << "Please enter a Year: ";
    cin >> Year;

    return Year;
}

unsigned short ReadDay(unsigned short Month, unsigned short Year)
{
    unsigned short Day;
    unsigned short MaximumDays = NumberOfDaysInAMonth(Month, Year);

    do
    {
        cout << "Please enter Day (1 - " << MaximumDays << "): ";
        cin >> Day;

    } while (Day < 1 || Day > MaximumDays);

    return Day;
}

sDate ReadFullDate()
{
    sDate Date;

    Date.Year = ReadYear();
    Date.Month = ReadMonth();
    Date.Day = ReadDay(Date.Month, Date.Year);

    return Date;
}

int main()
{
    sDate Date1 = ReadFullDate();

    if (IsLastDayInMonth(Date1))
        cout << "\nYes, Day is Last Day in Month.";
    else
        cout << "\nNo, Day is Not Last Day in Month.";
    

    if (IsLastMonthInYear(Date1.Month))
        cout << "\nYes, Month is Last Month in Year.";
    else
        cout << "\nNo, Month is Not Last Month in Year.";
    
    system("pause>0");
    return 0;
}
