//O(N)


#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left,*right;
    Node(int data)
    {
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

int leftdist=-1,rightdist=-1;

void printkdistanceNodedown(Node *root,int k)
{
    if(root==NULL || k<0)
     return;
    if(k==0)
     {
         cout<<root->data<<" ";
         return;
     }
    printkdistanceNodedown(root->left,k-1);
    printkdistanceNodedown(root->right,k-1);
}

int printkdistanceNode(Node *root,Node *target,int k)
{
    if(root==NULL)
     return -1;
    if(root==target)
     {
        printkdistanceNodedown(root,k);
        return 0;
     }
    int leftdist=printkdistanceNode(root->left,target,k);
    if(leftdist!=-1)
     {
        if(leftdist+1==k)
         cout<<root->data<<" ";
        else
         printkdistanceNodedown(root->right,k-2-leftdist);
        return 1+leftdist; 
     }
    int rightdist=printkdistanceNode(root->right,target,k);
    if(rightdist!=-1)
     {
        if(rightdist+1==k)
         cout<<root->data<<" ";
        else
         printkdistanceNodedown(root->left,k-2-rightdist);
        return 1+rightdist; 
     }
    return -1;
}

int main() {
	// your code goes here
	Node * root = new Node(20); 
    root->left = new Node(8); 
    root->right = new Node(22); 
    root->left->left = new Node(4); 
    root->left->right = new Node(12); 
    root->left->right->left = new Node(10); 
    root->left->right->right = new Node(14); 
    Node * target = root->left->right; 
    printkdistanceNode(root, target, 2); 
	return 0;
}
