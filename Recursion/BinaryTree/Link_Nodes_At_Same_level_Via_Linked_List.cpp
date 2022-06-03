#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right, *next;

	// constructor
	Node(int data)
	{
		this->data = data;
		this->left = this->right = this->next = nullptr;
	}
};

unordered_map<int,vector<Node *>> mp;
int level=0;

void linkNodes(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while(!q.empty())
    {
        level++;
        int size=q.size();
        while(size--)
        {
            Node *temp=q.front();
            q.pop();
            mp[level].push_back(temp);
            if(temp->left!=NULL)
            {
             q.push(temp->left);
             //cout<<temp->left->data<<" ";
            }
            if(temp->right!=NULL)
            {
             q.push(temp->right);
             //cout<<temp->right->data<<" ";
            }
        }
       //cout<<endl;    
    }
}

void print(Node* head)
{
    Node *temp=head;
    while(temp!=NULL)
     {
        cout<<temp->data<<"->";
        temp=temp->next;
     }
    cout<<"NULL"<<endl; 
}

int main() {
	// your code goes here
	/* Construct below Tree
		   1
		 /   \
		2	 3
	   / \	 \
	  4   5	 6
	   \	   /
		7	 8
	*/

	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->right = new Node(6);
	root->left->left->right = new Node(7);
	root->right->right->left = new Node(8);

	// link nodes at the same level
	linkNodes(root);
	for(int i=1;i<=mp.size();i++)
	 {
	     Node *prev=NULL;
	     Node *head=NULL;
	     for(int j=0;j<mp[i].size();j++)
	      {
	         //cout<<"*"<<endl; 
	         Node *curr=mp[i][j];
	         //cout<<curr->data<<" ";
	         if(head==NULL)
	         {
	           head=curr;  
	           prev=head;
	         }
	         else
	          prev->next=curr;
	         prev=curr; 
	      }
	     //prev->next=NULL;
	    // cout<<endl;
	     print(head);
	 }
	return 0;
}
