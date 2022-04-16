#include<bits/stdc++.h>
using namespace std;

//Bottom UP
int maxSum_BU(int *a,int n){
    int dp[100]= {0};
    dp[0] = dp[0]>0?dp[0]:0;

    int max_so_far = dp[0];
    for(int i = 1;i<n;i++){
        dp[i] = dp[i-1]+a[i];
        if(dp[i<0]){
            dp[i] = 0;
        }
        max_so_far = max(max_so_far,dp[i]);
    }
    return max_so_far;
}


//Bottom UP + space optimized
int maxSum_space_opt(int *a,int n){
    int current_sum = 0;

    int max_so_far = 0;
    for(int i = 0;i<n;i++){
        current_sum += a[i];
        if(current_sum < 0){
            current_sum = 0;
        }
        max_so_far = max(current_sum,max_so_far);
    }
    return max_so_far;
    
}

int main(){
    int n;
    cin>>n;
    int a[n];
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    cout<<maxSum_BU(a,n)<<endl;
    cout<<maxSum_space_opt(a,n)<<endl;


}

