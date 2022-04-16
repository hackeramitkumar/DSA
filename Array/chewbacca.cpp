#include<bits/stdc++.h>
using namespace std;

int main()
{
     long long int n;
	 cin>>n;
	 vector<int> v;

	 while(n>0)
	 {
		 int curr = n%10;
		 v.push_back(curr);
		 n = n/10;
	 }
	 int l = v.size();
	 if((9-v[l-1])>0)
	 {
		 v[l-1] = min(v[l-1],9-v[l-1]);
	 }
	 for(int i = 0;i<l-1;i++)
	 {
		 v[i] = min(v[i],9-v[i]);
	 }
	 for(int i = l-1;i>=0;i--)
	 {
		 cout<<v[i];
	 }
	 putchar('\n');




	 return 0;
}