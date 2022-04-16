#include<bits/stdc++.h>
using namespace std;

class Heap{
    vector<int> v;
    bool minHeap;
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


    public:
    Heap(int default_size = 10,bool type = true){
        v.reserve(default_size);
        v.push_back(-1);
        minHeap = type;
    }

    // push a element at last and move this to its right poasition so that follow the heap order property
    void  push(int d){
        v.push_back(d);
        int idx = v.size() - 1;
        int parent = idx/2;

        //keep pushing to the top till you reach to the root node or stop midway beacause current eleemtns is always greater then its parent
        while(idx > 1 and compare(v[idx],v[parent]))
        {
            swap(v[idx] , v[parent]);
            idx = parent;
            parent = parent/2;
        }
    }

    bool empty(){
        return v.size() == 1;
    }
    int top(){
        return v[1];
    }

    void pop(){
        int last = v.size() - 1;
        swap(v[1],v[last]);
        v.pop_back();
        Heapify(1);
    }
};

int main()
{
    Heap h(10,false);
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)
    {
        int no;
        cin>>no;
        h.push(no);

    }
    while(!h.empty())
    {
        cout<<h.top()<<" ";
        h.pop();
    }


}