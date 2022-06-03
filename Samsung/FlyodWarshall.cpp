// Shortest Path between pairs
// DP [O(N^3)]

void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n=matrix.size();
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==-1)
	             matrix[i][j]=INT_MAX;
	        }
	    }
	    // shortest path via edge i
	    for(int i=0;i<n;i++)
	    {
	        // shortest path between u & v
	        for(int u=0;u<n;u++)
	        {
	            for(int v=0;v<n;v++)
	            {
	                if(matrix[u][i]!=INT_MAX && matrix[i][v]!=INT_MAX)
	                 {
	                     matrix[u][v]=min(matrix[u][v],matrix[u][i]+matrix[i][v]);
	                 }
	            }
	        }
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(matrix[i][j]==INT_MAX)
	             matrix[i][j]=-1;
	        }
	    }
	}