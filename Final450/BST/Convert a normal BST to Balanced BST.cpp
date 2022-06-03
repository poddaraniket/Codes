#include <bits/stdc++.h>
using namespace std;
  
struct Node
{
    int data;
    Node* left,  *right;
};

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

void inorder(Node* root,vector<int> &v)
{
    if(root==NULL)
     return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

Node* buildTreeUtil(vector<int> v,int s,int e){
    if(s>e)
     return NULL;
    int m=(s+e)/2; 
    Node *root=newNode(v[m]);
    root->left=buildTreeUtil(v,s,m-1);
    root->right=buildTreeUtil(v,m+1,e);
    return root;
}

Node* buildTree(Node *root){
    if(root==NULL)
     return NULL;
    vector<int> v;
    inorder(root,v);
    Node* node;
    node=buildTreeUtil(v,0,v.size()-1);
    return node;
}
  
/* Function to do preorder traversal of tree */
void preOrder(Node* node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{
    /* Constructed skewed binary tree is
                10
               /
              8
             /
            7
           /
          6
         /
        5   */
  
    Node* root = newNode(10);
    root->left = newNode(8);
    root->left->left = newNode(7);
    root->left->left->left = newNode(6);
    root->left->left->left->left = newNode(5);
  
    root = buildTree(root);
  
    printf("Preorder traversal of balanced "
            "BST is : \n");
    preOrder(root);
}