//O(N) -> O(N)

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        // map<TreeNode*,TreeNode*> mp1;
        map<int,TreeNode*> mp;
        for(int i=0;i<descriptions.size();i++){
            vector<int> v=descriptions[i];
            int p=v[0];
            int c=v[1];
            TreeNode *parent,*child;
            if(mp.find(p)==mp.end()){
                parent=new TreeNode(p);
                mp[p]=parent;
            }
            else{
                parent=mp[p];
            }
            
            if(mp.find(c)==mp.end()){
                child=new TreeNode(c);
                mp[c]=child;
            }
            else{
                child=mp[c];
            }
            if(v[2]){
                parent->left=child;
            }
            else{
                parent->right=child;
            }
        }
       for(int i=0;i<descriptions.size();i++){
           mp.erase(descriptions[i][1]);
       } 
        return mp.begin()->second;
    }
};