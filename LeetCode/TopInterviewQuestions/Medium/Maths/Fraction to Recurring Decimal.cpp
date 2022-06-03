class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator  == 0) return "0";
        string ans="";
        ans+=((numerator>0)^(denominator>0))?"-":"";
        long n=abs(numerator),d=abs(denominator);
        long q=n/d;
        long r=n%d;
        ans+=to_string(q);
        if(r==0)
           return ans;
        ans+=".";
        unordered_map<long,int> mp;
        mp[r]=ans.size();
        while(r!=0){
            r*=10;
            q=r/d;
            ans+=to_string(q);
            r%=d;
            if(mp[r]){
                // used to add character n specified position
               ans.insert(mp[r],"(");
                ans+=")";
                break; 
            }
            mp[r]=ans.size();
        }
        return ans;
    }
};