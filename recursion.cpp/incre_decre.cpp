#include<bits/stdc++.h>
using namespace std;


//in this problem firstly we are printing the values then function call is taking place
//so we are printing the values in decreasing order


void printDec(int n)
{
    //base case
    if(n==0)
    return ;

    //solution of the case
    cout<<n;
    printDec(n-1);
}

// is problem mai print karne se pahle hi function call kar raha isiliye jab tak ham base
//  case the na pahunch jaye tab tak vo print vali line tak nahi ja payega
//jaise hi vo base case se return ho gaya to uske bad vale jo bhi code bache huye the har ek call mai vo ho jayega
void printInc(int n)
{
    //base case
    if(n==0)
    return ;

//solution
    printInc(n-1);
    cout<<n<<" ";
}
int main()
{
    int n;
    cin>>n;
    printDec(n);
    putchar('\n');

    printInc(n);
    putchar('\n');

    return 0;
}