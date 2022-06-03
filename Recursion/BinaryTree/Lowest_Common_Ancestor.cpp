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

bool LCA(Node *root,int &lca,Node *x,Node *y)
{
    if(root==NULL)
      return false;
    if(root==x || root==y)
     {
        lca=root->data;
        return true;
     }
    bool left=LCA(root->left,lca,x,y);
    bool right=LCA(root->right,lca,x,y);
    if(left && right)
     {
        lca=root->data;
        return true;
     }
    return left || right; 
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
    int lca=-1;
    LCA(root,lca,root->left,root->left->right);
    if(lca==-1)
     cout<<"No Ancestor"<<endl;
    else
     cout<<lca<<endl;
    return 0;
}
