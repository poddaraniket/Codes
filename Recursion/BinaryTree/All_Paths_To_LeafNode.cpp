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

void AllPaths(Node *root,vector<int> v)
{
    if(root==NULL)
    {
      return;
    }
    v.push_back(root->data);
    if(root->left==NULL && root->right==NULL)
    {
      for(int i=0;i<v.size();i++)
       cout<<v[i]<<" ";
      cout<<endl; 
    }
    AllPaths(root->left,v);
    AllPaths(root->right,v);
}

int main() {
	// your code goes here
	Node* root =NULL;
	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	vector<int> v;
    AllPaths(root,v);
    return 0;
}
