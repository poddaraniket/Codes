//O(N) -> O(1) 
class Solution {
public:
   
    TreeNode* find(TreeNode* curr){
        TreeNode* node=curr;
        curr=curr->left;
        while(curr->right && curr->right!=node)
            curr=curr->right;
        return curr;
    }
   
    int kthSmallest(TreeNode* root, int k) {
        int kSmall=0,count=0;
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                count++;
                if(count==k)
                    kSmall=curr->val;
                curr=curr->right;
            }
            else{
                TreeNode* predecesor=find(curr);
                if(predecesor->right==NULL){
                    predecesor->right=curr;
                    curr=curr->left;
                }
                else{
                    predecesor->right=NULL;
                    count++;
                    if(count==k)
                        kSmall=curr->val;
                    curr=curr->right;
                }
            }
        }
        return kSmall;
    }
};