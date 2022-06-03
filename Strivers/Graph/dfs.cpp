 TC -> O(V+E)  
 V -> bcoz we are marking all vertex as false initially
 E -> bcoz we are visiting all edges once

SC->O(|V|)  bcoz at one instant we can take the entire graph (0->1->2->3->4)



 void dfs(int src,vector<int> adj[],vector<int> &v,vector<bool> &vis){
        vis[src]=true;
        v.push_back(src);
        for(int i=0;i<adj[src].size();i++){
            if(!vis[adj[src][i]])
              dfs(adj[src][i],adj,v,vis);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> v;
        // O(V)---------------
        vector<bool> vis(V,false);
        //O(E)---------------
        dfs(0,adj,v,vis);
        return v;
    }