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

inline string day_of_week (int days){
     string days_name;
      switch (days){
        
         case 1:
              days_name = "Sunday"; break;
         case 2:
              days_name = "Monday"; break;
         case 3:
              days_name = "Tuesday"; break;
         case 4:
             days_name = "Wednesday"; break;
         case 5:
              days_name = "Thursday"; break;
         case 6:
              days_name ="Friday"; break;
         case 0:
             days_name = "Saturday"; break;
      }
    return days_name;
}
