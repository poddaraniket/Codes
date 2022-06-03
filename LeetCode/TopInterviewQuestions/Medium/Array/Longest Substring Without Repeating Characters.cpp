class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> pos(256,-1);
        int maxLength=0;
        int start=0,end=0;
        while(end<s.length()){
            while(pos[s[end]]!=-1){
                pos[s[start]]=-1;
                start++;
            }
            pos[s[end]]=end;
            maxLength=max(maxLength,end-start+1);
            end++;
        }
        return maxLength;
    }
};