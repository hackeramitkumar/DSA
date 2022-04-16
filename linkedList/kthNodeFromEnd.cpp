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
    node* temp = new node(data);
    tail->next = temp;
    temp->next = NULL;
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
        while(jump<= p-1){
            temp = temp->next;
            jump++;
        }
        node*n = new node(data);
        n->next = temp->next;
        temp->next = n;
    }
}


// Deletion
void deleteHead(node*&head) {
    if(head == NULL){
        return;
    }
    node*temp = head->next;
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
    delete(lastNode);
    temp->next = NULL;
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
        temp->next = temp->next->next;
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
    while(head != NULL){
        cout<<head->data<<"->";
        head = head->next;
    }
    putchar('\n');
}


/*void take_input(node*head){
    int d;
    cin>>d;
     while(d!=-1){
        insertAtHead(head,d);
        cin>>d;
    }
}
*/
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

//This function will detect the cycle in the linked list
bool DetectACycle(node*head){
    node*slow = head;
    node*fast = head;
    while(fast != NULL and fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            return true;
        }
    }
    return false;
}


//this function will remove the cycle . Here we use the Floyd's Algorithm
void RemoveCycle(node*&head){
    node*slow = head;
    node*fast = head;
    while(fast != NULL and fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow){
            break;
        }
    }
    slow = head;
    while(fast->next != slow->next){
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}


//mid_point calculaton By runner technique
node* RunnerTechnique(node*head){
    if(head==NULL || head->next == NULL){
        return head;
    }

    node*slow = head;
    node*fast = head->next;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

//this functon will create a cycle in the linked list
void createCycle(node*&head){
    node*temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = RunnerTechnique(head);
}

int main()
{
    node*head;
    cin >> head;
    cout << head;
    createCycle(head);

    if(DetectACycle(head)){
        cout<<"Present"<<endl;
    }else{
        cout<<"Not present"<<endl;
    }
    RemoveCycle(head);
    if(DetectACycle(head)){
        cout<<"Present"<<endl;
    }else{
        cout<<"Not present"<<endl;
    }

    
}