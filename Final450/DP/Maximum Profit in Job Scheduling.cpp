static bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b)
    {
        return a.first.second<b.first.second;
    }
    
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<pair<pair<int,int>,int>> job;
        int n=startTime.size();
        for(int i=0;i<n;i++)
         {
            job.push_back({{startTime[i],endTime[i]},profit[i]});
         }
        sort(job.begin(),job.end(),cmp);
        int dp[n];
        dp[0]=job[0].second;
        for(int i=1;i<n;i++)
        {
            int inc=job[i].second;
            int last=-1;
            int low=0;
            int high=i-1;
            while(low<=high)
            {
                int mid=(low+high)/2;
                if(job[mid].first.second<=job[i].first.first)
                 {
                   last=mid;
                   low=mid+1;
                 }
                else 
                   high=mid-1;
            }
                if(last!=-1)
                  inc+=dp[last];
                int exc=dp[i-1];
                dp[i]=max(inc,exc);
        }
        return dp[n-1];
    }