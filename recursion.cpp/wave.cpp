#include<bits/stdc++.h>
using namespace std;

void sort(int *arr,int n)
{
    int i = 0;
    while(i<n-2)
    {
        if(arr[i]<arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }
        i++;
        if(arr[i]>arr[i+1])
        {
            swap(arr[i],arr[i+1]);
        }
        i++;
    }
}

int main()
{
    int arr[] = {1,8,5,4,6,1,9,2,1};
    int n = sizeof(arr)/sizeof(int);
    sort(arr,n);
    for(int i = 0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    putchar('\n');
}