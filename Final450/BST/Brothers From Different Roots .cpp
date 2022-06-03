//O(N^2)
bool find(int val,Node *root2){
    if(root2==NULL)
     return false;
    if(val<root2->data)
     return find(val,root2->left);
    else if(val>root2->data)
     return find(val,root2->right);
    else
     return true;
}

void countPairsUtil(Node *root1,Node *root2,int x,int &count){
    if(root1==NULL)
     return;
    countPairsUtil(root1->left,root2,x,count); 
    if(find(x-root1->data,root2))
     count++;
    countPairsUtil(root1->right,root2,x,count);
}

int countPairs(Node* root1, Node* root2, int x)
{
    // Code here
    if(root1==NULL || root2==NULL)
     return 0;
    int count=0;
    countPairsUtil(root1,root2,x,count);
    return count; 
}