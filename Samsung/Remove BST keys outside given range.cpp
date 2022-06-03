//O(N)
Node* removekeys(Node* root, int l, int r) {
        // code here
        if(root==NULL)
         return NULL;
        root->left=removekeys(root->left,l,r);
        root->right=removekeys(root->right,l,r);
        
        // all values to its left child will be smaller then l take its right side
        if(root->data<l) 
         {
             Node *rChild=root->right;
             delete root;
             return rChild;
         }
        // all values to its right child will be smaller then l take its left side 
        if(root->data>r)
         {
             Node *lChild=root->left;
             delete root;
             return lChild;
         }
        return root; 
    }