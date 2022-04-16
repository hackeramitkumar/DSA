#include <bits/stdc++.h>
using namespace std;
#define ll long long int
bool isPossible(ll arr[], ll n, ll m, ll curr_hgt)
{
    ll sum = 0;
    for (ll i = 0; i < n; i++)
    {
        sum += max((ll)0, arr[i] - curr_hgt);
    }
    if (sum < m)
    {
        return false;
    }
    else
    {
        return true;
    }
}

ll maxHeight(ll arr[], ll n, ll m)
{
    ll max_hgt = 0;
    for (ll i = 0; i < n; i++)
    {
        max_hgt = max(max_hgt, arr[i]);
    }
    ll s = 0;
    ll e = max_hgt;
    ll ans = 0;
    while (s <= e)
    {
        ll mid = s + (e-s) / 2;
        if (isPossible(arr, n, m, mid))
        {
            ans = max(ans, mid);
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int main()
{
    ll n, m;
    cin >> n >> m;
    ll arr[n];
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << maxHeight(arr, n, m) << endl;

    return 0;
}