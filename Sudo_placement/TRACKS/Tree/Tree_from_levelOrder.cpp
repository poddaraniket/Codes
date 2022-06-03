Node *buildTreehelper(int lev[],int i,int n)
{
    if(i>n)
     return NULL;
    Node *new_node=new Node(lev[i]);
    new_node->left=buildTreehelper(lev,(2*i)+1,n);
    new_node->right=buildTreehelper(lev,(2*i)+2,n);
    return new_node;
}