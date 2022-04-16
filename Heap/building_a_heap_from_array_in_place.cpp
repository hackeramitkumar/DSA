#include<bits/stdc++.h>
using namespace std;

void print(vector<int> &v)
{
    for(int i = 1;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }

}

void buildHeap(vector<int> &v){
    for(int i = 2;i<v.size();i++)
    {
        int idx = i;
        int parent = i/2;
        while(idx > 1 and v[idx] > v[parent]){
            swap(v[idx] ,v[parent]);
                idx = parent;
                parent = parent/2;
        }

    }
}

// ...................optimized .............

bool minHeap = false;
 bool compare(int a,int b)
    {
        if(minHeap){
            return a<b;
        }
        return a>b;
    }
 void Heapify(int idx){
        int left = 2*idx;
        int right = 2*idx + 1;
        int min_idx = idx;
        int last = v.size() - 1;
        if(left <= last and compare(v[left] , v[idx])){
            min_idx = left;
        }
        if(right <= last and compare(v[right] , v[min_idx])){
            min_idx = right;
        }
        if(min_idx != idx){
            swap(v[idx],v[min_idx]);
        }

    }
   

int main()
{
    vector<int> v;
    v.push_back(-1);
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        int x;
        cin>>x;
        v.push_back(x);
    }
    print(v);
putchar('\n');
    buildHeap(v);
    print(v);
putchar('\n');


    
    

}