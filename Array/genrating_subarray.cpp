#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    int i = 0;
    while(i<n)
    {
      for(int j = i;j<=n;j++)
      {
          for(int k = i;k<j;k++)
          {
              cout<<arr[k]<<" ";
          }
          putchar('\n');
      }
      i++;
    }
return 0;
}