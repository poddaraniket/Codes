bool isValidBSTUtil(TreeNode* root,long long int mini,long long int maxi)
    {
        if(root==NULL)
           return true;
        if((long long int)root->val<=mini || (long long int)root->val>=maxi)
           return false;
        bool left=isValidBSTUtil(root->left,mini,root->val);
        bool right=isValidBSTUtil(root->right,root->val,maxi);
        return left && right;
    }
    
    bool isValidBST(TreeNode* root) {
      return isValidBSTUtil(root,-2147483650,2147483650);  
    }