//O(n)

#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node* left, *right;
};
 
/* Utility function to create a new Binary Tree node */
struct node*  newNode(int data)
{
    struct node* temp = new struct node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

int getMaxSumUtil(node* root,unordered_map<node* ,int> dp)
{
    if(root==NULL)
     return 0;
    if(dp[root])
     return dp[root];   //memoization
    int inc=root->data;
    if(root->left)
     {
        inc+=getMaxSumUtil(root->left->left,dp);
        inc+=getMaxSumUtil(root->left->right,dp);
     }
    if(root->right)
    {
        inc+=getMaxSumUtil(root->right->left,dp);
        inc+=getMaxSumUtil(root->right->right,dp);
    }
    int exc=getMaxSumUtil(root->left,dp)+getMaxSumUtil(root->right,dp);
    dp[root]=max(inc,exc);
    return dp[root];
}

int getMaxSum(node* root)
{
    if(root==NULL)
     return 0;
    unordered_map<node* ,int> dp;
    return getMaxSumUtil(root,dp);
}

int main()
{
    node*  root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->left->left = newNode(1);
 
    cout << getMaxSum(root) << endl;
    return 0;
}