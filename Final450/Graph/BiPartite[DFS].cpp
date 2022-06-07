//O(V+E)

class Solution {
public:
    
    bool dfs(int src,vector<vector<int>>& graph,vector<int> &colors){
        for(int i=0;i<graph[src].size();i++){
            int v=graph[src][i];
            if(colors[v]==-1){
                colors[v]=1-colors[src]; //colors[src]==1 ? 0 : 1
                if(!dfs(v,graph,colors))
                    return false;
            }else if(colors[v]==colors[src]){
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> colors(V,-1);
        for(int i=0;i<V;i++){
            if(colors[i]==-1){
                colors[i]= 0;
                if(!dfs(i,graph,colors))
                    return false;
            }
        }
        return true;
    }
};