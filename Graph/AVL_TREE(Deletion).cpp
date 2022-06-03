//O(log n) for insertion while O(1) for rotaion
//O(h) as roataion takes constant time uodating the height and gettig the balance factor also takes constant time

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left,*right;
    int height;
};

Node* newNode(int key)
{
    Node *node=new Node();
    node->data=key;
    node->left=NULL;
    node->right=NULL;
    node->height=1;
    return(node);
}

int height(Node *N)
{
    if(N==NULL)
     return 0;
    return N->height; 
}

int getBalance(Node* N)
{
    if(N==NULL)
      return 0;
    return height(N->left)-height(N->right);  
}

Node* getRightRotate(Node* z)
{
    Node *y=z->left;
    Node *t=y->right;
    
    y->right=z;
    z->left=t;
    
    z->height=max(height(z->left),height(z->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    
    return y;
}

Node* getLeftRotate(Node* x)
{
    Node *y=x->right;
    Node *t=y->left;
    
    y->left=x;
    x->right=t;
    
    x->height=max(height(x->left),height(x->right))+1;
    y->height=max(height(y->left),height(y->right))+1;
    
    return y;
}

Node* insert(Node *node,int key)
{
    if(node==NULL)
     return(newNode(key));
     
    if(key<node->data)
     node->left=insert(node->left,key);
    else if(key>node->data)
     node->right=insert(node->right,key);
    else 
     return node;
    
    //balancing after Insertion

    node->height=max(height(node->left),height(node->right))+1;
    
    int balance=getBalance(node);
    
    //left left
    if(balance>1 && key<node->left->data)
     return getRightRotate(node);
    
    //right right
    if(balance<-1 && key>node->right->data)
     return getLeftRotate(node);
    
    //left right
    if(balance>1 && key>node->left->data)
     {
        node->left=getLeftRotate(node->left);
        return getRightRotate(node);
     }
    
    //Right left
    if(balance<-1 && key<node->right->data)
     {
        node->right=getRightRotate(node->right);
        return getLeftRotate(node);
     }
    return node; 
}

Node* insertdelete(Node* rt,Node *lt)
{
    if(rt==NULL)
     return lt;
    rt->left=insertdelete(rt->left,lt);
    return rt;
}

//deletion is same as BST Deletion

Node* deleteNode(Node *root,int key)
{
    if(root==NULL)
     return NULL;
    if(key<root->data)
     root->left=deleteNode(root->left,key);
    else if(key>root->data)
     root->right=deleteNode(root->right,key);
    else
     {
        if(root->left==NULL)
         return root->right;
        else if(root->right==NULL)
         return root->left;
        else
         {
            Node *rt=root->right;
            Node *lt=root->left;
            return insertdelete(rt,lt);
         }
     }
    
    // balancing after deletion
    
    if(root==NULL)
     return root;
    
    int balance=getBalance(root);
    
    /* balncing is the same as in insertion just here instead of finding left left by key we have 
       to check by the balancig factor of its child if positive then left left else left right for
       bf of root as positive
    */
    
    // its is left rotaion 
    if(balance>1) 
     {
     // left left    
      if(getBalance(root->left)>=0)
       {
        return getRightRotate(root); 
       }
     //its left right 
      else
       {
        root->left=getLeftRotate(root->left);
        return getRightRotate(root);
       }
     }
    // its is right rotaion 
    else if(balance<-1)
     {
        // right right    
      if(getBalance(root->right)<0)
       {
        return getLeftRotate(root); 
       }
     //its right left 
      else
       {
        root->right=getRightRotate(root->right);
        return getLeftRotate(root);
       } 
     }
    else 
     return root;
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
    Node *root = NULL;
    root = insert(root, 9); 
    root = insert(root, 5); 
    root = insert(root, 10); 
    root = insert(root, 0); 
    root = insert(root, 6); 
    root = insert(root, 11); 
    root = insert(root, -1); 
    root = insert(root, 1); 
    root = insert(root, 2); 
    
    preorder(root);
    
    root = deleteNode(root, 10); 
    cout<<endl;
    
    preorder(root);
    return 0;
}
