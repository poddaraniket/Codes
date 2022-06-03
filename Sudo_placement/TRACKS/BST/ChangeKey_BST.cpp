#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node
{
	int key;
	struct node *left;
	struct node *right;
	
	node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

struct node* insert(struct node* root, int key)
{

	if (root == NULL) return (new node(key));
	if (key < root->key)
		root->left = insert(root->left, key);
	else
		root->right = insert(root->right, key);
	return root;
}

// Function to change a key value in Binary Search Tree
struct node *changeKey(struct node *root, int oldVal, int newVal);

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        struct node *root = NULL;
        int n, temp, oldKey, new_key;
        cin>>n;
        while(n--)
        {
            cin>>temp;
            root = insert(root, temp);
        }
        cin>>oldKey;
        cin>>new_key;
        root = changeKey(root, oldKey, new_key);
        inorder(root);
        printf("\n");
    }
	return 0;
}


// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct node
{
	int key;
	struct node *left, *right;
};
*/
// your task is to complete the Function
// Function is used to change a key value in the given BST
// Note: Function should return root node to the new modified BST

// struct node *insertk(struct node *root,int k)
// {
//     if (root == NULL) 
//       return new struct node(k); 
  
//     /* Otherwise, recur down the tree */
//     if (k<root->key) 
//         root->left  = insert(root->left, k); 
//     else if (k>root->key) 
//         root->right = insert(root->right, k);    
  
//     /* return the (unchanged) node pointer */
//     return root;
// }

struct node* shiftNode(struct node *node,struct node *temp)
{
    if(node==NULL)
     return temp;
    node->left=shiftNode(node->left,temp);
    return node;
}
struct node* del(struct node *root,int k)
{
    //cout<<"*";
    if(k<root->key)
     {
        root->left=del(root->left,k); 
     }
    else if(k>root->key)
     {
        root->right=del(root->right,k); 
     }
    else
    {
        if(root->left==NULL)
         {
             struct node *temp=root->right;
             return temp;
         }
        else if(root->right==NULL)
         {
             struct node *temp=root->left;
             return temp;
         }
        else
         {
             struct node *temp=root->right;
             struct node *curr=root->left;
             temp=shiftNode(temp,curr);
             return temp;
         }
    }
 return root;    
}

struct node *changeKey(struct node *root, int oldVal, int newVal)
{
	// Code here
	if(root==NULL)
    return root;
   root=del(root,oldVal);
   root=insert(root,newVal);
   return root;
}