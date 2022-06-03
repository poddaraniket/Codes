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

void inorder(Node* root)
{
    if(root==NULL)
     return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void truncate(Node* &root,int k,int sum)
{
    if(root==NULL)
     {
        return; 
     }
     
    sum+=root->data;
     
    truncate(root->left,k,sum);
    truncate(root->right,k,sum);
    
    if(sum<k && (root->left==NULL && root->right==NULL)){
        delete(root);
        root=NULL; 
    }
}

int main() {
	// your code goes here
	Node* root = nullptr;

	/* Construct below tree
			 6
		   /  \
		  /    \
		 3      8
			   /  \
			  /    \
			 4      2
		   /   \      \
		  /     \      \
		 1       7      3
    */

	root = new Node(6);
	root->left = new Node(3);
	root->right = new Node(8);
	root->right->left = new Node(4);
	root->right->right = new Node(2);
	root->right->left->left = new Node(1);
	root->right->left->right = new Node(7);
	root->right->right->right = new Node(3);

	int k = 20;
	truncate(root,k,0);
	inorder(root);
	return 0;
}
