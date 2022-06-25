// Instead of finding min elements to remove from left & right find max subarray 
// that will give u the diff between (sum & x)


class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        if(sum<x){
            return -1;
        }
        if(sum==x){
            return nums.size();
        }
        int diff=sum-x;
        // find the max subarray with the diff
        int l=0,r=0,maxi=0;
        sum=0;
        while(r<nums.size()){
            sum+=nums[r];
            while(sum>diff){
                sum-=nums[l++];
            }
            if(sum==diff){
                maxi=max(maxi,r-l+1);
            }
            r++;
        }
        return maxi==0 ? -1 : nums.size()-maxi;
    }
};