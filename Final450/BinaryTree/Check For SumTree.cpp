int isSumTreeHelper(Node* root){
        if(root==NULL)
         {
             return 0;
         }
        if(root->data==isSumTreeHelper(root->left)+isSumTreeHelper(root->right))
          
        return root->data; 
    }
    
    int sum(Node *root)
    {
        if(root==NULL)
         return 0;
        return sum(root->left)+root->data+sum(root->right); 
    }
    
    bool isSumTree(Node* root)
    {
         // Your code here
         if(root==NULL || (root->left==NULL && root->right==NULL))
          return true;
          
         int ls=sum(root->left);
         int rs=sum(root->right);
         
         if(root->data==ls+rs && isSumTree(root->left) && isSumTree(root->right))
          return true;
         return false; 
    }