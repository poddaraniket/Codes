int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      unordered_map<int,int>mp;
      for(int i=0;i<N;i++)
      {
          mp[arr[i]]=1;
      }
      int maxCount=0;
      for(int i=0;i<N;i++)
       {
          int count=0;
          if(mp[arr[i]-1]==0)
           {
              int a=arr[i];
              while(mp[a]!=0)
               {
                 count++;
                 a++;
               }
              maxCount=max(maxCount,count);
           }
       }
       return maxCount;
    }