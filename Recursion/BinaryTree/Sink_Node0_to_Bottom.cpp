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

//once a parent has 0 than it will replace it with its non-zero child which will then replace it with ots own non-zero child and so on
// that is why recursion in sink function 

void sink(Node* &root)
{
    if(root->left && root->left->data!=0)
     {
        int temp=root->data;
        root->data=root->left->data;
        root->left->data=temp;
        sink(root->left);
     }
    else if(root->right && root->right->data!=0)
     {
        int temp=root->data;
        root->data=root->right->data;
        root->right->data=temp;
        sink(root->right); 
     }
}

void sinkNodes(Node* &root)
{
    if(root==NULL)
     return;

 	//post-order tarversal so that all nodes are traversed and then we see from bottom if the parent has zero then replace it with its non-zero child

    sinkNodes(root->left);
    sinkNodes(root->right);
    if(root->data==0)
     {
         sink(root);
     }
}

int main() {
	// your code goes here
Node* root = new Node(0);
	root->left = new Node(1);
	root->right = new Node(0);
	root->right->left = new Node(0);
	root->right->right = new Node(2);
	root->right->left->left = new Node(3);
	root->right->left->right = new Node(4);

	sinkNodes(root);
	inorder(root);
	return 0;
}
