#include <iostream>
using namespace std;

int main()
{
    float BillValue;

    cout << "Please Enter BillValue : " << endl;
    cin >> BillValue;

    float services_Fee = 1.1; // 10% 
    float Sales_Tax = 1.16;   // 16% 

    float BillValue_with_ServicesFee = BillValue * services_Fee;
    float BillValue_with_SalesTax = BillValue_with_ServicesFee * Sales_Tax;

    float TotalBillValue = BillValue_with_SalesTax;

    cout << "Total Bill = " << TotalBillValue << endl;

    return 0;
}

