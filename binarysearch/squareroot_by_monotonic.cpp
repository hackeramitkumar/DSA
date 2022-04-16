#include<bits/stdc++.h>
using namespace std;

double sqrt(int n,int p){

double s = 1;
double e = n;
double ans = 0;
while(s<=e){
    double mid = (s+e) / 2;
    if(mid*mid == n){
        ans = mid;
        break;
    }else if(mid*mid < n){
         s = mid+1;
    }else{
        e = mid - 1;
    }


}


    // brute force 
    // floating part
double inc = 0.1;
for(int i= 0;i<= p;i++){

    while(ans*ans <= n){
        ans = ans + inc;
    }

    // overshot the value;
    ans = ans - inc;
    inc = inc/10;
}
return ans;

}





int main(){
    int n;
    cin>>n;

    cout<<sqrt(n,4)<<endl;

}