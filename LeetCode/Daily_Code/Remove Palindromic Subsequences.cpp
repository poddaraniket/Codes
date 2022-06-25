// ans -> 1(entire string palidrome) 2->otherwise

class Solution {
public:
    int removePalindromeSub(string s) {
        int l=0,r=s.length()-1;
        while(l<r){
            if(s[l++]!=s[r--])
                return 2;
        }
        return 1;
    }
};