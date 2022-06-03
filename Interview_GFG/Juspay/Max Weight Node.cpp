// O(N) O(N)

int maxWeightCell(int N, vector<int> Edge)
  {
      // code here
      int wt[N]={0};
      for(int i=0;i<N;i++)
       {
           // i is pointing to Edge[i]
           // wt[Edge[i]] += i;
           if(Edge[i]!=-1)
            wt[Edge[i]]+=i;
       }
      int maxi=-1000000,ans=0; 
      for(int i=0;i<N;i++){
        if(maxi<=wt[i])  
         {
            maxi=max(maxi,wt[i]);
            ans=i;
         }
      }
      return ans;    
  }