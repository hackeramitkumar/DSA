#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    //static allocation
    int a[n];
    cout<<sizeof(a)<<endl;



    //dynamic allocation
    int *b = new int[n];
    cout<<sizeof(b)<<endl;

// no change in this part
    for(int i = 0;i<n;i++)
    {
        /*
        cin>>a[i];
        cout<<a[i]<<" ";
        */

        cin>>b[i];
        // cout<<b[i]<<endl;
    }
    cout<<b[2]<<endl;

    delete [] b;

    cout<<b[2]<<endl;





}