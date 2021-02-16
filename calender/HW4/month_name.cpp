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

inline string month_name (int month){
  
   string month_str;
   
   switch (month){
   case 1:
       month_str = "January";break;
           
   case 2:
       month_str = "Feburary";break;

   case 3:
       month_str = "March";break;
       
   case 4:
       month_str = "April";break;
   case 5:
       month_str = "May";break;
   case 6:
       month_str = "June";break;
   case 7:
       month_str = "July";break;
   case 8:
       month_str = "August";break;
   case 9:
       month_str = "September";break;
   case 10:
       month_str = "October";break;
   case 11:
       month_str = "November";break;
   case 12:
       month_str = "December";break;
   }
    
    
    return month_str;
}
