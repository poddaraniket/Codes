// Left -> Right && Root -> left  ("->" means connect)
    
    TreeNode* find(TreeNode* root){
        TreeNode *temp=root->left;
        while(temp->right!=NULL){
            temp=temp->right;
        }
        return temp;
    }
    
    void flatten(TreeNode* root) {
        while(root!=NULL)
        {
            if(root->left!=NULL)
            {
                TreeNode *predecesor=find(root);
                // Left -> Right
                predecesor->right=root->right;

                // Root -> left
                root->right=root->left;
                
                //Make left part NULL
                root->left=NULL;
            }
          root=root->right;
        }
    }