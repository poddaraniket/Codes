//O(N) -> max every element will be touched twice
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256]={0};
        int maxi=0;
        int l=0,r=0;
        int len=s.length();
        while(r<len){
            int index=s[r];
            freq[index]++;
            while(freq[index]>1){
                int startIndex=s[l];
                freq[startIndex]--;
                l++;
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};