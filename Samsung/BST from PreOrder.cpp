TreeNode* newNode(int data)
    {
        TreeNode *temp=(TreeNode*)malloc(sizeof(TreeNode));
        temp->val=data;
        temp->left=temp->right=NULL;
        return temp;
    }
    
     TreeNode* constructTreeUtil(vector<int>& pre,int &index,int key,int mini,int maxi,int n)
    {
        if(index>=n || key<=mini || key>=maxi)
         return NULL;
        TreeNode *root=newNode(key);
        index++;
        root->left=constructTreeUtil(pre,index,pre[index],mini,key,n);
        root->right=constructTreeUtil(pre,index,pre[index],key,maxi,n);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& pre) {
        int n=pre.size();
        int index=0;
        TreeNode *root=constructTreeUtil(pre,index,pre[index],INT_MIN,INT_MAX,n);
        return root;
    }