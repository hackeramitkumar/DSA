#include<bits/stdc++.h>
using namespace std;

int clear_range(int n,int j,int i){
    int mask = (~0)<<j;
    mask = mask | (1<<i - 1);
     n = n & mask;
     return n;
}

int update_n_by_m(int n, int j,int i,int m){
    n = clear_range(n,j,i);
    int mask = m<<(i-1);
    n = n | mask;
    return n;
}

int main(){
    int n,j,i,m;
    cin>>n>>j>>i>>m;
    cout<<update_n_by_m(n,j,i,m);

}