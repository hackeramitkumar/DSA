#include<bits/stdc++.h>
using namespace std;

void solve(char *str,char *out,int i,int j)
{
    //base case



    //rec case
    solve(str,out,i+1,j);

    out[j] = str[i];
    solve(str,out,i+1,j+1);

}
int main()
{

}