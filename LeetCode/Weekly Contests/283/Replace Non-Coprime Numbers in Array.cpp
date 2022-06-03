//O(NlogM)

class Solution {
public:
    
    long long gcd(long long a,long long b){
        if(b==0)
            return a;
        return gcd(b,a%b);
    }
    
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            long long y=nums[i];
            while(ans.size()>0){
                long long gcdXY=gcd(ans.back(),y);
                if(gcdXY<=1)
                    break;
                long long x=ans.back();
                ans.pop_back();
                y=(x*y)/gcdXY;
            }
            ans.push_back(y);
        }
        return ans;
    }
};