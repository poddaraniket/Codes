int digits[10]={0};
    
    bool isPalindrome()
    {
        int count=0;
        for(int i=0;i<10;i++)
        {
            if(digits[i]%2!=0)
                 count++;
        }
        return count>1?false:true;
    }
    
    void path(TreeNode* root,int &result)
    {
        if(root==NULL)
        {
            return;
        }
        digits[root->val]++;
        if(root->left==NULL && root->right==NULL)
         {
             if(isPalindrome())
                result++;
         }
        else
         {
            path(root->left,result);
            path(root->right,result);
         }
       // backtrack 
        digits[root->val]--;
    }
    
    int pseudoPalindromicPaths (TreeNode* root) {
        int result=0;
        path(root,result);
        return result;
    }