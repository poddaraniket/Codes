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
    int total=0;
public:
    
    void findPathSum(TreeNode* root, int sum,int currsum)
    {
        if(root==NULL)
            return;
        currsum+=root->val;
        if(sum==currsum)
           total++;
        findPathSum(root->left,sum,currsum);
        findPathSum(root->right,sum,currsum);
    }
    
    int pathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return 0;
        findPathSum(root,sum,0);
        pathSum(root->left,sum);
        pathSum(root->right,sum);
        return total;
    }
};