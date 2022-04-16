#include<bits/stdc++.h>
using namespace std;
class node{
public:
int data;
node *next;
node *prev;

node(int d)
{
    data = d;
    next = NULL;
    prev = NULL;
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
    head->prev = n;
    head = n;
}




int length(node*head){
    int cnt = 0;
    while(head != NULL){
        cnt++;
        head= head->next;
    }
    return cnt;
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
    node* newNode = new node(data);
    tail->next =  newNode;
    newNode->prev = tail;
     newNode->next = NULL;
    newNode->prev = tail;

    return;
}


void InsertInMiddle(node*&head,int data,int p){
    //corner case
    if(head == NULL or p ==0){
        insertAtHead(head,data);
    }else if(p>length(head)){
        insertAtTail(head,data);
    }else{
        //take p-1 jump
        int jump = 1;
        node* temp = head;
        while(jump<= p-2){
            temp = temp->next;
            jump++;
        }
        node*n = new node(data);
        n->next = temp->next;
        temp->next = n;
        n->prev = temp;
        if(n->next != NULL){
            n->next->prev = n;
        }
    }
}







// Deletion
void deleteHead(node*&head) {
    if(head == NULL){
        return;
    }

    node*temp = head->next;
    temp->prev = head->prev;
    delete head;
    head = temp;
}

void deleteAtTail(node*&head){
    if(head==NULL){
        return;
    }
    if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }
    node*temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    node *lastNode = temp->next;
    temp->next = NULL;
    if(lastNode->prev != NULL){
        lastNode->prev->next = lastNode->next;
    }
    delete(lastNode);
}

void deleteInMiddle(node*&head,int p){
    if(head==NULL){
        return;
    }else if(p>length(head)){
        deleteAtTail(head);
    }else{
        int jump = 1;
        node*temp = head;
        while(jump<= p-2){
            temp = temp->next;
            jump++;
        }
        node*targetNode = temp->next;
        temp->next = targetNode->next;
        targetNode->next->prev = targetNode->prev;
        delete(targetNode);
    }
    
}


// searching in linkedList
//only linear search will be done in linkedList
bool search(node *head,int key){
    node*temp = head;
    while(head!=NULL){
        if(head->data ==key){
            return true;
        }
        head = head->next;
    }
    return false;
}
//search by recursive function
bool search_rec(node *head,int key){
    if(head == NULL){
        return false;
    }
    //rec case
    if(head->data == key){
        return true;
    }else{
        return search(head->next,key);
    }

}

//Taking input

void print(node * head){

    node*last;
    while(head != NULL){
        cout<<head->data<<"->";
        last = head;
        head = head->next;
    }
    putchar('\n');
    
    while(last != NULL)
    {
        cout<<last->data<<"->";
        last = last->prev;
    }
    putchar('\n');

}




//here type is node*
node* take_input(){
    int d;
    cin>>d;

    node*head = NULL;
    while(d!=-1){
        insertAtHead(head,d);
        cin>>d;
    }
    return head;
}


node* take_input_by_file(){
    int d;

    node*head = NULL;
    while(cin>>d){
        insertAtHead(head,d);
    
    }
    return head;
}

ostream& operator<<(ostream& os,node*head){
    print(head);
    return os;
}

istream& operator>>(istream& is,node*&head){
    head = take_input();
    return is;
}


node* KthNodeFromEnd(node*head,int k){
    if(head == NULL || k>length(head))
    {
        return head;
    }
    node*first = head;
    while(k-- and first != NULL){
        first = first->next;
    }
    node*second = head;
    while(first!=NULL)
    {
        first = first->next;
        second = second->next;
    }
    return second;
}


int main()
{
    node*head = NULL;
    insertAtHead(head,4);
    insertAtHead(head,3);
    insertAtHead(head,2);
    insertAtHead(head,1);
    cout << head;
    insertAtTail(head,7);
    insertAtTail(head,8);
    insertAtTail(head,9);
    cout << head;
    InsertInMiddle(head,5,5);
    InsertInMiddle(head,6,6);
    cout << head;
    deleteHead(head);
    cout << head;
    deleteAtTail(head);
    deleteAtTail(head);
    cout << head;
    deleteInMiddle(head,5);
    cout<<head;

}