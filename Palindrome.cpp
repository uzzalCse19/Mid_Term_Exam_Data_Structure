#include<bits/stdc++.h>
using namespace std;
int cnt=0;
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

int palindrome(Node* head,Node* tail)
{
    Node* tmp=tail;
    Node* tmp2=head;
   for(int i=0;i<cnt/2;i++)
   {
       if(tmp->val!=tmp2->val) return 0;
    tmp=tmp->prev;
    tmp2=tmp2->next;
   }

    return 1;
}
void insert_tail(Node *&head,Node* &tail,int v)
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
int v;
while(true)
{
    cin>>v;
    if(v==-1) break;
    insert_tail(head,tail,v );
    cnt++;

}
 
if( palindrome(head,tail)) cout<<"YES"<<endl;
else cout<<"NO"<<endl;
}
