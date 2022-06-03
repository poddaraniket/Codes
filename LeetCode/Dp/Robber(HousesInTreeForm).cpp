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
    unordered_map<TreeNode*,int> mp;
public:
    int rob(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(mp[root]!=0)
            return mp[root];
        int total=0;
        if(root->left)
            total+=rob(root->left->left)+rob(root->left->right);
        if(root->right)
            total+=rob(root->right->left)+rob(root->right->right);
        mp[root]=max(root->val+total,rob(root->left)+rob(root->right));
        return mp[root];
    }
};