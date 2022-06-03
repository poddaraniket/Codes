#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};


void diagonalPrint(Node* root)
{
    if(root==NULL)
     return;
    
    queue<Node*> q;
    queue<int> slope;
    q.push(root);
    slope.push(0);
    map<int,vector<int>> values;
    while(!q.empty()){
        Node *temp=q.front();
        q.pop();
        int s=slope.front();
        slope.pop();
        values[s].push_back(temp->data);
        if(temp->left)
         {
            q.push(temp->left);
            slope.push(s-1);
         }
        if(temp->right)
         {
            q.push(temp->right);
            slope.push(s);
         }
    }
    for(auto it=values.begin();it!=values.end();it++)
    {
        vector<int> v=it->second;
        for(int i=0;i<v.size();i++)
          cout<<v[i]<<" ";
        cout<<endl;  
    }
}

Node* newNode(int data)
{
    Node* node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
 
// Driver program
int main()
{
    Node* root = newNode(8);
    root->left = newNode(3);
    root->right = newNode(10);
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
 
    /*  Node* root = newNode(1);
        root->left = newNode(2);
        root->right = newNode(3);
        root->left->left = newNode(9);
        root->left->right = newNode(6);
        root->right->left = newNode(4);
        root->right->right = newNode(5);
        root->right->left->right = newNode(7);
        root->right->left->left = newNode(12);
        root->left->right->left = newNode(11);
        root->left->left->right = newNode(10);*/
 
    diagonalPrint(root);
 
    return 0;
}