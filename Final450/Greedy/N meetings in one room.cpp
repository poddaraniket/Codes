//O(NlogN)

static bool cmp(pair<int,int> a,pair<int,int> b)
    {
        return a.second<b.second;
    }
    
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
         {
             v.push_back({start[i],end[i]});
         }
        sort(v.begin(),v.end(),cmp);
        int endtime=0,count=0;
        for(int i=0;i<n;i++){
            if(v[i].first>endtime)
             {
                 endtime=v[i].second;
                 count++;
             }
        }
        return count;
    }