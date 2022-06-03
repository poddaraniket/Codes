void dfsOfGraphUtil(vector<int> adj[],int src,vector<bool> &vis,vector<int> &v){
	    vis[src]=true;
	    v.push_back(src);
	    for(int i=0;i<adj[src].size();i++)
	     {
	         if(!vis[adj[src][i]])
	          dfsOfGraphUtil(adj,adj[src][i],vis,v);
	     }
	} 
	
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    // Code here
	    vector<bool> vis(V,false);
	    vector<int> v;
	    dfsOfGraphUtil(adj,0,vis,v);
	    return v;
	}