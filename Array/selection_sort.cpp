#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[],int n)
{
    for(int i =1;i<n;i++)
    { int pick = arr[i];
    int j;
     /*   for( j = i-1;j>=0;j--)
        {
            if(arr[j]>pick)
            {
                arr[j+1] = arr[j];
               
            }else
            {
                break;
            }
        }
        */
       for(j = i-1;j>=0 and arr[j]>pick;j--)
       {
           arr[j+1] = arr[j];
       }
        arr[j+1] = pick;

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
    selection_sort(arr,n);
    for(int i =0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    putchar('\n');
    return 0;
}