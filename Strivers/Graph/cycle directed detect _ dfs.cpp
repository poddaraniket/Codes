//O(V+E) O(2*|V|)
// Every time a visited node comes again check if it forms a loop

// dfsVis keeps the node visited but once its child is visited and we come out of it make it 
unvisited so that if any other node visits is its false

eg 0->1  0->1
   0->2  1->2
   2->1  2->0
class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	
	bool isCycleUtil(vector<int> adj[],int src,vector<bool> &vis,vector<bool> &dfsVis)
	{
	    vis[src]=true;
	    dfsVis[src]=true
	    for(int i=0;i<adj[src].size();i++){
	        if(!vis[adj[src][i]])
	         {
	           parent[adj[src][i]]=src;  
	           if(isCycleUtil(adj,adj[src][i],vis,parent))
	             return true;
	         }
	        else if(dfsVis[adj[src][i]]{
	             return true;
	        }
	    }
	    dfsVis[src]=false;
	    return false;
	}
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   vector<bool> vis(V,false);
	   vector<bool> dfsVis(V,false);
	   //dfs O(E)
	   for(int i=0;i<V;i++){
	       if(!vis[i]){
	           if(isCycleUtil(adj,i,vis,parent))
	            return true;
	       }
	   }
	   return false;
 	}