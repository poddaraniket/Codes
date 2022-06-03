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

int maxDifference(Node* root,int &diff)
{
    if(root==NULL)
     return 0;
     
    int left=maxDifference(root->left);
    int right=maxDifference(root->right);
    
    int d=root->data-min(left,right);
    diff=max(diff,d);
    return min(min(left,right),root->data);
    
}

int main() {
	// your code goes here
	Node* root = nullptr;

    /* Construct below tree
              6
            /   \
           /     \
          3       8
                /   \
               /     \
              2       4
            /   \
           /     \
          1       7
    */

    root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(8);
    root->right->left = new Node(2);
    root->right->right = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(7);

    int diff=-1000000;
    maxDifference(root,diff);
    cout<<diff<<endl;

	return 0;
}
