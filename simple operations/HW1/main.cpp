/********************************************************************************
*Assignment : 1                                                                                          *
*Name: Yi Hong                                                                                          *
*Student ID: 002-24-4776                                                                           *
*Date: 10/2/2019                                                                                         *
*This program is to compute the wages for an employee                           *
***********************************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    string name;
    cout<<"Enter you name: ";
    cin>>name;
    double hours;
    cout<<"Enter the hours you worked: ";
    cin>>hours;
    double rate;
    cout<<"Enter the hourly rate: ";
    cin>>rate;
    
    const double insurance_rate = 0.042;
    const double union_dues_rate = 0.02;
    const double tax_rate = 0.2;
    double gross_pay = hours * rate;
    double insurance = gross_pay * insurance_rate;
    double union_dues = gross_pay * union_dues_rate;
    double tax = gross_pay * tax_rate;
    double total_deductions = insurance + union_dues + tax;
    double net_pay = gross_pay  - total_deductions;
    
    cout<<fixed<<setprecision(2);
    cout<<"Employee name: "<<name<<endl;
    cout<<"Hours worked: : "<<hours<<endl;
    cout<<"Hourly rate: "<<rate<<endl;
    cout<<"Gross Pay: "<<gross_pay<<endl;
    cout<<"\nDeductions: \n";
    cout<<"     Union dues: "<<union_dues<<endl;
    cout<<"     Employment insurance: "<<insurance<<endl;
    cout<<"     Taxes: "<<tax<<endl;
    cout<<"\nTotal Deductions: "<<total_deductions<<endl;
    cout<<"\nNet pay: "<<net_pay<<endl;
    
    return 0;
    
    
}
