#include <bits/stdc++.h>
using namespace std;


// there will be two possibility that element is present in part 1 or part 2
// for doing this task we will compare our mid point with starting element by doing this i will enter in the correspoing part of the array
// then i will check that the key iss present between starting and mid or later for first part
// and between the mid the last for the second part


int find(int *a, int n, int key)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = e - (s + e) / 2;

        if (a[mid] == key)
        {
            return mid;
        }
        else if (a[s] <= a[mid])
        {
            // 2 cases -> if key is present before the mid or after the mid
            if (a[mid] >= key and a[s] <= key)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        else
        {
            // 2 cases -> if key is present before the mid or after the mid

            if (a[mid] <= key and a[e] >= key)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cin >> key;
    cout << "The key is present at the index: " << find(arr, n, key) << endl;
    return 0;
}