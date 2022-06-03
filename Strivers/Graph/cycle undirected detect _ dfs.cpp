 //O(V+E)
 //O(|V|)
 bool isCycleUtil(int src,vector<int> adj[],int par,vector<bool> vis){
        vis[src]=true;
        for( auto it : adj[src]){
            if(!vis[it]){
                if(isCycleUtil(it,adj,src,vis)){
                    return true;
                }
            }else if(it!=par){
                return true;
            }
        }
        return false;
    }
    
    
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        int par=-1;
        //O(V+E)
        vector<bool> vis(V,false);
        //O(E)
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(isCycleUtil(i,adj,par,vis)){
                    return true;
                }
            }
        }
        return false;
    }