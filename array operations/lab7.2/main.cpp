//
// Yi Hong LAB7 Question 3

#include <iostream>
#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;


/*



*/
const int MAX_SIZE = 10;
int leftRightDiagonalSum(int square[][MAX_SIZE],int n){
    int sum = 0;
    for (int i = 1; i<=n; i++)
        sum += square[i][i];
    return sum;
}

int rightLeftDiagonalSum(int square[][MAX_SIZE],int n){
        int sum = 0;
        for (int i = 1; i<=n; i++)
            sum += square[i][n-i+1];
        return sum;
    }


int columnSum(int square[][MAX_SIZE],int n, int columnNumber){
        int sum = 0;
        for (int i = 1; i<=n; i++)
            sum += square[i][columnNumber];
        return sum;
    }


int rowSum(int square[][MAX_SIZE],int n, int rowNumber){
    int sum = 0;
      for (int i = 1; i<=n; i++)
          sum += square[rowNumber][i];
      return sum;

}
void readSquare(int square[][MAX_SIZE],int n){
    srand(static_cast<unsigned int>(time(0)));
    //cout<<"Enter "<<n<<" number per row(hit Enter to enter next row): \n";
    int numbers[n*n];
    bool dub = false;
    for (int i=1; i<=n*n; i++){
        numbers[i]=rand() %(n*n)+1;
    
        while (dub){
         for (int j=1; j<i; j++){
            if (numbers[i] == numbers[j]) return true;
        }
        cout<<setw(3)<<numbers[i];
    }
    
    }
}
bool validMagicSquare(int square[][MAX_SIZE],int n){
    int sum1 = leftRightDiagonalSum(square,n);
    int sum2 = rightLeftDiagonalSum(square,n);
    int sum3,sum4;
    int total_conlumn = 0;
    int total_row = 0;
    for (int i = 1; i<=n; i++){
        total_conlumn += columnSum(square,n, i);
     }
    sum3 = total_conlumn / n;
    
    for (int i = 1; i<=n; i++){
        total_row += rowSum(square,n, i);
    }
    sum4 = total_row / n;
    
    if (sum1==sum2 && sum2==sum3 && sum3==sum4 && sum4==sum1)
        return true;
    else return false;
}

int main() {
    int n;
    cout<<"input order of square: ";
    cin >>n;
    int square[MAX_SIZE][MAX_SIZE];
    readSquare (square,n);
   /* testing
    cout<<leftRightDiagonalSum(square,n);
    cout<<rightLeftDiagonalSum(square,n);
    cout<<columnSum(square,n,2);
    cout<<rowSum(square,n,2);
    */
    if (validMagicSquare(square,n))
        cout<<"it's a magic square.";
    if (!validMagicSquare(square,n))
    cout<<"it's not a magic square.";
    return 0;
}
