int result=INT_MIN;
    
    int maxPathSumUtil(TreeNode* root){
        if(root==NULL)
          return 0;
        int leftSide=maxPathSumUtil(root->left);
        int rightSide=maxPathSumUtil(root->right);
        
        //Case 1: [sending max path sum to parent]
        int maxStraight=max(max(leftSide,rightSide)+root->val,root->val);
        
        //Case 2:[max subtree]
        int maxSub=max(maxStraight,root->val+leftSide+rightSide);
        result=max(result,maxSub);
        
        return maxStraight;        
    }
    
    int maxPathSum(TreeNode* root) {
       
        maxPathSumUtil(root);
        return result;
    }