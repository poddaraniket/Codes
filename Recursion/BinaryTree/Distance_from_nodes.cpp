#include <iostream>
using namespace std;

int x_dist,y_dist,lca_dist;

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

bool LCA(Node *root,int &lca,Node *x,Node *y,int dist)
{
    if(root==NULL)
      return false;
    if(root==x) 
     {
        lca=root->data;
        x_dist=dist;
        return true;
     }
    if(root==y) 
     {
        lca=root->data;
        y_dist=dist;
        return true;
     } 
    bool left=LCA(root->left,lca,x,y,dist+1);
    bool right=LCA(root->right,lca,x,y,dist+1);
    if(left && right)
     {
        lca=root->data;
        lca_dist=dist;
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
	root->left->right = new Node(4);
	root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->right->right = new Node(8);
    int lca=-1;
    LCA(root,lca,root->right->left->left,root->right->right,0);
    
    //dist of both nodes from root - dist of lowest common ancestor from root
    
    if(lca!=-1)
     cout<<(x_dist+y_dist)-(2*lca_dist)<<endl;  
    else
     cout<<"NO"<<endl;
    return 0;
}
