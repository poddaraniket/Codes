#include <bits/stdc++.h>
using namespace std;

struct Node { 
    int data; 
    struct Node *left, *right; 
    Node(int key) 
     { 
        this->data=key;
        this->left=NULL;
        this->right=NULL;
     } 
}; 

queue<Node*> q;

int burnTree(Node *root,int target)
{
    if(root==NULL)
     return 0;
    if(root->data==target)
     {
        cout<<root->data<<endl;
        if(root->left!=NULL)
         q.push(root->left);
        if(root->right!=NULL)
         q.push(root->right);
        return 1;
     }
    int a=burnTree(root->left,target);
    if(a==1)
     {
        int size=q.size();
        while(size--)
         {
            Node *temp=q.front();
            cout<<temp->data<<" ";
            q.pop();
            if(temp->left!=NULL)
             q.push(root->left);
            if(temp->right!=NULL)
             q.push(root->right);
         }
        cout<<root->data<<" "<<endl;
        if(root->right!=NULL)
         q.push(root->right);
        return 1; 
     }
    int b=burnTree(root->right,target);
    if(b==1)
     {
        int size=q.size();
        while(size--)
         {
            Node *temp=q.front();
            cout<<temp->data<<" ";
            q.pop();
            if(temp->left!=NULL)
             q.push(root->left);
            if(temp->right!=NULL)
             q.push(root->right);
         }
        cout<<root->data<<" "<<endl;
        if(root->left!=NULL)
         q.push(root->left);
        return 1; 
     }
}
  
int main() {
	// your code goes here
	Node* root = new Node(10); 
    root->left = new Node(12); 
    root->right = new Node(13); 
  
    root->right->left = new Node(14); 
    root->right->right = new Node(15); 
  
    root->right->left->left = new Node(21); 
    root->right->left->right = new Node(22); 
    root->right->right->left = new Node(23); 
    root->right->right->right = new Node(24); 
    int targetNode = 14; 
    
    burnTree(root, targetNode); 
    
    while(!q.empty())
     {
        int size=q.size();
        while(size--)
         {
            Node *temp=q.front();
            q.pop();
            cout<<temp->data<<" ";
         }
     }
	return 0;
}
