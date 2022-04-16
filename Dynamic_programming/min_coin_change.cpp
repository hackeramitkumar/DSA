#include<bits/stdc++.h>
using namespace std;

int minCoinChange_TD(int n,int Coins[],int T,int dp[]){
    //Base case
    if(n == 0)
    return 0;

    //look up
    if(dp[n] != 0)
    {
        return dp[n];
    }

    //Rec case
    int ans = INT_MAX;
    for(int i = 0;i<T;i++){
        if(n-Coins[i] >= 0){
            int subProb = minCoinChange_TD(n - Coins[i],Coins,T,dp);
            ans = min(ans , subProb + 1);
        }
    }

    dp[n] =ans;
    return dp[n];
}

int minCoins_BU(int N,int Coins[],int T){
    int dp[N+1] = {0};
    // Iterate over all steps 1-------N
    for(int n = 1;n<=N;n++){
        //init curr ans INT_MAX
        dp[n] = INT_MAX;
        for(int i = 0;i<T;i++){
            if(n-Coins[i] >= 0){
                int subProb = dp[n-Coins[i]];
                dp[n] = min(dp[n],subProb + 1);

            }
        }
    }
    return dp[N];
}
int main(){
    int n;
    cin>>n;
    int Coins[] = {1,2,5,10,20,50,100};
    int T = 7;
    int dp[100] = {0};
    cout<<minCoinChange_TD(n,Coins,T,dp)<<endl;
    cout<<minCoins_BU(n,Coins,T)<<endl;



}