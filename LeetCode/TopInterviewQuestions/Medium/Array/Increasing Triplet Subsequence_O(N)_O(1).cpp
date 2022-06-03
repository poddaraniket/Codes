// first -> i second -> j nums[i] -> k

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first=INT_MAX,second=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<first){
                first=nums[i];  // storing the min element in first
            }
            else if(nums[i]>first && nums[i]<second){  // stroing the mid element i.e. 'j'
                second=nums[i];
            }else if(nums[i]>second) // finding the k where i < j < k
                return true;
        }
        return false;
    }
};