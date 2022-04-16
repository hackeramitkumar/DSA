#include<bits/stdc++.h>
using namespace std;

bool rateInMaze(char maze[][10],int sol[][10],int i,int j,int m,int n)
{
    
    if(i == m-1 && j == n-1 ){
        if(maze[i][j] == 'X'){
        sol[m-1][n-1] = 0;
        }else{
        sol[m-1][n-1] = 1;

        }
        for(int i = 0;i<m;i++)
        {
            for(int j = 0;j<n;j++)
            {
                cout<<sol[i][j]<<" ";
            }
            putchar('\n');
        }
        cout<<endl;
        return true;
    }

     if(maze[i][j] == 'X'){
        return false;
    }

    if(i>m || j > n)
    {
        return false;
    }
   
    if(maze[i][j] == 'X'){
        return false;
    }

    sol[i][j] = 1;
    bool rightSuccess = rateInMaze(maze,sol,i,j+1,m,n);
    bool downSuccess = rateInMaze(maze,sol,i+1,j,m,n);

    
//backtrce
    if(rightSuccess || downSuccess)
     {
         return true;
     }
sol[i][j] = 0;

    return false;
}
int main()
{
    int m,n;
    cin>>m>>n;
    char maze[10][10];
    int sol[10][10] = {0};
    for(int i = 0; i<m;i++)
    {
        for(int j =0;j<n;j++ )
        {
            cin>>maze[i][j];
        }
    }
    if(!rateInMaze(maze,sol,0,0,m,n))
    {
        cout<<"-1"<<endl;
    }
    return 0;
}