 string smallestWindow (string s, string p)
    {
        // Your code here
        int mp[256]={0};
        int b[256]={0};
        int count=0;
        for(int i=0;i<p.length();i++){
            if(mp[p[i]]==0)
             count++;
            mp[p[i]]++;
        }
        int low=0,start=0,mini=s.length();
        for(int high=0;high<s.length();high++){
            b[s[high]]++;
            if(b[s[high]]==mp[s[high]])
             count--;
            if(count==0){
                while(b[s[low]]>mp[s[low]]){
                    b[s[low]]--;
                    low++;
                }
                if(mini>(high-low+1)){
                    mini=high-low+1;
                    start=low;
                }
            } 
        }
        if(count>0)
         return "-1";
        return s.substr(start,mini);
    }