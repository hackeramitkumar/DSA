#include<bits/stdc++.h>
using namespace std;

#define ll long long int
int a[1000005],pre[1000005];

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        memset(pre,0,sizeof(pre));

        pre[0] = 1;
        int sum = 0;
        //read the input
        for(int i = 0;i<n;i++)
        {
            cin>>a[i];
            sum += a[i];
            sum %= n;
            sum = (sum+n)%n; // we are doing this for avoiding the negative values
            pre[sum]++;
        }

        ll ans = 0;
        for(int i = 0;i<n;i++)
        {
            int m = pre[i];
            ans += m*(m-1)/2;

        }
        cout<<ans<<endl;

    }
    return 0;

}