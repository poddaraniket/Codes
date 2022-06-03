long long dp[10][50];
	
	int mat[4][3]={{1,2,3},
	                {4,5,6},
	                {7,8,9},
	                {-1,0,-1}};
	
	int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
	
	long long solve(int r,int c,int n)
	 {
	     if(n==1)
	      return 1;
	     if(dp[mat[r][c]][n]!=-1)
	      {
	          return dp[mat[r][c]][n]; 
	      }
	     long long a=solve(r,c,n-1); 
	     long long b=0,c1=0,d=0,e=0;
	     if(r-1>=0 && mat[r-1][c]!=-1)
	      b=solve(r-1,c,n-1);
	     if(r+1<4 && mat[r+1][c]!=-1)
	      c1=solve(r+1,c,n-1);
	     if(c-1>=0 && mat[r][c-1]!=-1)
	      d=solve(r,c-1,n-1);
	     if(c+1<3 && mat[r][c+1]!=-1)
	      e=solve(r,c+1,n-1);
	     return dp[mat[r][c]][n]=a+b+c1+d+e; 
	 }
	
	long long getCount(int N)
	{
	    long long ans=0;
	    dp[10][N+1];
	    memset(dp,-1,sizeof(dp));
	    for(int i=0;i<4;i++)
	     {
	         for(int j=0;j<3;j++)
	         {
	            if(mat[i][j]!=-1){  
	              ans+=solve(i,j,N);
	            }
	         }
	     }
	    return ans; 
	}