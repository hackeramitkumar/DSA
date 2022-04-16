#include <bits/stdc++.h>
using namespace std;

void solve(char *str, char *out, int i, int j)
{
    // base case

    if (str[i] == '\0')
    {
        out[j] = '\0';
        cout << out << endl;
        return;
    }

    // recursive case
        int digit1 = str[i] - '0';
        char ch = digit1 + 'A' -1;
        out[j] = ch;

    solve(str, out, i + 1, j + 1);

    if (str[i + 1] != '\0')
    {
        int digit2 = str[i + 1] - '0';
        int val = digit1 * 10 + digit2;

        if (val <= 26)
        {
            out[j] = val + 'A' - 1;
            solve(str, out, i + 2, j + 1);
        }
    }
    return;
}
int main()
{
    char str[100];
    cin >> str;
    char out[100];
    solve(str, out, 0, 0);
}