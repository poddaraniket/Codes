O(ht. of bst + no. of nodes in given range)
void getCountUtil(Node *root,int l,int h,int &count){
    if(root==NULL)
     return;
    if(root->data>=l && root->data<=h)
     count++;
    getCountUtil(root->left,l,h,count);
    getCountUtil(root->right,l,h,count);
}

int getCount(Node *root, int l, int h)
{
  // your code goes here   
  int count=0;
  getCountUtil(root,l,h,count);
  return count;
}