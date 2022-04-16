#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    int key;
    cin>>key;

    int ans = (upper_bound(arr,arr+n,key) - arr ) - (lower_bound(arr,arr+n,key)-arr);

cout<<ans;

}