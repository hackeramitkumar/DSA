#include<bits/stdc++.h>
using namespace std;

/*
bool rate_in_maze(char arr[][100],int sol[100][100] , int m, int n , int i , int j){
    if(i == m and j == n){
        //print
        sol[i][j] = 1;
        for(int i = 0;i<=m;i++){
            for(int j = 0;j<=n;j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        return false;
    }

    if(i > m || j > n){

        return false;
    }
    if(arr[i][j] == 'X'){

        return false;
    }

    sol[i][j] = 1;
    bool  right = rate_in_maze(arr,sol,m,n,i,j+1);
    bool down = rate_in_maze(arr,sol,m,n,i+1,j);

    if(left || right){
        return true;
    }
    sol[i][j] = 0;
    return false;
}
int main(){
    int n,m;
    cin>>n>>m;
    char arr[100][100];
    int sol[100][100] = {0};
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            cin>>arr[i][j];
        }
    }


    cout<<rate_in_maze(arr,sol,m-1,n-1,0,0)<<endl;

}
*/


void permute(char *in,int i){
    if(in[i] == '\0'){
        cout<<in<<endl;
        return;
    }

    //rec case
    for(int j = i;in[j] != '\0';j++){
        swap(in[i],in[j]);
        permute(in,i+1);
        swap(in[i],in[j]);
    }

}


int main(){
    char in[100];
    cin>>in;

    permute(in,0);
}




