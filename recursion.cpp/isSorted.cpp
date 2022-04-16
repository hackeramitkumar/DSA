#include<bits/stdc++.h>
using namespace std;

bool isSorted(int *arr,int n)
{
    //base case

    //recursive case
    bool isSmallerSorted = isSorted(arr+1,n-1);
    if(isSmallerSorted && arr[0]<arr[1])
    {
        return true;
    }
    else{
        return false;
    }
}

bool isArray(int *arr,int n, int i){

    if(i == n)
    return true;

    if(arr[i]>arr[i+1])
    return false;

   return isArray(arr,n,i+1);
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
    cout<<isArray(arr,n,0)<<endl;
    cout<<isSorted(arr,n);

    return 0;
}