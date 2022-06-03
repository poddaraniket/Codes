#include<bits/stdc++.h>

using namespace std;

#define MAXSIZE 101

int arr[MAXSIZE];
int top=-1;

void push(int x)
{
    if(top==MAXSIZE-1)
     cout<<"OVERFLOW"<<endl;
    arr[++top]=x;
}

int pop()
{
    if(top==-1)
     return -1;
    return arr[top--]; 
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
     top=-1;    
     int q,a;
     cin>>q;
     while(q--)
     {
      int query=0;
      cin>>query;
      if(query==1)
       {
        cin>>a;
        push(a);
       }
      else
       {
        cout<<pop()<<" ";  
       }
     }
     cout<<endl;
    }
}