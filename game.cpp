#include<bits/stdc++.h>
using namespace std;



int find(vector<vector<int> > & board,int i , int j){
        
        int m = board.size();
        int n = board[0].size();
        
        int cnt = 0;
        if( i+1 < m  and board[i+1][j] == 1)
        {
            cnt += 1;
        }
        
         if(i-1 >= 0 and  board[i-1][j] == 1)
        {
            cnt += 1;
        }
        
         if( j+1 < n  and board[i][j+1] == 1 )
        {
            cnt += 1;
        }
        
        
         if(j-1 >= 0  and board[i][j-1] == 1)
        {
            cnt += 1;
        }
        

         if( j+1 < n and i+1 < m   and   board[i+1][j+1] == 1 )
        {
            cnt += 1;
        }
        
        
         if( j-1 >= 0 and i-1 >= 0 and board[i-1][j-1] == 1 )
        {
            cnt += 1;
        }
        
         if( j+1 < n and i-1 >= 0 and board[i-1][j+1] == 1)
        {
            cnt += 1;
        }
         
           if( j-1 >= 0 and i+1 < m  and board[i+1][j-1] == 1)
        {
            cnt += 1;
        }
        
    return cnt;
          
    }
    void gameOfLife(vector<vector<int>>& board) {
        
        int m = board.size();
        int n = board[0].size();
        int sol[26][26] = {0};
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(board[i][j] == 0){
                    int x = find(board,i,j);
                    if(x == 3){
                        sol[i][j] = 1;
                    }else {
                        sol[i][j] = 0;
                    }  
                }else if(board[i][j] == 1){
                    int x = find(board,i,j);
                    if(x<2 and x > 3){
                        sol[i][j]=0;
                    }
                    
                    if(x == 2 || x == 3){
                        sol[i][j] = 1;
                    }
                }
            }
        }
        
        
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                board[i][j] = sol[i][j];
            }
        }
        
    }


    int main(){
        int m,n;
        cin>>m>>n;
        vector<vector<int> > v(m+1 , vector<int> (n+1));
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                     cin>>v[i][j];
            }
        }

        gameOfLife(v);



        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                     cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }









    }