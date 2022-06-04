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
    
    
    int maxPathSumUtil(TreeNode* root,int &ans){
        if(root==NULL){
            return 0;
        }
        
        int data=root->val;
        
        int leftSum=maxPathSumUtil(root->left,ans);
        int rightSum= maxPathSumUtil(root->right,ans);
        int excludeSubtree=max(max(leftSum,rightSum)+data,data);
        int includeSubtree=leftSum+rightSum+data;
        ans=max(ans,max(excludeSubtree,includeSubtree));
        return excludeSubtree;
    } 
    
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        maxPathSumUtil(root,ans);
        return ans;
        
    }
};