#include<bits/stdc++.h>
using namespace std;

//sieve prime Approach - Genrate a new array containeing prime numbers O(n) for all numbers til n
void prime_sieve(int *p) {
    // first mark all odd numbers as prime
    for(long long i = 3;i<=1000000; i+= 2)
    {
        p[i] = 1;
    }
    // Sieve 
    for(long long i = 3;i <= 1000000; i+=2)
    {
        //if the current number is not mark it is prime
        if(p[i] == 1)
        {
            // mark all the multiples of i as not prime
            for(long long j = i*i; j<= 1000000;j = j+i)
            {
                p[j] = 0;
            }
        }
    }

    // handle sum speacial case
    p[2] = 1;
    p[1] = p[0] = 0;
}

int main()
{
    int n;
    cin>>n;

    int p[1000005] = {0};

    prime_sieve(p);

    int csum[1000005] = {0};

    //precomput the prime upto an index
    for(int i = 0;i<=1000000;i++)
    {
        csum[i] = csum[i-1]+p[i];
    }
    
    while(n--)
    {
        int x,y;
        cin>>x>>y;
        int ans = csum[y] - csum[x];
        cout<<ans<<endl;
    }

    return 0;

    
}
