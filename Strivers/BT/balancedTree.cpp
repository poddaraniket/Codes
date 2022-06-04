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
    
    pair<int,int> isBalancedUtil(TreeNode* root){
        if(root==NULL){
            return {true,0};
        }
        
        pair<int,int> left=isBalancedUtil(root->left);
        pair<int,int> right=isBalancedUtil(root->right);
        
        bool leftBalance=left.first;
        bool rightBalance=right.first;
        int lHeight=left.second;
        int rHeight=right.second;
        pair<int,int> ans;
        
        ans.first= abs(lHeight-rHeight)<=1 ? leftBalance && rightBalance : false;
        ans.second=max(lHeight,rHeight)+1;
        return ans;
    }
    
    bool isBalanced(TreeNode* root) {
        pair<bool,int> ans=isBalancedUtil(root);
        return ans.first;
    }
};