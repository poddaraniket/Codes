#include<bits/stdc++.h>
using namespace std;

map<int,int> mp;

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

void DiagonalSum(Node *root,int diag)
{
    if(root==NULL)
      return;
    if(mp.find(diag)==mp.end())       
     mp[diag]=root->data;
    else
     mp[diag]+=root->data;
    DiagonalSum(root->left,diag+1);  // everytime you go left you are in a new diagonal 
    DiagonalSum(root->right,diag);  // everytime u stay right u r in the same diagonal
}

int main() {
	// your code goes here
	Node* root =NULL;
    root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);
	
	DiagonalSum(root,0);
	
	for(auto it=mp.begin();it!=mp.end();it++)
	 {
	   cout<<it->second<<" ";
	 }
    return 0;
}
