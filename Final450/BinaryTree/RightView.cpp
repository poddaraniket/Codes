int maxLevel=-1;
    void rightViewUtil(TreeNode *root,int level,vector<int> &v)
    {
        if(root==NULL)
            return;
        if(maxLevel<level){
            v.push_back(root->val);
      // cout<<root->data<<endl;
            maxLevel=level;
        }    
   //cout<<root->data<<" ";
        rightViewUtil(root->right,level+1,v);
        rightViewUtil(root->left,level+1,v);
}
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        rightViewUtil(root,0,v);
        return v;
    }