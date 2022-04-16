#include<bits/stdc++.h>
using namespace std;

int main()
{
	char a[1000];
	cin>>a;
	int i = 0;
	while(i<strlen(a)){
		int cnt = 1;
		int j = i+1;
		while(a[j]==a[i])
		{
			cnt++;
			j++;
		}
		if(cnt>1){
		cout<<a[i]<<cnt;
		}else
		{
			cout<<a[i];
		}
		i = j;
	}
	return 0;
}