#include<bits/stdc++.h>
using namespace std;

class Book{
    public:
    string name;
    int price;

    Book(){

    }
    Book(string name,int price)
    {
        this->name = name;
        this->price = price;

    }
};

class BookComoare{
    public:
    bool operator()(Book A,Book B){
        if(A.name == B.name)
        {
            return true;
        }else
        return false;
        
    }
};

//generic function by using iterators + templates + comparators
template<class ForwardIterator ,class T,class Compare>
ForwardIterator search(ForwardIterator start,ForwardIterator end,T key,Compare cmp)
{
    while(start != end)
    {
        if(cmp(*start,key))
        {
            return start;
        }
        start++;
    }
    return end;
}


int main(){
    
    Book b1("c++",100);
    Book b2("python",450);
    Book b3("Physics",350);

    // list<Book> l;
    vector<Book> l; //  both will behave same 
    l.push_back(b1);
    l.push_back(b2);
    l.push_back(b3);
    
    Book key("c++",110);

    BookComoare cmp;

   // auto it = search(l.begin(),l.end(),key,cmp);
//both are same things
    // list<Book>::iterator it = search(l.begin(),l.end(),key,cmp);

    vector<Book>::iterator it = search(l.begin(),l.end(),key,cmp);


    if(it!=l.end())
    {
        cout<<"book found in the library "<<endl;
    }

   



}