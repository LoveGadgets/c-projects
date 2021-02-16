/********************************************************************************
*Assignment : 1                                                                                          *
*Name: Yi Hong                                                                                          *
*Student ID: 002-24-4776                                                                           *
*Date: 10/2/2019                                                                                         *
*This program is to compute the roots of the quadratic equations              *
***********************************************************************************/

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double a;
    double b;
    double c;
    cout<< "Enter the values of a b c (seperated by space): ";
    cin>>a>>b>>c;
    if ((pow(b,2) - 4 * a * c) >= 0){
        double square_root = sqrt(pow(b,2) - 4 * a * c);
        double x1 = (-b + square_root)/(2 * a);
        double x2 = (-b - square_root)/(2 * a);
        cout<<setprecision(5);
        cout<<"First root is: "<<x1<<", second root is: "<<x2<<endl;
    }
    else{
        cout<<"roots are complex!";
    }
    return 0;
}
