#include<bits/stdc++.h>
using namespace std;

bool canPlace(int board[][10],int n,int x,int y){
    //column
    for(int k = 0;k<x;k++){
        if(board[k][y] == 1){
            return false;
        }
    }
    //Left diag
    int i = x,j = y;
    while(i >= 0 and j >= 0) {
        if(board[i][j] == 1) {
            return false;
        }
        i-- ; j--;
    }

    //Right Diag
    i = x,j = y;
    while(i >= 0 and j<n) {
        if(board[i][j] == 1) {
            return false;
        }
        i--;
        j++;
    }
    return true;
}

bool nQueen(int n,int board[][10],int i){
    //Base case
    if(i == n) {
        //print the board
        for(int  x = 0;x < n;x++)
        {
            for(int y = 0;y < n;y++)
            {
                cout<<board[x][y] << " ";
            }
            cout<<endl;
        }
        cout<<endl;
        return false;
    }
        //recursive case
        // try toplac queen at every column/position in the grid
        for(int j = 0;j<n;j++){
            if(canPlace(board,n,i,j)) {
                board[i][j] = 1;
              if(  nQueen(n,board,i+1)){
                return true;
              }
              board[i][j] = 0;
            }
        }
        return false;
}
bitset<30> col , d1, d2; // this will take 30bits while bool array take 8*30 bits so this is preffred
void solve(int r,int n, int &ans){
    if(r == n){
        ans++;
        return;
    }

    for(int c= 0;c<n;c++){
        if(!col[c] && !d1[r-c + n-1] && !d2[r+c]){
            col[c] = d1[r-c+n-1] = d2[r+c] = 1;
            solve(r+1,n,ans);
            col[c] = d1[r-c+n-1] = d2[r+c] = 0;

        }
    }



}


int main()
{ 
    // int board[10][10] = {0};
    int n;
    cin>>n;
    int ans = 0;

    solve(0,n,ans);
    cout<<ans;
    return 0;


}


/*
#include<bits/stdc++.h>
using namespace std;

bool canPlace(int board[][10],int n,int x,int y){
    //column
    for(int k = 0;k<x;k++){
        if(board[k][y] == 1){
            return false;
        }
    }
    //Left diag
    int i = x,j = y;
    while(i >= 0 and j >= 0) {
        if(board[i][j] == 1) {
            return false;
        }
        i-- ; j--;
    }

    //Right Diag
    i = x,j = y;
    while(i >= 0 and j<n) {
        if(board[i][j] == 1) {
            return false;
        }
        i--;
        j++;
    }
    return true;
}
int nQueen(int n,int board[][10],int i){
    //Base case
    if(i == n) {
        //print the bpard
        for(int  x = 0;x < n;x++)
        {
            for(int y = 0;y < n;y++)
            {
                cout<<board[x][y] << " ";
            }
            cout<<endl;
            return 1;
        }

    }
        //recursive case
        // try toplac queen at every column/position in the grid
        int cnt = 0;
        for(int j = 0;j<n;j++){
            if(canPlace(board,n,i,j)) {
                board[i][j] = 1;
                cnt += nQueen(n,board,i+1);
            }
        }
        return cnt;

    

}
int main()
{ 
    int board[10][10] = {0};
    int n;
    cin>>n;

    cout<<nQueen(n,board,0)<<endl;
    return 0;


}


*/