//sO(V^2)

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V,INT_MAX);
        dist[S]=0;
        queue<int> q;
        q.push(S);
        while(!q.empty())
         {
             int u=q.front();
             q.pop();
             for(int i=0;i<adj[u].size();i++)
              {
                 vector<int> data=adj[u][i];
                 int v=data[0];
                 int wt=data[1];
                 if(dist[u]!=INT_MAX && dist[u]+wt<dist[v])
                  {
                      dist[v]=dist[u]+wt;
                      q.push(v);
                  }
              }
         }
        return dist; 
    }