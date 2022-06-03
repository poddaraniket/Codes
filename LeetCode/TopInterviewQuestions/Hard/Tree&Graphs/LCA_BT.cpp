//O(N)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root==NULL)
            return NULL;
        
        if(root->val==p->val || root->val==q->val)
            return root;
        
        TreeNode* leftSide=lowestCommonAncestor(root->left,p,q);
        TreeNode* rightSide=lowestCommonAncestor(root->right,p,q);
        
        if(leftSide && rightSide)
            return root;
        
        
        return (leftSide) ? leftSide : rightSide;
        
    }
};