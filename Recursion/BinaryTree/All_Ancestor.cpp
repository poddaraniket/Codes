#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;

	Node(int data)
	{
	this->data = data;
	this->left = this->right =NULL;
	}
};

map<Node*,Node*> mp;
//int flag=0;
Node *temp=NULL;

void AllAncestors(Node *root,int x)
{
    if(root==NULL)
    {
      return;
    }
    if(root->data==x)
     {
        //flag=1; 
        temp=root;
     }
    if(root->left!=NULL)
     {
        mp[root->left]=root; 
     }
    if(root->right!=NULL)
     {
        mp[root->right]=root; 
     }
    AllAncestors(root->left,x);
    AllAncestors(root->right,x);
}

int main() {
	// your code goes here
	Node* root =NULL;
	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->right = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->right->right = new Node(8);
    AllAncestors(root,7);
    if(temp==NULL) 
     cout<<"Number doesn't exist"<<endl;
    else
     {
      while(mp.find(temp)!=mp.end())
       {
        temp=mp[temp];
        cout<<temp->data<<" ";
       }
      cout<<endl; 
     }
    return 0;
}
