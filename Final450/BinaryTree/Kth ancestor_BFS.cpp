#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};
  

Node* newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

Node* kthAncestorDFS(Node *root, int node , int &k)
{
    if(root==NULL)
     return NULL;
    map<Node*,Node*> mp;
    queue<Node*> q;
    q.push(root);
    mp[root]=NULL;
    Node *t=NULL;
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        if(temp->data==node)
         {
            t=temp; 
            break; 
         }
        if(temp->left)
         {
            q.push(temp->left);
            mp[temp->left]=temp;
         }
        if(temp->right)
         {
            q.push(temp->right);
            mp[temp->right]=temp;
         } 
    }
    while(k){
        Node *temp=mp[t];
        if(temp==NULL)
         return NULL;
        t=temp;
       // cout<<t->data<<endl;
        --k;
    }
    //cout<<t<<endl;
    return t;
}

int main()
{
    // Let us create binary tree shown in above diagram
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
  
    int k = 3;
    int node = 5;
  
    // print kth ancestor of given node
    Node* parent = kthAncestorDFS(root,node,k);
      
    // check if parent is not NULL, it means
    // there is no Kth ancestor of the node
    if (parent==NULL)
        cout << "-1"<<endl;
    else
     cout<<parent->data<<endl;
    return 0;
}