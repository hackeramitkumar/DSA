#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i = 0;i<n;i++){
		cin>>arr[i];
	}

	int ans = 0;
	unordered_set<int> mp;
	int j = 0;
	for(int i = 0;i<n;i++){
		while(j<n and mp.find(arr[j]) == mp.end()){
			mp.insert(arr[j]);
			j++;
		}

        // cout<<"i:"<<i<<endl;
        // cout<<"j:"<<j<<endl;

		
		ans += ((j-1-i+1)*(j-1-i+2))/2;
		mp.erase(arr[i]);
	}
	cout<<ans<<endl;
}