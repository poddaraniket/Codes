vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int indegree[V]={0};
	    for(int i=0;i<V;i++){
	        for(int j=0;j<adj[i].size();j++){
	            indegree[adj[i][j]]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indegree[i]==0)
	         q.push(i);
	    }
	    vector<int> v;
	    while(!q.empty()){
	        int src=q.front();
	        q.pop();
	        v.push_back(src);
	        for(int i=0;i<adj[src].size();i++){
	            indegree[adj[src][i]]--;
	            if(indegree[adj[src][i]]==0)
	             q.push(adj[src][i]);
	        }
	    }
	    return v;
	}