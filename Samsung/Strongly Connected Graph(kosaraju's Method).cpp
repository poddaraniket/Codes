//O(V+E)  S->O(V)

//A directed graph is strongly connected if there is a path between all pairs of vertices. 

class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	
	void reverseGraph(int V,vector<int> adj[],vector<int> adjRev[]){
	    for(int i=0;i<V;i++){
	        for(int j=0;j<adj[i].size();j++){
	            adjRev[adj[i][j]].push_back(i);
	        }
	    }
	}
	
	void dfs(int src,vector<bool> &vis,stack<int> &s,vector<int> adj[]){
	    vis[src]=true;
	    for(int i=0;i<adj[src].size();i++){
	        if(!vis[adj[src][i]])
	          dfs(adj[src][i],vis,s,adj);
	    }
	    s.push(src);
	}
	
	void dfsRev(int src,vector<bool> &visRev,vector<int> adjRev[],vector<int> &v){
	    visRev[src]=true;
	    v.push_back(src);
	    for(int i=0;i<adjRev[src].size();i++)
	    {
	        if(!visRev[adjRev[src][i]])
	         {
	             dfsRev(adjRev[src][i],visRev,adjRev,v);
	         }
	    }
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        vector<bool> vis(V,false);
        stack<int> s;
        for(int i=0;i<V;i++){
            if(!vis[i])
             dfs(i,vis,s,adj);
        }
        vector<int> adjRev[V];
        reverseGraph(V,adj,adjRev);
        vector<bool> visRev(V,false);
        vector<vector<int>> result;
        while(!s.empty()){
            int src=s.top();
            s.pop();
            if(visRev[src])
             continue;
            vector<int> v;
            dfsRev(src,visRev,adjRev,v);
            result.push_back(v);
        }
        return result.size();
    }
};