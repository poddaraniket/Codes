pair<bool,int> isSum(Node* root){
        if(root==NULL)
         {
             pair<bool,int> p=make_pair(true,0);
             return p;
         }
        if(root->left==NULL && root->right==NULL){
             pair<bool,int> p=make_pair(true,root->data);
             return p;
        } 
        
        pair<bool,int> left=isSum(root->left);
        pair<bool,int> right=isSum(root->right);
        
        bool isSumLeft=left.first;
        bool isSumRight=right.first;
        
        // lefttreeSum(left.second)
        //righttreeSum(right.second)
        int sum=left.second+right.second;
        
        pair<bool,int> ans;
        ans.first=isSumLeft && isSumRight && (root->data==sum)?true:false;
        ans.second=root->data+sum;
        return ans;
    }
    
    bool isSumTree(Node* root)
    {
         // Your code here
         pair<bool,int> ans=isSum(root);
         return ans.first;
    }