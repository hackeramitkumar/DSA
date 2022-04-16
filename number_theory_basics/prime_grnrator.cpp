#include<bits/stdc++.h>
using namespace std;
const int N =100000; // choose accordingly the problem
vector<int> primes;
int p[N] = {0};
void sieve()
{
    for(int i =2;i<=N;i++)
    {
        if(p[i]==0){
            // store the i 
            primes.push_back(i);
            // mark all multiples of i as not prime
            for(int j = i;j <= N;j += i)
            {
                p[j] = 1; //not prime
            }
        }
    }


}

int main()
{
    sieve(); //build this sieve once for all
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>m>>n;

        bool segment[n-m+1];
        for(int i = 0;i < n-m+1;i++){
            segment[i] = 0;
        }

        // here segmented sieve logic
        for(auto x: primes)
        {

            // stop the loop if remaining primes are not needed
            if(x*x >n){
                break;
            }

            // the start is the multiple of x closet to m
            int start = (m/x)*x;

            //prime no lies in the segment sieve range
            // let suppose is our sqrt(n) is 10
            // and segment is ( 5 to 100)
            // so when we will have x grater than m then we will get starting point 
            // as zero so for avoiding  that case we will check firstly and is x is grater tha x then start will be atleast 2*x
            if(x >= m and x <= n) {
                start = x*2;
            }

            //mark all multiple of x in the range start to n as not primes
            for(int i = start;i<=n;i += x) {
                segment[i-m] = 1; // beacuse we have taken 1 for not prime
            }
        }


        //Loop over range m..n and print the primes
        for(int i = m;i<=n;i++)
        {
            if(segment[i-m] == 0 and i!= 1)
            {
                cout<<i<<endl;
            }
        }
        cout<<endl;
    }
    return 0;
}