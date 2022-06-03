//O(N)

class Solution {
public:
    
    TreeNode* convert(vector<int>& nums,int l,int r){
        if(l>r)
            return NULL;
        int index=(r+l)/2;
        int data=nums[index];
        TreeNode* root=new TreeNode(data);
        root->left=convert(nums,l,index-1);
        root->right=convert(nums,index+1,r);
        return root;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root=convert(nums,0,nums.size()-1);
        return root;
    }
};