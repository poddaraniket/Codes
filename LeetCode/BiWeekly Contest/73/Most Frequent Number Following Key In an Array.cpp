class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) {
        unordered_map<int,int> mp;
        int maxi=0,value=-1;
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]==key){
                mp[nums[i]]++;
                if(mp[nums[i]]>maxi){
                    maxi=mp[nums[i]];
                    value=nums[i];
                }
            }
        }
       return value; 
    }
};