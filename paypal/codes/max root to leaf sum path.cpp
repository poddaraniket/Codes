int maxPathSum(Node* root)
    {
        //code here
        if(root==NULL)
         return 0;
        int left=maxPathSum(root->left);
        int right=maxPathSum(root->right);
        return max(left,right)+root->data;
    }