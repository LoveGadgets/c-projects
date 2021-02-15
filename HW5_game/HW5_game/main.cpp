/********************************************************************************
*Assignment : 4                                                                                        *
*Name: Yi Hong                                                                                          *
*Student ID: 002-24-4776                                                                           *
*Date: 11/20/2019                                                                                       *
*This program is to simulates the behavior of a population of living cells
* that evolves from one generation to the next *
***********************************************************************************/

#include <stdio.h>

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

// Global constants
const int MAXGEN = 10; // maximum no. of generations
const int MAXROWS = 10; // no. of rows
const int MAXCOLS = 10; // no. of columns
int oldGrid[MAXROWS][MAXCOLS];
int newGrid[MAXROWS][MAXCOLS];

void initialize(int grid[][MAXCOLS], int n, int m){
    cout<<"Enter a 0 or 1, "<<n<<" numbers per row(hit Enter to enter next row): \n";
    double input;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> input;
            grid[i][j]=input;
        }
    }
}
void initialize2(int grid[][MAXCOLS], int n, int m, int density){
    srand(static_cast<unsigned int>(time(0)));
    double number;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            number = rand() %100 +1;
            if (number > density)
                grid[i][j]=0;
            if (number <= density)
                grid[i][j]=1;
        }
    }
}

int countNeighbours(int grid[][MAXCOLS], int r, int c){
     double count = 8;
   
    if (grid[r-1][c-1]==0)
            {
               count--;
            }
    if (grid[r-1][c]==0)
            {
                count--;
            }
    if (grid[r-1][c+1]==0)
            {
               count--;
            }
    if (grid[r][c-1]==0)
            {
                count--;
            }

    if (grid[r][c+1]==0)
            {
                count--;
            }
    if (grid[r+1][c-1]==0)
            {
                count--;
            }
    if (grid[r+1][c]==0)
             {
                 count--;
             }
    if (grid[r+1][c+1]==0)
            {
               count--;
            }
    return count;
}


void reproduce(int grid[][MAXCOLS], int n, int m)
{
    //copy cells to oppsite sides to mimic the effect of sphere. cells go from 1 to n(row),and 1
    //to m(column), so there are 4 hidden sides (such as 0 to n+1) serve as containers of copied cells.
    for (int j=1; j<=m; j++){
            grid[0][j]= grid[n][j];
            grid[n+1][j]= grid[1][j];
    }
    for (int i=1; i<=n; i++){
            grid[i][0]= grid[i][m];
            grid[i][m+1]= grid[i][1];
    }
    grid[0][0]=grid[n][m];
    grid[0][m+1]=grid[n][1];
    grid[n+1][0]=grid[1][m];
    grid[n+1][m+1]=grid[1][1];
    //check 8 neighbors of each cell. then generate new data to put into a new array.
    for (int r=1; r<=n; r++)
    {
        for (int c=1; c<=m; c++){
            int value = countNeighbours(grid,r,c);
            if (grid[r][c] == 1 && value < 2) //rule 1
            {
                newGrid[r][c]=0;
            }
            else if (grid[r][c]== 1 && (value == 2 || value == 3))//rule 2
            {
                newGrid[r][c]=1;
            }
            else if (grid[r][c]== 1 && value > 3 ) //rule 3
            {

                newGrid[r][c]=0;
            }
            else if (grid[r][c]== 0 && value ==3) //rule 4
            {
                newGrid[r][c]=1;
            }
        }
    }
    //copy data from new array back to the origianl array
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            grid[i][j]=newGrid[i][j];
        }
    }
    
}
//if all 0, then all dead.
bool allDead(int grid[][MAXCOLS], int n, int m){
    int count =0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (grid[i][j]==1)
                   count++;
        }
       
   }
    if (count == 0)
        return true;
    else
        return false;
}
//keey a copy of data from previous array for comparison
void TempGrid(int grid[][MAXCOLS], int n, int m){
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            oldGrid[i][j]=grid[i][j];
                
        }
      }
            
}
//check to see if the new generation and the previous one are exactly the same.
//if its the same then its stable.
bool stable(int grid[][MAXCOLS], int n, int m){
    int count =0;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (grid[i][j]!=oldGrid[i][j])
                count++;
             }
     }
 if (count == 0)
     return true;
 else
     return false;
}

    
void print(int grid[][MAXCOLS], int n, int m){
    cout<<"-";
    for (int i = 0; i < m; i++) {
        cout<<"----";
    }
    cout<<endl;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if (grid[i][j]==0)
                cout<<"|   ";
            if (grid[i][j]==1)
                cout<<"| X ";
        }
        cout<<"|"<<endl<<"-";
        for (int i = 0; i < m; i++) {
            cout<<"----";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    int grid[MAXROWS][MAXCOLS]={0};
    int n, m, density;
    cout<<"whats the number of row, column(maximum 8 rows and 8 columns), and density%? ";
    cin>>n>>m>>density;
    
    //initialize(grid,n,m);
    
    initialize2(grid,n,m,density);
    cout << "Initial population =" << endl;
    print(grid,n,m);
    int gen = 1;
    while (gen <= MAXGEN && !allDead(grid,n,m) && !stable(grid,n,m)){
        TempGrid(grid,n,m);
        reproduce(grid,n,m);// will call the function countNeighbours for each cell
        if (!stable(grid,n,m)){
            cout << "gen = " << gen<<endl;
            print(grid,n,m);
        }
        gen++;
    }
}


