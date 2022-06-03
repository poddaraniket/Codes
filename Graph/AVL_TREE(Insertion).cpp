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

Node *Balance(Node *node,int key)
{
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
    
    
    return Balance(node,key); 
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
    Node *root=NULL;
    root = insert(root, 10);  
    root = insert(root, 20);  
    root = insert(root, 30);  
    root = insert(root, 40);  
    root = insert(root, 50);  
    root = insert(root, 25);  
    
    preorder(root);
    return 0;
}
