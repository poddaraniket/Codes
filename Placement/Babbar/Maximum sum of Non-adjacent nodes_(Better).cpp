pair<int,int> getMaxSumUtil(Node *root) {
        if(root==NULL)
         {
             pair<int,int> p=make_pair(0,0);
             return p;
         }
        pair<int,int> leftSum=getMaxSumUtil(root->left);
        pair<int,int> rightSum=getMaxSumUtil(root->right);
        
        //include,exclude
        pair<int,int> ans;
        // when include obviuosly take the excluded data and add the current
        ans.first=leftSum.second+rightSum.second+root->data;
        // when exclude current data
        // yuo can take either of the included o excluded data from each side
        ans.second=max(leftSum.first,leftSum.second)+max(rightSum.first,rightSum.second);
        return ans;
    }
    
    int getMaxSum(Node *root) 
    {
        // Add your code here
        pair<int,int> ans=getMaxSumUtil(root);
        return max(ans.first,ans.second);
    }