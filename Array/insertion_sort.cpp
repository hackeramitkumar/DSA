#include<bits/stdc++.h>
using namespace std;

void insertion_sort(int arr[],int n)
{
    for(int i =0;i<n-1;i++)
    { //let minimum element is at the index i+1
        int min = i+1;
        for(int j = i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
               min = j;
            }
            
        }
    // Find minimum in the range[i+1 , n-1]
    //swap with arr[i]
        if(arr[i]>arr[min])
        {
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    insertion_sort(arr,n);
    for(int i =0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    putchar('\n');
    return 0;
}