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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)
           return 0; 
        queue<pair<TreeNode*,long long int>> q;
        q.push({root,0});
        long long int ans=0;
        while(!q.empty()){
            int size=q.size();
            //leftmost element will be least indexed
            int minIndex=q.front().second;
            long long int first,last;
            for(int i=0;i<size;i++){
                long long int currId=q.front().second-minIndex;
                TreeNode* temp=q.front().first;
                q.pop();
                if(i==0)
                   first=currId; 
                if(i==size-1)
                   last=currId;
                if(temp->left!=NULL){
                    q.push({temp->left,2*currId+1});
                }
                if(temp->right!=NULL){
                    q.push({temp->right,2*currId+2});
                }
            }
            ans=max(ans,last-first+1);
        }
        return ans;
    }
};