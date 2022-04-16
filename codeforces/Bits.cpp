#include <bits/stdc++.h>
using namespace std;
#define ll long long int

ll solve(ll l, ll r)
{
    if (l == r)
        return l;

    ll num = 1;

    while (num * 2 <= r)
    {
        num = 2 * num;
    }

        if (num <= l)
        {
            return solve(l - num, r - num) + num;
        }
        else if (2 * num - 1 == r)
        {
            return 2 * num - 1;
        }
        else
        {
            return num - 1;
        }
}
    int main()
    {
        int t;
        cin >> t;
        while (t--)
        {
            ll l, r;
            cin >> l >> r;
            ll ans = solve(l, r);
            cout << ans << endl;
        }
        return 0;
    }