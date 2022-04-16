#include<bits/stdc++.h>
using namespace std;

#define ll long long

ll solve(ll int){

}
ll solve(ll n,ll *dp){
	if(n == 0 || n == 1)
	{
		return n;
	}

	if(dp[n] != 0) return dp[n];

	//rec case
	ll ans = max (n , solve(n/2,dp)+solve(n/3,dp)+solve(n/4,dp));
	return dp[n] = ans;
}
int main(){
	ll n;
	cin>>n;
	unordered_map<
	cout<<solve(n,dp)<<endl;

}