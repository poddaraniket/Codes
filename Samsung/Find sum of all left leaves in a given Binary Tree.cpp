//O(logN)

void leftLeavesSumUtil(Node *root,bool exist,int &sum)
{
    if(root==NULL)
     return;
    if(root->left==NULL && root->right==NULL)
     {
         if(exist)
          sum+=root->data;
         return; 
     }
    leftLeavesSumUtil(root->left,true,sum);
    leftLeavesSumUtil(root->right,false,sum);
}

int leftLeavesSum(Node *root)
{
    // Code here
    int sum=0;
    bool exist=false;
    leftLeavesSumUtil(root,exist,sum);
    return sum;
}