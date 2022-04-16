#include<bits/stdc++.h>
using namespace std;

/*
Create matrix min_cost[n+1][W+1], where n is number of distinct weighted packets of orange and W is maximum capacity of bag.
Initialize 0th row with INF (infinity) and 0th Column with 0.
Now fill the matrix
if wt[i-1] > j then mincost[i][j] = mincost[i-1][j] ;
if wt[i-1] <= j then mincost[i][j] = min(mincost[i-1][j], val[i-1] + min_cost[i][j-wt[i-1]]);
If mincost[n][W]==INF then output will be -1 because this means that we cant not make make weight W by using these weights else output will be mincost[n][W].

*/

int solve(int *val,int n,int i,int W,int dp[1000][1000]){
	if(W == 0)
	return 0;

	if(i == W){
		return 10000000;
	}

	




}

int MinMoney(int prices[], int vidx, int cap, int strg[][]) {

        if (cap == 0) {
            return 0;
        }

        if (vidx == prices.length) {
            return 10000000;
        }

        if (strg[vidx][cap] != -1) {
            return strg[vidx][cap];
        }

        int inc = 10000000;
        if (cap >= vidx + 1 && prices[vidx] != -1) {
            inc = MinMoney(prices, vidx, cap - vidx - 1, strg) + prices[vidx];
        }
        int exc = MinMoney(prices, vidx + 1, cap, strg);

        return strg[vidx][cap] = Math.min(inc, exc);
    }


int solve(int *val,int n, int W){

	
	int dp[W+1] = {0};
	for(int i = 1;i<=n;i++){
		for(int j = i;j <= W;j++){
			dp[j] = max(dp[j] , dp[j - i]+ val[i]);
		}
	}
	int max1 = 0;
	for(int i = 0;i<= W;i++)
	{
        cout<<dp[i]<<" ";
		max1 = max(max1,dp[i]);
	}
    
    cout<<endl;
	return max1;

}


int main()
{
	int n,W;
	cin>>n>>W;
	int val[n+1];
	for(int i = 1;i<=W;i++){
		cin>>val[i];
	}
	int weight
	cout<<solve(val,n,W);

}