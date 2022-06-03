//O(N) -> traversed all nodes once

int maxDepth(TreeNode* root) {
        if(root==NULL)
          return 0;
        int lDepth=maxDepth(root->left);
        int rDepth=maxDepth(root->right);
        return max(lDepth,rDepth)+1;
    }