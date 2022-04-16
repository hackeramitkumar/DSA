#include<bits/stdc++.h>
using namespace std;

int fib(int n)
{
    //base case
    if(n==0 || n==1)
    {
        return n;
    }

    //recursive case
    // fib(n) = fib(n-2)+fib(n-1)
    // int smallAns1 =fib(n-1);
    // int smallAns2 = fib(n-2);

// find the solution
// int biggerAns = smallAns1 + smallAns2;
    // return biggerAns;
    return fib(n-1) + fib(n-2);

}
int main()
{
    int n;
    cin>>n;
    cout<<fib(n)<<endl;
}