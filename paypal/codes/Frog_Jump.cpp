//Nice Question
bool canCross(vector<int>& stones) {
        map<int,set<int>> mp;
        for(int i=0;i<stones.size();i++)
         {
            mp[stones[i]].insert(-1);
         }
        mp[0].insert(1);
        int k=1;
        for(int i=0;i<stones.size();i++)
        {
            set<int> s=mp[stones[i]];
            for(auto it : s)
            {
                if(it!=-1 && mp.find(it+stones[i])!=mp.end())
                {
                    if(it-1!=0)
                      mp[it+stones[i]].insert(it-1);
                    if(it!=0)
                     mp[it+stones[i]].insert(it);
                    if(it+1!=0)
                     mp[it+stones[i]].insert(it+1);
                }
            }
        }
        set<int> last=mp[stones[stones.size()-1]];
        for(auto it:last)
        {
            if(it!=-1)
                return true; 
        }
        return false;
    }