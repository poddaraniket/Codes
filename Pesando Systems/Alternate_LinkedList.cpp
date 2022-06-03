#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next=NULL;
    Node(int data)
    {
        this->data=data;
        this->next=NULL;
    }
};

Node* insert(Node *head,int key)
{
    Node *temp=head;
    Node *newnode=new Node(key);
    if(head==NULL)
    {
     head=newnode;
    }
    else
     {
        while(temp->next!=NULL)
         {
            temp=temp->next; 
         }
        temp->next=newnode;
     }
    return head; 
}

Node* reverse(Node *head)
{
    Node *temp=head;
    //int p=1;
    stack<Node*> st;
    while(temp!=NULL)
     {
        if(temp->next!=NULL)
         {
            //cout<<temp->data<<endl; 
            Node *curr=temp->next;
            temp->next=temp->next->next;
            curr->next=NULL;
            st.push(curr);
         }
        temp=temp->next; 
     }
    // temp=head; 
    // while(temp!=NULL)
    //  {
    //     cout<<temp->data<<" ";
    //     temp=temp->next;
    //  } 
    temp=head;
    while(!st.empty())
     {
        Node *curr=temp->next;
        temp->next=st.top();
        st.top()->next=curr;
        st.pop();
        temp=curr;
     }
    return head; 
}

int main() {
	// your code goes here
    int arr[]={1,8,3,6,5,4,7,2};
    Node *head=NULL;
    for(int i=0;i<8;i++)
     {
        head=insert(head,arr[i]); 
     }
    head=reverse(head);
    Node *temp=head;
    while(temp!=NULL)
     {
        cout<<temp->data<<" ";
        temp=temp->next;
     }
}
