//O(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root==NULL)
            return result;
        stack<TreeNode*> s1,s2;
        s1.push(root);
        vector<int> v;
        int level=0;
        while(!s1.empty()){
           TreeNode *temp=s1.top();
           s1.pop();
           v.push_back(temp->val);
           if(level%2==0){
              if(temp->left)
                  s2.push(temp->left);
              if(temp->right)
                  s2.push(temp->right);
            }
           else{
              if(temp->right)
                  s2.push(temp->right);
              if(temp->left)
                  s2.push(temp->left); 
           }
           if(s1.empty())
           {
               level++;
               s1.swap(s2);
               result.push_back(v);
               v.clear();
           }
        }
        return result;
    }
};