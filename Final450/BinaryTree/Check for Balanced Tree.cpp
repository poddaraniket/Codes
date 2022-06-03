int height(Node *root)
{
    if(root==NULL)
     return 0;
    return max(height(root->left),height(root->right))+1; 
}

//Function to check whether a binary tree is balanced or not.
bool isBalanced(Node *root)
{
    //  Your Code here
    if(root==NULL)
     return true;
    int lheight=height(root->left);
    int rheight=height(root->right);
    if(isBalanced(root->left) && isBalanced(root->right) && abs(lheight-rheight)<2)
     return true;
    return false;
}
