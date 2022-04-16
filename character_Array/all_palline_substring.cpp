#include<bits/stdc++.h>
using namespace std;

bool isPallin(char a[],int i,int j)
{
	while(i<j)
	{
		if(a[i] != a[j])
		return false;
		i++;
		j--;
	}
	return true;
}

int main()
{
	char a[1000];
	int cnt = 0;
	cin>>a;int n = strlen(a);
	for(int i = 0;i<n-1;i++)
	{
		for(int j = i+1;j<n;j++)
		if(isPallin(a,i,j)==1)
		{
			cnt++;
		}
	}
	cout<<cnt+n<<endl;
	return 0;

}