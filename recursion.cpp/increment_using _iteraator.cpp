#include<bits/stdc++.h>
using namespace std;

void print(int n,int i)
{
    if(i==n+1)
    return ;

    cout<<i<<" ";
    print(n,i+1);
}

int main()
{
    int n;
    cin>>n;
    print(n,1);
    return 0;

}