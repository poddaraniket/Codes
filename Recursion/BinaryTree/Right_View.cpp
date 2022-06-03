#include <bits/stdc++.h>
using namespace std;

unordered_map<int,int> mp;

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

void rightView(Node *root,int lev)
{
    if(root==NULL)
     {
        return; 
     }
     
    if(mp.find(lev)==mp.end())
     mp[lev]=root->data;
     
    rightView(root->right,lev+1);
    rightView(root->left,lev+1);
    
}

int main() {
	// your code goes here
	Node* root = NULL;

	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->right = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);

	rightView(root,0);
	
	for(int i=0;i<mp.size();i++)
	 cout<<mp[i]<<" ";
	cout<<endl; 
	return 0;
}
