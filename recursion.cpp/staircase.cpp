#include<bits/stdc++.h>
using namespace std;


int totalStep(int n,int k){
    if(n==0)
    return 1;

    if(n<0)
    {
        return 0;
    }

    return totalStep(n-1,k) +totalStep(n-2,k)+totalStep(n-3,k);


}


int main()
{
    int n;
    int k;
    cin>>n>>k;

    cout<<totalStep(n,k);
return 0;
}