#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
/* A linked list node */

void rearrange(struct Node *odd);

struct Node
{
    int data;
    struct Node *next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

struct Node *start = NULL;

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
    
}

void insert()
{
    int n,value;
    cin>>n;
    struct Node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            start = new Node(value);
            temp = start;
            continue;
        }
        else
        {
            temp->next = new Node(value);
            temp = temp->next;
        }
    }
}

int main()
{
    int t;
    cin>>t;
    while (t--) {
        insert();
        rearrange(start);
        printList(start);
    }
    return 0;
}
// } Driver Code Ends


/*
  reverse alternate nodes and append at the end
  The input list will have at least one element  
  Node is defined as 
  struct Node
  {
      int data;
      struct Node *next;
    
      Node(int x){
        data = x;
        next = NULL;
      }
   };
*/

#include<bits/stdc++.h>
void rearrange(struct Node *odd)
{
    int cnt=1;
    stack<Node *> s;
    //cout<<s.size()<<endl;
    //cout<<"*"<<endl;
    Node *curr=odd;
    Node *temp1=NULL;
    Node *prev=NULL;
    while(curr!=NULL)
     {
        //cout<<"#"<<endl;
       if(cnt%2==0)
        {
          prev->next=curr->next;
          s.push(curr);
          curr->next=NULL;
          curr=prev->next;
        }
       else
        {
            prev=curr;
            curr=curr->next;
        }
      ++cnt;    
     }
    //Node *new_node=prev; 
    // int c=0; 
    while(!s.empty())
    {
        prev->next=s.top();
        prev=prev->next;
        s.pop();
    }
}

