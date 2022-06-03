class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,bool> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=true;
        }
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]-1)!=mp.end())
               mp[nums[i]]=false; 
        }
        int maxLength=0;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]){
                int count=0;
                int val=nums[i];
                while(mp.find(val)!=mp.end()){
                    count++;
                    val++;
                }
                maxLength=max(count,maxLength);
                count=0;
            }
        }
        return maxLength;
    }
};