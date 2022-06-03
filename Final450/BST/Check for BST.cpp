void inorder(Node *root,vector<int> &v){
        if(root==NULL)
         return;
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    bool isBST(Node* root) 
    {
        // Your code here
        vector<int> v;
        inorder(root,v);
        for(int i=0;i<v.size()-1;i++)
         {
             if(v[i]>=v[i+1])
              return false;
         }
        return true; 
    }