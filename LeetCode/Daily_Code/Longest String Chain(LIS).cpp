//Max(16*1000)
class Solution {
public:
    
    static bool cmp(string a,string b){
        return a.length()<b.length();
    }

    
    int longestStrChain(vector<string>& words) {
        int maxi=1;
        sort(words.begin(),words.end(),cmp);
        int n=words.size();
        vector<int> LIS(n,1);
        map<string,int> mp;
        int res=0;
        //O(|words|)
        for(string w : words){
            int longest=0;
            //O(|words[i]|)
            for(int j=0;j<w.length();j++){
               string sub=w.substr(0,j)+w.substr(j+1);
               longest=max(longest,mp[sub]+1);
            }
            mp[w]=longest;
            res=max(res,mp[w]);
        }
        return res;
    }
};