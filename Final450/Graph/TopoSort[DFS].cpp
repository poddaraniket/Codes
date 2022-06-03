//Stack will conotain the order in opposite order

//O(V+E)
//O(|V|)

void dfs(int src,vector<int> adj[],vector<bool> &vis,stack<int> &st){
	    vis[src]=true;
	    for(auto it : adj[src]){
	        if(!vis[it]){
	            dfs(it,adj,vis,st);
	        }
	    }
	    st.push(src);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int> st;
	    vector<bool> vis(V,false);
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,adj,vis,st);
	        }
	    }
	    vector<int> v;
	    while(!st.empty()){
	        int u=st.top();
	        st.pop();
	        v.push_back(u);
	    }
	    return v;
	}