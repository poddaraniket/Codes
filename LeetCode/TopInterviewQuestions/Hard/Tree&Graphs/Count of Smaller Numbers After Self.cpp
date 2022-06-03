class Node{
    public:
        int val;
        int count;
        Node *left;
        Node* right;

        Node(int num1,int num2){
            val=num1;
            count=num2;
            left=NULL;
            right=NULL;
        }
};


class Solution {
public:
    
    int addNode(Node* &root,int value,int countSmaller){
        if (root == NULL)
        {
            root = new Node(value, 0);
            return countSmaller;
        }
        if (root->val < value)
        {
            return root->count + (addNode(root->right,value,countSmaller + 1));
        }
        else
        {
            root->count++;
            return addNode(root->left, value,countSmaller);
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n);
        Node *root=NULL;
        for(int i=n-1;i>=0;i--){
            ans[i]=addNode(root,nums[i],0);
        }
        return ans;
    }
};