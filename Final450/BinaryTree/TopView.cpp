vector<int> topView(Node *root)
    {
        //Your code here
        map<int,int> mp;
        queue<Node*> q;
        q.push(root);
        queue<int> width;
        width.push(0);
        while(!q.empty())
         {
            Node *temp=q.front();
            int w=width.front();
            q.pop();
            width.pop();
            if(mp.find(w)==mp.end())
              mp[w]=temp->data;
            if(temp->left)
             {
                q.push(temp->left);
                width.push(w-1);
             }
            if(temp->right)
              {
                q.push(temp->right);
                width.push(w+1);
              }    
         }
        vector<int> v;
        for(auto it=mp.begin();it!=mp.end();it++)
            v.push_back(it->second);
        return v;    
   }