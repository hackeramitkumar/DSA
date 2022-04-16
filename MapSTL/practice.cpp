#include<bits/stdc++.h>
using namespace std;

template<typename T>
class Node{
    public:
    string key;
    T value;
    Node<T> *next;
    Node(string key,T val){
        this -> key = key;
        value = val;
        next = NULL; 
    }
    ~Node(){
        if(next != NULL){
            delete next;
        }
    }
};

template<typename T>
class HashTable{
    Node<T> **table;
    int current_size;
    int table_size;

    int hashFn(string key){
        int idx = 0;
        int p = 1;
        for(int j = 0;j<key.length();j++){
            idx = idx + (key[j]*p)%table_size;
            idx = idx%table_size;
            p = (p*27)%table_size;
        }
        return idx;
    }

    //rehash
    void rehash(){
        Node<T>**oldTable = table;
        table_size = 2*table_size;
        table = new node<T>*[table_size];
        for(int i = 0;i<table_size;i++){
            table[i] = NULL;
        }

        current_size = 0;
        for(1111)
    }

    public:
    HashTable(int ts = 7){
        table_size = 7;
        table = new Node<T>*[table_size];
        current_size = 0;
        for(int i = 0;i<table_size;i++){
            table[i] = NULL;
        }
    }

    // insertion function
    void insert(string key,T value){
        int idx = hashFn(key);
        Node<T>*n = new Node<T>(key,value);
        n->next = table[idx];
        table[idx] = n;
        current_size++;

        //rehash


    }

    void erase(string key){
        int idx = hashFn(key);
        Node<T>*temp = table[idx];
        while(temp!=NULL)
        {
            if(temp->next->key == NULL)
        }

    }

    T& operator[](string key){
        T*f = search(key);
        if(f == NULL){
            T garbage;
            insert(key,garbage);
            f = search(key);
        }
        return *f;
    }

    void print(){
        for(int i = 0;i<table_size;i++){
            cout<<"Bucket "<<i<<" : ";
            Node<T>*temp = table[i];

            while(temp != NULL){
                cout<<temp->key<<"-->";
                temp = temp->next;
            }
            putchar('\n');
        }
    }

};

int main()
{
    HashTable<int> price_menu;
    price_menu.insert("Burger",120);
    price_menu.insert("Chips",20);
    price_menu.insert("Coke",40);
    price_menu.insert("Noodels",100);
    price_menu.insert("Pizza",200);
    price_menu.insert("samosa",10);
    price_menu.insert("bread pakoda",15);
    price_menu.insert("Gol_gappa",5);
    price_menu.insert("rasgulla",40);
    price_menu.insert("Aaloo tikka",15);
    price_menu.insert("Chatni",8);
    price_menu.insert("Gazar halwa",55);
    price_menu.insert("Gulab zamun",12);

    price_menu.print();






}
































