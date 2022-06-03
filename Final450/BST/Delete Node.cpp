TreeNode* insert(TreeNode *r,TreeNode *l){
        if(l==NULL)
          return r; 
        if(r==NULL)
          return l;
        r->left=insert(r->left,l);
        return r;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) 
         return NULL;
        if(root->val==key){
           if(root->right!=NULL)
            {
               insert(root->right,root->left);
               return root->right;
            }
           return root->left; 
        }
        root->left=deleteNode(root->left,key);
        root->right=deleteNode(root->right,key);
        return root;
    }