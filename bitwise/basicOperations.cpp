#include<bits/stdc++.h>
using namespace std;
//check evenodd
bool isOdd(int n)
{
    int lsb = (n&1)==0?0:1;
    return lsb;
}
bool checkbit(int n,int i)
{
    int mask = 1<<i;
    n = n&(mask);
    if( (n & (mask))>0)
    {
    return true;
    }
    else
    {
    return false;
    }
}

void setithBit(int &n,int i)
{
    int mask = 1<<i;
    n = n|(mask);   
}

//clear i bits
void clearBits(int &n,int i)
{
    int mask = (~0);
    mask = mask<<i;
    n = n&(mask);
}

// void clearrange
void clearRange(int &n,int i,int j)
{
    int mask_a = (~0);
    mask_a = mask_a<<j;
    int mask_b = (1<<i)-1;
    int mask = (mask_a) | (mask_b);
    n = n& (mask);
}

int countSetBits(int n)
{
    int ans = 0;
    while(n>0)
    {
        if(n&1 >0)
        {
            ans++;
            n = n>>1;
        }
        else
        {
            n = n>>1;
        }
    }
    return ans;
}

//update the bits in n by m

void updateNByM(int &n,int m,int i,int j)
{
    //1. update m
    m = m<<(i-1);
    // 2. update and clear the range of n int (j to i-1)
    clearRange(n,i-1,j);
    //3.update the value of n 
    n = n|m;
}

int main()
{
    int n;
    cin>>n;
    if(isOdd(n))
    {
        cout<<n<<" is : ODD"<<endl;
    }
    else
    {
        cout<<n<<" is : EVEN"<<endl;
    }
    if(checkbit(n,2))
    {
        cout<<"2nd bit is: "<<"1"<<endl;
    }else{
        cout<<"2nd bit is: "<<"0"<<endl;
    }

    setithBit(n,3);
    cout<<"Setting the ith bit: "<< n<<endl;
    cout<<"Number of set bits in "<<n<<" are: "<<countSetBits(n)<<endl;

    n = 15;
    clearRange(n,1,3);
    // clear ranges of number
    cout<<"number after bit clear : "<<n<<endl;
n = 16;
    //update n by m;
    updateNByM(n,3,2,3);
    cout<<"newValue: "<<n<<endl;


}