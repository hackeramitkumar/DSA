

/*#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

long long solve(long long n, long long m)
{
	//base case
if(n<m)
return 1;

	//rec case
	return (solve(n-1,m)%MOD+solve(n-m,m)%MOD)%MOD;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,m;
		cin>>n>>m;
		cout<<solve(n,m)<<endl;
	}
		return 0;

}
*/