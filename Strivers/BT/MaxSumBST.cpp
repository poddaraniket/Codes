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

class Info{
public:
    int ans;
    int min;
    int max;
    bool isBST;
};

class Solution {
public:
    
    int maxs=0;
    
    Info solve(TreeNode* root){
        if(root==NULL)
            return {0,INT_MAX,INT_MIN,true};
        if(root->left==NULL && root->right==NULL){
            maxs=max(maxs,root->val);
            return {root->val,root->val,root->val,true}; 
        }
        
        Info ls=solve(root->left);
        Info rs=solve(root->right);
        
        Info rt;
        
        bool childBST=ls.isBST && rs.isBST;

        if(childBST && ls.max<root->val && rs.min>root->val){
            rt.isBST=true;
            rt.ans=ls.ans+rs.ans+root->val;
            maxs=max(maxs,rt.ans);
            rt.max=max(rs.max,root->val);
            rt.min=min(ls.min,root->val);
            return rt;    
        }
        rt.isBST=false;
        rt.min=INT_MIN;
        rt.max=INT_MAX;
        rt.ans=max(ls.ans,rs.ans);
        return rt;
    }
    
    int maxSumBST(TreeNode* root) {
        Info maxBST=solve(root);  
        return maxs;
    }
};