#include<bits/stdc++.h>
using namespace std;


//update the bit by  A Given v

void update(int &n,int i,int v)
{
    int mask = 1<<i;
    n = (n&(~mask));
    n=(n|(v<<i));
}




// this will clear the ith bit
//in the function n is taken by refrence
void clearBit(int &n,int i)
{
    int mask = 1<<i;
    mask = (~mask);
    n = (n&mask);
    
}

int main(){
    int n,i;
    cin>>n>>i;
    // clearBit(n,i);
    update(n,i,1);
    cout<<n<<endl;
}