#include<bits/stdc++.h>
using namespace std;


bool checkPallindrome(char arr[])
{
    int i = 0,j= strlen(arr)-1;
    while(i<j)
    {
        if(arr[i] != arr[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}


int main()
{
    char arr[100];
    cin.getline(arr,1000);
    cout<<checkPallindrome(arr)<<endl;
    return 0;
}





