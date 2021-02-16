/********************************************************************************
*Assignment : 3                                                                                         *
*Name: Yi Hong                                                                                          *
*Student ID: 002-24-4776                                                                           *
*Date: 11/7/2019                                                                                       *
*This program is to print the complete 12-month calendar for a particular year.
The user will be asked to enter the year, as well as the day of the week for the 1st of January. *
***********************************************************************************/
#include <iostream>
#include <stdio.h>

using namespace std;

inline int find_max_days (int month, int year){
   int days;
   string month_str;
   switch (month){
   case 1:
       month_str = "January";
       days = 31;break;
   case 2:
       month_str = "Feburary";
       if (year % 400 == 0 ||(year % 4 == 0 && year % 100 != 0))
           days = 29;
       else
           days = 28;break;
   case 3:
       month_str = "March";
       days = 31;break;
   case 4:
       month_str = "April";
       days = 30;break;
   case 5:
       month_str = "May";
       days = 31;break;
   case 6:
       month_str = "June";
       days = 30;break;
   case 7:
       month_str = "July";
       days = 31;break;
   case 8:
       month_str = "August";
       days = 31;break;
   case 9:
       month_str = "September";
       days = 30;break;
   case 10:
       month_str = "October";
       days = 31;break;
   case 11:
       month_str = "November";
       days = 30;break;
   case 12:
       month_str = "December";
       days = 31;break;
   }
    
    
    return days;
}
