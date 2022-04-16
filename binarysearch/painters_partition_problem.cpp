#include<bits/stdc++.h>
using namespace std;
bool isPossible(int arr[],int n,int K,int curr_min)
{
    int painterUsed = 1;

    int timeTaken = 0;

    for(int i = 0;i<n;i++)
    {
        //not required
        if(timeTaken+arr[i] > curr_min)
        {
            painterUsed++;
            timeTaken = arr[i];
            if(painterUsed>K)
            {
                return false;
            }
        }else{
            timeTaken += arr[i];
        }
    }
    return true;
}

int minTime(int arr[],int n,int K)
{
    int sum = 0;
   /* if(n<K)
    {
        return -1;
    }

    */
    //count the no of pages
    for(int i = 0;i<n;i++)
    {
        sum += arr[i];
    }


    int s = arr[n-1];
    int e = sum;
    int ans = INT_MAX;

    while(s<=e)
    {
        int mid = (s+e)/2;

        if(isPossible(arr,n,K,mid))
        {
            ans = min(ans,mid);
            e = mid - 1;

        }else{
            //it is possible to devide the pages
            s = mid+1;
        }

    }
    return ans;
}

int main()
{
    
        int K,n;
        cin>>K;
        cin>>n;
        int arr[n];
        for(int i = 0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<minTime(arr,n,K)<<endl;
    
    return 0;

}