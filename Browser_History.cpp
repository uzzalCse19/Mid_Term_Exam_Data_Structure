#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    string data;
    Node* next;
    Node* prev;
    Node(string data)
    {
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }


};
void insert_tail(Node *&head,Node* &tail,string v)
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
    list<string>l;
    Node* head=NULL;
    Node* tail=NULL;
    while(true)
    {
        string s;
        cin>>s;
        if(s=="end") break;
        l.push_back(s);
        insert_tail(head,tail,s);
    }
    Node* tmp;
    int q;
    cin>>q;
    while(q--)
    {

        list<string>l2;
        int cnt;
        for(int i=0; i<1; i++)
        {
            string str;
            cin>>str;
            if(str=="visit")
            {
                l2.push_back(str);
                cin>>str;
                l2.push_back(str);
                cnt=2;
            }
            else
            {
                l2.push_back(str);

                cnt=1;
            }
        }
        if(cnt==2)
        {
            auto it=find(l.begin(),l.end(),l2.back());
            if(it!=l.end())
            {
                tmp=head;
                while(tmp->data!=l2.back())
                {
                    tmp=tmp->next;
                }
                cout<<tmp->data<<endl;
                l2.clear();
            }
            else cout<<"Not Available"<<endl;

        }
        else
        {
            if(l2.front()=="prev")
            {
                if(tmp->prev!=NULL)
                {
                    cout<<tmp->prev->data<<endl;
                    tmp=tmp->prev;
                }
                else cout<<"Not Available"<<endl;
            }
            else
            {
                if(tmp->next!=NULL)
                {
                    cout<<tmp->next->data<<endl;
                    tmp=tmp->next;
                }
                else

                {
                    cout<<"Not Available"<<endl;
                }
            }
        }
    }
}


