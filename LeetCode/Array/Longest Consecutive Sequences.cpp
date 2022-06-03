class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        sort(nums.begin(),nums.end());
        int maxi=0,cnt=1;    
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]-nums[i-1]==1)
                cnt++;
            else if(nums[i]-nums[i-1]==0)
                continue;
            else
            {
                maxi=max(maxi,cnt);
                cnt=1;
            }   
        }
        return max(maxi,cnt);
    }
};