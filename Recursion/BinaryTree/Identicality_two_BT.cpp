#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int data)
     {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
     }
};

bool isIdentical(Node* x,Node* y)
{
    if (x == NULL && y == NULL)
	  return true;
	if(x->data!=y->data)
     return false;  
	// if both trees are non-empty and value of their root node matches,
	// recur for their left and right sub-tree
	if(isIdentical(x->left, y->left) && isIdentical(x->right, y->right))
	  return true;
	return false;  
}

int main() {
	// your code goes here
	Node *x=NULL;
	x=new Node(15);
	x->left=new Node(10);
	x->right=new Node(20);
	x->left->left=new Node(8);
	x->left->right=new Node(12);
	x->right->left=new Node(16);
	x->right->right=new Node(25);
	
	Node *y=NULL;
	y=new Node(15);
	y->left=new Node(10);
	y->right=new Node(20);
	y->left->left=new Node(8);
	y->left->right=new Node(12);
	y->right->left=new Node(16);
	y->right->right=new Node(25);
	
	cout<<isIdentical(x,y)<<endl;
	return 0;
}
