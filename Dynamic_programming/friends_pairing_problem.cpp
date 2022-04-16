#include <bits/stdc++.h>
using namespace std;

// top down
int solve(int n, int dp[])
{
    if (n == 0 || n == 1)
    {
        return 1;
    }

    if (dp[n] != -1)
    {
        return dp[n];
    }

    // rec case
    int ans = solve(n - 1, dp) + (n - 1) * solve(n - 2, dp);
    return dp[n] = ans;
}

// Bottom Up
int solve_BU(int n)
{
    int dp[n + 1];

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int dp[10000];
    memset(dp, -1, sizeof dp);
    cout << solve(n, dp) << endl;
    cout << solve_BU(n) << endl;
}