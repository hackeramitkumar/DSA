#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {10,20,40,40,44,46,50,60};
    int n = sizeof(a)/sizeof(int);
    int key;
    cin>>key;
    // int *ans = lower_bound(a,a+n,key);
    int *ans = upper_bound(a,a+n,key);

    int index = ans - a;
cout<<*ans<<endl;
cout<<"first occurance of key:  "<<index<<endl;

int *x = upper_bound(a,a+n,key);
cout<<"last occurance of the key: "<<x - a - 1<<endl;

cout<<"NUmber of occurances of key: "<<x-ans<<endl;

    return 0;
}