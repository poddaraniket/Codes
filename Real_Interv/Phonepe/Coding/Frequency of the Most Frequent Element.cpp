//O(NlogN)

// Basic Sliding Window teq where window siz if flexible and you have to determine the best size 

class Solution {
public:
    
    int maxFrequency(vector<int>& nums, long k) {
        sort(nums.begin(),nums.end());
        int i=0,ans=0;
        //expand the window
        for(int j=0;j<nums.size();j++)
        {
            k+=nums[j];
            //shrink the window
            while(k<(long)nums[j]*(j-i+1))
             {
                k-=nums[i];
                i++;
             }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};