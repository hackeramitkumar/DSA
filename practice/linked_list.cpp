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

void insertAtHead(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }
    node *n = new node(data);
    n->next = head;
    head = n;
}

void print(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
}

int length(node *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

void insertAtTail(node *&head, int data)
{
    if (head == NULL)
    {
        head = new node(data);
        return;
    }
    node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    tail->next = new node(data);
    return;
}

void insertInMiddle(node *&head, int data, int p)
{
    if (head == NULL || p == 0)
    {
        insertAtHead(head, data);
    }
    else if (p > length(head))
    {
        insertAtTail(head, data);
    }
    else
    {
        int jump = 1;
        node *temp = head;
        while (jump <= p - 1)
        {
            temp = temp->next;
            jump++;
        }
        // create a new node
        node *n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }
}

// Delete the head

void deleteAtHead(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    node *temp = head->next;
    delete head;
    head = temp;
}

void deleteAtLast(node *&head)
{
    if (head == NULL)
    {
        return;
    }
    if (head->next == NULL)
    {
        deleteAtHead(head);
    }

    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = NULL;
    return;
}

void DeleteInMiddle(node *&head, int p)
{
    if (head == NULL)
    {
        return;
    }
    else if (p > length(head))
    {
        return;
    }
    else
    {
        int jump = 1;
        node *temp = head;
        while (jump <= p - 1)
        {
            temp = temp->next;
            jump++;
        }
        node *curr = temp->next;
        temp->next = curr->next;
        delete (curr);
        return;
    }
}

bool searching(node*head, int var){
    while(head != NULL){
        if(head->data == var){
            return true;
        }
        head = head->next;
    }
    return false;


}

bool search(node*head, int val){
    if(head == NULL){
        return false;
    }

    if(head->data == val ){
        return true;
    }else{
        return search(head->next,val);
    }
}
/*
node* take_input(){
    int d;
    cin>>d;
    node* head = NULL;
    while(d!=-1){
        insertAtTail(head,d);
        cin>>d;



    }
}
*/

// reverse the linkedlist
void reverse(node*&head){
node* curr = head;
node* prev = NULL;


    while(curr != NULL){
        node* temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    head = prev;
}

node* reverse_(node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    node* shead = reverse_(head->next);
    node* temp = shead;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    head->next = NULL;
    temp->next = head;

    return shead;

}

int main()
{
    node *head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    print(head);
    cout << endl;
    insertAtTail(head, 6);
    insertAtTail(head, 7);
    print(head);
    cout << endl;
    insertInMiddle(head, 5, 5);
    print(head);
    cout << endl;
    deleteAtHead(head);
    print(head);
    cout << endl;
    deleteAtLast(head);
    print(head);
    cout << endl;
    DeleteInMiddle(head, 3);
    print(head);
    cout << endl;
  node* newnode =   reverse_(head);
     print(newnode);
    cout << endl;
   
    // cout<<search(head,5)<<endl;
    // cout<<search(head,10)<<endl;
    // cout<<search(head,4)<<endl;

}