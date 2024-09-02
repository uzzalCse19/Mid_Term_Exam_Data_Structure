#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Write your code here
    list<int>l;
    list<int>l2;
    int q;
    cin>>q;
    while(q--)
    {
        int v,x;
        cin>>x>>v;
        if(x==0)
        {
            l.push_front(v);
            cout<<"L -> ";
            for(int val:l)
            {
                cout<<val<<" ";
            }
            cout<<endl;
             cout<<"R -> ";
             l2=l;
            l2.reverse();
           for(auto it=l2.begin();it!=l2.end();it++)
           {
               cout<<*it<<" ";
           }
           cout<<endl;
        }
        else if(x==1)
        {
            l.push_back(v);
            cout<<"L -> ";
            for(int val:l)
            {
                cout<<val<<" ";
            }
            cout<<endl;
            cout<<"R -> ";
            l2=l;
            l2.reverse();
           for(auto it=l2.begin();it!=l2.end();it++)
           {
               cout<<*it<<" ";
           }
           cout<<endl;
        }
        else
        {
            if(l.size()>v){
            l.erase(next(l.begin(),v));
            }
            cout<<"L -> ";
            for(int val:l)
            {
                cout<<val<<" ";
            }
            cout<<endl;
            cout<<"R -> ";
            l2=l;
            l2.reverse();
           for(auto it=l2.begin();it!=l2.end();it++)
           {
               cout<<*it<<" ";
           }
           cout<<endl;
        }
    }
    return 0;
}
