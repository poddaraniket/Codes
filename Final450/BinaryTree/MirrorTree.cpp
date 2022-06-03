#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
 
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};
  
void inorder(Node* root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


void mirrorify(Node* root)
{
    if(root==NULL)
     {
        return;
     }
    Node *t=root->left;
    root->left=root->right;
    root->right=t;
    
    if(root->left)
     mirrorify(root->left);
    if(root->right)
     mirrorify(root->right);
} 

int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */
 
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    inorder(root);
    cout<<endl;
    mirrorify(root);
    inorder(root);
 
    return 0;
}

