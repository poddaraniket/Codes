//O(N^2)

class Solution {
public:
    
    int gcd(int a,int b){
        if(b==0)
            return a;
        return gcd(b,a%b); 
    }
    
    long long countPairs(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> mp;
        long long count=0;
        for(int i=0;i<n;i++){
            // gcd of a number and k 
            int have=gcd(nums[i],k);
            // have means what factor u have got that is divisible by k
            int want=k/have;
            // want means u look for a number in map that pairs up with nums[i] and gives the needed factor so that when they multiply we get 
            // divisibe by k
            for(auto it : mp){
                if((it.first)%want==0){
                    count+=(it.second);
                }
            }
            mp[have]++;
        }
       
        return count;
    }
};