#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;

int main() {

	int t;
	cin>>t;
	int n,p;
	while(t--){
	cin>>n>>p;
if(n== 1){
	cout<<"NO"<<endl;
	continue;
}
// if(n == 2){
// 	if(p==1){
// 		cout<<"YES"<<endl;
// 	}else{
// 		cout<<"NO"<<endl;
// 	}
// 	continue;
// }
	int pair_cnt = 0;
	int k = 2;
	while(k <= n ){
		pair_cnt += (n-k+1);
		k = k + 2;
	}
    // cout<<pair_cnt<<endl;
	if(p == pair_cnt){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;

	}
	}
	return 0;
}