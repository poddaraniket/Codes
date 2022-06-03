int maxLevel=-1;
    void lefttViewUtil(TreeNode *root,int level,vector<int> &v)
    {
        if(root==NULL)
            return;
        if(maxLevel<level){
            v.push_back(root->val);
      // cout<<root->data<<endl;
            maxLevel=level;
        }    
   //cout<<root->data<<" ";
        leftViewUtil(root->left,level+1,v);
        leftViewUtil(root->right,level+1,v);
}
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        leftViewUtil(root,0,v);
        return v;
    }