// If we use Topo Sort,i.e,BFS the no. of nodes that come in list if not equal to no. of nodes then its cyclic  
//O(V+E)
// O(|V|)
class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
		//O(V)
	   	int indegree[V]={0};
	   	//O(E)
	   	for(int i=0;i<V;i++){
	   	    for(int j=0;j<adj[i].size();j++){
	   	        indegree[adj[i][j]]++;
	   	    }
	   	}
	   	queue<int> q;
	   	//O(V)
	   	for(int i=0;i<V;i++)
	   	 {
	   	   if(indegree[i]==0)
	   	    q.push(i);
	   	 }
	   	vector<int> v;
	   	//bfs O(E)
	   	while(!q.empty()){
	   	    int src=q.front();
	   	    v.push_back(src);
	   	    q.pop();
	   	    for(int i=0;i<adj[src].size();i++){
	   	        indegree[adj[src][i]]--;
	   	        if(indegree[adj[src][i]]==0)
	   	         q.push(adj[src][i]);
	   	    }
	   	}
	   	if(v.size()!=V)
	   	 return true;
	   	return false; 
	}