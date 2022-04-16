#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,d;
    cin>>n>>d;
    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];

    }
    sort(arr,arr+n);
    int cnt = 0;
    int first = arr[0];

    for(int i = 1;i<n;i++)
    {
        if(arr[i]-first <= d)
        {
            cnt++;
            i++;
            first = arr[i];
        }else{
            first = arr[i];
        }

    }
    cout<<cnt<<endl;

}