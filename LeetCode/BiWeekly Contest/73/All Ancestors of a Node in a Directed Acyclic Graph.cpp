//O(V*E)

class Solution {
public:
    
    void dfs(int src, vector<int> adj[],vector<bool> &vis){
        vis[src]=true;
        for(int i=0;i<adj[src].size();i++){
            if(vis[adj[src][i]])
                continue;
            dfs(adj[src][i],adj,vis);
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        vector<vector<int>> ans(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
       for(int i=0;i<n;i++){
           vector<bool> vis(n,false);
           dfs(i,adj,vis);
           for(int j=0;j<n;j++){
               if(i!=j && vis[j])
                  ans[j].push_back(i);
           }
       }
       return ans; 
    }
};