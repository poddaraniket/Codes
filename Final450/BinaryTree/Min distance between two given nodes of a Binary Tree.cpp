//O(n)
int distByValue(Node *root,int val){
    if(root==NULL)
     return 0;
    if(root->data==val)
     return 1;
    int a=distByValue(root->left,val);
    int b=distByValue(root->right,val);
    if(!a && !b)
     return 0;
    else
     return a+b+1;
}   

Node* LCA(Node *root,int a,int b){
    if(root==NULL)
     return NULL;
    if(root->data==a || root->data==b)
     return root;
    Node *left=LCA(root->left,a,b); 
    Node *right=LCA(root->right,a,b);
    if(left && right)
     return root;
    if(!left && !right)
     return NULL;
    return left?left:right; 
}
   
int findDist(Node* root, int a, int b) {
    // Your code here
    Node *ancestor=LCA(root,a,b);
    int distA=distByValue(ancestor,a);
    int distB=distByValue(ancestor,b);
    // cout<<ancestor->data<<endl;
    // int distC=distByValue(root,ancestor->data);
    //cout<<distA<<" "<<distB<<" "<<endl;
    return distA+distB-2;
}