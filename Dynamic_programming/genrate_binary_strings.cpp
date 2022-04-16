#include<bits/stdc++.h>
using namespace std;

int count_strings(int n, int last_digit,int dp[][2]){
    if(n == 1)
    return 2;

    if(dp[n][last_digit] != 0)
    {
        return dp[n][last_digit];
    }

    int ans = 0;

    if(last_digit == 0){
       ans =  count_strings(n-1,0,dp)+count_strings(n-1,1,dp);
       dp[n][last_digit] = ans;
    }else{
        ans = count_strings(n-1,0,dp);
       dp[n][last_digit] = ans;
    }
    return dp[n][last_digit];
}

//bottom_up_dp
int count_string_BU(int n)
{
    int dp[100000][2] = {0};
    dp[1][0] = 1;
    dp[1][1] = 1;

    dp[2][0] = dp[1][1]+dp[1][0];
    dp[2][1] = dp[1][0];


    for(int i = 3;i<=n;i++){
        dp[i][0] = dp[i-1][1] + dp[i-1][0];
        dp[i][1] = dp[i-1][0];
    }

    return dp[n][0]+dp[n][1];
}

int main(){
    int n,t;
    cin>>t;
    while(t--){
    cin>>n;

    // int dp[100000][2] = {0};
    cout<<count_string_BU(n)<<endl;
    }
}