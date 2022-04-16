#include <bits/stdc++.h>
using namespace std;


int firstOccurance(int *arr, int n, int key)
{
    // base case
    if (n == 0)
        return -1;

    if (arr[0] == key)
    {
        return 0;
    }

    int i = firstOccurance(arr + 1, n - 1, key);
    if (i == -1)
    {
        return -1;
    }
    return i + 1;
}

//iterative approach
int firstOccurance_ite(int *arr,int n,int i,int key){
    //base case
    if(i == n){
        return -1;
    }
    if(arr[i] == key){
        return i;
    }
    return firstOccurance_ite(arr,n,i+1,key);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int key;
        cin >> key;

        cout << "First occurance of the key is"
             << ": " << firstOccurance_ite(arr, n,0, key) << endl;
    }
    return 0;
}