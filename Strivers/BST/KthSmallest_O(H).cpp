/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    stack<TreeNode*> st;
    void solve(TreeNode* root){
        if(root==NULL)
          return;
        st.push(root);
        solve(root->left);
    }
    
    int kthSmallest(TreeNode* root, int k) {
        solve(root);
        while(k>1){
            TreeNode* temp=st.top();
            st.pop();
            solve(temp->right);
            k--;
        }
        return st.top()->val;
    }
};