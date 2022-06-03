// O(N)

// Assumption that map takes  O(1) time to search 
int findLongestConseqSubseq(int arr[], int N)
    {
      //Your code here
      unordered_map<int,int> mp;
      unordered_map<int,int> vis;
      for(int i=0;i<N;i++)
       {
           mp[arr[i]]=1;
       }
      int count=1,maxCount=0; 
      for(int i=0;i<N;i++)
       {
          int val=arr[i];
          count=1;
          while(mp[val-1]!=0)
           {
               if(vis[val-1]==0)
                count++;
               else{
                count+=vis[val-1];
                break;   
               }
               val--;
           }
          vis[arr[i]]=count; 
          maxCount=max(maxCount,count); 
       }
      return maxCount; 
    }