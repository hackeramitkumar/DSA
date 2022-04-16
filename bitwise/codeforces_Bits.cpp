#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int msb(ll n){
    int pos = 0;
    for(int i = 63;i>=0;i--){
            int bit = (n>>i)&1;
            if(bit){
                pos = i;
                break;
            }
        }
        return pos;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll l,r;
        cin>>l>>r;
        int msb_r = msb(r);
        int msb_l = msb(l);
        // cout<<msb(r)<<" "<<msb(l)<<endl;
        
        ll ans = 0;

        if(msb_l < msb_r){
            ans = (1<<msb_r)-1;
        }
        else{
            while(msb(r) == msb(l)){
                ans += 1<<msb(r);
                r -= 1<<msb(r);
                l -= 1<<msb(l);
            }
            ans = ans +( 1<<msb(r)) - 1;
        }

        cout<<ans<<endl;
    }
    return 0;

}