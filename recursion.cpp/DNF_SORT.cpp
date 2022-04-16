#include<bits/stdc++.h>
using namespace std;

void sort(int *arr,int n)
{
    int lo = 0;
    int mid = 0;
    int hi = n-1;
    while(mid<=hi)
    {
        if(arr[mid] == 0)
        {
            swap(arr[lo++],arr[mid++]);
        }else if(arr[mid] == 2)
        {
            swap(arr[hi--],arr[mid]);
        }else{
            mid++;
        }
    }
}

int main()
{
    int arr[] {1,0,0,1,2,2,0,1,2,0,2,1,1,2,0,2,1,2,0,1};
    int n = sizeof(arr)/sizeof(int);
    sort(arr,n);
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    putchar('\n');
}