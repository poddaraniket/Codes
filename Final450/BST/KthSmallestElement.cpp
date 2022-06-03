void KthSmallestElementUtil(Node* root,int &k,int &val){
        if(root==NULL || k<0)
         return;
        KthSmallestElementUtil(root->left,k,val);
        k--;
        if(k==0){
         val=root->data;
            return;
        }
        KthSmallestElementUtil(root->right,k,val); 
    }
    
    int KthSmallestElement(Node *root, int K)
    {
        //add code here.
        if(root==NULL)
         return -1;
        int val=-1; 
        KthSmallestElementUtil(root,K,val);
        return val;
    }