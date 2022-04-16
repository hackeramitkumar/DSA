#include<bits/stdc++.h>
using namespace std;



/*
void uniqueNumber2(int arr[] ,int n)
{
    int ans = 0;
    for(int i = 0;i<n;i++)
    {
        ans ^= arr[i];
    }
    int x = 1;
    while(ans&x == 0)
    {
        x = x<<1;
    }
    int val1=0,val2=0;
    for(int i = 0;i<n;i++)
    {
        if((arr[i] & x) ==0)
        {
            val1 = val1^arr[i];
        }else
        {
            val2 = val2^arr[i];
        }
    }
    cout<<val1<<" "<<val2<<endl;
    
}
*/
void unique2Number(int arr[] , int n)
{
    int ans = 0;
    for(int i = 0;i<n;i++)
    {
        ans ^= arr[i];
    }

    int result = ans; // a^b
    //extract the bit position with value 1 ,that would mean in both the numbers

    int pos = 0;
    while(ans>0)
    {
        if((ans &1)>0)
        {
            break;
        }
        pos++;
        ans = ans >> 1;
    }

    //we need to start the serparation the numbers according to the bit positions
    int x = 1 << pos;
    int uni1 = 0;
    for(int i =0;i<n;i++)
    {
        if( ((arr[i])&x)== 0)
        {
            uni1 ^= arr[i];
        }
    }

    int uni2 = result ^ uni1;
    cout<<uni1<<" "<<uni2;
}


int main()
{
    /*
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
    }
    */
   int arr[] = {6, 1, 6, 1, 3, 5};
   int n = sizeof(arr)/sizeof(int);




     int ans = 0;
    for(int i = 0;i<n;i++)
    {
        ans ^= arr[i];
    }

    int result = ans; // a^b
    //extract the bit position with value 1 ,that would mean in both the numbers

    int pos = 0;
    while(ans > 0)
    {
        if((ans & 1)>0)
        {
            break;
        }
        pos++;
        ans = ans >> 1;
    }

    //we need to start the serparation the numbers according to the bit positions
    int x = 1 << pos;
    cout<<x<<endl;

    int uni1 = 0;
    for(int i =0;i<n;i++)
    {
        if((arr[i] & x)== 0)
        {

            uni1 ^= arr[i];
        }
    }

    int uni2 = result ^ uni1;
    cout<<uni1<<" "<<uni2<<endl;
    unique2Number(arr,n);
    return 0; 

}