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

void inorder(Node *root)
{
    if(root==NULL)
     return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}


Node* vanish(Node* &root)
{
    if(root==NULL)
     return NULL;

    // we have kept root->left and root->right so that the new node can be attached with the old one

    root->left=vanish(root->left);  
    root->right=vanish(root->right);
    
    if((root->left && root->right) || !(root->left) && !(root->right))
     return root;
    
    // if any of its child is not there then the root is removed and the right child is added to the parent of that root and then we recheck 

    if(root->left==NULL)
     {
       delete(root);
       return root->right;
     }
    else
     {
        delete(root);
        return root->left;
     }
}

int main() {
	// your code goes here
	Node *root=NULL;
    root = new Node(0);
	root->left = new Node(1);
	root->right = new Node(2);
	root->left->left = new Node(3);
	root->right->left = new Node(4);
	root->left->left->left = new Node(5);
	root->right->left->left = new Node(6);
	root->right->left->right = new Node(7);

	vanish(root);
	inorder(root);
	return 0;
}
