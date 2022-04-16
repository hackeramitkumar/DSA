#include <bits/stdc++.h>
using namespace std;

bool compare(int a,int b)
{
    cout<<a<<" "<<b<<endl;
    
    return a<=b;
}


int main()
{
    int arr[] = {1, 2, 5,8, 25, 50, 100};
    int n = sizeof(arr) / sizeof(int);

    int money;
    cin >> money;
    while (money > 0)
    {
        //doubt in this problem how this compare is working

        int index = lower_bound(arr,arr+n,money,compare)- arr-1;
        cout<<"Coins are: "<<arr[index]<<endl;
        money -= arr[index];

    }
    return 0;
}





/*

int main()
{
    int arr[] = {1, 2, 5, 25, 50, 100};
    int n = sizeof(arr) / sizeof(int);

    int money;
    cin >> money;
    int cnt = 0;
    while (money > 0)
    {

        int *add = lower_bound(arr, arr + n, money);
        int index = add - arr;
        int *coin;
        if (index == n)
        {
            coin = add - 1;
        }
        else if (arr[index] > money)
        {
            coin = add - 1;
        }
        else
        {
            coin = add;
        }
        cout << *coin << endl;
        money = money - *coin;
        cnt++;
    }
    cout << cnt << endl;
}

*/