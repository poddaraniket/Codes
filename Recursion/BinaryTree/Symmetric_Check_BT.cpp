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

int isSymmetric(Node *x,Node *y)
{
    if(x==NULL && y==NULL)
     return true;
    
    if((x!=NULL && y!=NULL) && isSymmetric(x->left,y->right) && isSymmetric(x->right,y->left))
     return true;
    return false; 
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
    cout<<isSymmetric(root->left,root->right)<<endl;   
	//cout<<diameter<<endl;
	return 0;
}
