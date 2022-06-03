 //O(N)

 int maxPathSumUtil(Node* root,int &sum){
       if(root==NULL)
        return 0;
       if(root->left==NULL && root->right==NULL)
        return root->data;
       int lSum=maxPathSumUtil(root->left,sum);
       int rSum=maxPathSumUtil(root->right,sum);
       
       // If both left and right children exists
       if(root->left!=NULL && root->right!=NULL){
           sum=max(sum,lSum+rSum+root->data);
           return max(lSum,rSum)+root->data;
       }
        // If any of the two children is empty, return
       // root sum for root being on one side
       return (root->left!=NULL)?root->data+lSum:root->data+rSum;
   }

    int maxPathSum(Node* root)
    {
        // code here
        int sum=INT_MIN;
        int res=maxPathSumUtil(root,sum);
        return sum==INT_MIN?res:sum;
    }