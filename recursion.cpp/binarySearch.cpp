#include<bits/stdc++.h>
using namespace std;

int binarySearch(int *a,int s,int e,int key)
{
    if(s>e)
    return -1;


    // recursive case
    int m = (s+e)/2;
    if(a[m] == key){
    return m;
    }else if(a[m]>key){
    return binarySearch(a,m+1,e,key);
    }else
    {
        binarySearch(a,s,m-1,key);
    }
}
int main()
{

        int n;
        cin>>n;
        int arr[n];
        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        int key;
        cin>>key;
       int ans  = binarySearch(arr,0,n,key);
        cout<<ans<<endl;
    
    return 0;
}
