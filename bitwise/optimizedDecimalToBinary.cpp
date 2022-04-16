#include<bits/stdc++.h>
using namespace std;

void decimalToBinary(int n)
{int mask = 1<<30;
bool isOneFound = false;
vector<int> v;

while(mask != 0)
{
    if((((mask) &n) == 0) and isOneFound == false)
    {
        mask =mask>>1;
        continue;
    }
    else{
        isOneFound = true;
        if((mask & n)>0)
        {
            v.push_back(1);
        }else
        {
            // cout<<"0";
            v.push_back(0);

        }
        mask = mask>>1;
    }
    int l = v.size();
    for(int i = 0;i<l;i++)
    {
        cout<<v[i];
    }
    putchar('\n');
}
    cout<<endl;
    }




int main()
{
    int n;
    cin>>n;
    decimalToBinary(n);
    return n;
}