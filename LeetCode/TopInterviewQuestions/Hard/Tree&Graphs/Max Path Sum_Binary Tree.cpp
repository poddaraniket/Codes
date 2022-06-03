//O(N)

class Solution {
public:
    
    int maxPathSumUtil(TreeNode* root,int &ans){
        if(root==NULL)
            return 0;
        
        int data=root->val; 
        
        int leftSum=maxPathSumUtil(root->left,ans);
        int rightSum=maxPathSumUtil(root->right,ans);
        
        // Max path for parent call of root. This path must include at-most one child of root
        // sending max to above
        int includeParent=max(max(leftSum,rightSum)+root->val,root->val);
        
        // till here is the actula max
        int excludeParent=leftSum+rightSum+data;
        
        ans=max(ans,max(includeParent,excludeParent));
        
        return includeParent;
    }
    
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        maxPathSumUtil(root,ans);
        return ans;
    }
};