#include<bits/stdc++.h>
using namespace std;

int* func()
{
// so for making our task succesful we have to make a dynamic array

    // int a[]={1,2,3,4,5};
    int *a = new int[5];
    for(int i = 0;i<5;i++)
    {
        a[i] = i+1;
    }
    cout<<a<<endl;
    cout<<a[0]<<endl;

// we should never return a local variable
    return a;

}

int main()
{
    int *b = func();
    cout<<b<<endl;
    cout<<b[0]<<endl;

    return 0;

}