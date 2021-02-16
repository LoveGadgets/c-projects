/********************************************************************************
*Assignment : 3                                                                                         *
*Name: Yi Hong                                                                                          *
*Student ID: 002-24-4776                                                                           *
*Date: 11/7/2019                                                                                       *
*This program is to print the complete 12-month calendar for a particular year.
The user will be asked to enter the year, as well as the day of the week for the 1st of January. *
***********************************************************************************/
#include <iostream>
#include <string>
#include <stdio.h>
#include "draw_month.cpp"
using namespace std;

int main() {

    cout << "which year? ";
    int year, first_day; // needed to decide whether it’s a leap year (for February)
    cin >> year;
    cout << "enter the day of the week for the 1st of January (1=Sun, 2=Mon etc) ";
    cin >> first_day;
    for (int month = 1; month <= 12; month++){
        draw_month (first_day, month, year);
    }
     
    cout<<endl;
    
    return 0;
}
