#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int key)
    {
        this->data=key;
        this->left=NULL;
        this->right=NULL;
    }
};

// here it does calculation of ReplaceNode of odd nodes and even nodes

void ReplaceNodeOfEvenNodes_OddNodes(Node *root,int val,int &lt,int &rt)
{
    if(root==NULL)
     return;
    if(val==1)
     lt+=root->data;
    if(val==2)
     rt+=root->data;
    ReplaceNodeOfEvenNodes_OddNodes(root->left,1,lt,rt);
    ReplaceNodeOfEvenNodes_OddNodes(root->right,2,lt,rt);
}

// to traverse each node and in preorder fashion send each root for updation

void ReplaceNode(Node *root)
{
    if(root==NULL)
     return;
    int lt=0,rt=0;
    ReplaceNodeOfEvenNodes_OddNodes(root,-1,lt,rt);
    root->data+=(lt*rt);
    ReplaceNode(root->left);
    ReplaceNode(root->right);
}

void preorder(Node *root)
{
    if(root==NULL)
     return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
	// your code goes here
	Node* root =NULL;
	root = new Node(4);
	root->left = new Node(2);
	root->right = new Node(6);
	root->left->left = new Node(1);
	root->left->right = new Node(3);
	root->right->left = new Node(5);
	root->right->right = new Node(7);
	ReplaceNode(root);
	preorder(root);
	return 0;
}
