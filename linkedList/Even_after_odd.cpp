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
void insertAfterANode(node*&head,node*lastOdd,node* temp){
    lastOdd->next = temp;
    temp->next = head;
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


void migrateEven(node*&head){
    node*temp = head;
    node*last = head;
    node*prev = head;

 while(last->next!=NULL){
     last = last->next;
    }

    if((temp->data)%2 == 0){
        prev = prev->next;
        
    }

    while(temp!=NULL){
        if((temp->data)%2 == 0)
        {
            prev->next = temp->next;
            node*move = temp;
            temp = temp->next;
            insertNodeAtHead(head,move);
        }else{
            temp = temp->next;
            prev = prev->next;
        }
    }
}



int main()
{
    int n;
    cin>>n;
    node* head = take_input(n);
    migrateOdd(head);
    print(head);
}