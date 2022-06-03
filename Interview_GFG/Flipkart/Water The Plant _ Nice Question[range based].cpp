int min_sprinklers(int gallery[], int n)
    {
        // code here
        vector<pair<int,int>> range;
        for(int i=0;i<n;i++)
         {
             if(gallery[i]!=-1)
              {
                  range.push_back({i-gallery[i],i+gallery[i]});
              }
         }
        sort(range.begin(),range.end());
        int target=0,ans=0;
        int i=0;
        while(target<n)
        {                         // not meeting your left range                 
            if(i==range.size() || range[i].first>target)  
              return -1;
            int right=range[i].second; 
            // left side of range is still in  limits so maiximse your right range
            while(i+1<range.size() && range[i+1].first<=target)
             {
                 i++;
                 right=max(right,range[i].second);
             }
            // covering your left range and not reaching your right range 
            if(right<target) 
             return -1;
            ans++; 
            target = right+1;
        }
        return ans;
    }