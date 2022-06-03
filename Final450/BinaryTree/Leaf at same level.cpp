int maxLevel=-1;
    
    bool checkers(Node *root,int level)
    {
        if(root==NULL)  
         return true;
        if(root->left==NULL && root->right==NULL){
            if(maxLevel==-1)
             {
                 maxLevel=level;
                 return true;
             }
            return (maxLevel==level); 
        }
        return (checkers(root->left,level+1) && checkers(root->right,level+1));
    }
    
    bool check(Node *root)
    {
        //Your code here
       // lowestlevel(root,0);
        return checkers(root,0);
         
    }