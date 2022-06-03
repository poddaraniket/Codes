 // O(E(V+E))
// Bridge in  a N/W can represent critical wires or connections and is similar to SPOF. we can eliminate such vulnerability by adding edges or redesigning .
 void tarjan_dfs(int u,vector <int> &disc,vector <int> &low,vector <int> &parent,vector <int> adj[],int V,vector <pair<int,int>> &bridge)
    {
      static int time=0;
      disc[u]=time;
      low[u]=time;
      time++;
      for(int i=0;i<adj[u].size();i++){
          int v=adj[u][i];
          if(disc[v]==-1){
              parent[v]=u;
              tarjan_dfs(v,disc,low,parent,adj,V,bridge);
              // there might be a backedge from the subgraph rooted at v to ancestor of u or u
              low[u]=min(low[u],low[v]);  
              //Condition of bridge [no back edge]
              if(low[v]>disc[u]){
              // cout<<u<<" "<<v<<endl;
               bridge.push_back({u,v});
              }
           }
          else if(parent[u]!=v){
              //Backedge found update it
              low[u]=min(low[u],disc[v]);
          }
      }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector <int> disc(V,-1),low(V,-1),parent(V,-1);
        vector<pair<int,int>> bridge;
        for(int i=0;i<V;i++){
            tarjan_dfs(i,disc,low,parent,adj,V,bridge);
        }
        
        for(int i=0;i<bridge.size();i++) 
         {
             pair<int,int> p=bridge[i];
             if(p.first==c || p.second==c){
                 if(p.first==d || p.second==d)
                  return 1;
             }
         }
        return 0; 
    }