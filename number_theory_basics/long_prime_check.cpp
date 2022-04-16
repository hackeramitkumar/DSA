// -> space optimised sieve using bitset
// -> checking if a large number is prime or not ~10^12 type


#include<iostream>
#include<bitset>
#include<vector>
using namespace std;

#define ll long long int

const int n = 10000000;  //maximum size of sieve
bitset<10000005> b;
vector<int> primes;

void sieve(){
    // firstly set all the bits
    b.set();

    b[0] = b[1] = 0;
    for(ll i = 2;i<=n;i++)
    {
        if(b[i]){
            primes.push_back(i);
            for(ll j = i*i;j<=n;j = j+i)
            {
                b[j] = 0;
            }
        }
    }
}

// now i will check a large nu,ber is prime or not
bool isPrime(ll No)
{
    if(No<=n)
    {
        return b[No]==1 ? true : false;
    }
    for(ll i = 0;primes[i]*primes[i] <= No;i++)
    {
        if(No%primes[i] == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    sieve();
    ll No;
    cin>>No;
    cout<<isPrime(No)<<endl;
}


