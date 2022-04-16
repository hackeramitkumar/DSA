#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//this will make the class genral that may be used for every type of data type;
template<typename T>
class Stack{
    private:
    vector<T> v;
    public:


    void push(T data){
        v.push_back(data);
    }

    bool empty(){
        return v.size() == 0;

    }

    void pop(){
        if(!empty()){
            return v.pop_back();
        }
    }

    T top() {
        return v[v.size() - 1];
    }
};

int main(){

    Stack<string> s;
    for(int i = 0;i<5;i++){
        string str;
        cin>>str;
        s.push(str);
    }

    cout<<s.top()<<" ";
    s.pop();
    cout<<s.top()<<" ";
    s.pop();




}