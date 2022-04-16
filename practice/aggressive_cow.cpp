#include <bits/stdc++.h>
using namespace std;



#define ll long long

bool isPossible(ll stalls[],ll n, ll c, ll min_sep){
	ll last_cow = stalls[0];
	ll cnt = 1;
	
	for(ll i = 1;i<n;i++){
		if(stalls[i] - last_cow >= min_sep){
			last_cow = stalls[i];
			cnt++;
			if(cnt == c){
				return true;
			}
		}
	}
	return false;
}



ll binary_search_(ll arr[],ll n, ll c){
ll s = 0;
	ll e = n-1;
	ll ans = 0;
	while(s <= e){
		ll mid = (s+e)/2 ;
		bool cowRakhPaye = isPossible(arr,n,c,mid);
		if(cowRakhPaye){
			ans = mid;
			s = mid + 1;
			
		}else{
			e = mid - 1;
		}
	}
	return ans;
}

int main() {
	int t;
	cin>>t;
	while(t--){
		ll n,c;
	cin>>n>>c;
	ll arr[n];
	for(ll i = 0;i< n;i++){
		cin>>arr[i];
	}
	
	cout<<binary_search_(arr,n,c)<<endl;
	
	}
	return 0;
}