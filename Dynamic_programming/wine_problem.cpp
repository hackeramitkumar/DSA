#include<bits/stdc++.h>
using namespace std;

//Top down
int wine_max_prof(int *P,int i,int j,int y,int dp[][100]){
    //base case
    if(i>j)
    {
        return 0;
    }
    //look up
    if(dp[i][j] != 0)
    {
        return dp[i][j];
    }

    //rec case
    int op1 = P[i]*y + wine_max_prof(P,i+1,j,y+1,dp);
    int op2 = P[j]*y + wine_max_prof(P,i,j-1,y+1,dp);
    
    return dp[i][j] = max(op1,op2);
}

//bottom up
int wine_max_prof_BU(int *P,int i ,int j,int dp[][100]){
    
}

int main(){
    int n;
    cin>>n;
    int P[n];
    int dp[100][100] = {0};
    for(int i = 0;i<n;i++){
        cin>>P[i];
    }
    cout<<wine_max_prof(P,0,n-1,1,dp)<<endl;


}

