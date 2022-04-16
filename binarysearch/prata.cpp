#include<bits/stdc++.h>
using namespace std;

bool isPossible(int arr[],int L,int P,int curr_min)
{
    int total = 0;
    for(int i = 0;i<L;i++)
    {
    int time = 0;
    int j = 1;
        while((time+arr[i]*j)<=curr_min)
        {
            time = time+arr[i]*j;
            total++;
            j++;
        }
    }
    if(total>=P)
    {
        return true;
    }else{
        return false;
    }
    
}
int minTime(int arr[],int L,int P)
{
    int sum = 0;
    int ans = INT_MAX;
    for(int i =1;i<=P;i++)
    {
        sum += arr[0]*i;
    }

    int s = 0;
    int e = sum;
    while(s<= e)
    {
        int mid = (s+e)/2;
        if(isPossible(arr,L,P,mid))
        {
            ans = min(ans,mid);
            e = mid-1;
        }else
        {
            s = mid+1;
        }
    }

    return ans;

}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int P,L;
        cin>>P;
        cin>>L;
        int arr[L];
        for(int i=0;i<L;i++)
        {
            cin>>arr[i];
        }
        cout<<minTime(arr,L,P)<<endl;

    }
    return 0;
}