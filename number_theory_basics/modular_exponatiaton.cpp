#include<bits/stdc++.h>
using namespace std;

    /* Iterative Function to calculate (x^y)%p in O(log y) */
int power(long long x, unsigned int y, int p) 
{ 
    int res = 1;     // Initialize result 

    x = x % p; // Update x if it is more than or 
                // equal to p
 
    if (x == 0) return 0; // In case x is divisible by p;

    while (y > 0) 
    { 
        // If y is odd, multiply x with result 
        if (y & 1) 
            res = (res*x) % p; 

        // y must be even now 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 


}
int expo(int a,int b,int c)
{
    int res = 1;
    a = a%c;

    if(a == 0)
    return 0;

    while(b>0)
    {
        if(b&1)
        res = (res*a)%c;

        b = b>>1;
        a = (a*a)%c;
        
    }
    return res;
}

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    cout<<expo(a,b,c)<<endl;
    return 0;
}