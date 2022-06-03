//O(V^2) -> Greedy Algo

// Shortest Path from a single src to all nodes

vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> dist(V,INT_MAX);
        queue<int> q;
        q.push(S);
        dist[S]=0;
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