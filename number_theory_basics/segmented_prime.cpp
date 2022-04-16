#include<bits/stdc++.h>
using namespace std;

const int N =  100000;
int p[N] = {0};
vector<int> primes;

void sieve(){
    p[0] = p[1] = 1;
    for(int i = 2;i< N;i++){
        if(p[i] == 0){
            primes.push_back(i);
            for(int j = i*i;j<N;j += i){
                p[j] = 1;
            }
        }
    }
}


int main(){

    sieve();

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>m>>n;

        bool segment[n-m+1];
        for(int i = 0;i< n-m+1;i++){
            segment[i] = 0;
        }
        // here segment sieve logic

        for(auto x : primes) {
            // stop the loop if remaining primes numbers are not needed
            if(x*x > n){
                break;
            }
            int start = (m/x)*x;

// prime no lies in the segment sieve range
if(x >= m and x <= n){
    start = x * 2;
}

            // mark all multiples of x in the range start 
            for(int i = start; i<= n; i+= x){
                segment[i-m] = 1;
            }
        }

        for(int i = m;i<=n;i++){
            if(segment[i-m] == 0 and i != 1){
                cout<<i<<endl;
            }
        }
    }
    
}