class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int l=0,index=0;
        int count=0;
        for(int r=1;r<nums.size();r++){
            if(l%2==0){
                if(nums[index]==nums[r]){
                    count++;
                }else{
                    l++;
                    index=r;
                }
            }else{
                    l++;
                    index=r;
                }
        }
        int n=nums.size();
        int rem=n-count;
        return (rem%2) ? count + 1 : count;
    }
};