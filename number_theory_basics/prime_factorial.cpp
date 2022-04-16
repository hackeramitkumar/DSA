#include <bits/stdc++.h>
using namespace std;

 #define INT__MAX 10000000

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int acc = 0;

        int ans = INT__MAX;
        for (int i = 2; i * i <= k; i++)
        {
            if (k % i == 0)
            {
                acc = 0;
                while (k % i == 0)
                {
                    acc++;
                    k = k / i;
                }
                // find out the power of i in n! side by side
                int cnt = 0;
                long long p = i;
                while (p <= n)
                {
                    cnt += n / p;
                    p = p * i;
                }
                ans = min(ans, cnt / acc);
            }

        }

            // we may have a case that prime factor is left
            if (k > 1)
            {
                int cnt = 0;
                long long p = k;
                while (p <= n)
                {
                    cnt += n / p;
                    p = p*k;
                }
                ans = min(ans, cnt);
            }
        
        if (ans == INT__MAX)
        {
            ans = 0;
        }
        
        cout << ans << endl;
    }
    return 0;
}