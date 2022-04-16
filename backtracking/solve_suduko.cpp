#include <bits/stdc++.h>
using namespace std;

bool canPlace(int mat[][9],int i,int j,int n,int number)
{
    for(int x = 0;x<n;x++)
    {
        //row and column check
        if(mat[x][j] == number || mat[i][x] == number){
            return false;
        }
    }
    int rn = sqrt(n);
    int sx = (i/rn)*rn;
    int sy = (j/rn)*rn;

    for(int x = sx;x <sx+rn;x++)
    {
       for( int y = sy;y < sy+rn;y++){
           if(mat[x][y] == number)
           {
               return false;
           }
       }
    }
    return true;

}
bool solveSuduko(int mat[][9], int i, int j, int n)
{
    // base case
    if (i == n)
    {
        // print the matrix
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << mat[i][j] << " ";
            }
            putchar('\n');
        }
        return true;
    }

    //case row end
    if(j == n) {
        return solveSuduko(mat,i+1,0,n);
    }
    //skip the prefilled cells
    if(mat[i][j] != 0) {
        return solveSuduko(mat,i,j+1,n);
    }

    //recursive case
    //fill the current cell with possible options
    for(int number =1;number <= n;number++)
    {
        if(canPlace(mat,i,j,n,number)){
            //Assume
            mat[i][j] = number;
            bool couldBeSolved = solveSuduko(mat,i,j+1,n);
            if(couldBeSolved)
            {
                return true;
            }


        }
    }
    //backtrace here
    mat[i][j] = 0;
    return false;
}
int main()
{
    int n;
    cin >> n;
    int mat[9][9];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
        }
    }
    solveSuduko(mat,0,0,n);
}