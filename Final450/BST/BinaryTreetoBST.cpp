void inorder(Node*root,vector<int> &v){
        if(root==NULL)
         return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    
    void binaryTreeToBSTUtil(Node *root,vector<int> &v,int &p)
    {
        if(root==NULL)
         return;
        binaryTreeToBSTUtil(root->left,v,p);
        root->data=v[p++];
        binaryTreeToBSTUtil(root->right,v,p);
    }
    
    Node *binaryTreeToBST (Node *root)
    {
        //Your code goes here
        vector<int> v;
        inorder(root,v);
        sort(v.begin(),v.end());
        int p=0;
        binaryTreeToBSTUtil(root,v,p);
        return root;
    }