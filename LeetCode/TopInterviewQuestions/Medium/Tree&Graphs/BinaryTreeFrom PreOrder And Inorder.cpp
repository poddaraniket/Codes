//O(N)
class Solution {
public:
    
    int search(vector<int>& inorder,int inS,int inE,int target){
        for(int i=inS;i<=inE;i++){
            if(inorder[i]==target)
                return i;
        }
        return -1;
    }
    
    TreeNode* buildTreeUtil(vector<int>& preorder,int preS,int preE ,vector<int>& inorder,int inS,int inE){
        if(preS>preE){
            return NULL;
        }
        
        int val=preorder[preS];
        TreeNode* newNode=new TreeNode(val);
        int index=search(inorder,inS,inE,val);
        
        int linS=inS;
        int linE=index-1;
        int rinS=index+1;
        int rinE=inE;
        int lPreS=preS+1;
        int lPreE=lPreS+(linE-linS);
        int rPreS=lPreE+1;
        int rPreE=preE;
        
        newNode->left=buildTreeUtil(preorder,lPreS,lPreE,inorder,linS,linE);
        newNode->right=buildTreeUtil(preorder,rPreS,rPreE,inorder,rinS,rinE);
        return newNode;     
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeUtil(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
};