 //TC -> O(V+E)
 //SC ->  O(|V|) -> a node that has max child will take the most space and that most can be all the vertices

 vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        vector<int> vec;
        //O(V)-----------------
        vector<bool> vis(V,false);
        q.push(0);
        vis[0]=true;
        //O(E)----------
        while(!q.empty()){
            int u=q.front();
            vec.push_back(u);
            q.pop();
            for(int j=0;j<adj[u].size();j++){
                if(!vis[adj[u][j]]){
                  q.push(adj[u][j]);
                  vis[adj[u][j]]=true;
                }
            }
        }
        return vec;
    }