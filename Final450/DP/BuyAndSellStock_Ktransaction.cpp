//O(K*N)
int maxProfit(int K, int N, int A[]) {
        // code here
        int profit[K+1][N];
        memset(profit,0,sizeof(profit));
        for(int i=1;i<=K;i++)
         {
             int maxdiff=-1*A[0];
             for(int j=1;j<N;j++)
              {
                  profit[i][j]=max(profit[i][j-1],A[j]+maxdiff);
                  maxdiff=max(maxdiff,profit[i-1][j]-A[j]);
              }
         }
        return profit[K][N-1]; 
    }