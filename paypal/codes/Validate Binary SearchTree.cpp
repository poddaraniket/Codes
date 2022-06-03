#include<bits/stdc++.h>
 
using namespace std;
 
/* A binary tree node has data,
pointer to left child and
a pointer to right child */
class node
{
    public:
    int data;
    node* left;
    node* right;
     
    /* Constructor that allocates
    a new node with the given data
    and NULL left and right pointers. */
    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};
 
int isBSTUtil(node* node, int min, int max);
 
/* Returns true if the given
tree is a binary search tree
(efficient version). */
int isBST(node* node)
{
    return(isBSTUtil(node, INT_MIN, INT_MAX));
}
 
/* Returns true if the given
tree is a BST and its values
are >= min and <= max. */
int isBSTUtil(node* root, int min, int max)
{
   if(root==NULL) 
    return 1;
   if(root->data<min || root->data>max)
    return 0;
   return isBSTUtil(root->left,min,root->data-1) && isBSTUtil(root->right,root->data+1,max);    
}
 
 
/* Driver code*/
int main()
{
    node *root = new node(4);
    root->left = new node(2);
    root->right = new node(5);
    root->left->left = new node(1);
    root->left->right = new node(3);
     
    if(isBST(root))
        cout<<"Is BST";
    else
        cout<<"Not a BST";
         
    return 0;
}