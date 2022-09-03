#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    Node(int data)
    {
        this->data=data;
        next=NULL;
    }
};

void printList(Node* head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node* getTail(Node* &head)
{
    Node* temp=new Node(-1);
    temp=head;
    while(temp->next)
    {
        temp=temp->next;
    }
    return temp;
}


void reverse(Node* &head)
{
    Node* curr=head;
    Node* prev=NULL;
    Node* temp=NULL;
    
    while(curr)
    {
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
        
    }
    head=prev;
}

void insertAtHead(Node* &head , int d)
{
    Node* temp=new Node(d);
    temp->next=head;
    head=temp;
}

void insertAtTail(Node* tail , int d)
{
    Node* temp=new Node(d);
    tail->next=temp;
    temp=tail;
}

int main()
{
    Node* a=new Node(1);
    Node* b=new Node(2);
    a->next=b;
    Node* c=new Node(3);
    b->next=c;
    
    printList(a);
    
    insertAtHead(a,0);
    
    printList(a);
    
    insertAtTail(getTail(a),4);
    printList(a);
    
    reverse(a);
    printList(a);
    return 0;
}