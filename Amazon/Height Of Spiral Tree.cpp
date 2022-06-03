bool isLeaf(Node* root){
    return root->left && root->left->right==root && root->right && root->right->left==root;
}

int findTreeHeight(Node* root)
{
	// Code here
	if(root==NULL)
	  return 0;
	if(isLeaf(root))
	  return 1;
	int left=findTreeHeight(root->left);
	int right=findTreeHeight(root->right);
	return max(left,right)+1;
}