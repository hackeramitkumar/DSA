#include<bits/stdc++.h>
using namespace std;

void towerOfHanoi(char src,char dest,char helper,int n){
    if(n==0){
        return ;
    }

    towerOfHanoi(src,helper,dest,n-1);
    cout<<"move tne "<<n<<"th disk from "<<src<<" to "<<dest<<endl;
    towerOfHanoi(helper,dest,src,n-1);




}
int main(){
    int n;
    cin>>n;
    towerOfHanoi('A','B','C',n);
}