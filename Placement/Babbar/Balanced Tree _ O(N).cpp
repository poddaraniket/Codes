pair<bool,int> isBalancedUtil(TreeNode* root){
        if(root==NULL)
         {
            pair<bool,int> p=make_pair(true,0);
            return p;
         }
        pair<bool,int> left=isBalancedUtil(root->left);
        pair<bool,int> right=isBalancedUtil(root->right);
        
        bool leftBalanced=left.first;
        bool rightBalanced=right.first;
        
        int heightDiff=abs(left.second-right.second);
        
        pair<bool,int> ans;
        ans.first=(leftBalanced && rightBalanced) && (heightDiff<2 ? true:false);
        ans.second=max(left.second,right.second)+1;
        return ans;
    }
    
    bool isBalanced(TreeNode* root) {
      pair<bool,int> ans=isBalancedUtil(root);   
        return ans.first;
    }