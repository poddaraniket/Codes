//O(N)

class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int i=1,l=0,r=1;
        int count=0;
        while(r<nums.size()){
            // cout<<r<<endl;
            if(nums[i]==nums[l]){
                i++;
                if(r<i)
                  r=i;  
                continue;
            }
            else if(nums[i]==nums[r])
            {
                r++;
            }
            else{
                if( (nums[l]>nums[i] && nums[r]>nums[i]) || (nums[l]<nums[i] && nums[r]<nums[i]) )
                  count++;
                l=i;
                i=r;
            }
        }
       return count;
    }
};