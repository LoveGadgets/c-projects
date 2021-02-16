//
//  main.cpp
//  new
//
//  Created by Daniel on 12/1/19.
//  Copyright © 2019 Daniel. All rights reserved.
//

#include <iostream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

double average(double* a, int size){
    double total = 0;
    for (int i=0; i < size; i++){
        total += *a;
        a++;
    }
    double average = total/size;
    return average;
}


bool palindrome(char * text){
    int length = strlen(text);
    bool palindrome = false;
    for (int i = 0; i<(length/2); i++){
        if (*text == *(text+length-1)){
            palindrome = true;
        }
    }
    return palindrome;
}


int* read_data(int & size){
    int length = 5;
    int *ptr = new int[length];
    int input;
    cout<<"input numbers, enter q or Q to quit: \n";
    while (cin>>input){
        ptr[size]=input;
        size++;
        if (size >= length){
            length = length*2;
            int *ptr2 = ptr;
            ptr = new int[length];
            for (int i=0; i<(size); i++){
                ptr[i]=ptr2[i];
            }
            delete[] ptr2;
        }
    }
    int *result = new int[size];
    for (int i=0; i<size; i++)
        result[i]=ptr[i];
    delete[] ptr;
    return result;
}
  

int main() {
//for testing
//question 1
    double data[] = {1,2,3,4,5,6,7,8,9};
    double ave;
    ave = average(data,9);
    cout<<"average is "<<ave<<endl;

  
//question 2
    char string[] = "aabaa";
    if (palindrome(string))
        cout<<"It's a palindrome"<<endl;
    if (!palindrome(string))
    cout<<"It's not a palindrome"<<endl;

    
//question 3
    int size = 0;
    int *ptr = read_data(size);
    for (int i=0; i<size; i++)
        cout<<setw(4)<<ptr[i];
    
    
    
    
    return 0;
}

