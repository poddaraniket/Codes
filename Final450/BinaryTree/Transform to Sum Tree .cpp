int convert(Node* root)
    {
        if(root==NULL)
          return 0;
        int temp=root->data;
        root->data=convert(root->left)+convert(root->right);
        return temp+root->data;
    }
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        // Your code here
        convert(node);
    }