//O(V+E)
//O(|V|)
bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    //O(V)
	    vector<int> vis(V,-1);
	   	queue<int> q;
	   	for(int i=0;i<V;i++)
	   	{
	   	  if(vis[i]!=-1)
	   	   continue;
	   	  q.push(i);
	   	  vis[i]=0;
	   	  //bfs O(E)
	   	  while(!q.empty()){
	   	    int src=q.front();
	   	    q.pop();
	   	    vis[src]=1;
	   	    for(int i=0;i<adj[src].size();i++){
	   	        if(vis[adj[src][i]]==-1){
	   	            q.push(adj[src][i]);
	   	            vis[adj[src][i]]=0;
	   	        }
	   	        else if(vis[adj[src][i]]==0)
	   	         return true;
	   	    }
	   	}
	   	}
	   	return false;
	}