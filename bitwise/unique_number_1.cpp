#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {8, 9 , 6 ,6,9,8,8,9,6,5};
    int n = sizeof(arr)/sizeof(int);

// create a cnt array hash that will store the sum of all bits at that index 
    int cnt[64] = {0};
    for(int i = 0;i<n;i++)
    {
        // this variable will maintam the position of the bits for hashing
        int pos = 0;
        //store the bits for a number no
        int no = arr[i];
        while(no>0)
        {
            if((no&1)==1)
            {
                cnt[pos]++;
            }
            no = no >> 1;
            pos++;
        }
    }
// calculate the ans by the cnt array by cnverting this array into a binary number
      int ans = 0;
      int p = 1;
    for(int i = 0;i<64;i++)
    {
        cnt[i] = cnt[i]%3;
        ans += (cnt[i])*p;
        p = p*2;
    }
    cout<<ans<<endl;
    return 0;
}