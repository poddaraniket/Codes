/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int diameterOfBinaryTreeUtil(TreeNode* root,int &maxi_diameter)
    {
       if(root==NULL)
           return 0;
       int left_ht=diameterOfBinaryTreeUtil(root->left,maxi_diameter);
       int right_ht=diameterOfBinaryTreeUtil(root->right,maxi_diameter);
       int diameter=left_ht+right_ht+1; 
       maxi_diameter=max(maxi_diameter,diameter);
       return max(left_ht,right_ht)+1; 
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
      //maxi_diameter will give you the max no. of nodes in path
       int maxi_diameter=0;
       if(root==NULL)
           return 0;
       diameterOfBinaryTreeUtil(root,maxi_diameter);
       return maxi_diameter-1;
    }
};