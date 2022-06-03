//O(V^3)
int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    vector<int> dist(n,INT_MAX);
	    dist[0]=0;
	    // Update the weight for n-1 times
	    for(int i=0;i<n-1;i++){
	        for(int j=0;j<edges.size();j++){
	            int u=edges[j][0];
	            int v=edges[j][1];
	            int wt=edges[j][2];
	            if(dist[u]!=INT_MAX && dist[u]+wt<dist[v])
	             dist[v]=dist[u]+wt;
	        }
	    }
	    // If the weight updates for the nth time it means there is negative cycle 
	    for(int i=0;i<edges.size();i++){
	            int u=edges[i][0];
	            int v=edges[i][1];
	            int wt=edges[i][2];
	            if(dist[u]!=INT_MAX && dist[u]+wt<dist[v])
	             return 1;
	        }
	   return 0;     
	}