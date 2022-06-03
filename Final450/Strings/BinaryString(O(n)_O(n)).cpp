int countBinarySubstrings(string s) {
// Forming groups and then min of the adjacent grps will be the number of subxtring formed in that grp
        int idx=0;
        vector<int> grp(s.length());
        grp[0]=1;
        for(int i=1;i<s.length();i++){
            if(s[i-1]!=s[i]){
                idx++;
                grp[idx]=1;
            }
            else{
                grp[idx]++;
            }
        }
       int ans=0; 
       for(int i=1;i<=idx;i++){
           ans+=min(grp[i-1],grp[i]);
       } 
       return ans; 
    }