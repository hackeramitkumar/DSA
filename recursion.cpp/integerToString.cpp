#include<bits/stdc++.h>
using namespace std;

string a[] = { "zero","one","two","three","four","five","six","seven","eight","nine"};

void integerToString(int n)
{
    if(n==0)
    return ;

    int digit = n%10;
    // cout<<a[digit]<<" ";

    integerToString(n/10);
    // fro correct order 
    cout<<a[digit]<<" ";


}

int main()
{
    int n;
    cin>>n;
    integerToString(n);
    return 0;
}