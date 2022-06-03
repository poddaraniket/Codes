int countBinarySubstrings(string s) {
// Forming groups and then min of the adjacent grps will be the number of subxtring formed in that grp
        int idx=0,prev=0,curr=1;
        int ans=0;
        //vector<int> grp(s.length());
        //grp[0]=1;
        for(int i=1;i<s.length();i++){
            if(s[i-1]!=s[i]){
                ans+=min(prev,curr);
                prev=curr;
                curr=1;
            }
            else{
                curr++;
            }
        }
        
       // for(int i=1;i<=idx;i++){
       //     ans+=min(grp[i-1],grp[i]);
       // } 
       ans+=min(prev,curr); 
       return ans; 
    }