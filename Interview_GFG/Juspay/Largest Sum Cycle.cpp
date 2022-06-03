 // O(N)  -> it doesn't iterater the nde mre than once


 vector<vector<int>> v;
  vector<int> vis,temp,par;
  
  long long dfs(int node,int p=-1)
   {
       vis[node]=1;
       par[node]=p;
       temp.push_back(node);
       for(auto it : v[node])
        {
            if(vis[it]==0)
             {
                 long long z=dfs(it,node);
                 if(z!=-1)
                  return z;
             }
            else if(vis[it]==1)
             {
                 long long sum=it;
                 while(node!=it)
                  {
                      sum+=node;
                      node=par[node];
                  }
                 if(node==it)
                  return sum;
                 return -1; 
             }
             
        }
      return -1;    
   }
  
  
  long long largestSumCycle(int N, vector<int> Edge)
  {
    // code 
    vis=vector<int> (N,0);
    v=vector<vector<int>> (N);
    par=vector<int>(N);
    long long ans=-1;
    for(int i=0;i<N;i++)
     {
         if(Edge[i]!=-1)
          v[i].push_back(Edge[i]);
     } 
    for(int i=0;i<N;i++)
     {
         if(vis[i]==0)
          {
              ans=max(ans,dfs(i));
              for(auto it : temp)
               vis[it]=2;
              temp.clear(); 
          }
     }
    return ans; 
  }