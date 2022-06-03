//O(ElogV)
int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<bool> vis(V,false);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({-1,{-1,0}});
        // vis[0]=true;
        int count=0,mst=0;
        while(!pq.empty()){
            pair<int,pair<int,int>> p=pq.top();
            pq.pop();
            int wt=p.first;
            int u=p.second.first;
            int v=p.second.second;
            if(vis[v])
             continue;
            vis[v]=true;
            if(wt!=-1){
            //  cout<<u<<" "<<v<<" "<<wt<<endl;
             mst+=wt;
             count++;        
            }
            if(count==V-1)
             break;
            for(int i=0;i<adj[v].size();i++){
                int wt1=adj[v][i][1];
                int u1=v;
                int v1=adj[v][i][0];
                if(!vis[v1])
                  pq.push({wt1,{u1,v1}});
            }
        }
        return mst;
    }