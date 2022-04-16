#include<bits/stdc++.h>
using namespace std;

int Binary_search(int a[],int n,int key)
{
    int s = 0 , e = n-1;

    while(s<=e){
        int mid = e - (s+e)/2;

        if(a[mid] == key)
        {
            return mid;
        }else if(a[mid]>key)
        {
            return e = mid-1;
        }else{
            s = mid+1;
        }


    }
    return -1;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    int key;
    cin>>key;
    cout<<"The key is present at the index: "<<Binary_search(arr,n,key)<<endl;
    return 0;

}