//O(V+E) O(2*|V|)
// Every time a visited node comes again check if it forms a loop

class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	
	bool isCycleUtil(vector<int> adj[],int src,vector<bool> &vis,vector<int> &parent)
	{
	    vis[src]=true;
	    for(int i=0;i<adj[src].size();i++){
	        if(!vis[adj[src][i]])
	         {
	           parent[adj[src][i]]=src;  
	           if(isCycleUtil(adj,adj[src][i],vis,parent))
	             return true;
	         }
	        else{
	            int child=adj[src][i];
	            int par=src;
	            //O(V)
	            while(child!=par){
	                par=parent[par];
	                if(par==-1)
	                 break;
	            }
	            if(par==child)
	             return true;
	        }
	    }
	    return false;
	}
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   vector<bool> vis(V,false);
	   vector<int> parent(V,-1);
	   //dfs O(E)
	   for(int i=0;i<V;i++){
	       if(!vis[i]){
	           if(isCycleUtil(adj,i,vis,parent))
	            return true;
	       }
	   }
	   return false;
 	}