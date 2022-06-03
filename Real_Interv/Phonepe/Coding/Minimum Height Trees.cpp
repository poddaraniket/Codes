// Use of idea of topological Sort[Not exactly topo -> used in DAG]

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
         vector<int> v;
        if(n<=0)
           return v;
        if(n==1)
        {
            v.push_back(0);
            return v;
        } 
        int degree[n];
        bool vis[n];
        memset(vis,false,sizeof(vis));
        memset(degree,0,sizeof(degree));
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++)
         {
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
         }
        queue<int> q;
        for(int i=0;i<n;i++)
         {
            if(degree[i]==1){
               q.push(i);
               vis[i]=true; 
            }
         }
        int count=n;
        while(count>2)
        {
            int size=q.size();
            count-=size;
            while(size--)
            {
                int u=q.front();
                //cout<<u<<endl;
                q.pop();
                for(int i=0;i<adj[u].size();i++)
                {
                    int v=adj[u][i];
                    degree[v]--;
                    if(degree[v]==1 && vis[v]==false){
                       vis[v]=true;
                       q.push(v);  
                     }
                }

            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            v.push_back(u);
        }
        return v;
    }