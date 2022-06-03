//O(ElogV)
//E-> every edges going through
//logV -> binary heap

// from present vertex pick the edge to a vertex that doesn't lead to cycle and is of min wt

int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<bool> vis(V,false);
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({-1,{-1,0}});
        int mst=0,vertex=0;
        while(!pq.empty())
        {
            int wt=pq.top().first;
            int u=pq.top().second.first;
            int v=pq.top().second.second;
            pq.pop();
            // Avoiding Cycle
            if(vis[v])
             continue;
            vis[v]=true;
            if(wt!=-1)
             {
                mst+=wt;
                vertex++;
             }
            if(vertex==V)
             break;
            for(int i=0;i<adj[v].size();i++)
             {
                 int wt1=adj[v][i][1];
                 int v1=adj[v][i][0];
                 int u1=v;
                 pq.push({wt1,{u1,v1}});
             }
        }
        return mst;
    }