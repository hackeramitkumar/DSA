#include<bits/stdc++.h>
using namespace std;

class Fun{
    public:
    void operator()(string s){
        cout<<"Having fun with "<<s;
    }
};

class Person{
    public:
    string name;
    int age;

    Person(){

    }
    Person(string n,int a){
        name = n;
        age = a;

    }
};

// this class must have overloaded round bracket
class PersonCompare{
    public:
    bool operator()(Person A,Person B){
        return A.age<B.age;
    }
};

int main(){
   /* Fun f; //constructor
    f("C++"); //overloaded () operator = Function call where f is an object
    */
     int n;
     cin>>n;


     priority_queue<Person,vector<Person>, PersonCompare > pq;
     for(int i = 0;i<n;i++) {
         string name;
         int age;
         cin>>name>>age;
         Person p(name,age);
         pq.push(p);
     }

     int k = 3;
     for(int i = 0;i<3;i++)
     {
         Person p = pq.top();
         cout<<p.name<<" "<<p.age<<" ";
         pq.pop();
     }


}