#include<bits/stdc++.h>
using namespace std;

int fact(int n)
{
    // 1. Base case
    if(n == 0)
    {
        return 1;
    }
    // 2. recurance relation/recursive case
    // n! = n*(n-1)!
    // fact(n) = n*fact(n-1)
    int samllerAns = fact(n-1);

    //3. Find the solution
    // int boggerAns = n * samllerAns;
    // return boggerAns;

    return n*fact(n-1);

}
int main()
{
    int n;
    cin>>n;
    cout<<fact(n)<<endl;

}