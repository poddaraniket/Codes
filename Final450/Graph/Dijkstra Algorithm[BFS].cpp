//O(V^2)

 vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        
        vector<int> dist(V,INT_MAX);
        //vector<int> dist(V,INT_MAX);
        dist[S]=0;
        queue<int> q;
        q.push(S);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i=0;i<adj[u].size();i++){
                int v=adj[u][i][0];
                int wt=adj[u][i][1];
                if(dist[u]+wt<dist[v])
                  {
                      dist[v]=dist[u]+wt;
                      q.push(v);
                  }
            }
        }
        return dist;
    }