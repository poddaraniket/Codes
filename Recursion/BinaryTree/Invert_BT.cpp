#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;

	Node(int data)
	{
		this->data = data;
		this->left = this->right = nullptr;
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

void invertBinaryTree(Node *root)
{
    if(root==NULL) 
     return;
    
    Node *temp=root->left;
    root->left=root->right;
    root->right=temp;
    
    invertBinaryTree(root->left);
    invertBinaryTree(root->right);
}

int main() {
	// your code goes here
	Node* root = nullptr;

	/* Construct below tree
			  1
			/   \
		   /     \
		  2       3
		 / \     / \
		4   5   6   7
	*/

	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	invertBinaryTree(root);
	preorder(root);
	return 0;
}
