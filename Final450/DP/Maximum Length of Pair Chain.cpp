class Solution {
public:
    
    static bool cmp(pair<int,int> a,pair<int,int> b)
    {
        if(a.first<b.first)
          return true;
        else if(a.first==b.first)
        {
            if(a.second<b.second)
                return true; 
        }  
        return false;
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
        // if(pairs.size()==1)
        //    return 1;  
        vector<pair<int,int>> v;
        for(int i=0;i<pairs.size();i++)
         {
            v.push_back({pairs[i][0],pairs[i][1]});
         }
        sort(v.begin(),v.end(),cmp);
        // for(int i=0;i<v.size();i++)
        //      cout<<v[i].first<<" "<<v[i].second<<endl;
        int n=v.size();
        int LIS[n];
        for(int i=0;i<n;i++)
          LIS[i]=1;
        //cout<<LIS[0]<<endl;
        int maxi=1;
        for(int i=1;i<v.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(v[j].second<v[i].first){
                   LIS[i]=max(LIS[i],LIS[j]+1); 
                    maxi=max(LIS[i],maxi);
                }
            }
        }
        return maxi;
    }
};