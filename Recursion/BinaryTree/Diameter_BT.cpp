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

int Diameter(Node *root,int &diameter)
{
    if(root==NULL)
     return 0;
    int left_ht=Diameter(root->left,diameter);
    int right_ht=Diameter(root->right,diameter);
    int max_diameter=left_ht+right_ht+1;
    diameter=max(max_diameter,diameter);
    return max(left_ht,right_ht)+1;
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
	int diameter=0;
    Diameter(root,diameter);   // it is a subtree if that subtree sectioh has same data as well as same address,i.e, it is actually a subtree
	cout<<diameter<<endl;
	return 0;
}
