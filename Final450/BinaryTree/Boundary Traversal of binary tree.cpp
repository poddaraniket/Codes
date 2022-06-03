 void printBoundaryLeft(Node *root,vector<int> &v)
    {
        if(root==NULL)
         return;
        
        if(root->left){
            // Push before alling for top-down approach
            v.push_back(root->data);
            printBoundaryLeft(root->left,v);
        }
        else if(root->right){
            v.push_back(root->data);
            printBoundaryLeft(root->right,v);
        }
    }
    
     void printBoundaryRight(Node *root,vector<int> &v)
     {
        if(root==NULL)
         return;
        
        if(root->right){
            // Push after calling for down-top approach
            printBoundaryRight(root->right,v);
            v.push_back(root->data);
        }
        else if(root->left){
            printBoundaryRight(root->left,v);
            v.push_back(root->data);
        }
     }
    
    void printLeaves(Node *root,vector<int> &v)
     {
        if(root==NULL)
         return;
        
        printLeaves(root->left,v);
        
        if(!(root->right) && !(root->left)){
            v.push_back(root->data);
        }
        
        printLeaves(root->right,v);
     }
    
    vector <int> printBoundary(Node *root)
    {
        //Your code here
        vector<int> v;
        v.push_back(root->data);
        printBoundaryLeft(root->left,v);
        printLeaves(root->left,v);
        printLeaves(root->right,v);
        printBoundaryRight(root->right,v);
        return v;
    }