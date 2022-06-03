//O(V(V+E))
// find single point of failure in N/W and remove it by either adding more edges or redesigning the N/W. This inc reliability
 

 void tarjan_dfs(int u,vector <int> &disc,vector <int> &low,vector <int> &parent,vector <int> adj[],vector<bool> &ap)
    {
      static int time=0;
      disc[u]=time;
      low[u]=time;
      time++;
      int child=0;
      for(int i=0;i<adj[u].size();i++){
          int v=adj[u][i];
          if(disc[v]==-1){
              child++;
              parent[v]=u;
              tarjan_dfs(v,disc,low,parent,adj,ap);
              // there might be a backedge from the subgraph rooted at v to ancestor of u or u
              low[u]=min(low[u],low[v]);  
              // Case 1: if src vertex is root node then Ap possible if child >1
              if(parent[u]==-1 && chid>1){
              // cout<<u<<" "<<v<<endl;
               ap[u]=true;
              }
              // Case 2: if src node is not root node then Ap possible if no backedge
              if(parent[u]!=-1 && low[v]>=disc[u]){
                  ap[u]=true;
              }
           }
           // assuming that cild to prent edge is not a backedge
          else if(parent[u]!=v){
              //Backedge found update it
              low[u]=min(low[u],disc[v]);
          }
      }
    }
    void isAp(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector <int> disc(V,-1),low(V,-1),parent(V,-1);
        vector<bool> ap(V,false);
        for(int i=0;i<V;i++){
            tarjan_dfs(i,disc,low,parent,adj,ap);
        }
        
        for(int i=0;i<ap.size();i++) 
         {
             if(ap[i])
              cout<<i<<<endl;
         }
        return 0; 
    }