#include<iostream>
#include<cstring>
using namespace std;

template <typename T>
class Node{
    public:
    string key;
    T value;
    Node<T> *next;

    Node(string key, T value){
        this->key = key;
        this->value = value;
        next = NULL;
    }
//destructor
    ~Node(){
        if(next != NULL){
            delete next;
        }
    }

};

template <typename T>
class HashTable{
    Node<T>**table;
    int current_size;
    int table_size;

    //this will convert the key into integer
    int hashFn(string key) {
        int idx = 0;
        int p = 1;
        for(int j = 0;j<key.length();j++)
        {
            idx = idx + (key[j]*p)%table_size;
            idx = idx%table_size;
            p = (p*27)%table_size;
        }
        return idx;
    }

    //rehash
    void rehash() {
        Node <T>** oldTable = table;
        int oldTable_size = table_size;
        table_size = 2*table_size;
        table = new Node<T>*[table_size];

        for(int i = 0;i<table_size;i++)
        {
            table[i] = NULL;
        }

        current_size = 0;
        //shift the elements from old table to the new table
        for(int i = 0;i<oldTable_size;i++)
        {
            Node<T>*temp = oldTable[i];
            while(temp != NULL)
            {
                insert(temp->key,temp->value);
                temp = temp->next;
            }
            // now delete the previous entire row which has been copied
            //here destructure will bw called
            if(oldTable[i] != NULL)
            {
                delete oldTable[i];
            }
        }
        //delete the complete old table array
        delete [] oldTable;
    }

    public:
    HashTable(int ts= 7)
    {
        table_size = ts;
        table = new Node<T>*[table_size];
        current_size = 0;
        for(int i = 0;i<table_size;i++)
        {
            table[i] = NULL;
        }
    }

    void insert(string key,int value)
    {
        int idx = hashFn(key);
        Node<T>*n = new Node<T>(key,value);
        //insert at head of the linked list with id = idx
        n->next = table[idx];
        table[idx] = n;
        current_size++;
        //rehash -> this will increse the size of hash table when we cross particular thresshold

        float load_factor = current_size/(1.0*table_size);

        if(load_factor > 0.7){
            rehash();
        }
    }

    void print(){
        for(int i = 0;i<table_size;i++)
        {
            cout<<"Bucket "<<i<<"->";
            Node<T>*temp = table[i];
            while(temp!=NULL){
                cout<<temp->key<<"->";
                temp = temp->next;
            }
            putchar('\n');
        }
    }

    // searching in hashtable
    T* search(string key){
        int idx = hashFn(key);
        Node<T>*temp = table[idx];
        while(temp != NULL){
            if(temp->key == key)
            {
                return &temp->value;
            }
            temp = temp->next;

        }
        return NULL;
    }

    //
    T& operator[](string key){
        T *f = search(key);
        if(f==NULL){
            T garbage;
            insert(key,garbage);
            f = search(key);
        }
        return *f;
    }

  /*  void erase(string key){
        int idx = hashFn(key);
        node<T>*temp = table[i];
        while(temp!=NULL)
        {
            if(temp->key == key)
            {

            }
        }
    }
    */

};