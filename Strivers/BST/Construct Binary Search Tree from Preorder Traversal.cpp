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
    
    // index whose value is larger then root
    int search(vector<int> &preorder,int s,int e){
        int val=preorder[s];
        for(int i=s+1;i<=e;i++){
            if(preorder[i]>val){
                return i;
            }
        }
        return e+1;
    }
    
    TreeNode* solve(vector<int> &preorder,int s,int e){
        if(s==e){
            TreeNode* root=new TreeNode(preorder[s]);
            return root;
        }
        if(s>e)
            return NULL;
        TreeNode* root=new TreeNode(preorder[s]);
        int index=search(preorder,s,e);
        root->left=solve(preorder,s+1,index-1);
        root->right=solve(preorder,index,e);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int s=0,e=preorder.size()-1;
        TreeNode* root=solve(preorder,s,e);
        return root;
    }
};