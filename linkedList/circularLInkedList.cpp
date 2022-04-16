#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

// insertion
void insertAtHead(node *&head, int data)
{
   
    node *n = new node(data);
    n->next = head;
    node*temp = head;
    if(temp!=NULL){
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = n;
    }
    head = n;
}

int length(node *head)
{
    node*temp = head;
    int cnt = 0;
    while (temp->next != head)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}



// Deletion
void deleteHead(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head->next;
    delete head;
    head = temp;
}
void deleteAtTail(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    node *lastNode = temp->next;
    delete (lastNode);
    temp->next = NULL;
}
// searching in linkedList
// only linear search will be done in linkedList
bool search(node *head, int key)
{
    node *temp = head;
    while (head != NULL)
    {
        if (head->data == key)
        {
            return true;
        }
        head = head->next;
    }
    return false;
}
// search by recursive function
bool search_rec(node *head, int key)
{
    if (head == NULL)
    {
        return false;
    }
    // rec case
    if (head->data == key)
    {
        return true;
    }
    else
    {
        return search(head->next, key);
    }
}

// Taking input

void print(node *head)
{
    node*temp = head;
    while (temp->next != head)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout<<temp->data;
    putchar('\n');
}

// finding the node
node* getNode(node*head,int data)
{
    node*temp = head;
    while(temp->next != head){
        if(temp->data== data){
            return temp;
        }
        temp = temp->next;
    }
    //out of the loop
    if(temp->data == data){
        return temp;
    }
    return NULL;
}

//deletion in linked list

void deletNOde(node*&head,int data){
    node* del = getNode(head,data);
    if(del==NULL){
        return;
    }
    //otherwise
    if(head == del){
        head = head->next;
    }
    node*temp = head;
    while(temp->next != del){
        temp = temp->next;
    }
temp->next = del->next;
delete del;
}


int main()
{
    node *head = NULL;
    insertAtHead(head, 4);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    insertAtHead(head, 0);
    print(head);

}