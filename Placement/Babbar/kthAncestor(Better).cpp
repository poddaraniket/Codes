Node* kthAncestorUtil(Node *root, int &k, int node){
    if(root==NULL)
     return NULL;
    if(root->data==node){
        return root;
    } 
    
    Node *leftSide=kthAncestorUtil(root->left,k,node);
    Node *rightSide=kthAncestorUtil(root->right,k,node);
    
    if(leftSide!=NULL && rightSide==NULL){
        k--;
        if(k<=0){
            k=INT_MAX;//so that in recursion it never coms to 0 again
            return root;
        }
        return leftSide;
    }
    
    if(leftSide==NULL && rightSide!=NULL){
        k--;
        if(k<=0){
            k=INT_MAX;//so that after k bcoms 0 once ans is fixed 
            // now everytime k is decremented it will not be o and it will pas root ether in form of leftSode or rghtSSide
            return root;
        }
        return rightSide;
    }
    
    return NULL;
}

int kthAncestor(Node *root, int k, int node)
{
    // Code here
    Node *ans=kthAncestorUtil(root,k,node);
    if(ans==NULL || ans->data==node)
     return -1;
    return ans->data;
}
