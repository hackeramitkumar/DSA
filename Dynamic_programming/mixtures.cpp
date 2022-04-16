#include<bits/stdc++.h>
using namespace std;

int a[101];
long long dp[101][101];

long long sum(int s,int e){
    long long sum = 0;
    long long ans = 0; 
    for(int i = s;i<=e;i++){
        sum += a[i];
        ans %= 100;
    }
    return ans;
}

long long solveMixtures(int i,int j){
    // Base case

    if(i >= j){
        return 0;
    }

    if(dp[i][j] != -1){
        return dp[i][j];
    }

    dp[i][j] = INT_MAX;
    for(int k = i;k<=j;k++){
        dp[i][j] = min(dp[i][j],solveMixtures(i,k) + solveMixtures(k+1 ,j)+ sum(i,k)*sum(k+1,j));
    }

    return dp[i][j];
}

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<solveMixtures(0,n-1)<<endl;


}