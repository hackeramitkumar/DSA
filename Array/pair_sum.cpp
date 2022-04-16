#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,sum;
    cin>>n>>sum;
    int arr[n];
    for(int i =0;i<n;i++)
    {
        cin>>arr[i];
    }
    int i = 0,j = n-1,cnt = 0;
    while(i<j)
    {
        if(arr[i]+arr[j]>sum)
        {
            j--;
        }else if(arr[i]+arr[j]<sum)
        {
            i++;
        }
        else{
            cout<<"element of pair will be at index:"<<"{"<<i<<","<<j<<"}"<<endl;
            cnt = 1;
            i++;
            j--;
        }
    }
    if(cnt == 0)
    {
        cout<<"NO pair found"<<endl;

    }
return 0;
}