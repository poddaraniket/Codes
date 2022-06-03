void allpathSourceTargetUtil(vector<vector<int>>& graph,int src,int dest,vector<bool> &vis,vector<vector<int>> &res,vector<int> v){
        if(src==dest)
        {
            v.push_back(src);
            res.push_back(v);
            return;
        }
        vis[src]=true;
        v.push_back(src);
        for(int i=0;i<graph[src].size();i++){
            if(!vis[graph[src][i]])
             allpathSourceTargetUtil(graph,graph[src][i],dest,vis,res,v);
        }
        vis[src]=false;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int k=graph.size();
        int src=0;
        int dest=k-1;
        vector<bool> vis(k);
        vector<vector<int>> res;
        vector<int> v;
        allpathSourceTargetUtil(graph,src,dest,vis,res,v);
        return res;
    }