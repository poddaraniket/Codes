class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> mp;
        set<string> st;
        for(int i=0;i<words.size();i++){
            st.insert(words[i]);
            mp[words[i]]++;
        }
        int count=0;
        for(string w : st){
            string revW=w;
            reverse(revW.begin(),revW.end());
            if(w!=revW && mp[revW]>0){
              int pairs=min(mp[w],mp[revW]);
              count+=pairs*2;
              mp[revW]=0;
              mp[w]=0;  
            }
        }
        bool flag=false;
        for(string w : st){
            string revW=w;
            reverse(revW.begin(),revW.end());
            if(w==revW){
               int pairs=mp[w]/2; 
               if(pairs){
                   count+=(pairs*2);
                   mp[w]-=(pairs*2);
               }
               if(mp[w]>=1 && !flag){
                   count++;
                   flag=true;
               } 
            }
        }
        return count*2;
    }
};