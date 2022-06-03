#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};
 
/* Helper function that allocates a new node
   with the given data and NULL left and right
   pointers. */
struct Node* getNode(int data)
{
    struct Node *newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void inorder(Node *root,vector<int> &v){
    if(root==NULL)
     return;
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

void convertToMinHeap(Node* root,vector<int> &v,int &i){
    if(root==NULL) 
     return;
    root->data=v[i++];
    convertToMinHeap(root->left,v,i);
    convertToMinHeap(root->right,v,i);
}

void convertToMinHeapUtil(Node *root){
    vector<int> arr;
    inorder(root,arr);
    int i=0;
    convertToMinHeap(root,arr,i);
}

void preorderTraversal(Node *root)
{
    if(root==NULL) 
     return;
    cout<<root->data<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main()
{
    struct Node *root = getNode(4);
    root->left = getNode(2);
    root->right = getNode(6);
    root->left->left = getNode(1);
    root->left->right = getNode(3);
    root->right->left = getNode(5);
    root->right->right = getNode(7);
 
    convertToMinHeapUtil(root);
    cout << "Preorder Traversal:" << endl;
    preorderTraversal(root);
 
    return 0;
}