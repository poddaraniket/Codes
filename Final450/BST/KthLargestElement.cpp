void kthLargestUtil(Node *root,int &k,int &val){
        if(root==NULL || k<0)
         return;
        kthLargestUtil(root->right,k,val);
        k--;
        if(k==0)
         {
             val=root->data;
         }
        kthLargestUtil(root->left,k,val); 
    }
    
    int kthLargest(Node *root, int K)
    {
        //Your code here
        if(root==NULL)
         return 0;
        int val=-1; 
        kthLargestUtil(root,K,val); 
        return val;
    }