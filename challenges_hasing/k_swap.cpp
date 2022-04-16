#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int k;
    cin >> n >> k;
    int arr[n];
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        m[arr[i]] = i;
    }
    int i = 0;
    while (k > 0 and i< n)
    {

        if (arr[i] == n-i)
        {
            continue;
        }

        int index = m[n-i];
        m[arr[i]] = index;
        m[n-i] = i;
            swap(arr[index], arr[i]);
            k--;
        
        i++;
    }
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
/*
#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin >> n >> k;
    vector<int> v;
    unordered_map<int,int> m ;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        v.push_back(x);
        m[v[i]] = i ;
    }
    for(int i=0;i<n && k>0;i++){
        int x = n - i;
        if(v[i] == x){
            //Already correct element
            continue;
        }
        int index = m[x];
        m[v[i]] = index ;
        m[x] = i;
        swap(v[i],v[index]);
        k--;
    }
    for(int i=0;i<n;i++){
        cout << v[i] << " ";
    }

    return 0;
}
*/