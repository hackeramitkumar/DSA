/*#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> node;

vector<int> mergeKSortedArrays(vector<vector<int>> arr)
{

    vector<int> result;
    priority_queue<node, vector<node>, greater<node>> pq; // min  priority queue

    // insert the 0th element of the every array in the pq
    for (int i = 0; i < arr.size(); i++)
    {
        pq.push({arr[i][0], {i, 0}});
    }
    // remove the elements one by from the min heap and add to result vector
    while (!pq.empty())
    {
        node current = pq.top();
        pq.pop();
        int element = current.first;
        int x = current.second.first;  // row in which element is present
        int y = current.second.second; // col in which element is present

        result.push_back(element);

        // you nedd to push the next element of current element x,y+1
        if (y + 1 < arr[x].size())
        {
            pq.push({arr[x][y + 1], {x, y + 1}});
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> v{
        {1, 8, 9, 15},
        {5, 45, 90, 99},
        {1, 3, 5, 11}};

    vector<int> output = mergeKSortedArrays(v);
    for (int i = 0; i < output.size(); i++)
    {

        cout << output[i] << " ";
    }
    putchar('\n');
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> node;

vector<int> mergeKSortedArrays(vector<vector<int>> arr)
{

    vector<int> result;
    priority_queue<node, vector<node>, greater<node>> pq; // min  priority queue

    // insert the 0th element of the every array in the pq
    for (int i = 0; i < arr.size(); i++)
    {
        pq.push({arr[i][0], {i, 0}});
    }
    // remove the elements one by from the min heap and add to result vector
    while (!pq.empty())
    {
        node current = pq.top();
        pq.pop();
        int element = current.first;
        int x = current.second.first;  // row in which element is present
        int y = current.second.second; // col in which element is present

        result.push_back(element);

        // you nedd to push the next element of current element x,y+1
        if (y + 1 < arr[x].size())
        {
            pq.push({arr[x][y + 1], {x, y + 1}});
        }
    }
    return result;
}

int main()
{
	int n,m;
	cin>>n>>m;

    vector<vector<int> > v(n);
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<m;j++)
		{
			int no;
			cin>>no;
			v[i].push_back(no);
		}
	}

 vector<int> output = mergeKSortedArrays(v);
    for (int i = 0; i < output.size(); i++)
    {

        cout << output[i] << " ";
    }

    putchar('\n');
    return 0;
}