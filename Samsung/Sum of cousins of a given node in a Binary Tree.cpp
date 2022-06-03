//O(N)

#include <bits/stdc++.h>
using namespace std;
 
// A Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};
 
// A utility function to create a new
// Binary Tree Node
struct Node* newNode(int item)
{
    struct Node* temp = new Node();
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Function to find sum of cousins of
// a given node.
int findCousinSum(Node* root, int key)
{
    if(root==NULL)
     return -1;
    if(root->data==key)
     return -1;
    int found=false; 
    queue<Node*> q;
    q.push(root);
    int currSum=0;
    while(!q.empty())
     {
        if(found==true)
         return currSum;
        currSum=0;
        int size=q.size();
        while(size--)
        {
            Node *temp=q.front();
            q.pop();
            if((temp->left && temp->left->data==key) || (temp->right && temp->right->data==key))
             found =true;
            else
            {
                if(temp->left){
                    currSum+=root->left->data;
                    q.push(temp->left);
                }
                if(temp->right){
                    currSum+=root->right->data;
                    q.push(temp->right);
                }
            }
        }
     }
    return -1; 
}
 
// Driver Code
int main()
{
    /*
                1
              /  \
             3    7
           /  \  / \
          6   5  4  13
             /  / \
            10 17 15
    */
 
    struct Node* root = newNode(1);
    root->left = newNode(3);
    root->right = newNode(7);
    root->left->left = newNode(6);
    root->left->right = newNode(5);
    root->left->right->left = newNode(10);
    root->right->left = newNode(4);
    root->right->right = newNode(13);
    root->right->left->left = newNode(17);
    root->right->left->right = newNode(15);
 
    cout << findCousinSum(root, 13) << "\n";
 
    cout << findCousinSum(root, 7) << "\n";
    return 0;
}
