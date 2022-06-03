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
    
    int maxPathSumUtil(TreeNode *root,int &final_max)
    {
        if(root==NULL)
            return 0;
        int left=maxPathSumUtil(root->left,final_max);
        int right=maxPathSumUtil(root->right,final_max);
    /*sum stores the max path sum assumong it is in the path of max sum and not the complete path h
    ence it considers path like either parent of that subtree or it sum with one of the child whichever is max*/
        int sum=max(max(left,right)+root->val,root->val);
    //curr_max stroes assuming that the max path sum is till here so it adds both the child possibility also including sum possibilty
        int curr_max=max(sum,root->val+left+right);
        final_max=max(final_max,curr_max);
        return sum;
    }
    
    int maxPathSum(TreeNode* root) {
        int final_max=-1000000;
        maxPathSumUtil(root,final_max);
        return final_max;
    }
};