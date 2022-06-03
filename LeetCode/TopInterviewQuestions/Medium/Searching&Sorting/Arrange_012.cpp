//O(N)

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int l=0,m=0,r=n-1;
        while(m<=r){
            if(nums[m]==0)
                swap(nums[l++],nums[m++]);
            else if(nums[m]==2)
                swap(nums[m],nums[r--]);
            else
                m++;
        }
    }
};