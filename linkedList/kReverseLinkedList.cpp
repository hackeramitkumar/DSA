#include<bits/stdc++.h>
using namespace std;


class node{
public:
int data;
node *next;

node(int d)
{
    data = d;
    next = NULL;
}
};




//insertion
void insertAtHead(node*&head,int data){
    if(head == NULL){
        head = new node(data);
        return;
    }
    node *n = new node(data);
    n->next = head;
    head = n;
}



void insertAtTail(node *&head,int data){
    if(head == NULL){
        head = new node(data);
        return;
    }

    node *tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }
    node* temp = new node(data);
    tail->next = temp;
    temp->next = NULL;
    return;
}

node* take_input(int n){
    int d;

    node*head = NULL;
    while(n>0){
        cin>>d;
        insertAtTail(head,d);
		n--;
    }
    return head;
}



void print(node * head){
    while(head->next != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
	cout<<head->data;
    putchar('\n');
}



node* reverse(node* head, int k)
{
    // base case
    if (!head)
        return NULL;


    node* current = head;
    node* next = NULL;
    node* prev = NULL;
    int count = 0;
 
    /*reverse first k nodes of the linked list */
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
 
    /* next is now a pointer to (k+1)th node
    Recursively call for the list starting from current.
    And make rest of the list as next of first node */
    if (next != NULL)
        head->next = reverse(next, k);
 
    /* prev is new head of the input list */
    return prev;
}


int main()
{

int n,key;
cin>>n>>key;
    node* head = take_input(n);
    head = reverse(head,key);
    print(head);
}