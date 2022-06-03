//O(logN)

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 0;
        if(nums[0]>nums[1])
            return 0;
        if(nums[n-2]<nums[n-1])
            return n-1;
       int l=0,h=n-1;
       int mid;
        while(l<=h){
            mid=h-(h-l)/2;
            if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
                return mid;
            else if(nums[mid]<nums[mid+1]){
                l=mid+1;
            }else
                h=mid-1;
        }
        return mid;
    }
};