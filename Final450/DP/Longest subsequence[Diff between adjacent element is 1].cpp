int longestSubsequence(int N, int A[])
    {
        // code here
        int LIS[N];
        for(int i=0;i<N;i++)
         {
            LIS[i]=1;
         }
        for(int i=1;i<N;i++)
         {
            for(int j=0;j<i;j++)
             {
                if(abs(A[j]-A[i])==1)
                 LIS[i]=max(LIS[j]+1,LIS[i]);
             }
         }
        int maxi=0;
        for(int i=0;i<N;i++)
         {
            maxi=max(maxi,LIS[i]);
         }
        return maxi; 
    }