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

/*
-1->need camera
1->covered
0->have a camera

*/


class Solution {
public:
    
    int count=0;
    
    int postOrder(TreeNode* root){
        if(root==NULL){
            return 1;
        }
        int leftChild=postOrder(root->left);
        int rightChild=postOrder(root->right);
        if(leftChild==-1 || rightChild==-1){
            count++;
            return 0;
        }
        // if either of its child has camera the prent is covered
        if(leftChild==0 || rightChild==0)
           return 1;  
         // if the parents left and right child is covered and they don't have camera then
         // the parent needs to be covered and it will ask its parent to cover him
         //if(leftChild==1 && rightChild==1) -> asking its parent to cover him
         return -1;
    }
    
    int minCameraCover(TreeNode* root) {
        int rootNeed=postOrder(root);
        if(rootNeed==-1)
            count++;
        return count;
    }
};