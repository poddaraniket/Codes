//O(N)_O(N)

void preorder(Node *root,map<int,int> &nonLeaf,map<int,int> &Leaf)
{
    if(root==NULL)
     return;
    if(root->left==NULL && root->right==NULL)
    {
        Leaf[root->data]=1;
    }
    else
        nonLeaf[root->data]=1;
    preorder(root->left,nonLeaf,Leaf);
    preorder(root->right,nonLeaf,Leaf);
}

bool isDeadEnd(Node *root)
{
    //Your code here
    if(root==NULL)
     return true;
    map<int,int> nonLeaf,Leaf;
    preorder(root,nonLeaf,Leaf);
    for(auto x:Leaf){
        if(x.first==1){
            if(nonLeaf[x.second+1]==1)
             return true;
        }
        else{
            if(nonLeaf[x.first-1]==1 && nonLeaf[x.first+1]==1)
             return true;
        }
    }
    return false;
}