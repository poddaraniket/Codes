void sum(Node *root,int k,vector<int> &v,int &count){
        if(root==NULL)
         return;
        
        v.push_back(root->data);
        sum(root->left,k,v,count);
        sum(root->right,k,v,count);
        
        //print(v);
        //find sum as k in vector
        int s=0;
        // from last element till u get a sum as k
        for(int i=v.size()-1;i>=0;i--){
            s+=v[i];
            if(s==k)
             count++;
        }
        // removing the last element as its calculation is taken now we want other than last element
        v.pop_back();
    }
    
    int sumK(Node *root,int k)
    {
        // code here
        vector<int> v;
        int count=0;
        sum(root,k,v,count);
        return count;
    }