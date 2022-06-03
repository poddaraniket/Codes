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

int maxleavesSum(Node *root,int &sum)
{
    if(root==NULL)
     return 0;
    int left_ht=maxleavesSum(root->left,sum);
    int right_ht=maxleavesSum(root->right,sum);
    int max_sum=left_ht+right_ht+root->data;
    sum=max(max_sum,sum);
    return max(left_ht,right_ht)+root->data;
}

int main() {
	// your code goes here
	Node* root =NULL;
	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->right = new Node(-4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);
	int sum=0;
    maxleavesSum(root,sum);   // it is a subtree if that subtree sectioh has same data as well as same address,i.e, it is actually a subtree
	cout<<sum<<endl;
	return 0;
}
