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

int height(Node* root)
{
    if(root==NULL)
     return 0;
     
    if((root->left!=NULL && root->left->right==root) && (root->right!=NULL && root->right->left==root)) 
      return 1;
      
    int left=height(root->left);
    int right=height(root->right);
    
    return max(left,right)+1;
}

int main() {
	// your code goes here
	Node* root = NULL;
	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);		// leaf node
	root->right->right = new Node(6);   	// leaf node
	root->left->left->left = new Node(7);   // leaf node

	// construct circular doubly linked list from leaves
	Node *first = root->left->left->left;
	Node *second = root->left->right;
	Node *third = root->right->right;

	// set previous and next pointers of the linked list
	// (left and right pointer of binary tree node respectively)
	first->left = third;
	first->right = second;

	second->left = first;
	second->right = third;

	third->left = second;
	third->right = first;

    cout<<height(root)<<endl;

	return 0;
}
