#include<bits/stdc++.h>
using namespace std;

void no_of_divisors(int n)
{
    int ans = 1;
    for(int i = 2; i*i <= n;i++)
    {
        if(n%i == 0)
        {
            // keep on deviding it by i till it is divisible 
            int cnt = 0;
            while(n%i == 0)
            {
                cnt++;
                n = n/i;
            }
            ans = ans*(cnt+1);
        }
    }
    if( n != 1)
    {
        ans = ans*2;
    }
    cout<<ans<<endl;


}

int main()
{
    int n;
    cin>>n;
    no_of_divisors(n);
    return 0;

}