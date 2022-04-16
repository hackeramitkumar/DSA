/*#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> leftHeap;
    priority_queue<int, vector<int>, greater<int>> rightHeap;

    int d;
    cin >> d;
    leftHeap.push(d);
    float med = d;
    cout << "median " << med << endl;
    cin >> d;

    // input all elements
    while (d != -1)
    {
        // logic
        if (leftHeap.size() > rightHeap.size())
        {
            if (d < med)
            {
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(d);
            }
            else
            {
                rightHeap.push(d);
            }
            med = (leftHeap.top() + rightHeap.top()) / 2.0;
        }
        else if (leftHeap.size() == rightHeap.size())
        {
            if (d < med)
            {
                leftHeap.push(d);
                med = leftHeap.top();
            }
            else
            {
                rightHeap.push(d);
                med = rightHeap.top();
            }
        }
        else
        {
            if (d > med)
            {
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(d);
            }
            else
            {
                leftHeap.push(d);
            }
            med = (leftHeap.top() + rightHeap.top()) / 2.0;
        }
        cout << "median " << med << endl;
        cin >> d;
    }
    return 0;
}

*/




#include <bits/stdc++.h>
using namespace std;

vector<int> median(vector<int> v){
    priority_queue<int> leftHeap;
    priority_queue<int, vector<int>, greater<int>> rightHeap;
   vector<int> result;
    leftHeap.push(v[0]);
    float med = v[0];
    result.push_back(med);
    

    // input all elements
    for(int i = 1;i<v.size();i++){
        int d = v[i];
        // logic
        if (leftHeap.size() > rightHeap.size())
        {
            if (d < med)
            {
                rightHeap.push(leftHeap.top());
                leftHeap.pop();
                leftHeap.push(d);
            }
            else
            {
                rightHeap.push(d);
            }
            med = (leftHeap.top() + rightHeap.top()) / 2.0;
        }
        else if (leftHeap.size() == rightHeap.size())
        {
            if (d < med)
            {
                leftHeap.push(d);
                med = leftHeap.top();
            
            }
            else
            {
                rightHeap.push(d);
                med =rightHeap.top();
            }
        }
        else
        {
            if (d > med)
            {
                leftHeap.push(rightHeap.top());
                rightHeap.pop();
                rightHeap.push(d);
            }
            else
            {
                leftHeap.push(d);
            }
            med = (leftHeap.top() + rightHeap.top()) / 2.0;
        }
        result.push_back(med);
}
return result;

}

int main()
{
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<int> v;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }

    vector<int> medianV= median(v);
    for(int i = 0;i<medianV.size();i++)
    {
        cout<<medianV[i] <<" ";
    }
    }
    return 0;
}