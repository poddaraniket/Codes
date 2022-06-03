//O(N)
bool isBSTUtil(Node *root,int mini,int maxi){
        if(root==NULL)
         return 1;
        if(root->data<mini || root->data>maxi)
         return 0;
        return (isBSTUtil(root->left,mini,root->data-1) && isBSTUtil(root->right,root->data+1,maxi));
        
    }
    
    bool isBST(Node* root) 
    {
        // Your code here
        isBSTUtil(root,INT_MIN,INT_MAX);
    }