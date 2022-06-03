//O(V*E)
// single src shortest path covering negative weights as well

vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        // Code here
        vector<int> dist(V,100000000);
        dist[S]=0;
        for(int i=0;i<V-1;i++){
            for(int i=0;i<adj.size();i++){
                int u=adj[i][0];
                int v=adj[i][1];
                int wt=adj[i][2];
                if(dist[u]!=100000000 && dist[u]+wt<dist[v])
                 {
                    dist[v]=dist[u]+wt;
                 }
            }
        }
        return dist;
        // check one more time(Vth time) if dist[v]<dist[u]+wt if yes negative wt cycle eist 
    }