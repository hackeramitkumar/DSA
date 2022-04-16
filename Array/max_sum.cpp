#include<bits/stdc++.h>
using namespace std;

int Max_sum(int arr[],int n){
	int max_sum = arr[0],curr_sum =arr[0];
	for(int i = 1;i<n;i++)
	{
		 curr_sum = max(curr_sum+arr[i], arr[i]);
		max_sum = max(curr_sum,max_sum);
	}
	return max_sum;
}


int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int arr[n];
		for(int i = 0;i<n;i++){
			cin>>arr[i];
		}
		cout<<Max_sum(arr,n)<<endl;
	}
	return 0;

}