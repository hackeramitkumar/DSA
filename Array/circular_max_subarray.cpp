#include<bits/stdc++.h>
using namespace std;


//Logic behind this code is -
/*
firstly i calculated array sum
then i calculated the minimum sub array sum


this code is giving wrong answer in only Test case 0 

what is wrong with it

*/

int maxSum(int arr[],int n)
{
	int sum = 0;
	for(int i = 0;i<n;i++)
	{
		sum += arr[i];
	}
	int minsum = INT_MAX;int curr_sum = 0;
	for(int i = 0;i<n;i++)
	{
		curr_sum = min(curr_sum+arr[i],arr[i]);
		minsum = min(curr_sum , minsum);
	}
	return sum - minsum;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int arr[n];
		for(int i = 0;i<n;i++)
		{
			cin>>arr[i];
		}

		cout<<maxSum(arr,n)<<endl;
	}
	return 0;

}