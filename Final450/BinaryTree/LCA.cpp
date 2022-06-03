Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root==NULL)
        return NULL;
       if(root->data==n1 || root->data==n2)
         {
            return root;
         }
        Node *left=lca(root->left,n1,n2);
        Node *right=lca(root->right,n1,n2);
        // recieving not null from both side shows that we have got the LCA
        if(left!=NULL && right!=NULL)
         return root;
        // recieving null from both side shows that number not found 
        if(left==NULL && right==NULL)
         return NULL;
        // if one is found return the parent of it 
        return left!=NULL?left:right; 
    }