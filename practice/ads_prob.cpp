#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    bool isOne = false;
    vector<int> v;
    for(int i = 30; i>=0;i--){
        int mask = 1<<i ;
        int bit = n&mask;
        if(bit != 0){
            isOne = true;
        }
        if(isOne){
           int   rev_bit = (bit != 0)? 0:1;
        //    cout<<rev_bit;
            v.push_back(rev_bit);
        }
    }
    int ans = 0;
    int pro = 1;
    for(int i = v.size() - 1;i>=0;i-- ){
        ans += v[i]*pro;
        pro *= 2;
        // cout<<v[i];
    }

    cout<<ans;

}