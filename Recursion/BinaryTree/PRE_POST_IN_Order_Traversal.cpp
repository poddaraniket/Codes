#include <iostream>
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

void postorder(Node *root)
{
    if(root==NULL)
     return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void preorder(Node *root)
{
    if(root==NULL)
     return;
    cout<<root->data<<" "; 
    preorder(root->left);
    preorder(root->right);
}


void inorder(Node *root)
{
    if(root==NULL)
     return;
    inorder(root->left);
    cout<<root->data<<" "; 
    inorder(root->right);
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
    postorder(root);
    cout<<endl;
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    return 0;
}
