//O(V+E)

class Solution {
public:
    
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> colors(V,-1);
        for(int i=0;i<V;i++){
            if(colors[i]!=-1)
              continue;
            queue<int> q;
            q.push(i);
            colors[i]=0;
            while(!q.empty()){
                int size=q.size();
                for(int i=0;i<size;i++){
                    int u=q.front();
                    int colorToGive=1-colors[u];
                    q.pop();
                    for(int v : graph[u]){
                        if(colors[v]==-1){
                            colors[v]=colorToGive;
                            q.push(v);
                        }else if(colors[v]==colors[u]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};