int height(Node *node)
    {
        if(node==NULL)
         return 0;
        return max(height(node->left),height(node->right))+1; 
    }
    

//  int diameter(Node* root,int &height) 
    int diameter(Node* root) {
        // Your code here
        if(root==NULL){
         // *height=0;
         return 0;
        }


        //int lheight=0,rheight=0;
     

        int lheight=height(root->left);
        int rheight=height(root->right);
        
        // int ldiameter=diameter(root->left,&lheight);
        // int rdiameter=diameter(root->right,&rheight);    
        // *height=max(lheight,rheight)+1;


        int ldiameter=diameter(root->left);
        int rdiameter=diameter(root->right);
        
        return max(max(ldiameter,rdiameter),lheight+rheight+1);
    }