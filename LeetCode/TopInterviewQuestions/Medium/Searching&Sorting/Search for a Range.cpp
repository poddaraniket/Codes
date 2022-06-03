//O(logN)

class Solution {
public:
    
    int start(vector<int>& nums, int target){
        int low=0,high=nums.size()-1,best=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target)
                best=mid;
            if(nums[mid]<target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return best;
    }
    
    int end(vector<int>& nums, int target){
        int low=0,high=nums.size()-1,best=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(nums[mid]==target)
                best=mid;
            if(nums[mid]<=target){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return best;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int a=start(nums,target);
        int b=end(nums,target);
        vector<int> v;
        v.push_back(a);
        v.push_back(b);
        return v;
    }
};