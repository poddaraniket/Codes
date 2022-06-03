#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node {
public:
    int data;
    node* left;
    node* right;
};
 
// A utility function to create a node
node* newNode(int data)
{
    node* temp = new node();
 
    temp->data = data;
    temp->left = temp->right = NULL;
 
    return temp;
}

node* constructTreeUtil(int pre[],int s,int e,int &preindex,int size){
    if(preindex>=size|| s>e)
     return NULL;
    node *root=newNode(pre[preindex]);
    preindex++; 
    if(s==e)
     return root;
    int index=s;
    int t=pre[s];
    while(index<=e)
     {
        if(t<pre[index])
         break;
        index++; 
     }
    //low =preindex bocz preindex-1 already put in tree now after that will be left subtree 
    root->left=constructTreeUtil(pre,preindex,index-1,preindex,size); 
    root->right=constructTreeUtil(pre,index,e,preindex,size);
    return root;
}

node* constructTree(int pre[],int size){
    
    int start=0,end=size-1,preindex=0;
    return constructTreeUtil(pre,start,end,preindex,size);
}

void printInorder(node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}
 

int main()
{
    int pre[] = { 10, 5, 1, 7, 40, 50 };
    int size = sizeof(pre) / sizeof(pre[0]);
 
    node* root = constructTree(pre, size);
 
    cout << "Inorder traversal of the constructed tree: \n";
    printInorder(root);
 
    return 0;
}
 
