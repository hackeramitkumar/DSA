#include<bits/stdc++.h>
using namespace std;

void printFactors(int n)
{
    vector<pair<int,int> > factors;
    int cnt;

    for(int i = 2; i*i <= n;i++)
    {
        if(n%i == 0)
        {
            // keep on deviding it by i till it is divisible 
            cnt = 0;
            while(n%i == 0)
            {
                cnt++;
                n = n/i;
            }
            factors.push_back(make_pair(i,cnt));
        }
    }
    if( n != 1)
    {
        // what ever is left is prime fector itself
        factors.push_back(make_pair(n,1));
    }

    // print the factors
    for(auto p: factors)
    {
        cout<<p.first<<"^"<<p.second<<endl;
    }

}

int main()
{
    int n;
    cin>>n;
    printFactors(n);
    return 0;

}