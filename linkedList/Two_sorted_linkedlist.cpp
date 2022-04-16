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
    if (head == NULL)
    {
        head = new node(data);
        return;
    }
    node *n = new node(data);
    n->next = head;
    head = n;
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
    node *temp = new node(data);
    tail->next = temp;
    temp->next = NULL;
    return;
}

node *take_input(int n)
{
    int d;

    node *head = NULL;
    while (n > 0)
    {
        cin >> d;
        insertAtTail(head, d);
        n--;
    }
    return head;
}

void print(node *head)
{
    while (head->next != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data;
    putchar('\n');
}

node *merge(node *a, node *b)
{
    node *c;
    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            insertAtTail(c, a->data);
            a = a->next;
        }
        else
        {
            insertAtTail(c, b->data);
            b = b->next;
        }
    }
    while (a != NULL)
    {
        insertAtTail(c, a->data);
        a = a->next;
    }
    while (b != NULL)
    {
        insertAtTail(c, b->data);
        b = b->next;
    }
    return c;

}



node* merge_rec(node*a,node*b){
        if(a==NULL){return b;}
        if(b==NULL){return a;}

        node*c;
        if(a->data < b->data){
            c = a;
            c->next = merge_rec(a->next,b);
        }else{
            c = b;
            c->next = merge_rec(a,b->next);
        }
    return c;
}


int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int n1;
        cin >> n1;
        node *head1 = take_input(n1);
        int n2;
        cin >> n2;

        node*head2 = take_input(n2);

        node*head = merge_rec(head1,head2);
        print(head);        

    }
    return 0;
}