#include<bits/stdc++.h>
using namespace std;
void solve(int n,char *out,int j,int *cnt)
{
	//base case
	if(j == n)
	{
		out[j] = '\0';
		(*cnt)++;
		return;
	}

	//rec case
	out[j] = 'a';
	solve(n,out,j+1,cnt);
if(out[j-1] != 'b' || j==0){
	out[j] = 'b';
	solve(n,out,j+1,cnt);
}

	
}
int main()
{
int t;
cin>>t;
int k = 1;
while(t--)
{
	int n;
	cin>>n;
char out[25];

	int cnt = 0;
	solve(n,out,0,&cnt);
	cout<<"#"<<k<<" : "<<cnt<<endl;
	k++;
}
return 0;
}