#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int k;
    cin>>n>>k;
    int occ;
int ans = 0;
    for(int i = 2;i*i <= k;i++){

        if(k%i == 0){
            occ = 0;
            while(k%i == 0){
                occ++;
                k = k/i;
            }

          int  p = i;
          int cnt = 0;
            while(p <= i){
                cnt  += n/p;
                p = p*i;
               
            }
            ans = min(ans , cnt / occ); 
        }
    }
    if(k > 1){
    int cnt = 0;
    int p = k;
    while(p<=n){
        cnt += n/p;
        p = p*k;

    }
    ans = min(ans,cnt);

    }

    if(ans == INT_MAX){
        ans = 0;
    }

    cout<<ans;

    
}