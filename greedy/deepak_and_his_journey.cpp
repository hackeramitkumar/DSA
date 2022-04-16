#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int c[n];
		int l[n];
		for(int i = 0;i<n;i++){
			cin>>c[i];
		}
		for(int i = 0;i<n;i++){
			cin>>l[i];
		}

		int cost = c[0]*l[0];
		// priority_queue<int,vector<int>, greater<int> > pq;

		// pq.push(c[0]);
        int val = c[0];
		for(int i = 1;i<n;i++){
			// pq.push(c[i]);
            val = min(val,c[i]);
			cost += l[i]*val;
		}
		cout<<cost<<endl;
	}
	return 0;
}