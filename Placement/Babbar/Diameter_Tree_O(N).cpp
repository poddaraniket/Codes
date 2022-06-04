pair<int,int> diameterFast(Node* root){
        if(root==NULL)
         {
            pair<int,int> p=make_pair(0,0); 
            return p; 
         }
        pair<int,int> left=diameterFast(root->left);
        pair<int,int> right=diameterFast(root->right);
        
        int leftDiamter=left.first;
        int rightDiamter=right.first;
        
        //  height= left + right + 1;
        int height=left.second+right.second+1;
        
        pair<int,int> ans;
        //diamter
        ans.first=max(height,max(leftDiamter,rightDiamter));
        //height
        ans.second=max(left.second,right.second)+1;
        
        return ans; 
    }
    
    int diameter(Node* root) {
        // Your code here
        pair<int,int> ans=diameterFast(root);
        return ans.first;
    }