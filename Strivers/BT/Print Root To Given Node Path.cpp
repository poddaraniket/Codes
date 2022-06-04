/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
bool solveUtil(TreeNode* root,int B,vector<int> &v){
 for(int i=0;i<v.size();i++){
     cout<<v[i]<<endl;
 }
 if(root->val==-1)
  return false;
 
 if(root->val==B){
     v.push_back(B);
     return true;
 }  
v.push_back(root->val); 
 if(solveUtil(root->left,B,v) || solveUtil(root->right,B,v))
  return true;
 v.pop_back();
 return false;
}
vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> v;
    solveUtil(A,B,v);
    return v;
}
