// Yi Hong LAB7 Question 1

#include <iostream>
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>

using namespace std;

void calc_averages (int n, double mid[], double finals[], double ave[]){
    for (int i = 0; i < n; i++){
        double average= (mid[i]+finals[i])/2;
        ave[i]= average;
    }
    
}

void calc_grades(int n, double ave[], char grades[]){
    for (int i = 0; i < n; i++){
        if (ave[i]>=0 && ave[i]<=49)
            grades[i]='F';
        else if (ave[i]>=50 && ave[i]<=64)
        grades[i]='C';
        else if (ave[i]>=65 && ave[i]<=79)
        grades[i]='B';
        else if (ave[i]>=80 && ave[i]<=100)
        grades[i]='A';
            
        }
    }
    

void get_info (int &n, string names[], double mid[], double finals[]){
    string studentName;
    double midScore;
    double finalScore;
    for (int i= 0; i < n; i++) {
        cout << "input name: ";
        cin >> studentName;
        names[i] = studentName;
        
        cout << "input mid term Score: ";
        cin >> midScore;
        mid[i] = midScore;
    
        cout << "input final score: ";
        cin >> finalScore;
        finals[i] = finalScore;
    }
}


void print_all (int &n, string names[], double mid[], double finals[], double ave[],
                char grades[]){
    cout << setw(10)<<"name";
    cout << setw(10) <<"midterm";
    cout << setw(10) <<"final";
    cout << setw(10)<< "average";
    cout << setw(11)<<"grades\n";
    for (int i= 0; i < n; i++) {
        cout << setw(10) << names[i];
        cout << setw(10)<< mid[i];
        cout << setw(10)<< finals[i];
        cout << setw(10)<< ave[i];
        cout << setw(10)<< grades[i];
        cout<<endl;
    }
}


const int MAX = 10;

int main() {
    string names[MAX];
    double mid[MAX];
    double fin[MAX];
    double ave[MAX];
    char grades[MAX];
    int n;
    cout<<"number of students: ";
    cin>>n;
    get_info (n,names,mid,fin);
    calc_averages(n,mid,fin,ave);
    calc_grades(n,ave,grades);
    print_all (n,names,mid,fin,ave,grades);
    return 0;
}
