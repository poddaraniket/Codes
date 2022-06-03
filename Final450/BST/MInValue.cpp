void minValueUtil(Node *root,int &mini)
{
    if(root==NULL)
     return;
    mini=min(mini,root->data);
    minValueUtil(root->left,mini);
}

int minValue(Node* root)
{
    // Code here
    int mini=root->data;
    minValueUtil(root,mini);
    return mini;
}