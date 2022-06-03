bool cmp(pair<int,int> a,pair<int,int> b){
    return a.first<b.first;
}

int maxChainLen(struct val p[],int n)
{
//Your code here
  vector<pair<int,int>> v;
  for(int i=0;i<n;i++)
   {
       v.push_back({p[i].first,p[i].second});
   }
   sort(v.begin(),v.end(),cmp);
   int LIS[n];
   for(int i=0;i<n;i++)
    {
       LIS[i]=1;
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
         {
             if(v[j].second<v[i].first)
              LIS[i]=max(LIS[j]+1,LIS[i]);
         }
    }
    int maxi=0;
    for(int i=0;i<n;i++)
     maxi=max(maxi,LIS[i]);
     
    return maxi; 
}