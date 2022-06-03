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

void preorder(Node *root)
{
    if(root==NULL)
     return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void ConvertToMirror(Node *x,Node *y)
{
    if(x==NULL && y==NULL)
     return;
    
    if(x!=NULL && y!=NULL)
     {
        int t=x->data;
        x->data=y->data;
        y->data=t;
     }
    ConvertToMirror(x->left,y->right);
    ConvertToMirror(x->right,y->left);
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
	//int diameter=0;
    ConvertToMirror(root->left,root->right);
    preorder(root);
    return 0;
}
