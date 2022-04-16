#include<iostream>
#include<unordered_map>
#include<cstring>
using namespace std;

int main()
{
    unordered_map<string, int> m;

   /**************** 1. insert  **********************/

    // way -> 1
    m.insert(make_pair("mango", 100));
    m.insert(make_pair("mago", 120));


    // way -> 2
    pair<string, int> p;
    p.first = "Apple";
    p.second = 150;
    m.insert(p);
   
   
    // way -> 3

    m["Banana"] = 20;
    m["Lichi"] = 60;
    m["Lemon"] = 80;
    /******************* 2. search**************************/

    string fruit;
    cin >> fruit;
    auto it = m.find(fruit); // map<string,int>::iterator it = m.find(fruit);


    
    if (it != m.end())
    {
        cout << " price of " << fruit << " is" << m[fruit] << endl;
    }
    else
    {
        cout << "Fruit is not present " << endl;
    }

    // another way to find a particular map
    //it stores unique keys only once

    // note -> this count fuction return a integer while find functon
    // return a iterator
    if(m.count(fruit)){
        cout<<"price is "<<m[fruit]<<endl;
    }else{
        cout<<"Could not found"<<endl;
    }

    /* *************** Erase **********/
    // m.erase(fruit);

    /* *************** Update ***********/
    m[fruit] += 22;

    //  iterator over all the key value pairs
    for(auto it = m.begin();it!= m.end();it++)
    {
        cout<<it->first<<" and "<<it->second<<endl;
    }

    //for each loop
    for(auto p:m)
    {
        cout<<p.first<<" : "<<p.second<<endl;
    }


}