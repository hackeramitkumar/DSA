#include<bits/stdc++.h>
using namespace std;

// Naieve Approach  O(sqrt(N)) for each numbers
bool isPrime(int n) {
    if( n == 1) {
        return false;
    }
    if(n == 2)
    {
        return true;
    }
    for(int i = 2;i*i<n;i++)
    {
        if(n%i == 0)
        return false;
    }
    return true;
}

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

    //lets print primes 
    for(int i=0;i<n;i++)
    {
        if(p[i] == 1) {
            cout<< i <<" ";
        }
    }
    putchar('\n');

    return 0;

    
}
