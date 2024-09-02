#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }

};
void print_normal(Node *head)
{
    Node* tmp=head;
    cout<<"L -> ";
    while(tmp!=NULL)
    {
        cout<<tmp->val<<" ";
        tmp=tmp->next;

    }
    cout<<endl;
}
void reverse_print(Node* tail)
{
    Node* tmp=tail;
    cout<<"R -> ";
    while(tmp!=NULL)
    {
        cout<<tmp->val<<" ";
        tmp=tmp->prev;
    }
    cout<<endl;
}
void insert_head(Node* &head,Node* &tail,int v)
{
    Node* newNode=new Node(v);
    if(head==NULL)
    {
        head=newNode;
        tail=newNode;
        return;
    }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
}
int size_l(Node* head)
{
    Node* tmp=head;
    int sz=0;
    while(tmp!=NULL)
    {
        sz++;
        tmp=tmp->next;
    }
    return sz;
}
void insert_any_position(Node* head,Node* &tail,int v,int pos)
{
    Node* newNode=new Node(v);
    Node* tmp=head;
    for(int i=0;i<pos-1;i++)
    {
        tmp=tmp->next;
    }
    newNode->next=tmp->next;
    tmp->next=newNode;
    newNode->next->prev=newNode;
    newNode->prev=tmp;
}
void insert_tail(Node* &head,Node* &tail,int v)
{
    Node* newNode=new Node(v);
    if(tail==NULL)
    {
        head=newNode;
        tail=newNode;
        return;
    }
    tail->next=newNode;
    newNode->prev=tail;
    tail=tail->next;
}
int main()
{
    Node* head=NULL;
    Node* tail=NULL;
    int q;
    cin>>q;
    while(q--)
    {
        int x,v;
        cin>>x>>v;
        if(x==0) {
        insert_head(head,tail,v);
        print_normal(head);
        reverse_print(tail);
        }
       else if(x>size_l(head)) cout<<"Invalid"<<endl;
       else if(x==size_l(head))
       {
           insert_tail(head,tail,v);
           print_normal(head);
        reverse_print(tail);
       }
       else
       {
           insert_any_position(head,tail,v,x);
            print_normal(head);
        reverse_print(tail);
       }

    }
}
