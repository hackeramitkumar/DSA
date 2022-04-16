#include<iostream>
#include "vector.h"

using namespace std;

void display(vector v)
{
    for(int i = 0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    putchar('\n');
}

int main(){
    vector v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
display(v);

    v.pop_back();
display(v);
    v.push_back(6);
    display(v);




}
