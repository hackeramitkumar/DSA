#include<bits/stdc++.h>
using namespace std;


//TOP DOWN 
int ladder_TD(int n,int *dp){
    if(n == 0)
    return 1;

    //look up
    if(dp[n] != 0)
    {
        return dp[n];
    }

    //rec case
    int ways = 0;
    for(int i = 1;i<=n;i++){
        if( n-i >= 0){
            ways += ladder_TD(n-i,k,dp);
        }
    }
    return dp[n] = ans;
}

//BOTTOM UP
int fib_BU(int n){
    int dp[n+1] = {0};

    dp[0] = 0;
    dp[1] = 1;

    for(int i  = 2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    return dp[n];
}

// space optimised
int fib_opti(int n){
    if(n == 0|| n==1 ){
        return n;
    }
    int a = 0;
    int b = 1;
    int c ;


    for(int i  = 2;i<=n;i++){
        c = a+b;
        a = b;
        b = c;
    }
    return c;

}


int main(){
    int n;
    cin>>n;
    int dp[100] = {0};
    cout<<ladder_TD(n,dp)<<endl;
    cout<<ladder_BU(n)<<endl;
    cout<<ladder_opti(n)<<endl;


}