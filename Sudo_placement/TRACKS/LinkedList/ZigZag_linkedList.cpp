#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *root)
{
	Node *temp = root;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
 
 Node *zigZack(Node* head);


int main() {
	// your code goes here
	int T;
	cin>>T;
	
	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;
 
		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		Node *ans = zigZack(head);
		print(ans);
		cout<<endl;
	}
	return 0;
}// } Driver Code Ends


/*

The structure of linked list is the following
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/


Node *zigZack(Node* head)
{
 // your code goes here
 int c=1,swap;
 Node *prev=head;
 Node *curr=head->next;
 //Node *nxt=curr->next;
 while(curr)
  {
    if(c%2!=0)
     {
        if(prev->data>curr->data)
         {
             swap=prev->data;
             prev->data=curr->data;
             curr->data=swap;
         }
        ++c;
        prev=curr;
        curr=curr->next;
     }
    else
     {
        if(prev->data<curr->data)
          {
                swap=curr->data;
                curr->data=prev->data;
                prev->data=swap;
          }
        ++c;
        prev=curr;
        curr=curr->next;  
     }
  }
  return head;
}