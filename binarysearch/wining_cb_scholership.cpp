#include<bits/stdc++.h>
using namespace std;


int maxScholership(int N,int M,int X,int Y)
{
    

    int s = 0;
    int e = N;
    int ans = 0;
    while(s<= e)
    {
        int mid = (s+e)/2;

        if((M+(N-mid)*Y)>=(mid*X))
        {
            ans = max(ans,mid);
            s = mid+1;
        }else
        {
            e = mid-1;
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
        int N,M,X,Y;
        cin>>N>>M>>X>>Y;

        cout<<maxScholership(N,M,X,Y)<<endl;

    }
    return 0;
}