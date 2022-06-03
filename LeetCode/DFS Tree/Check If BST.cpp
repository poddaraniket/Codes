#include<bits/stdc++.h> 

using namespace std; 

struct Treenode 
{ 
  int val; 
  Treenode* left; 
  Treenode* right; 
  Treenode(int data) 
  { 
    this->data = data; 
    this->left = NULL; 
    this->right = NULL; 
  } 
};


bool isValidBSTUtil(TreeNode* root,long long int min,long long int max)
{
  if(root==NULL)
     return true;
  if((long long int)root->val<=min || (long long int)root->val>=max)
    {
         // cout<<max<<endl;  
      return false;   
    }
  return isValidBSTUtil(root->left,min,root->val) && isValidBSTUtil(root->right,root->val,max);
}


bool isValidBST(TreeNode* root)
{
  return isValidBSTUtil(root,-2147483650,2147483650);
}


int main() 
{ 
  Treenode *root = new Treenode(4); 
  root->left = new Treenode(2); 
  root->right = new Treenode(5); 
  root->left->left = new Treenode(1); 
  root->left->right = new Treenode(3); 
  
  if(isBST(root)) 
    cout<<"Is BST"; 
  else
    cout<<"Not a BST"; 
    
  return 0; 
} 
