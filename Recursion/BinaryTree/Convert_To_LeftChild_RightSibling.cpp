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

void preorder(Node *root)
{
    if(root==NULL)
     return;
     
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void convertToLCRS(Node *root)
{
    //cout<<root->data<<" ";
    if(root==NULL)
     {
       return;
     }
    
    convertToLCRS(root->left);
    convertToLCRS(root->right);
    
    if(root->left==NULL)
     {
        //cout<<root->data<<endl; 
        root->left=root->right;
        root->right=NULL;
        
        // if(root->left!=NULL)
        //  cout<<root->left->data<<" ";
        // if(root->right!=NULL)
        //  cout<<root->right->data<<endl;
     }
    else
     {
        root->left->right=root->right;
        root->right=NULL;
     }
}

int main() {
	// your code goes here
	Node* root =NULL;
	root = new Node(6);
	root->left = new Node(5);
	root->right = new Node(8);
	root->right->left = new Node(4);
	root->right->right = new Node(2);
	root->right->left->left = new Node(1);
	root->right->left->right = new Node(7);
	root->right->right->right = new Node(3);
	
	convertToLCRS(root);
	preorder(root);
	return 0;
}
