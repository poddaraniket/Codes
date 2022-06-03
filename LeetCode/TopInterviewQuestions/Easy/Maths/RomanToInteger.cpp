//O(N)

class Solution {
public:
    int romanToInt(string s) {
        map<char,int> mp;
        mp['I']=1;
        mp['V']=5;
        mp['X']=10;
        mp['L']=50;
        mp['C']=100;
        mp['D']=500;
        mp['M']=1000;
        if(s.length()==1){
            return mp[s[0]];
        }
        int sum=0;
        for(int i=s.length()-1;i>=0;i--){
            sum+=mp[s[i]];
            if(i-1>=0 && mp[s[i]]>mp[s[i-1]]){
                sum-=mp[s[i-1]];
                i--;
            }
            // cout<<sum<<endl;
        }
        return sum;
    }
};