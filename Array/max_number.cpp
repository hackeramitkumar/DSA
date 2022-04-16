#include<bits/stdc++.h>
using namespace std;

int myCompare(string X,string Y)
{
	 // first append Y at the end of X
    string XY = X.append(Y);
 
    // then append X at the end of Y
    string YX = Y.append(X);
 
    // Now see which of the two
    // formed numbers is greater
    return XY.compare(YX) > 0 ? 1 : 0;
}

void LargestNumber(vector<string>& v)
{
sort(v.begin(),v.end(),myCompare);

}

int main()
{
	int n;
	cin>>n;
	vector<string> arr;
	for(int i=0;i<n;i++)
	{
		string s;
		cin>>s;
		arr.push_back(s);
	}
	LargestNumber(arr);
	for(int i = 0;i<n;i++)
	{
		cout<<arr[i];
	}
return 0;

}