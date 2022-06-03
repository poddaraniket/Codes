//O(N)

class Solution {
public:
    
    bool isSymetricUtil(TreeNode* root1,TreeNode* root2){
        if(root1==NULL && root2==NULL)
            return true;
        if(root1==NULL || root2==NULL)
            return false;
        
        int rootData1=root1->val;
        int rootData2=root2->val;
        
        bool extremeSym=isSymetricUtil(root1->left,root2->right);
        bool midSym=isSymetricUtil(root1->right,root2->left);
        return (rootData1==rootData2 && extremeSym && midSym);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)
            return true;
        return isSymetricUtil(root->left,root->right);
    }
};