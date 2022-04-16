#include<bits/stdc++.h>
using namespace std;

bool compare(int a,int b)
{
    return a<b;
}

void bubble_sort(int arr[],int n,bool (&tulna_karo)(int a,int b))
{
    for(int i =0;i<n;i++)
    {
        for(int j = 0;j<n-i-1;j++)
        {
            // if(arr[j]>arr[j+1])
            if(tulna_karo(arr[j],arr[j+1]))
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
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
    bubble_sort(arr,n,compare);
    for(int i =0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    putchar('\n');
    return 0;
}