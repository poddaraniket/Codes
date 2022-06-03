#include <bits/stdc++.h>
using namespace std;
 
struct Node
{
    int val;
    struct Node *left, *right;
};
 
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->val = data;
    temp->left = temp->right =  NULL;
    return temp;
}

void deepestLeftLeafUtil(Node *root,int level,int &maxlevel,Node **temp,int isLeft)
{
    if(root==NULL)
     return;
    
    if(level>maxlevel && isLeft)
     {
        maxlevel=level;
        *temp=root;
        //return;
     }
    
    deepestLeftLeafUtil(root->left,level+1,maxlevel,temp,true);
    deepestLeftLeafUtil(root->right,level+1,maxlevel,temp,false);
}

Node* deepestLeftLeaf(Node *root)
{
    int maxlevel=0;
    Node *temp=NULL;
    deepestLeftLeafUtil(root,0,maxlevel,&temp,false);
    return temp;
}

int main()
{
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->right->left = newNode(5);
    root->right->right = newNode(6);
    root->right->left->right = newNode(7);
    root->right->right->right = newNode(8);
    root->right->left->right->left = newNode(9);
    root->right->right->right->right = newNode(10);
 
    Node *result = deepestLeftLeaf(root);
    if (result)
        cout << "The deepest left child is " << result->val;
    else
        cout << "There is no left leaf in the given tree";
 
    return 0;
}