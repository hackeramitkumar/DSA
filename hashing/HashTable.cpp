#include<iostream>
#include<cstring>
#include "hashTable.h"
using namespace std;




int main()
{
    HashTable<int> price_menu;
    price_menu.insert("Burger",120);
    price_menu.insert("Pizza",300);
    price_menu.insert("Ice Cream",80);
    price_menu.insert("mgreta",120);
    // price_menu.insert("magrta",120);
    price_menu.insert("a",50);
    price_menu.insert("b",50);
    price_menu.insert("c",50);
    price_menu.insert("d",50);
    price_menu.insert("e",50);
     price_menu.insert("a",50);
    price_menu.insert("b",50);
    price_menu.insert("c",50);
    price_menu.insert("d",50);
    price_menu.insert("e",50);
   
    price_menu.insert("f",50);
    price_menu.insert("o",50);
    price_menu.print();
putchar('\n');
    int *price = price_menu.search("Burger");    
    cout<<*price<<endl;
    if(price== NULL)
    {
        cout<<"Not present!"<<endl;

    }else
    {
        cout<<"price is : "<<*price<<endl;
    }
    price_menu["amit"] = 19;
    price_menu.print();

}