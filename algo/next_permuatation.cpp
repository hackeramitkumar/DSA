#include <bits/stdc++.h>
using namespace std;



int main()
{
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(int);

    //np(arr,arr+n); -> 1,3,2
    do{
        for(int i = 0;i<n;++i)
        {
            cout<<arr[i]<<" ";
        }
        putchar('\n');
    }while(next_permutation(arr,arr+n)==true);
    


    
    return 0;
}




