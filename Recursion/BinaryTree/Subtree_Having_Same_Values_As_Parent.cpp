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

int countSubtrees(Node *root,int &count)
{
    if(root==NULL)
     return -1;  // if its 

    if(root->left==NULL && root->right==NULL)  // the leaf will always be included as a subtree
     {
        count++;
        return root->data;
     }
    
    int left=countSubtrees(root->left,count);
    int right=countSubtrees(root->right,count);
    if((left==-1 && right==root->data)||(left==root->data && right==-1)||(left==root->data && right==root->data))
       {
           count++;
           return root->data;
       }
    return 10000;   
}

int main() {
	// your code goes here
	Node* root = NULL;
	/*
	             1
				/ \
			   /   \
			  2     3
			 /     / \
			/     /   \
		   4     5     6
		  /     / \     \
		 /     /   \     \
		4     5     5     7
    */

	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->left->left->left = new Node(4);
	root->right->left->left = new Node(5);
	root->right->left->right = new Node(5);
	root->right->right->right = new Node(7);

    int count=0;

    countSubtrees(root,count);
    cout<<count<<endl;
	return 0;
}
