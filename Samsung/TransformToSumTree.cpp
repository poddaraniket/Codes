//O(N)

int toSumTreeUtil(Node *node)
    {
        if(node==NULL)
         return 0;
        int oldVal=node->data;
        int left=toSumTreeUtil(node->left);
        int right=toSumTreeUtil(node->right);
        node->data=left+right;
        return oldVal+node->data;
    }
    
    void toSumTree(Node *node)
    {
        // Your code here
        toSumTreeUtil(node); 
    }