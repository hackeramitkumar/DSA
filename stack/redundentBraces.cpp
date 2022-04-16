#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        bool ans = false;
        string s;
        cin >> s;
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
            {
                st.push(s[i]);
            }
            else if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else if (s[i] == ')')
            {
                if (st.top() == '(')
                {
                    ans = true;
                    break;
                }
                while (!st.empty() && ( st.top() == '+' || st.top() == '-' || st.top() == '*' || st.top() == '/'))
                {
                    st.pop();
                }
                if(!st.empty())
                st.pop();
            }
        }

        if (ans)
        {
            cout << "Duplicate" << endl;
        }
        else
        {
            cout << "Not Duplicate" << endl;
        }
    }
    return 0;
}