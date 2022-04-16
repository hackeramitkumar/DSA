#include<bits/stdc++.h>
using namespace std;

void decimalToBinary(int n)
{
    long long int p =1;
    long long int ans = 0;
    while(n>0)
    {
        ans += (n%2)*p;
        
        p *= 10;
        n = n>>1;
    }
    cout<<ans<<endl;
}

//methode - 2

void decimalToBinary(int n)
{
    long long int p =1;
    long long int ans = 0;
    while(n>0)
    {
        ans += (n&1)*p;
        p *= 10;
        n = n>>1;
    }
    cout<<ans<<endl;
}


int main()
{
    int n;
    cin>>n;
    decimalToBinary(n);
    return n;
}