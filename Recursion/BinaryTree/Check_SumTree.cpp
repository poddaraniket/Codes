#include <iostream>
using namespace std;

int flag=0;

struct Node
{
	int data;
	Node *left, *right;
	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

void prefixPrint(Node *root)
{
    if(root==NULL)
     return;
    cout<<root->data<<" ";
    prefixPrint(root->left);
    prefixPrint(root->right);
}

int CheckSum(Node *root)
{
    if(root->left==NULL && root->right==NULL) 
     return root->data;
    int left=CheckSum(root->left);
    int right=CheckSum(root->right);
    if(root->data!=left+right)
    {
        flag=1;
    }
    return left+right+root->data;
}

int main() {
	// your code goes here
	Node* root =NULL;
	root = new Node(44);
	root->left = new Node(9);
	root->right = new Node(13);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
    CheckSum(root);
    if(flag==1)
     cout<<"NOT SUM TREE"<<endl;
    else
     cout<<"SUM TREE"<<endl;
	return 0;
}
