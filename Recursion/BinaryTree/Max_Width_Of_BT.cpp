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

void maxWidth(Node *root,int lev)
{
    if(root==NULL)
     {
        return; 
     }
     
    mp[lev]+=1;
     
    maxWidth(root->left,lev+1);
    maxWidth(root->right,lev+1);
    
}

int main() {
	// your code goes here
	Node* root = NULL;

	root = new Node(15);
	root->left = new Node(10);
	root->right = new Node(20);
	root->left->left = new Node(8);
	root->left->right = new Node(12);
	root->right->left = new Node(16);
	root->right->right = new Node(25);

	maxWidth(root,0);
	
	int maxi=0;
	
	for(int i=0;i<mp.size();i++)
	 maxi=max(maxi,mp[i]);
	cout<<maxi<<endl; 
	return 0;
}
