#include<bits/stdc++.h>
using namespace std;

vector<int> primeSieve(int *p,int n)
{
    p[0] = 0;
    p[1] = 0;
    p[2] = 1;
    for(int i = 3;i<=n;i+=2)
    {
        p[i] = 1;
    }
    for(long long i = 3;i<=n;i+=2)
    {
        if(p[i])
        {
            for(long long j = i*i;j<=n;j += i)
            {
                p[j] = 0;
            }
        }

    }
    vector<int> primes;
    primes.push_back(2);
    for(int i = 3;i<=n;i += 2)
    {
        if(p[i])
        {
            primes.push_back(i);
        }
    }
    return primes;
}
int main()
{
	 int N = 1000000;
    int p[N] = {0};
    //  primeSieve(p,500000);
    vector<int> primes = primeSieve(p,500000);
	
int t;
cin>>t;
while(t--)
{
	int x;
	cin>>x;
	cout<<primes[x-1]<<endl;
}
	return 0;
}