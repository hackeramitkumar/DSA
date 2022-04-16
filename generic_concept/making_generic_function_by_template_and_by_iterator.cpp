#include<bits/stdc++.h>
using namespace std;

// generic function by using template
template<typename T>
int search(T arr[],int n, T key)
{
    for(int i = 0;i<n;i++)
    {
        if(arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

//generic function by using iterators + templates 
template<class ForwardIterator ,class T>
ForwardIterator search_by_iterator(ForwardIterator start,ForwardIterator end,T key)
{
    while(start != end)
    {
        if(*start == key)
        {
            return start;
        }
        start++;
    }
    return end;
}

int main(){

    float arr[] = {1.1,5.4,8.6,4.9,3};
    int n = sizeof(arr)/sizeof(int);
    // cout<<search(arr,n,key)<<endl;



    //for iterator generic function
    vector<string> s;
    s.push_back("Amit");
    s.push_back("Poonam");
    s.push_back("Sarvesh");
    s.push_back("ashish");
    s.push_back("devendra");
    s.push_back("mahi");

    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(8);
    v.push_back(4);
    v.push_back(6);
    v.push_back(45);


int key;
cin>>key;

    auto it = search_by_iterator(v.begin(),v.end(),key);
    cout<<key<<" in the array is present at the index: "<<*it<<endl;




}