struct Info{
    int sz; // Size of subtree
    int max; // Min value in subtree
    int min; // Max value in subtree
    int ans; // Size of largest BST which is subtree of current node
    bool isBst; // If subtree is BST
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    Info largestBstUtil(Node *root)
    {
       if(root==NULL)
        {
            return {0,INT_MIN,INT_MAX,0,true};
        }
       if(root->left==NULL && root->right==NULL)
        {
            return {1,root->data,root->data,1,true};
        }
       Info ls=largestBstUtil(root->left);
       Info rs=largestBstUtil(root->right);
       
       Info ret;
       ret.sz=(ls.sz+rs.sz+1);
       
       if(ls.isBst && rs.isBst && ls.max<root->data && rs.min>root->data)
       {
           ret.min=min(ls.min,min(root->data,rs.min));
           ret.max=max(rs.max,max(root->data,ls.max));
           ret.isBst=true;
           ret.ans=ret.sz;
           return ret;
       }
       ret.ans=max(ls.ans,rs.ans);
       ret.isBst=false;
       return ret;
    }
    
    int largestBst(Node *root)
    {
    	//Your code here
    	Info val= largestBstUtil(root);
    	return val.ans;
    }
};