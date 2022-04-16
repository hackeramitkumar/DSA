#include <bits/stdc++.h>
using namespace std;

// TOP DOWN
int minSteps_TD(int n, int *dp)
{
    if (n == 1){
        return 0;
    }

    // look up
    if (dp[n] != 0)
    {
        return dp[n];
    }
    
    // rec case
    int op1, op2, op3;
    op1 = op2 = op3 = INT_MAX;
    if (n % 3 == 0)
    {
        op1 = minSteps_TD(n / 3, dp) + 1;
    }
    if (n % 2 == 0)
    {
        op2 = minSteps_TD(n / 2, dp) + 1;
    }

    op3 = minSteps_TD(n - 1, dp) + 1;

    int ans = min(op1, min(op2, op3));
    return dp[n] = ans;

}


// BOTTOM--UP
int minSteps_BU(int n)
{
    int dp[n + 1] = {0};
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int op1, op2, op3;
        op1 = op2= op3 = INT_MAX;
        if (i % 3 == 0)
        {
            op1 = dp[i / 3];
        }
        if (i % 2 == 0)
        {
            op2 = dp[i / 2];
        }
        op3 = dp[i - 1];
        dp[i] = min(op3, min(op1, op2)) + 1;
    }
    return dp[n];
}

int main()
{
    int n;
    cin >> n;
    int dp[100] = {0};
    cout << minSteps_TD(n, dp) << endl;
    cout << minSteps_BU(n) << endl;
}