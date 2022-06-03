//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }
        
};

Node *newNode(int data)
{
    Node *temp=new Node(data);
    
    return temp;
}


Node *addNode(Node *head, int data)
{
    if(head==NULL)
    head=newNode(data);
    else
    head->next=addNode(head->next,data);
    
    return head;
}


void displayList(Node *head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}



 // } Driver Code Ends


//User function Template for C++

/*
struct Node
{
    int data;
    Node * next;
    Node (int x)
    {
        data=x;
        next=NULL;
    }
        
};

*/

Node * insertInSorted(Node * head, int data)
{
    //Your code here
    int c=0;
    Node *new_node=new Node(data);
    Node *curr=head;
    Node *prev=head;
    if(head==NULL || head->data>=data)
     {
        new_node->next=head;
        head=new_node; 
        return head;
     }
    else
     {
       while(curr->next!=NULL)
        {
         if(curr->data>=new_node->data)
          {
              new_node->next=prev->next;
              prev->next=new_node;
              return head;
          }
        prev=curr; 
        curr=curr->next;
       }
    }
    if(c==0)
     {
        cout<<"*"<<endl; 
        if(curr->data>=new_node->data)
         {
            new_node->next=prev->next;
            prev->next=new_node; 
         }
        else
         {
            curr->next=new_node;
         }
     }
    return head; 
}


// { Driver Code Starts.


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    Node *head=NULL;
	    for(int i=0;i<n;i++)
	    {
	        int x;
	        cin>>x;
	        head=addNode(head,x);
	    }
	    
	  
	    int data;
	    cin>>data;

	    head=insertInSorted(head,data);
	    
	    displayList(head);
	    
	    cout<<endl;
	}
	return 0;
}  // } Driver Code Ends