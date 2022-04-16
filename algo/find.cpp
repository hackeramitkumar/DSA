#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {1,2,3,4,5,6};
    int n = sizeof(a)/sizeof(int);
    int key;
    cin>>key;
    int *ans = find(a,a+n,key);
    int index = ans - a;

if(index == n)
{
    cout<<"element is not present"<<endl;
}else{
    cout<<"element is present "<<index<<endl;
}

    return 0;
}