/********************************************************************************
*Assignment : 3                                                                                         *
*Name: Yi Hong                                                                                          *
*Student ID: 002-24-4776                                                                           *
*Date: 11/7/2019                                                                                       *
*This program is to print the complete 12-month calendar for a particular year.
The user will be asked to enter the year, as well as the day of the week for the 1st of January. *
***********************************************************************************/

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
#include <stdio.h>
#include "find_max_days.cpp"
#include "month_name.cpp"
#include "day_of_week.cpp"
using namespace std;

inline void draw_month(int &first_day, int month_index, int year)

{
    
    int days;
    string month;
    switch (month_index){
    case 1:
        month = "January";
        days = 31;break;
    case 2:
        month = "Feburary";
        if (year % 400 == 0 ||(year % 4 == 0 && year % 100 != 0))
            days = 29;
        else
            days = 28;break;
    case 3:
        month = "March";
        days = 31;break;
    case 4:
        month = "April";
        days = 30;break;
    case 5:
        month = "May";
        days = 31;break;
    case 6:
        month = "June";
        days = 30;break;
    case 7:
        month = "July";
        days = 31;break;
    case 8:
        month = "August";
        days = 31;break;
    case 9:
        month = "September";
        days = 30;break;
    case 10:
        month = "October";
        days = 31;break;
    case 11:
        month = "November";
        days = 30;break;
    case 12:
        month = "December";
        days = 31;break;
    }
    cout<<"\nHere is the calendar for "<<month<<" of "<<year<<":\n";
    cout<<" Sun Mon Tue Wed Thu Fri Sat\n";
    cout<<"----------------------------\n";
      int day = 1;
      cout << setw (first_day*4) << day; // position the "1" under the right day of the week
      int pos = first_day;  // used to place the number in the correct column
      for (day = 2; day <= days; day++){// loop to print all the days
         if (pos % 7 == 0)              // go to a new line at the end of the week
            cout << endl;
         cout << setw(4) << day;
         pos++;
      }
    
    // print the last weekday of the month
      cout <<"\nThe month ends on a ";
      switch (pos%7){
         case 1: cout << "Sunday"; break;
         case 2: cout << "Monday"; break;
         case 3: cout << "Tuesday"; break;
         case 4: cout << "Wednesday"; break;
         case 5: cout << "Thursday"; break;
         case 6: cout << "Friday"; break;
         case 0: cout << "Saturday"; break;
      }
    string day_name = day_of_week(first_day);
    first_day = pos%7+1;
    cout <<"\nMaximum days of this month is "<< find_max_days (month_index, year);
    cout <<"\nName of the month is "<< month_name (month_index);
    cout <<"\nThe name of the first day of the month is "<< day_name <<endl<<endl;
    
}
