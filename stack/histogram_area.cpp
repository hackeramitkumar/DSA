#include <bits/stdc++.h>
using namespace std;

int HistogramArea(int bars[], int n)
{
    stack<int> s;
    int max_area = 0;
    int top_val;
    int area_with_top;
    int i=0;
    while(i<n)
    {
        if (s.empty() || (bars[s.top()]<=bars[i]))
        {
            s.push(i++);
        }
        else
        {
            top_val = s.top();
            s.pop();
        area_with_top = bars[top_val] * (s.empty() ? i : i - s.top() - 1);

            max_area = max(max_area, area_with_top);
        }
    }

    // now pop the remaining bars from the stack and calculate area with every popped bar as the smallest bar
    while (!s.empty())
    {
        top_val = s.top();
        s.pop();
        area_with_top = bars[top_val] * (s.empty() ? i : i - s.top() - 1);
        max_area = max(max_area, area_with_top);
    }
    return max_area;
}
int main()
{
    int n;
    cin >> n;
    int bars[100000];
    for (int i = 0; i < n; i++)
    {
        cin >> bars[i];
    }
    cout << HistogramArea(bars, n) << endl;
}