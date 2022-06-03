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

bool check(Node *tree,Node *subtree)  //it checks if it is a subtree or not 
{
    // if(tree==NULL)
    //  cout<<"0"<<" "<<"0"<<endl;
    // else
    //  cout<<tree->data<<" "<<subtree->data<<endl;
    if(tree!=subtree)
     return false;
    if(tree==NULL && subtree==NULL)
     return true;
    if(tree==subtree && check(tree->left,subtree->left) && check(tree->right,subtree->right))
     return true;
    return false; 
}

bool CheckSubTree(Node *tree, Node *subtree)   // it traverses the main tree till it finds the first element of the subtree
{
    //cout<<tree->data<<" "<<subtree->data<<endl;
    if(tree==subtree)
     return check(tree,subtree);
    if(tree==NULL)
     return false;
    if(CheckSubTree(tree->left,subtree) || CheckSubTree(tree->right,subtree))
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
	
	Node* root2 =NULL;
	root2 = new Node(3);
	root2->left = new Node(6);
	root2->right = new Node(7);
	//cout<<root->data<<" "<<root2->data<<endl;
	
    cout<<CheckSubTree(root,root->right)<<endl;   // it is a subtree if that subtree sectioh has same data as well as same address,i.e, it is actually a subtree
	return 0;
}
