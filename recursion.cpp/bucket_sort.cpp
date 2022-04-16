#include<bits/stdc++.h>
using namespace std;

class Student {
    public:
    int marks;
    string name;
};

void sort(Student s[],int n){
    vector<Student> v[101];
    for(int i = 0;i<n;i++)
    {
        int m = s[i].marks;
        v[m].push_back(s[i]);
    }

    for(int i = 100;i>=0;i--)
    {
        for(vector<Student>::iterator it = v[i].begin(); it != v[i].end();it++){
            cout<<(*it).marks<<" "<<(*it).name<<endl;
        }

    }

}

void bubble_sort(int *arr,int n,int i){
    if(i == n-1)
    {
        return;
    }
    for(int j = 0;j<n-1-i;j++)
    {
        if(arr[j]>arr[j+1])
        {
            swap(arr[j],arr[j+1]);
        }
    }
    bubble_sort(arr,n,i+1);

}


int main()
{
    int n;
    Student s[100000];

     cin>>n;
    for(int i = 0;i<n;i++ )
    {
        cin>>s[i].name>>s[i].marks;
    }
    sort(s,n);
    return 0;
}