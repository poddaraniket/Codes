int maxlevel=-1,maxSum=0;
    
    void sumUtil(Node *root,int level,int sum){
        if(root==NULL)
         return;
        sum+=root->data; 
        if(level>maxlevel){
         maxSum=sum;
         maxlevel=level;
        }
        else if(level==maxlevel){
         maxSum=max(maxSum,sum);
        }
        sumUtil(root->left,level+1,sum);
        sumUtil(root->right,level+1,sum);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        sumUtil(root,0,0);
        return maxSum;
    }