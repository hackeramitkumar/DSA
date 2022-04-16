#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MOD 1000000007
#define ll long long

int power(long long x,ll y, int p) 
{ 
    int res = 1;    

    x = x % p; 
            
 
    if (x == 0) return 0; 

    while (y > 0) 
    { 
        
        if (y & 1) 
            res = (res*x) % p; 

    
        y = y>>1;
        x = (x*x) % p; 
    } 
    return res; 
} 


int main() {
    
    int t;
    cin>>t;
    while(t--)
    {
        int mod = 1000000007;
        string s;
        cin>>s;
        ll val = 0;
        ll length = s.length();
        for(ll i = 0;i<length;i++)
        {
            char ch = s[length - 1 - i];
            int curr = ch - 'A' + 1;
            // cout<<s[i]<<curr<<endl;
            val = (val%MOD + (power(26 , i,mod)%MOD*curr%MOD)%MOD)%MOD ;
        }
        cout<<val<<endl;
    }
    return 0;
}
