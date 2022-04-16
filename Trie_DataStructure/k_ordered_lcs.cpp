#include<bits/stdc++.h>
using namespace std;
#define MAX 2000

int solve(int *arr1,int *arr2 ,int n,int m,int k,int dp[MAX][MAX][6]){

	// If at most changes is less than 0.
    if (k < 0)
        return -1e7;
 
    // If any of two array is over.
    if (n < 0 || m < 0)
        return 0;

	// Making a reference variable to dp[n][m][k]
    int& ans = dp[n][m][k];
 
	if(ans != -1)
	{
		return ans;
	}




	// make no change 
	ans = max(solve(arr1,arr2,n-1,m,k,dp) , solve(arr1,arr2, n,m-1,k,dp));


	if(arr1[n-1] == arr2[m-1]){
		ans = max( ans , 1 + solve(arr1,arr2, n-1,m-1,k,dp));
	}

	//change made
	ans = max(ans , 1 + solve(arr1,arr2,n-1,m-1,k-1,dp));

	return ans;

}

int main(){
	int n,m,k;
	cin>>n>>m>>k;

	int arr1[n];
	int arr2[m];
	for(int i = 0;i<n;i++){
		cin>>arr1[i];
	}
	for(int i = 0;i<m;i++){
		cin>>arr2[i];
	}
	int dp[MAX][MAX][6];
    memset(dp, -1, sizeof(dp));

	cout<<solve(arr1,arr2,n,m,k,dp);
	cout<<solve(dp,arr1,arr2,n,m,k,dp);



}