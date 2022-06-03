#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

void prefixPrint(Node *root)
{
    if(root==NULL)
     return;
    cout<<root->data<<" ";
    prefixPrint(root->left);
    prefixPrint(root->right);
}

int ConvertToSum(Node *root)
{
    if(root==NULL) 
     return 0;
    int left=ConvertToSum(root->left);
    int right=ConvertToSum(root->right);
    int old=root->data;
    root->data=left+right;
    return root->data+old;
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
    ConvertToSum(root);
    prefixPrint(root);
	return 0;
}
